#include "program.h"

int main()
{
    int *nums = generateNumbers();
    // printNumbers(nums);
    sequentialMultiply(nums);

#pragma omp parallel
    {
#pragma omp sections
        {
#pragma omp section
            sequentialMultiply(nums);
#pragma omp section
            sequentialMultiply(nums);
        }
    }
    free(nums);
    return 0;
}