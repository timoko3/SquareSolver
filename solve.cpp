#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solve.h"
#include "common.h"

numRoots solveQuadEqua(equationData_t* data){ // user?
    // assert
    assert(isfinite(data->coefs.a));
    assert(isfinite(data->coefs.b));
    assert(isfinite(data->coefs.c));

    assert(&data->roots.x1 != NULL);
    assert(&data->roots.x2 != NULL);
    
    if(isZero(data->coefs.a)){
        return solveLinear(data->coefs.b, data->coefs.c, &data->roots.x1);
    }

    double discriminant = data->coefs.b * data->coefs.b - 4 * data->coefs.a * data->coefs.c; 

    if(isZero(discriminant)){
        data->roots.x1 = (-data->coefs.b) / (2 * data->coefs.a);
        return ONE_ROOT;
    }
    else if(discriminant < 0){
        return NO_VALID_ROOTS;
    }
    else /* if(discriminant > 0) */{   
        data->roots.x1 = (-data->coefs.b - sqrt(discriminant)) / (2 * data->coefs.a);
        data->roots.x2 = (-data->coefs.b + sqrt(discriminant)) / (2 * data->coefs.a);
        

        assert(!isEqualDoubles(data->roots.x1, data->roots.x2));

        return TWO_ROOTS;
    }

}

numRoots solveLinear(double k, double b, double* x){
    assert(isfinite(k));
    assert(isfinite(b));
    assert(x != NULL);

    if(isZero(k)){
        if(isZero(b)){
            return INFINITY_OF_ROOTS;
        }
        else{
            return NO_VALID_ROOTS;
        }
    }
    else{
        *x = -b / k;
        return ONE_ROOT;
    }
    
}
