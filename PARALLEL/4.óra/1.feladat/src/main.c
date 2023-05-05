#include "program.h"
#include <time.h>
int main()
{
    int *nums = generateNumbers();
    int section_result1 = 1;
    int section_result2 = 1;
    clock_t start_time = clock();
#pragma omp parallel
    {
#pragma omp sections
        {
#pragma omp section
            section_result1 = pararellMultiply(nums, section_result1, 1, 0, SIZE / 2);
#pragma omp section
            section_result2 = pararellMultiply(nums, section_result2, 2, SIZE / 2, SIZE);
        }
    }
    double time_spent = (double)(clock() - start_time) / CLOCKS_PER_SEC;
    printf("\nPararell result:%d\n", section_result1 * section_result2);
    printf("\nPararell time: %lf\n", time_spent);
    printf("\n");
    sleep(10);
    sequentialMultiply(nums);
    free(nums);
    return 0;
}