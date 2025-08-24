#include "modes.h"
#include "UI.h"
#include "solve.h"

const char* WORK_IN_PROGRESS = "В разработке\n";

int userEquations(){
    double a = 0,b = 0,c = 0;
    double x1 = 0, x2 = 0;
    if(get_coefficents(&a, &b, &c) == RETURN_TO_TOP_MENU){
        return RETURN_TO_TOP_MENU;
    }
    numRoots curOutput = solveQuadEqua(a,b,c, &x1, &x2); // Вызов основной функции
    printFinalOutput(&x1, &x2, curOutput); // вызов функции вывода
    return 0;
}

int randomEquations(){
    printf("%s", WORK_IN_PROGRESS);
    return 0;
}

int trainerEquations(){
   printf("%s", WORK_IN_PROGRESS);
   return 0;
}
