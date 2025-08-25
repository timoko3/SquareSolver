#ifndef N_ROOTS_H
#define N_ROOTS_H

enum numRoots{
    INFINITY_OF_ROOTS,
    NO_VALID_ROOTS,
    TWO_ROOTS,
    ONE_ROOT,
    NO_ANY_ROOTS
};

struct coefficents 
{
    double a;
    double b;
    double c;
};

struct roots
{
    double x1;
    double x2;
};

struct dataForSolving {
    coefficents userModeCoefficents;
    roots userModeRoots;
};

struct refRoots {
    double x1ref;
    double x2ref;
};

struct dataForSolvingTests {
    coefficents testsCoefficents;
    refRoots testsRoots;
};

#endif /* N_ROOTS_H */