#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "funcs.h"
#include "config.h"
#include "text.h"
#include "lib.h"

// implemented with rectangle method (riemann sum)
double integral(DtoDFunc f, DtoDFunc g, double a, double b, double eps) {
    double h = (b - a) / INTEGRAl_PARTITION_ACCURACY;
    double result = 0;
    for (size_t i = 0; i < INTEGRAl_PARTITION_ACCURACY; ++i) {
        result += get_func_diff(f, g, a + (i + 0.5) * h);
    }
    result *= h;
    if (!is_real(result)) {
        perror(MSG_ERR_INTEGRAL_NOTFOUND);
        exit(1);
    }
    return result;
}
