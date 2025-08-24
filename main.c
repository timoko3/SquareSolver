 //main_quad.c — Решение квадратного уравнения
//assert
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "all.h"

// для финального вывода
const char* USER_EQUATIONS_VARIANT = "Решение введенных вами квадратных уравнений\t";
const char* RANDOM_EQUATIONS_VARIANT = "Решение множества квадратных уравнений со случайными коэффицентами\n";
const char* TRAINER_EQUATIONS_VARIANT = "Тренажер по решению квадртаных уравнений\t";
const char* EXIT_VARIANT = "Выйти из программы\n";

int main(void){

    // инициализация структуры меню
    struct menuMode allModes[TOP_BORDER]{
        {userEquations, USER_EQUATIONS_VARIANT},
        {randomEquations, RANDOM_EQUATIONS_VARIANT},
        {trainerEquations, TRAINER_EQUATIONS_VARIANT},
        {NULL, EXIT_VARIANT}
    };

    // главная часть от куда начинается выполнение всей программы
    bool flagOutOfMode = true;
    while(flagOutOfMode){
        int choose = showTopMenu(allModes);
        bool flagInMode = true;
        if(choose == TOP_BORDER){
            flagInMode = false;
            flagOutOfMode = false;
        }
        while(flagInMode){
            if(((allModes[choose].mode)()) == RETURN_TO_TOP_MENU){
                flagInMode = false;
            }
        }
    }
    return 0;
}












