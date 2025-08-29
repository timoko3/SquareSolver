#include "modes.h"
#include "UI.h"
#include "solve.h"
#include "common.h"
#include "unitTests.h"

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

    int randMaxModule = chooseRandMaxModule();
    while(true){
        genRandomCoefs(&reference.equationData, randMaxModule);
        
        reference.nRootsRef = solveQuadEqua(&reference.equationData);

        sortRoots(&reference.equationData.roots.x1, &reference.equationData.roots.x2);

        printf(INSTRUCTION_TRAINER);
        printf(EQUATION, reference.equationData.coefs.a, 
                        reference.equationData.coefs.b, 
                        reference.equationData.coefs.c);

        testsData_t userData = {0};
        userData.equationData.coefs = reference.equationData.coefs;
        if(!userEnterSolution(&userData)) break; // норм или лучше со скобками?

        printf("ref %lf — user %lf\nref %lf — user %lf\nref %d — user %d\n", reference.equationData.roots.x1, 
                                                                            userData.equationData.roots.x1,
                                                                            reference.equationData.roots.x2,
                                                                            userData.equationData.roots.x2,
                                                                            reference.nRootsRef,
                                                                            userData.nRootsRef);

        printDependingOnResult(isSolutionRight(&reference, &userData));
    }
}
