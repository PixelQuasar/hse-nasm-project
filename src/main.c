#include <stdio.h>
#include <math.h>
#include "lib.h"
#include "config.h"
#include "text.h"

extern int iterations;

int main(int argc, char* argv[]) {
    Arguments flags = load_flags(argc, argv);

    printf("%s\n", gen_separator(50, '>'));

    double a = root(func_a, func_c, func_a_der, func_c_der, 2 + ROOT_EPS, 10, ROOT_EPS);
    double b = root(func_b, func_c, func_b_der, func_c_der, 2 + ROOT_EPS, 10, ROOT_EPS);
    double c = root(func_a, func_b, func_a_der, func_b_der, ROOT_EPS, 10, ROOT_EPS);

    double area = 
        fabs(integral(func_a, func_c, a, b, ROOT_EPS)) + 
        fabs(integral(func_a, func_b, b, c, ROOT_EPS));

    if (flags.iterations) {
        printf("%s: %d.\n", MSG_RESULT_ITERATIONS, iterations);
    }

    if (flags.root) {
        printf("%s - %lf, %lf, %lf.\n", MSG_RESULT_ROOTS, a, b, c);
    }

    printf("%s: %lf.\n", MSG_RESULT_INTEGRAL, area);

    printf("%s\n", gen_separator(50, '>'));
    return 0;
}
