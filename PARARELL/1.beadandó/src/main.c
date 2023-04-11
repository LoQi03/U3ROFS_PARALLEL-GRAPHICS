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
    pthread_create(&thread_Gauss, NULL, gaussianEliminationThread, (void *)matrixGauss);
    pthread_create(&thread_Norm, NULL, normalize, (void *)matrixNorm);

    pthread_join(thread_Norm, NULL);
    printf("Normalizalas utan:\n");
    printMatrix(matrixNorm);

    pthread_join(thread_Gauss, NULL);
    printf("Pivotalas es Gauss-eliminacio utan:\n");
    printMatrix(matrixGauss);
    return 0;
}
