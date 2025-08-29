#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
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

void sortRoots(double* root1, double* root2){ // sort number
    if(*root1 > *root2){
        double temp = *root1;
        *root1 = *root2;
        *root2 = temp;
    }
}

void clearBuffer(){
    while(getchar() != '\n'){
        continue;
    }
}
// rand
void genRandomCoefs(equationData_t* data, int randMaxModule){
    assert(data);

    srand(time(0));

    // генерация чисел от -randMaxModule до +randMaxModule
    data->coefs.a = myRand(randMaxModule); 
    data->coefs.b = myRand(randMaxModule);
    data->coefs.c = myRand(randMaxModule);
}

void genRandomRoots(equationData_t* data){
    assert(data);

    srand(time(0));

    data->roots.x1 = myRand(MAX_ROOT_EASY_MODE);
    data->roots.x2 = myRand(MAX_ROOT_EASY_MODE);
}

int myRand(int randMaxModule){
    return -randMaxModule + rand() % (2 * randMaxModule + 1); 
}
