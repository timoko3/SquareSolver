#include "modes.h"
#include "UI.h"
#include "solve.h"

const char* WORK_IN_PROGRESS = "В разработке\n";
struct coefficent 
{
    double a;
    double b;
    double c;
};
struct root
{
    double x1;
    double x2;
};


int userEquations(){
    coefficent coefficents = {0,0,0};
    root roots = {0,0};
    
    if(get_coefficents(&coefficents.a, &coefficents.b, &coefficents.c) == RETURN_TO_TOP_MENU){
        return RETURN_TO_TOP_MENU;
    }
    numRoots curOutput = solveQuadEqua(coefficents.a,coefficents.b,coefficents.c, &roots.x1, &roots.x2); // Вызов основной функции
    printFinalOutput(&roots.x1, &roots.x2, curOutput); // вызов функции вывода
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
