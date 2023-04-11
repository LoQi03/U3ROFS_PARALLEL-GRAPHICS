#ifndef PROGRAM_H
#define PROGRAM_H

#define N 3

void printMatrix(float matrix[N][N]);
void swapRows(float matrix[N][N], int i, int j);
void gaussianElimination(float matrix[N][N]);
void normalize(float matrix[N][N]);
void gaussianEliminationThread(void *matrix);
void normalizeThread(void *matrix);
#endif