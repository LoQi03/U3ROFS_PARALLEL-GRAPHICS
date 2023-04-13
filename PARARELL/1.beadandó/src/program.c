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
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = (double)rand() / RAND_MAX; // generáljunk egy véletlen számot 0 és 1 között
        }
    }
}
void swap_rows(double matrix[N][N], int row1, int row2, int cols)
{
    for (int i = 0; i < cols; i++)
    {
        double temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

void pivot(double matrix[N][N])
{
    int max_index;
    double max_value, abs_value;
    for (int i = 0; i < N; i++)
    {
        max_index = i;
        max_value = matrix[i][i];
        for (int j = i + 1; j < N; j++)
        {
            abs_value = fabs(matrix[j][i]);
            if (abs_value > max_value)
            {
                max_index = j;
                max_value = abs_value;
            }
        }

        swap_rows(matrix, i, max_index, N);

        for (int j = i + 1; j < N; j++)
        {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < N; k++)
            {
                matrix[j][k] = matrix[j][k] - factor * matrix[i][k];
            }
        }
    }
}

void normalize(double matrix[N][N])
{
    double det = 1.0;
    for (int i = 0; i < N; i++)
    {
        det *= matrix[i][i];
    }
    printf("Determinans: %f\n", det);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] /= matrix[i][i];
        }
    }
}