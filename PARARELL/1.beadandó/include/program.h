#ifndef PROGRAM_H
#define PROGRAM_H

#define N 3

void printMatrix(float matrix[N][N + 1]);
void swapRows(float matrix[N][N + 1], int i, int j);
void gaussianElimination(float matrix[N][N + 1]);
void normalize(float matrix[N][N + 1]);
#endif