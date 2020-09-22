#include <stdio.h>
#include <time.h>

#include <unistd.h>

void func() {
    for (int i = 0; i<1000000000; i++) {}
}

int main(int argc, char *argv[]) {
    clock_t begin = clock();
    
    func();
    
    clock_t end = clock();
    double elapsed = ((double)(end-begin)) / CLOCKS_PER_SEC;
    
    printf("Elapsed: %f\n", elapsed);
    
    return 0;
}
