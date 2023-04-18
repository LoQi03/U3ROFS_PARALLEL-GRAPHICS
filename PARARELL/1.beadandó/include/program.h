#ifndef PROGRAM_H
#define PROGRAM_H

#define N 1000
int arr[N];

void quickSort(int *arr, int left, int right);
void *parallel_quickSort(void *arg);

#endif