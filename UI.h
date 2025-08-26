#ifndef UI_H
#define UI_H

#include "nRoots.h"
#include "modes.h"
#include "consoleColors.h"

const char* const TO_PRINT_TESTS_RESULT_SUCCESS = SET_STYLE_BOLD_FONT_GREEN "Пройдено %d/%d тестов\n" RESET;
const char* const TO_PRINT_TESTS_RESULT_FAILURE = SET_STYLE_BLINKING_FONT_RED "Пройдено %d/%d тестов\n" RESET;

const char* const WELCOME          = SET_STYLE_ITALICS_FONT_PURPLE "Добро пожаловать!\n" RESET;
const char* const CHOOSE_MODE      = "Выберите один из режимов:\n";
const char* const ALLERT_INCORRECT = "Выбирайте из предложенных вариантов\n";
const char* const INSTRUCTION      = "Введите парметры приведенного квадратного уравнения" SET_STYLE_ITALICS_FONT_YELLOW " ax^2+bx+c" RESET ":(для возврата к выбору режима нажмите q)\n";
const char* const HOW_TO_USE       = "Необходимо вводить парметры в виде:" SET_STYLE_ITALICS_FONT_YELLOW "a b c" RESET "(a,b,c — действительные числа)\n";

const int nRootsCases = 5;

const char* const INFINITY_OF_ROOTS_TO_PTINT = "Данное уравнение имеет " SET_STYLE_UNDERLINED_FONT_RED "бесконечное" RESET " количество решений\n";
const char* const NO_VALID_ROOTS_TO_PTINT    = "Данное уравнение не имеет решений в " SET_STYLE_UNDERLINED_FONT_RED "действительных числах\n" RESET;
const char* const TWO_ROOTS_TO_PTINT         = "Данное уравнение имеет два корня " SET_STYLE_BOLD_FONT_YELLOW "x1 = %lg, x2 = %lg\n" RESET;
const char* const ONE_ROOT_TO_PTINT          = "Данное уравнение имеет один корень " SET_STYLE_BOLD_FONT_YELLOW "x1 = %lg\n" RESET;

struct rootDescription{
    numRoots quantity;
    const char* const stringDescription;
};

const struct rootDescription allRootsDescription[nRootsCases]{
    {INFINITY_OF_ROOTS, INFINITY_OF_ROOTS_TO_PTINT},
    {NO_VALID_ROOTS,    NO_VALID_ROOTS_TO_PTINT},
    {TWO_ROOTS,         TWO_ROOTS_TO_PTINT},
    {ONE_ROOT,          ONE_ROOT_TO_PTINT},
};

void showTestsResult(int nPassed, int nAllTests);
menu_mode_t chooseMode();
bool get_coefficents(coefs_t* coefs);
void printFinalOutput(roots_t* roots, numRoots nRoots);

#endif /*  */


