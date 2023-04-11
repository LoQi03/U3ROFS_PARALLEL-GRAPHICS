#include "program.h"
#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main()
{

    float matrixGauss[N][N] = {
        {2, 1, -1},
        {-3, -1, 2},
        {-2, 1, 2}};
    float matrixNorm[N][N] = {
        {2, 1, -1},
        {-3, -1, 2},
        {-2, 1, 2}};

    printf("Kezdeti matrix:\n");
    printMatrix(matrixGauss);

    pthread_t thread_Gauss, thread_Norm;
    clock_t start_Gauss = clock();
    pthread_create(&thread_Gauss, NULL, pivot, (void *)matrixGauss);
    clock_t start_Norm = clock();
    pthread_create(&thread_Norm, NULL, normalize, (void *)matrixNorm);

    pthread_join(thread_Norm, NULL);
    double end_Norm = (double)(clock() - start_Norm) / CLOCKS_PER_SEC;
    printf("Normalizalas utan:(%lf)\n", end_Norm);
    printMatrix(matrixNorm);

    pthread_join(thread_Gauss, NULL);
    double end_Gauss = (double)(clock() - start_Gauss) / CLOCKS_PER_SEC;
    printf("Gauss-eliminacio utan:(%lf)\n", end_Gauss);
    printMatrix(matrixGauss);
    return 0;
}
