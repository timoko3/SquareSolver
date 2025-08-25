#ifndef UI_H
#define UI_H

#include "nRoots.h"
#include "modes.h"

const char* const TO_PRINT_TESTS_RESULT = "Пройдено %d/%d тестов\n";

const char* const WELCOME          = "Добро пожаловать!\n";
const char* const CHOOSE_MODE      = "Выберите один из режимов:\n";
const char* const ALLERT_INCORRECT = "Выбирайте из предложенных вариантов\n";
const char* const INSTRUCTION      = "Введите парметры приведенного квадратного уравнения ax^2+bx+c:(для возврата к выбору режима нажмите q)\n";
const char* const HOW_TO_USE       = "Необходимо вводить парметры в виде: a b c(a,b,c — действительные числа)\n";

const int nRootsCases = 5;

const char* const INFINITY_OF_ROOTS_TO_PTINT = "Данное уравнение имеет бесконечное количество решений\n";
const char* const NO_VALID_ROOTS_TO_PTINT    = "Данное уравнение не имеет решений в действительных числах\n";
const char* const TWO_ROOTS_TO_PTINT         = "Данное уравнение имеет два корня x1 = %lf, x2 = %lf\n";
const char* const ONE_ROOT_TO_PTINT          = "Данное уравнение имеет один корень x1 = %lf\n";
const char* const NO_ANY_ROOTS_TO_PTINT      = "Данное уравнения не имеет решений\n"; 

struct rootDescription{
    numRoots quantity;
    const char* const stringDescription;
};

const struct rootDescription allRootDescriptions[nRootsCases]{
    {INFINITY_OF_ROOTS, INFINITY_OF_ROOTS_TO_PTINT},
    {NO_VALID_ROOTS,    NO_VALID_ROOTS_TO_PTINT},
    {TWO_ROOTS,         TWO_ROOTS_TO_PTINT},
    {ONE_ROOT,          ONE_ROOT_TO_PTINT},
    {NO_ANY_ROOTS,      NO_ANY_ROOTS_TO_PTINT}
};

void showTestsResult(int nPassed, int nAllTests);
menu_mode_t chooseMode();
bool get_coefficents(coefs_t* coefs);
void printFinalOutput(roots_t* roots, numRoots nRoots);

#endif /*  */


