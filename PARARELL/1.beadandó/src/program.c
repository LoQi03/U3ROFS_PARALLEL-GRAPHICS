#include <stdio.h>
#include "program.h"
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define N 3
void printMatrix(float matrix[N][N + 1])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N + 1; j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void swapRows(float matrix[N][N + 1], int i, int j)
{
    for (int k = 0; k < N + 1; k++)
    {
        float temp = matrix[i][k];
        matrix[i][k] = matrix[j][k];
        matrix[j][k] = temp;
    }
}

void gaussianElimination(float matrix[N][N + 1])
{
    for (int i = 0; i < N; i++)
    {
        // Pivotálás
        int maxRow = i;
        for (int j = i + 1; j < N; j++)
        {
            if (matrix[j][i] > matrix[maxRow][i])
            {
                maxRow = j;
            }
        }
        if (i != maxRow)
        {
            swapRows(matrix, i, maxRow);
        }

        // Gauss-elimináció
        for (int j = i + 1; j < N; j++)
        {
            float ratio = matrix[j][i] / matrix[i][i];
            for (int k = i; k < N + 1; k++)
            {
                matrix[j][k] -= ratio * matrix[i][k];
            }
        }
    }
}
void normalize(float matrix[N][N + 1])
{
    float sum;

    for (int j = 0; j < N + 1; j++)
    {
        sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += matrix[i][j];
        }

        for (int i = 0; i < N; i++)
        {
            matrix[i][j] /= sum;
        }
    }
}