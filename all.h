#ifndef ABC
#define ABC

// меню
const int BOTTOM_BORDER = 1;
const int TOP_BORDER = 4;

const int countOutputCases = 5;// кол-во вариантов вывода
const double INFELICITY = 0.000001;

// создание типа для указателя на функцию в меню
typedef int(*menuPtr)();
// прототип структуры меню
struct menuMode{
    menuPtr mode;
    const char * toPrint;
};

enum quadEqConst{
    INFINITY_OF_ROOTS = -1,
    NO_VALID_NUMBERS = -2,
    TWO_ROOTS = 2,
    ONE_ROOT = 1,
    NO_ANY_ROOTS = 0
};

// прототипы структур для результатов решения
struct quadEqCase{
    quadEqConst quantity;
    const char * toPrint;
};

const struct quadEqCase allOutputs[countOutputCases]{
    {INFINITY_OF_ROOTS, "Данное уравнение имеет бесконечное количество решений\n"},
    {NO_VALID_NUMBERS, "Данное уравнение не имеет решений в действительных числах\n"},
    {TWO_ROOTS, "Данное уравнение имеет два корня x1 = %lf, x2 = %lf\n"},
    {ONE_ROOT, "Данное уравнение имеет один корень x1 = %lf\n"},
    {NO_ANY_ROOTS, "Данное уравнения не имеет решений\n"}
};

// UI функции
int showTopMenu(struct menuMode* allModes);

void print_with_specifiers(quadEqCase curOutput, double* x1, double* x2);
void printFinalOutput(double* x1, double* x2, quadEqConst curOutput);
void isCorrect(int* choose);

// константы для меню
enum menuConst{
    RETURN_TO_TOP_MENU
};

// функции режима
int userEquations();
int randomEquations();
int trainerEquations();

// функции sidefunc

bool isZero(double number);
void clearBuffer();

// функции внутри режима userEquations
quadEqConst solveLinear(double b, double c, double* x);
quadEqConst solveQuadEqua(double a, double b, double c, double* x1, double* x2);

#endif /* ABC */
