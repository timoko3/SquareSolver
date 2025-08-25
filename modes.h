#ifndef MODES_H
#define MODES_H

#include <stdio.h>

const int MENU_FIRST_ITEM = 1; 
const char RETURN_TO_TOP_MENU = 'q';

typedef int menu_mode_t;      
typedef void(*modePrt)();

struct menuMode{
    modePrt function;
    const char* stringDescription;
};

const char* const USER_EQUATIONS_VARIANT    = "Решение введенных вами квадратных уравнений\t";
const char* const RANDOM_EQUATIONS_VARIANT  = "Решение множества квадратных уравнений со случайными коэффицентами\n";
const char* const TRAINER_EQUATIONS_VARIANT = "Тренажер по решению квадртаных уравнений\t";
const char* const EXIT_VARIANT              = "Выйти из программы\n";

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