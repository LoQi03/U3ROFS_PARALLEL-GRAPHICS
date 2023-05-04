#include <stdio.h>
#include <stdlib.h>
#include "program.h"
#include <time.h>
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Hibas bemenet!\n");
        return 1;
    }
    double x = strtod(argv[1], NULL);
    int n = atoi(argv[2]);
    int thread_count = atoi(argv[3]);
    printf("pararell:\n");
    printf("x=%f, n=%d, thread_count=%d\n", x, n, thread_count);

    cos_taylor(x, n, thread_count);
    sin_taylor(x, n, thread_count);
    exp_taylor(x, n, thread_count);

    printf("szekvencialis:\n");
    seq_cos_taylor(x, n);
    seq_sin_taylor(x, n);
    seq_exp_taylor(x, n);
    return 0;
}
