#include "solve.h"
#include "common.h"
#include "unitTests.h"
#include <stdio.h>

int RunTest(){
    int passed = 0;
    passed += OneTest(1,-5,6,3,2,TWO_ROOTS); // инструкция к тесту (<coef a>, <coef b>, <coef c>, <max root>, <min root>, <numRoot>)
    passed += OneTest(1,0,-4,2,-2,TWO_ROOTS);
    return passed;
}
int OneTest(double a, double b, double c, double x1ref, double x2ref, numRoots nRootsRef){
    static int nTest = 1;
    double x1 = 0, x2 = 0;
    numRoots nRoots = solveQuadEqua(a,b,c, &x1,&x2);
    if(!(isEqualDoubles(x1,x1ref) && isEqualDoubles(x2,x2ref) && isEqualDoubles(nRoots,nRootsRef))){
        printf("Тест номер %d провален\n", nTest);
        nTest++;
        return 0;
    }
    printf("Тест номер %d пройден\n", nTest);
    nTest++;
    return 1;
}
