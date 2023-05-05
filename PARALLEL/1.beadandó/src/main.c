#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "program.h"
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Hibas bemenet!\n");
        return 1;
    }
    int N = atoi(argv[1]);
    if (N > N_MAX)
    {
        printf("Tul nagy a tomb!\n");
        return 1;
    }
    arr = (int *)malloc(N * sizeof(int));
    int num_threads = atoi(argv[2]);
    int i;
    pthread_t *threads;
    int *args;
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand();
        printf("%d\n", arr[i]);
    }

    clock_t begin = clock();
    threads = (pthread_t *)malloc(num_threads * sizeof(pthread_t));
    args = (int *)malloc(num_threads * 2 * sizeof(int));
    int chunk_size = N / num_threads;
    int left, right;

    for (i = 0; i < num_threads; i++)
    {
        left = i * chunk_size;
        right = (i == num_threads - 1) ? N - 1 : (left + chunk_size - 1);
        args[2 * i] = left;
        args[2 * i + 1] = right;
        pthread_create(&threads[i], NULL, parallel_quickSort, &args[2 * i]);
    }
    for (i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], NULL);
    }
    printf("parallel_quickSort:%lf\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
    begin = clock();
    quickSort(arr, 0, N - 1);
    printf("sequence_quickSort:%lf\n", (double)(clock() - begin) / CLOCKS_PER_SEC);
    printf("\n");

    return 0;
}