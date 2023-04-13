#include "program.h"
#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main()
{
    double matrixGauss[N][N];
    double matrixNorm[N][N];
    generateMatrix(matrixGauss);

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            matrixNorm[i][j] = matrixGauss[i][j];
        }
    }

    printf("Kezdeti matrix:\n");
    printMatrix(matrixGauss);

    clock_t start = clock();
    pthread_t thread_Gauss, thread_Norm;
    pthread_create(&thread_Gauss, NULL, pivot, (void *)matrixGauss);
    pthread_create(&thread_Norm, NULL, normalize, (void *)matrixNorm);
    pthread_join(thread_Gauss, NULL);
    printf("Gauss utani matrix(%lf):\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    printMatrix(matrixGauss);
    pthread_join(thread_Norm, NULL);
    printf("Normalas utani matrix(%lf):\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    printMatrix(matrixNorm);

    return 0;
}
