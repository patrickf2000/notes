// clang -g llvm2.c `llvm-config --cflags --ldflags --system-libs --libs all` -o llvm2
#include <llvm-c/Core.h>
#include <llvm-c/Target.h>
#include <llvm-c/TargetMachine.h>
#include <llvm-c/Support.h>

#include <stddef.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    // When we compile, we really want Intel syntax
    char const *args[] = { "", "--x86-asm-syntax=intel" };
    LLVMParseCommandLineOptions(2, args, NULL);
    
    LLVMContextRef context = LLVMContextCreate();
    LLVMModuleRef module = LLVMModuleCreateWithNameInContext("mod1", context);
    LLVMBuilderRef builder = LLVMCreateBuilderInContext(context);
    
    // Create the main function
    LLVMTypeRef i32_type = LLVMInt32TypeInContext(context);
    LLVMTypeRef func_type = LLVMFunctionType(i32_type, NULL, 0, 0);
    
    LLVMValueRef func = LLVMAddFunction(module, "main", func_type);
    LLVMBasicBlockRef block = LLVMAppendBasicBlockInContext(context, func, "entry");
    LLVMPositionBuilderAtEnd(builder, block);
    
    LLVMBuildRetVoid(builder);
    
    // debug
    LLVMDumpModule(module);
    
    // compile
    LLVMInitializeAllTargetInfos();
    LLVMInitializeAllTargets();
    LLVMInitializeAllTargetMCs();
    LLVMInitializeAllAsmParsers();
    LLVMInitializeAllAsmPrinters();
    
    char *target_triple = LLVMGetDefaultTargetTriple();
    
    LLVMTargetRef target;
    char *msg;
    LLVMGetTargetFromTriple(target_triple, &target, &msg);
    
    char *cpu_name = LLVMGetHostCPUName();
    char *cpu_features = LLVMGetHostCPUFeatures();
    
    LLVMTargetMachineRef machine = LLVMCreateTargetMachine(target, target_triple, cpu_name, cpu_features,
                                    LLVMCodeGenLevelNone, LLVMRelocDefault, LLVMCodeModelDefault);
                                    
    LLVMTargetMachineEmitToFile(machine, module, "./first.s", LLVMAssemblyFile, &msg);
                                    
    LLVMDisposeTargetMachine(machine);
    
    // Cleanup and return
    LLVMDisposeModule(module);
    LLVMContextDispose(context);

    return 0;
}
