enum quadEqConst{
    INFINITY_OF_ROOTS,
    NO_VALID_ROOTS,
    TWO_ROOTS,
    ONE_ROOT,
    NO_ANY_ROOTS
};

// функции внутри режима userEquations
quadEqConst solveLinear(double b, double c, double* x);
quadEqConst solveQuadEqua(double a, double b, double c, double* x1, double* x2);

bool isZero(double number);
