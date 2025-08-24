#include <stdbool.h>
#include <math.h>
#include "common.h"

const double INFELICITY = 0.000001;

// проверка double на равенство нулю
bool isZero(double number){
    if(fabs(number) < INFELICITY){
        return true;
    }
    return false;
}