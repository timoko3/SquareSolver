#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solve.h"
#include "common.h"

numRoots solveQuadEqua(double a, double b, double c,
                  double* x1, double* x2){
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
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
        assert(discriminant > 0);
        *x1 = (-b + sqrt(discriminant)) / (2 * a);
        *x2 = (-b - sqrt(discriminant)) / (2 * a);
        assert((*x1 - *x2) > INFELICITY);
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
