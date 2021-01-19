// clang++ -g -O3 llvm1.cpp `llvm-config --cxxflags --ldflags --system-libs --libs all` -o llvm1
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

int main(int argc, char *argv[]) {
    std::unique_ptr<llvm::LLVMContext> context;
    std::unique_ptr<llvm::IRBuilder<>> builder;
    std::unique_ptr<llvm::Module> mod;
    
    context = std::make_unique<llvm::LLVMContext>();
    builder = std::unique_ptr<llvm::IRBuilder<>>(new llvm::IRBuilder<>(*context));
    mod = std::make_unique<llvm::Module>("mod1", *context);
    
    // Create the main function
    llvm::FunctionType *intType = llvm::FunctionType::get(llvm::IntegerType::getInt32Ty(*context),
        std::vector<llvm::Type *>(), false);
    
    llvm::Function *main_func = llvm::Function::Create(intType, llvm::Function::ExternalLinkage,
        "main", mod.get());
        
    llvm::BasicBlock *mainBB = llvm::BasicBlock::Create(*context, "entry", main_func);
    builder->SetInsertPoint(mainBB);
    
    llvm::APInt retVal(32, (uint32_t)0, true);
    builder->CreateRet(llvm::ConstantInt::get(*(context), retVal));
    
    // Debug
    mod->print(llvm::outs(), nullptr);

    return 0;
}
