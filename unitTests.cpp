#include "solve.h"
#include "common.h"
#include "unitTests.h"
#include <stdio.h>

int RunTest(){
    int passed = 0;
//    parseTestsFromFile();
    // инструкция к тесту OneTest(<coef a>, <coef b>, <coef c>, <max root>, <min root>, <numRoot>) // swap
    funcSolveQuadEquationTest all_tests[NUMBER_OF_TESTS] = {
        {{{.a = 1, .b = -5, .c = 6},  {.x1ref = 3, .x2ref = 2}},  .nRootsRef = TWO_ROOTS},
        {{{.a = 1, .b = 0,  .c = -4}, {.x1ref = 2, .x2ref = -2}}, .nRootsRef = TWO_ROOTS},
    };
    for(int test = 0; test < NUMBER_OF_TESTS; test++){
        passed += OneTest(all_tests[test]);
    }
    return passed;
}

nPassedTests OneTest(funcSolveQuadEquationTest curTest){
    static int nTest = 0;

    dataForSolving temporary = {};
    temporary.userModeCoefficents = curTest.forTest.testsCoefficents;
    temporary.userModeRoots.x1 = curTest.forTest.testsRoots.x1ref;
    temporary.userModeRoots.x1 = curTest.forTest.testsRoots.x2ref;

    numRoots nRoots = solveQuadEqua(&temporary);
    nTest++;
    if(!(isEqualDoubles(temporary.userModeRoots.x1, curTest.forTest.testsRoots.x1ref) && 
         isEqualDoubles(temporary.userModeRoots.x2, curTest.forTest.testsRoots.x2ref) && 
         isEqualDoubles(nRoots, curTest.nRootsRef))){
        printf("Тест номер %d провален\n", nTest);
        return 0;
    }
    //printf("Тест номер %d пройден\n", nTest);
    return 1;
}

// int parseTestsFromFile(){
//     FILE * fileWithTests;
//     if((fileWithTests = fopen("test_quad.txt", "r")) == NULL){
//         printf("%s", TESTING_FAILURE_PRINT);
//         return PARSE_FAILURE;
//     }
//     char symbol = '\0';
//     while((symbol = getchar()) != '\n'){
        
//     }

//     return PARSE_SUCCESS;
// }
