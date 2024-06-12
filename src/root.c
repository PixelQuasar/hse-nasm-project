#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "funcs.h"
#include "config.h"
#include "text.h"
#include "lib.h"

int iterations = 0;

// implemented with combined method
double root(DtoDFunc f, DtoDFunc g, DtoDFunc f_der, DtoDFunc g_der, double a, double b, double eps) {
    size_t i = ROOT_INTERATION_ACCURACY;
    while(i--) {
        // (aF(b) - bF(a)) / (F(b) - F(a)) where F(x) = f(x) - g(x).
        double c = 
           (a * get_func_diff(f, g, b) - b * get_func_diff(f, g, a)) / 
           (get_func_diff(f, g, b) - get_func_diff(f, g, a));

        if (fabs(get_func_diff(f, g, c)) < eps) {
            if (!is_real(c)) {
                perror(MSG_ERR_ROOT_NOTFOUND);
                exit(1);
            }
            iterations += ROOT_INTERATION_ACCURACY - i;
            return c;
        }

        int direction = fsgn(get_func_diff(f, g, c)) * fsgn(get_func_diff(f, g, a));

        if (direction == -1) {
            b = c;
            a = a - (get_func_diff(f, g, a) / get_func_diff(f_der, g_der, a));
        }
        else {
            a = c;
            b = b - (get_func_diff(f, g, b) / get_func_diff(f_der, g_der, b));
        }
    }
    perror(MSG_ERR_ROOT_NOTFOUND);
    exit(1);
    return NAN;
}
