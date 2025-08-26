#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "solve.h"
#include "common.h"

numRoots solveQuadEqua(equationData_t* data){ // user?
    assert(data);

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

        fixInfelicity(&data->roots.x1);
        fixInfelicity(&data->roots.x2);
        
        assert(!isEqualDoubles(data->roots.x1, data->roots.x2));

        return TWO_ROOTS;
    }

}

numRoots solveLinear(double k, double b, double* x){
    assert(x);

    assert(isfinite(k));
    assert(isfinite(b));

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
        fixInfelicity(x);
        return ONE_ROOT;
    }
    
}
