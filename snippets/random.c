#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create_random(float *numbers, int size) {
    srand((unsigned)time(NULL));
    int lo = 0;
    int hi = 100;
    
    for (int i = 0; i<size; i++) {
        numbers[i] = (float)(rand()) / (float)(RAND_MAX/(hi-lo));
    }
}

void print(float *numbers, int size) {
    printf("[ ");
    for (int i = 0; i<size; i++)
        printf("%.4f ", numbers[i]);
    printf("]\n");
} 

int main() {
    int N = 10;
    float *numbers = malloc(sizeof(float)*N);
    
    create_random(numbers, N);
    print(numbers, N);
    
    free(numbers);

    return 0;
}
