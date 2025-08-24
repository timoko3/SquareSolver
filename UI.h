// меню
const int BOTTOM_BORDER = 1;
const int TOP_BORDER = 4;

const int countOutputCases = 5;// кол-во вариантов вывода

// константы для меню
enum menuConst{
    RETURN_TO_TOP_MENU = -1
};

enum quadEqConst{
    INFINITY_OF_ROOTS,
    NO_VALID_ROOTS,
    TWO_ROOTS,
    ONE_ROOT,
    NO_ANY_ROOTS
};

// создание типа для указателя на функцию в меню
typedef int(*menuPtr)();

// прототип структуры меню
struct menuMode{
    menuPtr mode;
    const char * toPrint;
};

// прототипы структур для результатов решения
struct quadEqCase{
    quadEqConst quantity;
    const char * toPrint;
};

const struct quadEqCase allOutputs[countOutputCases]{
    {INFINITY_OF_ROOTS, "Данное уравнение имеет бесконечное количество решений\n"},
    {NO_VALID_ROOTS, "Данное уравнение не имеет решений в действительных числах\n"},
    {TWO_ROOTS, "Данное уравнение имеет два корня x1 = %lf, x2 = %lf\n"},
    {ONE_ROOT, "Данное уравнение имеет один корень x1 = %lf\n"},
    {NO_ANY_ROOTS, "Данное уравнения не имеет решений\n"}
};

// UI функции
int showTopMenu(struct menuMode* allModes);
void printFinalOutput(double* x1, double* x2, quadEqConst curOutput);
void isCorrect(int* choose);
void clearBuffer();
void print_with_specifiers(quadEqCase curOutput, double* x1, double* x2);




