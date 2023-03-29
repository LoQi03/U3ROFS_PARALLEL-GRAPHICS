#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include "program.h"
#include <pthread.h>

int *generateNumbers()
{
    int *num = (int *)malloc(SIZE * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++)
    {
        num[i] = (rand() % (10 - 1)) + 1;
    }
    return num;
}
void printNumbers(int *nums)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", nums[i]);
    }
}
void sequentialMultiply(int *nums)
{
    clock_t start = clock();
    long result = nums[0];
    for (int i = 1; i < SIZE; i++)
    {
        result *= nums[i];
        printf("%ld ", result);
    }
    double time_spent = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("\nResult: %ld \n", result);
    printf("\nSequential time: %lf\n", time_spent);
}
void pararellMultiply(int *nums)
{
    clock_t start = clock();
    long result = nums[0];
    for (int i = 1; i < SIZE; i++)
    {
        result *= nums[i];
        printf("%ld ", result);
    }
    double time_spent = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("\nResult: %ld \n", result);
    printf("\nSequential time: %lf\n", time_spent);
}