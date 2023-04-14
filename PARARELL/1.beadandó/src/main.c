#include "program.h"
#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    double matrix[N][N];
    double matrixMultiply[N][N];
    double matrixDivision[N][N];
    double matrixSqrt[N][N];
    double matrixPow[N][N];
    generateMatrix(matrix);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrixMultiply[i][j] = matrix[i][j];
            matrixDivision[i][j] = matrix[i][j];
            matrixSqrt[i][j] = matrix[i][j];
            matrixPow[i][j] = matrix[i][j];
        }
    }

    printf("Kezdeti matrix:\n");
    printMatrix(matrix);

    pthread_t thread_Multiply, thread_Division, thread_Sqrt, thread_Pow;
    pthread_create(&thread_Multiply, NULL, multiply_matrix, (void *)matrixMultiply);
    pthread_create(&thread_Division, NULL, division_matrix, (void *)matrixDivision);
    pthread_create(&thread_Sqrt, NULL, sqrt_matrix, (void *)matrixSqrt);
    pthread_create(&thread_Pow, NULL, pow_matrix, (void *)matrixPow);
    pthread_join(thread_Multiply, NULL);
    pthread_join(thread_Division, NULL);
    pthread_join(thread_Sqrt, NULL);
    pthread_join(thread_Pow, NULL);
    return 0;
}
