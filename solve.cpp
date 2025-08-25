#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solve.h"
#include "common.h"

numRoots solveQuadEqua(dataForSolving* userData){
    assert(isfinite(userData->userModeCoefficents.a));
    assert(isfinite(userData->userModeCoefficents.b));
    assert(isfinite(userData->userModeCoefficents.c));

    assert(&userData->userModeRoots.x1 != NULL);
    assert(&userData->userModeRoots.x2 != NULL);
    
    if(isZero(userData->userModeCoefficents.a)){
        return solveLinear(userData->userModeCoefficents.b, userData->userModeCoefficents.c, &userData->userModeRoots.x1);
    }

    double discriminant = userData->userModeCoefficents.b * userData->userModeCoefficents.b - 4 * userData->userModeCoefficents.a * userData->userModeCoefficents.c; 

    if(isZero(discriminant)){
        userData->userModeRoots.x1 = (-userData->userModeCoefficents.b) / (2 * userData->userModeCoefficents.a);
        return ONE_ROOT;
    }
    else if(discriminant < 0){
        return NO_VALID_ROOTS;
    }
    else /* if(discriminant > 0) */{
        
        userData->userModeRoots.x1 = (-userData->userModeCoefficents.b + sqrt(discriminant)) / (2 * userData->userModeCoefficents.a);
        userData->userModeRoots.x2 = (-userData->userModeCoefficents.b - sqrt(discriminant)) / (2 * userData->userModeCoefficents.a);
        assert(!isEqualDoubles(userData->userModeRoots.x1, userData->userModeRoots.x2));
        return TWO_ROOTS;
    }
}

numRoots solveLinear(double b, double c, double* x){
    assert(isfinite(b));
    assert(isfinite(c));
    assert(x != NULL);
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
