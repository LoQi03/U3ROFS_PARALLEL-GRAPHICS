#ifndef PROGRAM_H
#define PROGRAM_H

#define SIZE 12
#define THREAD_SIZE 4;

int *generateNumbers();
void printNumbers(int *nums);
void sequentialMultiply(int *nums);
int pararellMultiply(int *nums, int result, int thread_index, int start, int end);

#endif