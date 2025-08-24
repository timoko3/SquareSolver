
#include <math.h>

#include "solve.h"
#include "common.h"

numRoots solveQuadEqua(double a, double b, double c,
                  double* x1, double* x2){
    if(isZero(a)){
        return solveLinear(b, c, x1);
    }

    double discriminant = b * b - 4 * a * c; 

    if(isZero(discriminant)){
        *x1 = (-b) / (2 * a);
        return ONE_ROOT;
    }
    else if(discriminant < 0){
        return NO_VALID_ROOTS;
    }
    else /*if(discriminant > 0)*/{
        *x1 = (-b + sqrt(discriminant)) / (2 * a);
        *x2 = (-b - sqrt(discriminant)) / (2 * a);
        return TWO_ROOTS;
    }
}

numRoots solveLinear(double b, double c, double* x){
    if(isZero(b)){
        if(isZero(c)){
            return INFINITY_OF_ROOTS;
        }
        else{
            return NO_ANY_ROOTS;
        }
    }
    else{
        *x = c;
        return ONE_ROOT;
    }
}
