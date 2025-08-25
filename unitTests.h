#include "nRoots.h"

struct funcSolveQuadEquationTest{
    double a,b,c;
    double x1ref,x2ref;
    numRoots nRootsRef;
};

const int NUMBER_OF_TESTS = 2;

int RunTest();
int OneTest(double a, double b, double c, double x1ref, double x2ref, numRoots nRootsRef);