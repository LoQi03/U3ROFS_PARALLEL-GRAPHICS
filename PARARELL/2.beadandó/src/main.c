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
    printf("pararell:\n");
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
    printf("szekvencialis:\n");
    seq_cos_taylor(x, n);
    seq_sin_taylor(x, n);
    seq_exp_taylor(x, n);
    return 0;
}
