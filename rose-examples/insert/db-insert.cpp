//db-insert.cpp
#include <iostream>
#include <vector>
#include <rose.h>

using namespace SageInterface;
using namespace SageBuilder;

//Our class for traversing the tree
class Searcher : public AstSimpleProcessing {
protected:
	virtual void visit(SgNode *node);
public:
	bool found = false;
	std::vector<SgNode *> pragmas;
	std::vector<std::string> funcs;
};

//Called when the traversal hits a new node
void Searcher::visit(SgNode *node) {
	//See if we have a function definition
	if (node->variantT() == V_SgFunctionDeclaration) {
		//If we have a function following the #pragma test declaration, then add it to our list
		if (found) {
			SgFunctionDeclaration *f = dynamic_cast<SgFunctionDeclaration *>(node);
			funcs.push_back(f->get_name());
			found = false;
		}
		return;
		
	//Otherwise ignore anything not a pragma definition
	} else if (node->variantT() != V_SgPragma) {
		return;
	}
		
	//Push the node back to the list so we can delete it later
	SgPragma *pragma = dynamic_cast<SgPragma *>(node);
	if (pragma->get_pragma() == "test") {
		pragmas.push_back(node);
	}
	
	found = true;
}

int main(int argc, char *argv[]) {
	//Build the tree
	SgProject *project = frontend(argc, argv);
	
	//Gather necessary information about our tree
	Searcher s;
	s.traverseInputFiles(project, preorder);
	
	//Insert the header
	auto global = getFirstGlobalScope(project);
	insertHeader("debug.h", PreprocessingInfo::after, false, global);
	
	//Insert the debug statements
	for (auto s : s.funcs) {
		auto func = findFunctionDeclaration(project, s, NULL, false);
		auto body = func->get_definition()->get_body();
		pushScopeStack(body);
		
		auto ret_type = buildVoidType();
		auto arg_list = buildExprListExp();
		auto callStmt = buildFunctionCallStmt("debug", ret_type, arg_list);
		
		auto firstStmt = getLastStatement(topScopeStack());
		insertStatement(firstStmt, callStmt);
		popScopeStack();
	}
	
	//Remove the pragma test statements
	for (auto pr : s.pragmas) {
		deleteAST(pr);
		delete pr;
	}
	
	//Rebuild our source file
	return backend(project);
}
