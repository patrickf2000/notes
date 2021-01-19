//This removes return statements from a file
#include <iostream>
#include <vector>

#include "rose.h"
#include "RoseAst.h"

using namespace SageInterface;

class Searcher : public AstSimpleProcessing {
protected:
	virtual void visit(SgNode* n);
public:
	std::vector<SgNode *> return_nodes;
};

void Searcher::visit(SgNode* node) {
	std::cout << "CLASS: " << node->class_name() << std::endl;

	if (node->variantT() == V_SgReturnStmt) {
		std::cout << "return!" << std::endl;
		return_nodes.push_back(node);
	}
}

int main(int argc, char * argv[]) {
	SgProject *project = frontend (argc, argv);
	
	Searcher s;
	s.traverseInputFiles(project,preorder);
	
	for (auto rNode : s.return_nodes) {
		SgStatement *ss = dynamic_cast<SgStatement *>(rNode);
		removeStatement(ss, true);
	}

	return backend(project);
}

