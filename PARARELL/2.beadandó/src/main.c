
#include <stdio.h>
#include "program.h"

#include <stdio.h>
#include <math.h>

int main()
{
    double x = 0.5; // pont, ahol a függvényeket kiértékeljük
    int n = 10;     // sorfejtés pontossága
#pragma omp parallel
    {
#pragma omp sections
        {
#pragma omp section
            printf("cos(%f) = %f\n", x, cos_taylor(x, n));
#pragma omp section
            printf("sin(%f) = %f\n", x, sin_taylor(x, n));
#pragma omp section
            printf("exp(%f) = %f\n", x, exp_taylor(x, n));
        }
    }
    return 0;
}
