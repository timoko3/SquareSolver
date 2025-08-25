#ifndef SOLVE_QUAD_H
#define SOLVE_QUAD_H 
#include "nRoots.h"
numRoots solveLinear(double b, double c, double* x);
numRoots solveQuadEqua(double a, double b, double c, double* x1, double* x2);
#endif