#include <stdio.h>
#include "program.h"
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#define N 3

void printMatrix(float matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void swapRows(float matrix[N][N], int i, int j)
{
    for (int k = 0; k < N + 1; k++)
    {
        float temp = matrix[i][k];
        matrix[i][k] = matrix[j][k];
        matrix[j][k] = temp;
    }
}

void gaussianElimination(float matrix[N][N])
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
void normalize(float matrix[N][N])
{
    float det = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][0] * matrix[1][2] * matrix[2][1] - matrix[0][1] * matrix[1][0] * matrix[2][2];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] /= det;
        }
    }
}
void gaussianEliminationThread(void *matrix)
{
    gaussianElimination((float(*)[N])matrix);
}
void normalizeThread(void *matrix)
{
    normalize((float(*)[N])matrix);
}