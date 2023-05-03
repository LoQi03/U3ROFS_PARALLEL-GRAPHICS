#ifndef PROGRAM_H
#define PROGRAM_H

double cos_taylor(double x, int n, int thread_count);
double sin_taylor(double x, int n, int thread_count);
double exp_taylor(double x, int n, int thread_count);
double seq_cos_taylor(double x, int n);
double seq_sin_taylor(double x, int n);
double seq_exp_taylor(double x, int n);
double factorial(int n);
#endif