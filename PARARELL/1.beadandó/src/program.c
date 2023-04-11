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

void swap_rows(float matrix[N][N], int row1, int row2, int n)
{
    float temp;
    for (int i = 0; i < n; i++)
    {
        temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

void pivot(float matrix[N][N])
{
    int max_index;
    float max_value, abs_value;
    for (int i = 0; i < N; i++)
    {
        max_index = i;
        max_value = matrix[i][i];
        // find the row with the maximum absolute value
        for (int j = i + 1; j < N; j++)
        {
            abs_value = fabs(matrix[j][i]);
            if (abs_value > max_value)
            {
                max_index = j;
                max_value = abs_value;
            }
        }

        // swap the current row with the row with the maximum absolute value
        swap_rows(matrix, i, max_index, N);

        // zero out the elements below the current pivot element
        for (int j = i + 1; j < N; j++)
        {
            float factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < N; k++)
            {
                matrix[j][k] = matrix[j][k] - factor * matrix[i][k];
            }
        }
    }
}
void normalize(float matrix[N][N])
{

    float det = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][0] * matrix[1][2] * matrix[2][1] - matrix[0][1] * matrix[1][0] * matrix[2][2];
    printf("Determinans: %f\n", det);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] /= det;
        }
    }
}