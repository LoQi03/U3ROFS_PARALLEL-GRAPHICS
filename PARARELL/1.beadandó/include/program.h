#ifndef PROGRAM_H
#define PROGRAM_H

#define N_MAX 150000
int *arr;

void quickSort(int *arr, int left, int right);
void *parallel_quickSort(void *arg);

#endif