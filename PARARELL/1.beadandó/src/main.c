#include "program.h"
#include <stddef.h>
#include <pthread.h>
#include <stdio.h>
int main()
{

    float matrixGauss[N][N + 1] = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}};
    float matrixNorm[N][N + 1] = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}};

    printf("Kezdeti matrix:\n");
    printMatrix(matrixGauss);

    gaussianElimination(matrixGauss);
    normalize(matrixNorm);
    printf("Normalizalas utan:\n");
    printMatrix(matrixNorm);
    printf("Pivotalas es Gauss-eliminacio utan:\n");
    printMatrix(matrixGauss);

    return 0;
}
