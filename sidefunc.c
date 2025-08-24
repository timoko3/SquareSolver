#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sidefunc.h"

// проверка double на равенство нулю
bool isZero(double number){
    if(fabs(number) < INFELICITY){
        return true;
    }
    return false;
}

// очистка буфера
void clearBuffer(){
    while(getchar() != '\n'){
        continue;
    }
}
