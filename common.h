#ifndef COMMON_H
#define COMMON_H
#include "solve.h"

const double INFELICITY = 0.000001;
const double INFELICITY_TRAINER = 0.01;
const int MAX_ROOT_EASY_MODE = 50;

bool isZero(double num);
bool isEqualDoubles(double num1, double num2, const double infelicity);
void fixInfelicity(double* num);
void sortRoots(double* conversion1, double* conversion2);
void clearBuffer();
void genRandomCoefs(equationData_t* data, int randMax);
void genRandomRoots(equationData_t* dat);
int myRand(int randMaxModule);


#endif