// прототипы функций

// UI функции
int showTopMenu(struct menuMode* allModes);
void print_with_specifiers(int right, struct quadEqCase* allOutputs, double* x1, double* x2);
void printFinalOutput(double* x1, double* x2, int nRoots, struct quadEqCase* allOutputs);
void isCorrect(int* choose);

// функции режима
int userEquations();
int randomEquations();
int trainerEquations();

// функции внутри режима userEquations
int solveQuadEqua(double a, double b, double c, double* x1, double* x2);
int solveLinear(double b, double c, double* x);

// побочные функции
bool isZero(double number);
void clearBuffer();

// Задание констант. Не следует менять!

// Константы для функции решения квадратных уравнений
enum quadEqConst{
    INFINITY_OF_ROOTS = -1,
    NO_VALID_NUMBERS = -2,
    TWO_ROOTS = 2,
    ONE_ROOT = 1,
    NO_ANY_ROOTS = 0
};

// константы для меню
enum menuConst{
    MODES = 4,
    RETURN_TO_TOP_MENU = -1
};
//для проверки равенства нулю
const double INFELICITY = 0.000001;


// создание типа для указателя на функцию в меню
typedef int(*menuPtr)();

// прототипы структур для вывода меню и резьтатов решения
struct quadEqCase{
    int quantity;
    char * toPrint;
};
struct menuMode{
    menuPtr mode;
    char * toPrint;
};
