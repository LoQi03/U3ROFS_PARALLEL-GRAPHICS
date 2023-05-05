#include <stdio.h>
#include <stdlib.h>
#include "program.h"
#include <math.h>
#include <time.h>
double factorial(int n)
{
    double result = 1.0;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

double cos_taylor(double x, int n, int thread_count)
{
    clock_t start = clock();
    double result = 1.0;
#pragma omp parallel for num_threads(thread_count) reduction(+ : result)
    for (int i = 1; i <= n; i++)
    {
        double term = pow(-1, i) * pow(x, 2 * i) / factorial(2 * i);
        result += term;
    }
    printf("cos(%f) = %lf\t ido:%lf\n", x, result, (double)(clock() - start) / CLOCKS_PER_SEC);
    return result;
}

double sin_taylor(double x, int n, int thread_count)
{
    clock_t start = clock();
    double result = x;
#pragma omp parallel for num_threads(thread_count) reduction(+ : result)
    for (int i = 1; i <= n; i++)
    {
        double term = pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
        result += term;
    }
    printf("sin(%f) = %lf\t ido:%lf\n", x, result, (double)(clock() - start) / CLOCKS_PER_SEC);
    return result;
}

double exp_taylor(double x, int n, int thread_count)
{
    clock_t start = clock();
    double result = 1.0;
#pragma omp parallel for num_threads(thread_count) reduction(+ : result)
    for (int i = 1; i <= n; i++)
    {
        double term = pow(x, i) / factorial(i);
        result += term;
    }
    printf("exp(%f) = %lf\t ido:%lf\n", x, result, (double)(clock() - start) / CLOCKS_PER_SEC);
    return result;
}
double seq_cos_taylor(double x, int n)
{
    clock_t start = clock();
    double result = 1.0;
    for (int i = 1; i <= n; i++)
    {
        double term = pow(-1, i) * pow(x, 2 * i) / factorial(2 * i);
        result += term;
    }
    printf("cos(%f) = %lf\t ido:%lf\n", x, result, (double)(clock() - start) / CLOCKS_PER_SEC);
    return result;
}

double seq_sin_taylor(double x, int n)
{
    clock_t start = clock();
    double result = x;
    for (int i = 1; i <= n; i++)
    {
        double term = pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
        result += term;
    }
    printf("sin(%f) = %lf\t ido:%lf\n", x, result, (double)(clock() - start) / CLOCKS_PER_SEC);
    return result;
}

double seq_exp_taylor(double x, int n)
{
    clock_t start = clock();
    double result = 1.0;
    for (int i = 1; i <= n; i++)
    {
        double term = pow(x, i) / factorial(i);
        result += term;
    }
    printf("exp(%f) = %lf\t ido:%lf\n", x, result, (double)(clock() - start) / CLOCKS_PER_SEC);
    return result;
}