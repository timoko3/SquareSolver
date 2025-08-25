#include <stdbool.h>
#include <math.h>
#include "common.h"

// проверка double на равенство нулю
bool isZero(double number){
    if(fabs(number) < INFELICITY){
        return true;
    }
    return false;
}

bool isEqualDoubles(double num1, double num2){
    if(fabs(num2 - num1) < INFELICITY){
        return true;
    }
    return false;
}