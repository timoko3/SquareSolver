#ifndef SOLVE_QUAD_H
#define SOLVE_QUAD_H 

#include "nRoots.h"

numRoots solveLinear(double b, double c, double* x); // kx+b // ax+b
numRoots solveQuadEqua(equationData_t* data);

#endif