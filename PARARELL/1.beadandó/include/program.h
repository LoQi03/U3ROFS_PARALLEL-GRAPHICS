#ifndef PROGRAM_H
#define PROGRAM_H

#define N 30

void printMatrix(double matrix[N][N]);
void generateMatrix(double matrix[N][N]);
void swap_rows(double matrix[N][N], int row1, int row2, int n);
void pivot(double matrix[N][N]);
void normalize(double matrix[N][N]);
#endif