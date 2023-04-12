#include <stdio.h>
#include <stdlib.h>
#include "program.h"
#include <math.h>

double cos_taylor(double x, int n)
{
    double result = 1.0;
    int i;
#pragma omp parallel for reduction(+ \
                                   : result)
    for (i = 1; i <= n; i++)
    {
        result += pow(-1, i) * pow(x, 2 * i) / tgamma(2 * i + 1);
    }
    return result;
}

double sin_taylor(double x, int n)
{
    double result = x;
    int i;
#pragma omp parallel for reduction(+ \
                                   : result)
    for (i = 1; i <= n; i++)
    {
        result += pow(-1, i) * pow(x, 2 * i + 1) / tgamma(2 * i + 2);
    }
    return result;
}
double exp_taylor(double x, int n)
{
    double result = 1.0;
    int i;
#pragma omp parallel for reduction(+ \
                                   : result)
    for (i = 1; i <= n; i++)
    {
        result += pow(x, i) / tgamma(i + 1);
    }
    return result;
}