#ifndef LIB_INCLUDED
#define LIB_INCLUDED

#include "funcs.h"

typedef struct MathArguments {
    DtoDFunc* f;
    DtoDFunc* f_deriv;
    DtoDFunc* g;
    DtoDFunc* g_deriv;
    double a;
    double b;
    double eps;
    double result;
} MathArguments;

typedef struct Arguments {
    int root;
    int iterations;
    int test_root;
    int test_integral;
    int help;
    int list;
    MathArguments math_args;
} Arguments;

double root(DtoDFunc f, DtoDFunc g, DtoDFunc f_der, DtoDFunc g_der, double a, double b, double eps);
double integral(DtoDFunc f, DtoDFunc g, double a, double b, double eps);
int test_all();
double get_func_diff (DtoDFunc f, DtoDFunc g, double x);
int is_real(double x);
int fsgn(double x);
char* gen_separator(size_t len, char ch);
Arguments load_flags(int flags_amount, char* flags[]);
DtoDFunc* func_by_number(int n);
DtoDFunc* func_deriv_by_number(int n);
double lin(double x);
double lin_plus2(double x);
double lin_plus2_neg(double x);
double lin_neg(double x);
double zero(double x);
double one(double x);
double minus_one(double x);
double two(double x);
double lin_2x(double x);
double lin_minus_2x(double x);
double quad(double x);
double quad_neg(double x);
int compare_doubles(double a, double b);

#endif
