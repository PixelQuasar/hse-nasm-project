#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"
#include "config.h"

double get_func_diff (DtoDFunc f, DtoDFunc g, double x) {
    return f(x) - g(x);
}

int is_real(double x) {
    return !(x == NAN || x == -NAN || x == -INFINITY || x == INFINITY);
}

double lin(double x) {
    return x;
}

double lin_plus2(double x) {
    return x + 2;
}

double lin_plus2_neg(double x) {
    return -x + 2;
}

double lin_neg(double x) {
    return -x;
}

double zero(double x) {
    return 0;
}

double minus_one(double x) {
    return -1;
}

double one(double x) {
    return 1;
}

double two(double x) {
    return 2;
}

double lin_2x(double x) {
    return 2 * x;
}

double lin_minus_2x(double x) {
    return -2 * x;
}

double quad(double x) {
    return x * x;
}

double quad_neg(double x) {
    return -(x * x) + 2;
}

int compare_doubles(double a, double b) {
    return fabs(a - b) < ROOT_EPS;
} 

int fsgn(double x) {
    if (x == 0) {
        return 0;
    }
    if (x < 0) {
        return -1;
    }
    return 1;
}

char* gen_separator(size_t len, char ch) {
    char* result = malloc(len + 1);
    for (int i = 0; i < len; ++i) {
        result[i] = ch;
    };
    result[len] = '\0';
    return result;
}

DtoDFunc* func_by_number(int n) {
    switch (n) {
        case 1:     return &func_a;
        case 2:     return &func_b;
        case 3:     return &func_c;
        case 4:     return &lin;
        case 5:     return &lin_plus2;
        case 6:     return &lin_plus2_neg;
        case 7:     return &lin_neg;
        case 8:     return &zero;
        case 9:     return &one;
        case 10:    return &two;
        case 11:    return &lin_2x;
        case 12:    return &quad;
        case 13:    return &quad_neg;
        default:    return &zero;
    }
}

DtoDFunc* func_deriv_by_number(int n) {
    switch (n) {
        case 1:     return &func_a_der;
        case 2:     return &func_b_der;
        case 3:     return &func_c_der;
        case 4:     return &one;
        case 5:     return &one;
        case 6:     return &minus_one;
        case 7:     return &minus_one;
        case 8:     return &zero;
        case 9:     return &zero;
        case 10:    return &zero;
        case 11:    return &two;
        case 12:    return &lin_2x;
        case 13:    return &lin_minus_2x;
        default:    return &zero;
    }
}
