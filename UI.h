#include "nRoots.h"

enum menuConst{
    SUCCESS_CHOOSE_MODE,
    RETURN_TO_TOP_MENU
};

const int BOTTOM_BORDER = 1;
const char QUIT = 'q';

const char* const WELCOME = "Добро пожаловать!\n";
const char* const CHOOSE_MODE = "Выберите один из режимов:\n";
const char* const ALLERT_INCORRECT = "Выбирайте из предложенных вариантов\n";
const char* const INSTRUCTION = "Введите парметры приведенного квадратного уравнения ax^2+bx+c:(для возврата к выбору режима нажмите q)\n";
const char* const HOW_TO_USE = "Необходимо вводить парметры в виде: a b c(a,b,c — действительные числа)\n";

struct nOutput{
    numRoots quantity;
    const char* toPrint;
};

const int countOutputCases = 5;

const char* const INFINITY_OF_ROOTS_TO_PTINT = "Данное уравнение имеет бесконечное количество решений\n";
const char* const NO_VALID_ROOTS_TO_PTINT = "Данное уравнение не имеет решений в действительных числах\n";
const char* const TWO_ROOTS_TO_PTINT = "Данное уравнение имеет два корня x1 = %lf, x2 = %lf\n";
const char* const ONE_ROOT_TO_PTINT = "Данное уравнение имеет один корень x1 = %lf\n";
const char* const NO_ANY_ROOTS_TO_PTINT = "Данное уравнения не имеет решений\n"; 

const struct nOutput allOutputs[countOutputCases]{
    {INFINITY_OF_ROOTS, INFINITY_OF_ROOTS_TO_PTINT},
    {NO_VALID_ROOTS, NO_VALID_ROOTS_TO_PTINT},
    {TWO_ROOTS, TWO_ROOTS_TO_PTINT },
    {ONE_ROOT, ONE_ROOT_TO_PTINT},
    {NO_ANY_ROOTS, NO_ANY_ROOTS_TO_PTINT}
};

void printFinalOutput(double* x1, double* x2, numRoots curOutput);
int get_coefficents(double* a, double* b, double* c);
int chooseMode();
