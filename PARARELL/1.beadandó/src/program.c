#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "program.h"

void printMatrix(double matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}
void generateMatrix(double matrix[N][N])
{
    clock_t start = clock();
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = (double)rand() / RAND_MAX;
        }
    }
}
void multiply_matrix(double matrix[N][N])
{
    clock_t start = clock();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] *= CONSTANT;
        }
    }
    printf("Szorzas(%lf)\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}
void division_matrix(double matrix[N][N])
{
    clock_t start = clock();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] /= CONSTANT;
        }
    }
    printf("Osztas(%lf)\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}
void pow_matrix(double matrix[N][N])
{
    clock_t start = clock();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = pow(matrix[i][j], CONSTANT);
        }
    }
    printf("Hatvanyozas(%lf)\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}
void sqrt_matrix(double matrix[N][N])
{
    clock_t start = clock();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = pow(matrix[i][j], 1.0f / CONSTANT);
        }
    }
    printf("Gyok(%lf)\n", (double)(clock() - start) / CLOCKS_PER_SEC);
}