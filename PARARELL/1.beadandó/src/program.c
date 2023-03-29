#include "program.h"
#include <stdio.h>
#include <time.h>

void sorNumbers(int *num)
{
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i; j < SIZE; j++)
        {
            if (num[i] > num[j])
            {
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
}

void printNumbers(int *num)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ", num[i]);
    }
}

void *calcAvg(void *int_num)
{
    int *num = (int *)int_num;
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += num[i];
    }
    double avg = (double)sum / SIZE;
    printf("\nAvg:%lf", avg);
    return NULL;
}

void *generateNumbers(void *vargp)
{
    srand(time(NULL));
    int *num = (int *)vargp;
    clock_t start = clock();
    for (int i = 0; i < SIZE; i++)
    {
        num[i] = (rand() % (10000 - 1)) + 1;
    }
    return NULL;
}
void *calcMedian(void *int_num)
{
    int *num = (int *)int_num;
    double median = 0;
    if (SIZE % 2 == 0)
    {
        median = (double)(num[SIZE / 2] + num[(SIZE / 2) - 1]) / 2.0f;
    }
    else
    {
        median = (double)num[SIZE / 2];
    }
    printf("\nMedian:%lf", median);
}