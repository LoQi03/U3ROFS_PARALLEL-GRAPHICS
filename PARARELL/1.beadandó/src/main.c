#include "program.h"
#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main()
{
    float matrixGauss[N][N] = {
        {1.8, 3.2, -2.5},
        {-4.1, 0.7, 1.3},
        {2.1, -3.7, 2.6}};
    float matrixNorm[N][N] = {
        {1.8, 3.2, -2.5},
        {-4.1, 0.7, 1.3},
        {2.1, -3.7, 2.6}};

    printf("Kezdeti matrix:\n");
    printMatrix(matrixGauss);

    pthread_t thread_Gauss, thread_Norm;
    pthread_create(&thread_Gauss, NULL, pivot, (void *)matrixGauss);
    pthread_create(&thread_Norm, NULL, normalize, (void *)matrixNorm);
    pthread_join(thread_Gauss, NULL);
    pthread_join(thread_Norm, NULL);
    return 0;
}
