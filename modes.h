#ifndef MODES_H
#define MODES_H

#include <stdio.h>

#include "consoleColors.h"
#include "unitTests.h"

const int  MENU_FIRST_ITEM = 1; 
const char RETURN_TO_TOP_MENU = 'q';

typedef int menu_mode_t;      
typedef int complexity_mode_t;
typedef void(*modePrt)();
typedef void(*complexityPtr)(testsData_t* reference);

struct menuMode{
    modePrt function;
    const char* stringDescription;
};

struct complexityMode{
    complexityPtr function;
    const char* const stringDescription;
};

const char* const USER_EQUATIONS_VARIANT        = SET_STYLE_BOLD_FONT_BLUE "Решение введенных вами квадратных уравнений\n" RESET;
const char* const RANDOM_EQUATIONS_VARIANT      = SET_STYLE_BOLD_FONT_BLUE "Решение множества квадратных уравнений со случайными коэффицентами\n" RESET;
const char* const TRAINER_EQUATIONS_VARIANT     = SET_STYLE_BOLD_FONT_BLUE "Тренажер по решению квадртаных уравнений\n" RESET;
const char* const EXIT_VARIANT                  = SET_STYLE_BOLD_FONT_BLUE "Выйти из программы\n" RESET;

const char* const CHOOSE_COMPLEXITY_INSTRUCTION = "Выберите уровень сложности:\n"
                                                  "1) " SET_STYLE_BOLD_FONT_GREEN "Нормальный" RESET "\t2) " SET_STYLE_BOLD_FONT_RED "Дедский сад 'Ромашка'\n" RESET;
const char* const DESCRIPTION_EASY_MODE         = "Вы выбрали простой режим\n";
const char* const DESCRIPTION_HARD_MODE         = "Вы выбарли сложный режим\n"; 

const char* const EQUATION                      = "Уравнение: " SET_STYLE_ITALICS_FONT_YELLOW "%+lg*x^2%+lg*x%+lg\n" RESET;

void userEquations();
void randomEquations();
void trainerEquations();

complexity_mode_t chooseComplexity();
void easyComplexity(testsData_t* reference);
void hardComplexity(testsData_t* reference);

const int EXIT = 4;  //

const menuMode allModes[EXIT]{
    {userEquations, USER_EQUATIONS_VARIANT},
    {randomEquations, RANDOM_EQUATIONS_VARIANT},
    {trainerEquations, TRAINER_EQUATIONS_VARIANT},
    {NULL, EXIT_VARIANT}
};

const complexityMode allComplexityModes[2]{
    {hardComplexity, DESCRIPTION_HARD_MODE},
    {easyComplexity, DESCRIPTION_EASY_MODE}
};

#endif /* MODES_H */