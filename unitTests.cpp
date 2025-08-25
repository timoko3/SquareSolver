#include "solve.h"
#include "common.h"
#include "unitTests.h"
#include <stdio.h>

int RunTest(){
    int nPassed = 0;
//    parseTestsFromFile();
    // инструкция к тесту OneTest(<coefs a>, <coefs b>, <coefs c>, <max root>, <min root>, <numRoot>) // swap
    testsData all_tests[NUMBER_OF_TESTS] = {
        {{{.a = 1, .b = -5, .c = 6},  {.x1 = 3, .x2 = 2}},  .nRootsRef = TWO_ROOTS},
        {{{.a = 1, .b = 0,  .c = -4}, {.x1 = 2, .x2 = -2}}, .nRootsRef = TWO_ROOTS},
    };

    for(int test = 0; test < NUMBER_OF_TESTS; test++){
        nPassed += OneTest(all_tests[test]);
    }
    
    return nPassed;
}

nPassedTests OneTest(testsData curTest){
    static int nTest = 0;

    equationData_t reference = {};
    reference.coefs = curTest.equationData.coefs;
    reference.roots.x1 = curTest.equationData.roots.x1;
    reference.roots.x1 = curTest.equationData.roots.x2;

    numRoots nRoots = solveQuadEqua(&reference);
    nTest++;
    if(!(isEqualDoubles(reference.roots.x1, curTest.equationData.roots.x1) && 
         isEqualDoubles(reference.roots.x2, curTest.equationData.roots.x2) && 
         isEqualDoubles(nRoots, curTest.nRootsRef))){
        printf(TEST_FAILURE_ALLERT, nTest);
        return 0;
    }
    //printf("Тест номер %d пройден\n", nTest);
    return 1;
}

// int parseTestsFromFile(){
//     FILE * fileWithTests;
//     if((fileWithTests = fopen("test_quad.txt", "r")) == NULL){
//         printf("%s", TESTS_OPEN_FAILURE_PRINT);
//         return PARSE_FAILURE;
//     }
//     char symbol = '\0';
//     while((symbol = getchar()) != '\n'){
        
//     }

//     return PARSE_SUCCESS;
// }
