#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "program.h"

void quickSort(int *arr, int left, int right)
{
    int i = left, j = right;
    int temp;
    int pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
void *parallel_quickSort(void *arg)
{
    int *sub_arr = arg;
    int left = sub_arr[0];
    int right = sub_arr[1];
    quickSort(arr, left, right);
    pthread_exit(NULL);
}
