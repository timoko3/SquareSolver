#ifndef COMMON_H
#define COMMON_H

const double INFELICITY = 0.000001;
const double INFELICITY_TRAINER = 0.01;

bool isZero(double num);
bool isEqualDoubles(double num1, double num2, const double infelicity);
void fixInfelicity(double* num);


#endif