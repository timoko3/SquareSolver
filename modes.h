
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

void clearBuffer();
// функции режима
int userEquations();
int randomEquations();
int trainerEquations();

// функции внутри режима userEquations
quadEqConst solveLinear(double b, double c, double* x);
quadEqConst solveQuadEqua(double a, double b, double c, double* x1, double* x2);

// UI функции
void printFinalOutput(double* x1, double* x2, quadEqConst curOutput);
