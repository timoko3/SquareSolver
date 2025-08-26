#include "solve.h"
#include "common.h"
#include "unitTests.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

nPassedTests RunTest(int* nAllTests){
    // инструкция к тесту OneTest(<coefs a>, <coefs b>, <coefs c>, <max root>, <min root>, <numRoot>) // swap
    FILE* fileWithTests = NULL;

    if(openFile(&fileWithTests) == PARSE_FAILURE) return PARSE_FAILURE; // OpenFile // Roots roots

    int nPassed = 0;
    
    while(true){
        
        testsData_t curTest = {};
        
        if(!parseTestsFromFile(fileWithTests, &curTest, nAllTests))break;

        nPassed += OneTest(curTest);
    }
    
    fclose(fileWithTests);

    return nPassed;
}

 bool parseTestsFromFile(FILE* fileWithTests, testsData_t* curTest, int* nAllTests){
    assert(fileWithTests != NULL);

    if(getTestToFile(fileWithTests, curTest) == PARSE_FAILURE) return PARSE_FAILURE;
    (*nAllTests)++;

    return PARSE_SUCCESS;
}

bool openFile(FILE** fileWithTests){
    assert(fileWithTests);

    if((*fileWithTests = fopen("test_quad.txt", "r")) == NULL){
        printf("%s", TESTS_OPEN_FILE_FAILURE_ALLERT);
        return PARSE_FAILURE;
    }
    return PARSE_SUCCESS;
}

bool getTestToFile(FILE* fileWithTests, testsData_t* curTest){ 
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

nPassedTests OneTest(testsData_t curTest){
    static int nTest = 0;
    nTest++;

    equationData_t reference = {};
    createReferenceTest(&reference, &curTest);
    numRoots nRoots = solveQuadEqua(&reference);
    if(isUnpassed(&curTest, &reference, nRoots, nTest)) 
        return 0;
    return 1;
}

void createReferenceTest(equationData_t* reference, testsData_t* curTest){
    reference->coefs = curTest->equationData.coefs;
}

bool isUnpassed(testsData_t* curTest, equationData_t* reference, numRoots nRoots, int nTest){
    if(!(isEqualDoubles(reference->roots.x1, curTest->equationData.roots.x1) && 
         isEqualDoubles(reference->roots.x2, curTest->equationData.roots.x2) && 
         nRoots == curTest->nRootsRef)){
        printf("%d %d", nRoots, curTest->nRootsRef);
        printf(TEST_FAILURE_ALLERT, nTest, curTest->equationData.coefs.a, 
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
