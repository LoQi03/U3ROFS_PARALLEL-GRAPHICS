#include <stdio.h>
#include <stdlib.h>
#include "program.h"
#include <time.h>
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Hibas bemenet!\n");
        return 1;
    }
    double x = strtod(argv[1], NULL); // pont, ahol a függvényeket kiértékeljük
    int n = atoi(argv[2]);            // sorfejtés pontossága
    double result_cos, result_sin, result_exp;
    clock_t start = clock();
    printf("x = %f, n = %d\n", x, n);

#pragma omp parallel
    {
#pragma omp sections
        {
#pragma omp section
            cos_taylor(x, n);
#pragma omp section
            sin_taylor(x, n);
#pragma omp section
            exp_taylor(x, n);
        }
    }
    return 0;
}
