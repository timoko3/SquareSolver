#include "modes.h"
#include "UI.h"
#include "solve.h"

int userEquations(){
    dataForSolving userData = {
        {.a = 0, .b = 0, .c = 0}, 
        {.x1 = 0, .x2 = 0}
    };
    if(get_coefficents(&userData.userModeCoefficents) == RETURN_TO_TOP_MENU){
        return RETURN_TO_TOP_MENU;
    }
    numRoots curOutput = solveQuadEqua(&userData); 
    printFinalOutput(&userData.userModeRoots, curOutput); 
    return 0;
}

const char* WORK_IN_PROGRESS = "В разработке\n";
int randomEquations(){
    printf("%s", WORK_IN_PROGRESS);
    return 0;
}

int trainerEquations(){
   printf("%s", WORK_IN_PROGRESS);
   return 0;
}
