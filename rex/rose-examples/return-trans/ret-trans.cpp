//This iterates through a source file and transforms return statements
#include <iostream>
#include <vector>

#include "rose.h"
#include "RoseAst.h"

class Searcher : public AstSimpleProcessing {
protected:
	virtual void visit(SgNode* n);
private:
	bool was_ret = false;
};

void Searcher::visit(SgNode* node) {
	std::cout << "CLASS: " << node->class_name() << std::endl;

	if (node->variantT() == V_SgReturnStmt) {
		std::cout << "return!" << std::endl;
		was_ret = true;
	} else if (node->variantT() == V_SgIntVal) {
		if (was_ret) {
			SgIntVal *iv = dynamic_cast<SgIntVal *>(node);
			iv->set_valueString("30");
			
			was_ret = false;
		}
	} else if (node->variantT() == V_SgStringVal) {
		std::cout << "String!" << std::endl;
		
		dynamic_cast<SgStringVal *>(node)->set_value("HELLO!!!");
	} else {
		was_ret = false;
	}
}

int main(int argc, char * argv[]) {
	SgProject *project = frontend (argc, argv);
	
	Searcher s;
	s.traverseInputFiles(project,preorder);

	return backend(project);
}

