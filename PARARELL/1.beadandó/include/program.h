#ifndef PROGRAM_H
#define PROGRAM_H

#define N 3

void printMatrix(float matrix[N][N]);
void swap_rows(float matrix[N][N], int row1, int row2, int n);
void pivot(float matrix[N][N]);
void normalize(float matrix[N][N]);
#endif