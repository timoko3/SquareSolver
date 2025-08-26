#include "solve.h"
#include "common.h"
#include "unitTests.h"
#include <stdio.h>

nPassedTests RunTest(){
    int nPassed = 0;
    
    // инструкция к тесту OneTest(<coefs a>, <coefs b>, <coefs c>, <max root>, <min root>, <numRoot>) // swap
    testsData_t all_tests[N_OF_TESTS] = {
       // {{{.a = 1, .b = -5, .c = 6},  {.x1 = 3, .x2 = 2}},  .nRootsRef = TWO_ROOTS},
       // {{{.a = 1, .b = 0,  .c = -4}, {.x1 = 2, .x2 = -2}}, .nRootsRef = TWO_ROOTS},
    };
    parseTestsFromFile(all_tests);

    for(int test = 0; test < N_OF_TESTS; test++){
        nPassed += OneTest(all_tests[test]);
    }
    
    return nPassed;
}

nPassedTests OneTest(testsData_t curTest){
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

 bool parseTestsFromFile(testsData_t* testsData){
    FILE * fileWithTests;
    if((fileWithTests = fopen("test_quad.txt", "r")) == NULL){
        printf("%s", TESTS_OPEN_FILE_FAILURE_ALLERT);
        return PARSE_FAILURE;
    }

    int i = 0;
    int nBadTests = 0;

    while(i < N_OF_TESTS){
        int nroots;
        if((fscanf(fileWithTests, "%lf %lf %lf %lf %lf %d", &testsData[i].equationData.coefs.a, 
                                                            &testsData[i].equationData.coefs.b, 
                                                            &testsData[i].equationData.coefs.c,
                                                            &testsData[i].equationData.roots.x1,
                                                            &testsData[i].equationData.roots.x2,
                                                            &nroots)) != 6){
            nBadTests++;
            continue;
        }
        (testsData[i].nRootsRef) = (numRoots)nroots;
        i++;
    }
    fclose(fileWithTests);
    return PARSE_SUCCESS;
}
