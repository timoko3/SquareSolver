#ifndef SOLVE_QUAD_H
#define SOLVE_QUAD_H 

#include "nRoots.h"

numRoots solveLinear(double k, double b, double* x); 
numRoots solveQuadEqua(equationData_t* data);

void calcCoefsForRoots(equationData_t* reference);

#endif