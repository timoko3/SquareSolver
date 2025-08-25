#ifndef N_ROOTS_H
#define N_ROOTS_H

#include <math.h>

enum numRoots{
    INFINITY_OF_ROOTS = -1,
    NO_VALID_ROOTS = 0,
    TWO_ROOTS = 2,
    ONE_ROOT = 1,
    NO_ANY_ROOTS = 0
};

struct coefs_t {
    double a;
    double b;
    double c;
};

struct roots_t {
    double x1;
    double x2;
};

struct equationData_t {
    coefs_t coefs;
    roots_t roots;
};

#endif /* N_ROOTS_H */