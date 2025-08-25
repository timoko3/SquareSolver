#include "solve.h"
#include "common.h"
#include "unitTests.h"
#include <stdio.h>

int RunTest(){
    int passed = 0;
    // инструкция к тесту OneTest(<coef a>, <coef b>, <coef c>, <max root>, <min root>, <numRoot>)
    funcSolveQuadEquationTest all_tests[NUMBER_OF_TESTS] = 
    {
        {.a = 1, .b = -5, .c = 6, .x1ref = 3, .x2ref = 2, .nRootsRef = TWO_ROOTS},
        {.a = 1, .b = 0, .c = -4, .x1ref = 2, .x2ref = -2, .nRootsRef = TWO_ROOTS},
    };
    for(int test = 0; test < NUMBER_OF_TESTS; test++){
        passed += OneTest(all_tests[test].a, all_tests[test].b, all_tests[test].c, all_tests[test].x1ref, all_tests[test].x2ref, all_tests[test].nRootsRef);
    }
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
