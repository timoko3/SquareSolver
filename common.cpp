#include <stdbool.h>
#include <math.h>
#include "common.h"

bool isZero(double number){
    return isEqualDoubles(number, 0);
}

bool isEqualDoubles(double num1, double num2){
    if(fabs(num2 - num1) < INFELICITY){
        return true;
    }
    return false;
}