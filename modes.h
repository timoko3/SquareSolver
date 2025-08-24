
#include <stdio.h>

typedef int mode;      
typedef int(*menuPtr)();

struct menuMode{
    menuPtr mode;
    const char* toPrint;
};

const int MENU_TOP_BORDER = 4; 

const char* const USER_EQUATIONS_VARIANT = "Решение введенных вами квадратных уравнений\t";
const char* const RANDOM_EQUATIONS_VARIANT = "Решение множества квадратных уравнений со случайными коэффицентами\n";
const char* const TRAINER_EQUATIONS_VARIANT = "Тренажер по решению квадртаных уравнений\t";
const char* const EXIT_VARIANT = "Выйти из программы\n";

int userEquations();
int randomEquations();
int trainerEquations();

const struct menuMode allModes[MENU_TOP_BORDER]{
    {userEquations, USER_EQUATIONS_VARIANT},
    {randomEquations, RANDOM_EQUATIONS_VARIANT},
    {trainerEquations, TRAINER_EQUATIONS_VARIANT},
    {NULL, EXIT_VARIANT}
};
