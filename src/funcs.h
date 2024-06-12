#ifndef FUNCS_INCLUDED
#define FUNCS_INCLUDED

#define CDECL_ATTR __attribute__ ((cdecl))

typedef double DtoDFunc(double);

extern CDECL_ATTR DtoDFunc func_a;
extern CDECL_ATTR DtoDFunc func_a_der;
extern CDECL_ATTR DtoDFunc func_b;
extern CDECL_ATTR DtoDFunc func_b_der;
extern CDECL_ATTR DtoDFunc func_c;
extern CDECL_ATTR DtoDFunc func_c_der;

typedef struct MathFunction {
    double (*base) (double);
    double (*derivative) (double);
} MathFunction;

#endif
