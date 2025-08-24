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