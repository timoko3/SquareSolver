#ifndef UI_H
#define UI_H

#include "nRoots.h"
#include "modes.h"
#include "consoleColors.h"
#include "unitTests.h"

const char* const TO_PRINT_TESTS_RESULT_SUCCESS = SET_STYLE_BOLD_FONT_GREEN "Пройдено %d/%d тестов\n" RESET;
const char* const TO_PRINT_TESTS_RESULT_FAILURE = SET_STYLE_BOLD_FONT_RED "Пройдено %d/%d тестов\n" RESET;

const char* const WELCOME          = SET_STYLE_BOLD_FONT_TURQUOISE "Добро пожаловать!\n" RESET;
const char* const CHOOSE_MODE      = "Выберите один из режимов:\n";
const char* const ALERT_INCORRECT = "Выбирайте из предложенных вариантов\n";
const char* const INSTRUCTION      = "Введите парметры приведенного квадратного уравнения" SET_STYLE_ITALICS_FONT_YELLOW " ax^2+bx+c" RESET ":\n(для возврата к выбору режима нажмите q)\n";
const char* const HOW_TO_USE       = "Необходимо вводить парметры в виде:" SET_STYLE_ITALICS_FONT_YELLOW "a b c" RESET "(a,b,c — действительные числа)\n";

const int nRootsCases = 5;

const char* const INFINITY_OF_ROOTS_TO_PRINT = "Данное уравнение имеет " SET_STYLE_UNDERLINED_FONT_RED "бесконечное" RESET " количество решений\n";
const char* const NO_VALID_ROOTS_TO_PRINT    = "Данное уравнение не имеет решений в " SET_STYLE_UNDERLINED_FONT_RED "действительных числах\n" RESET;
const char* const TWO_ROOTS_TO_PRINT         = "Данное уравнение имеет два корня " SET_STYLE_BOLD_FONT_YELLOW "x1 = %lg, x2 = %lg\n" RESET;
const char* const ONE_ROOT_TO_PRINT          = "Данное уравнение имеет один корень " SET_STYLE_BOLD_FONT_YELLOW "x1 = %lg\n" RESET;

const char* const INSTRUCTION_ENTER_RAND_MAX = "Введите максималное значение коэффицентов квадратного уравнения\n";
const char* const ALERT_INCORRECT_RAND_MAX   = "Максимальное значение коэффицентов должно быть целым числом\n";
const char* const TRY_AGAIN                  = "Попробуйте еще раз\n";
const char* const INSTRUCTION_TRAINER        = "Решите уравнение и напишете результат в виде <min root> <max root>\n"
                                               "(Если количество корней бескночено пишите \"inf\",\n"
                                               "елси корень отсутствует пишите \"nan\",\n"
                                               "дайте ответ с точностью до сотых\n";
const char* const ALERT_INCORRECT_ANS_ENTER  = "Некорректный ввод решений квадратного уравнения\n";
const char* const PRAISE                     = "Молодец! Ты решил правильно!\n";
const char* const COMFORT                    = "В этот раз не вышло. Попробуй еще раз\n";

struct rootDescription{
    numRoots quantity;
    const char* const stringDescription;
};

const struct rootDescription allRootsDescription[nRootsCases]{
    {INFINITY_OF_ROOTS, INFINITY_OF_ROOTS_TO_PRINT},
    {NO_VALID_ROOTS,    NO_VALID_ROOTS_TO_PRINT},
    {TWO_ROOTS,         TWO_ROOTS_TO_PRINT},
    {ONE_ROOT,          ONE_ROOT_TO_PRINT},
};

struct  answers{
    char ans1[50];
    char ans2[50];
};


void showTestsResult(int nPassed, int nAllTests);
menu_mode_t chooseMode();
bool get_coefficients(coefs_t* coefs);
void printFinalOutput(roots_t* roots, numRoots nRoots);

// 3 режим

int chooseRandMaxModule();
void userEnterSolution(testsData_t* data);
bool isSolutionRight(testsData_t* reference, testsData_t* userData);
void printDependingOnResult(bool isRight);



#endif /* UI_H */


