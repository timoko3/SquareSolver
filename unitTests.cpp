#include "solve.h"
#include "common.h"
#include "unitTests.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static bool openFile(FILE** filewithTests);
static bool getTestToFile(FILE* fileWithTests, testsData_t* curTest);
static void createReferenceTest(equationData_t* reference, testsData_t* curTest);
static bool isUnpassed(testsData_t* curTest, equationData_t* reference, numRoots nRoots, int nTest);
static nPassedTests OneTest(testsData_t all_tests);

nPassedTests RunTest(int* nAllTests){
    assert(nAllTests);
    // инструкция к тесту OneTest(<coefs a>, <coefs b>, <coefs c>, <min root>, <max root>, <numRoot>)
    FILE* fileWithTests = NULL;

    if(openFile(&fileWithTests) == PARSE_FAILURE) return PARSE_FAILURE; // OpenFile // Roots roots

    int nPassed = 0;
    while(true){
        testsData_t curTest = {};
        
        if (getTestToFile(fileWithTests, &curTest) == PARSE_FAILURE) break;
        (*nAllTests)++;

        nPassed += OneTest(curTest);
    }
    
    fclose(fileWithTests);

    return nPassed;
}

static bool openFile(FILE** fileWithTests){
    assert(fileWithTests);

    if((*fileWithTests = fopen("test_quad.txt", "r")) == NULL){
        printf("%s", TESTS_OPEN_FILE_FAILURE_ALERT);
        return PARSE_FAILURE;
    }
    return PARSE_SUCCESS;
}

static bool getTestToFile(FILE* fileWithTests, testsData_t* curTest){ 
    assert(fileWithTests);
    assert(curTest);

    char nroots[4];
    if((fscanf(fileWithTests, "%s %lf %lf %lf", nroots,
                                                &curTest->equationData.coefs.a, 
                                                &curTest->equationData.coefs.b, 
                                                &curTest->equationData.coefs.c
                                                )) != 4){
        return PARSE_FAILURE;
    }  
    if(!strcmp(nroots, INF)){
        curTest->nRootsRef = INFINITY_OF_ROOTS;
        
    }
    else if(!strcmp(nroots, ZERO)){
        curTest->nRootsRef = NO_VALID_ROOTS; 
    }
    else if(!strcmp(nroots, ONE)){
        curTest->nRootsRef = ONE_ROOT;
        fscanf(fileWithTests, "%lf", &curTest->equationData.roots.x1);
    }
    else if(!strcmp(nroots, TWO)){
        curTest->nRootsRef = TWO_ROOTS;
        fscanf(fileWithTests, "%lf %lf", &curTest->equationData.roots.x1, &curTest->equationData.roots.x2);
    }
    return PARSE_SUCCESS;
}

static nPassedTests OneTest(testsData_t curTest){
    static int nTest = 0;
    nTest++;

    equationData_t reference = {};
    createReferenceTest(&reference, &curTest);
    numRoots nRoots = solveQuadEqua(&reference);
    if(isUnpassed(&curTest, &reference, nRoots, nTest)) 
        return 0;
    return 1;
}

static void createReferenceTest(equationData_t* reference, testsData_t* curTest){
    assert(reference);
    assert(curTest);

    reference->coefs = curTest->equationData.coefs;
}

static bool isUnpassed(testsData_t* curTest, equationData_t* reference, numRoots nRoots, int nTest){
    assert(curTest);
    assert(reference);

    if(!(isEqualDoubles(reference->roots.x1, curTest->equationData.roots.x1, INFELICITY) && 
         isEqualDoubles(reference->roots.x2, curTest->equationData.roots.x2, INFELICITY) && 
         nRoots == curTest->nRootsRef)){
        printf(TEST_FAILURE_ALERT, nTest, curTest->equationData.coefs.a, 
                                           curTest->equationData.coefs.b,
                                           curTest->equationData.coefs.c,
                                           reference->roots.x1,
                                           reference->roots.x2,
                                           curTest->equationData.roots.x1,
                                           curTest->equationData.roots.x2);
        return true;
    }
    return false;
}
