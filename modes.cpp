#include "modes.h"
#include "UI.h"
#include "solve.h"
#include "common.h"
#include "unitTests.h"
#include "image.h"

const char* WORK_IN_PROGRESS = "В разработке\n";

void userEquations(){
    while(true){
        equationData_t data = {
            {.a = 0, .b = 0, .c = 0}, 
            {.x1 = 0, .x2 = 0}
        };

        if(!get_coefficients(&data.coefs)){
            break;
        }

        numRoots nRoots = solveQuadEqua(&data); 
        printFinalOutput(&data.roots, nRoots); 
    }
}

void randomEquations(){
    printf("%s", WORK_IN_PROGRESS);
}

void trainerEquations(){
    
    testsData_t reference = {0};

    complexity_mode_t complexity = chooseComplexity(); // func

    printf(allComplexityModes[complexity].stringDescription);
    while(true){
        (*allComplexityModes[complexity].function)(&reference);

        printf(INSTRUCTION_TRAINER);
        printf(EQUATION, reference.equationData.coefs.a, 
                         reference.equationData.coefs.b, 
                         reference.equationData.coefs.c);

        testsData_t userData = {0};
        userData.equationData.coefs = reference.equationData.coefs;
        printf(BECOME_MILLONER);
        if(!userEnterSolution(&userData)) break;

        printDependingOnResult(isSolutionRight(&reference, &userData));
    }
}

complexity_mode_t chooseComplexity(){
    printf(CHOOSE_COMPLEXITY_INSTRUCTION);

    int complexity = 0;
    while(!scanf("%d", &complexity) || complexity < 1 || complexity > 2){
        printf(ALERT_INCORRECT);
        clearBuffer();
    }

    return complexity - 1;
}

void easyComplexity(testsData_t* reference){
    genRandomRoots(&reference->equationData);
    sortRoots(&reference->equationData.roots.x1, &reference->equationData.roots.x2);

    reference->nRootsRef = TWO_ROOTS;

    calcCoefsForRoots(&reference->equationData);
}

void hardComplexity(testsData_t* reference){

    int randMaxModule = chooseRandMaxModule();
    
    genRandomCoefs(&reference->equationData, randMaxModule);
    // equ 
    // creat
    reference->nRootsRef = solveQuadEqua(&reference->equationData);

    sortRoots(&reference->equationData.roots.x1, &reference->equationData.roots.x2);
}


