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

        if(!get_coefficents(&data.coefs)){
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

    int randMax = chooseRandMax();
    genRandomCoefs(&reference.equationData, randMax);
    
    reference.nRootsRef = solveQuadEqua(&reference.equationData);
    printTrainerInstruction();
    printf("Уравнение: %lg*x^2+%lg*x+%lg", reference.equationData.coefs.a, 
                                        reference.equationData.coefs.b, 
                                        reference.equationData.coefs.c);

    testsData_t userData = {0};
    userData.equationData.coefs = reference.equationData.coefs;

    userEnterSolution(&userData);

    printDependingOnResult(isSolutionRight(&reference, &userData));
    printf("%s", WORK_IN_PROGRESS);
}
