#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include "common.h"

bool isZero(double number){
    return isEqualDoubles(number, 0, INFELICITY);
}

bool isEqualDoubles(double num1, double num2, const double infelicity){
    if(fabs(num2 - num1) < infelicity){
        return true;
    }
    return false;
}

void fixInfelicity(double* num){
    assert(num);

    if(fabs(*num) < INFELICITY){
        *num = 0;
    }
}

void sortRoots(double* root1, double* root2){
    if(*root1 > *root2){
        double temp = *root1;
        *root1 = *root2;
        *root2 = temp;
    }
}
