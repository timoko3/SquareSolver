#ifndef MODES_H
#define MODES_H

#include <stdio.h>

#include "consoleColors.h"

const int  MENU_FIRST_ITEM = 1; 
const char RETURN_TO_TOP_MENU = 'q';

typedef int menu_mode_t;      
typedef void(*modePrt)();

struct menuMode{
    modePrt function;
    const char* stringDescription;
};

const char* const USER_EQUATIONS_VARIANT    = SET_STYLE_BOLD_FONT_BLUE "Решение введенных вами квадратных уравнений\n" RESET;
const char* const RANDOM_EQUATIONS_VARIANT  = SET_STYLE_BOLD_FONT_BLUE "Решение множества квадратных уравнений со случайными коэффицентами\n" RESET;
const char* const TRAINER_EQUATIONS_VARIANT = SET_STYLE_BOLD_FONT_BLUE "Тренажер по решению квадртаных уравнений\n" RESET;
const char* const EXIT_VARIANT              = SET_STYLE_BOLD_FONT_BLUE "Выйти из программы\n" RESET;

void userEquations();
void randomEquations();
void trainerEquations();

const int EXIT = 4;  //

const menuMode allModes[EXIT]{
    {userEquations, USER_EQUATIONS_VARIANT},
    {randomEquations, RANDOM_EQUATIONS_VARIANT},
    {trainerEquations, TRAINER_EQUATIONS_VARIANT},
    {NULL, EXIT_VARIANT}
};

#endif /* MODES_H */