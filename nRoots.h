#ifndef N_ROOTS_H
#define N_ROOTS_H

enum numRoots{
    INFINITY_OF_ROOTS,
    NO_VALID_ROOTS,
    TWO_ROOTS,
    ONE_ROOT,
    NO_ANY_ROOTS
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