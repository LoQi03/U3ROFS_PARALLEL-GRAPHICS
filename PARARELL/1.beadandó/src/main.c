#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <stdio.h>
#include "program.c"

int main()
{
    pthread_t thread1, thread2, thread3;
    int int_num[SIZE];
    pthread_create(&thread1, NULL, generateNumbers, (void *)&int_num);
    pthread_join(thread1, NULL);
    sorNumbers(int_num);
    printNumbers(int_num);
    pthread_create(&thread1, NULL, calcAvg, (void *)&int_num);
    pthread_create(&thread2, NULL, calcMedian, (void *)&int_num);
    pthread_join(thread2, NULL);
    pthread_join(thread1, NULL);
    exit(0);
}
