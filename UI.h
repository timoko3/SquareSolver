#include "nRoots.h"

enum menuConst{
    RETURN_TO_TOP_MENU = -1
};

const int BOTTOM_BORDER = 1; 

const char* const WELCOME = "Добро пожаловать!\n";
const char* const CHOOSE_MODE = "Выберите один из режимов:\n";
const char* const ALLERT_INCORRECT = "Выбирайте из предложенных вариантов\n";
const char* const INSTRUCTION = "Введите парметры приведенного квадратного уравнения ax^2+bx+c:(для возврата к выбору режима нажмите q)\n";
const char* const HOW_TO_USE = "Необходимо вводить парметры в виде: a b c(a,b,c — действительные числа)\n";

struct quadEqCase{
    numRoots quantity;
    const char* toPrint;
};

const int countOutputCases = 5;

const struct quadEqCase allOutputs[countOutputCases]{
    {INFINITY_OF_ROOTS, "Данное уравнение имеет бесконечное количество решений\n"},
    {NO_VALID_ROOTS, "Данное уравнение не имеет решений в действительных числах\n"},
    {TWO_ROOTS, "Данное уравнение имеет два корня x1 = %lf, x2 = %lf\n"},
    {ONE_ROOT, "Данное уравнение имеет один корень x1 = %lf\n"},
    {NO_ANY_ROOTS, "Данное уравнения не имеет решений\n"}
};

void printFinalOutput(double* x1, double* x2, numRoots curOutput);
int BAD_NAME_UI_SCANF(double* a, double* b, double* c);
int chooseMode();
