// функции режима
int userEquations();
int randomEquations();
int trainerEquations();

// UI функции
int showTopMenu(struct menuMode* allModes);


// константы для меню
enum menuConst{
    RETURN_TO_TOP_MENU = -1
};

// для финального вывода
const char* USER_EQUATIONS_VARIANT = "Решение введенных вами квадратных уравнений\t";
const char* RANDOM_EQUATIONS_VARIANT = "Решение множества квадратных уравнений со случайными коэффицентами\n";
const char* TRAINER_EQUATIONS_VARIANT = "Тренажер по решению квадртаных уравнений\t";
const char* EXIT_VARIANT = "Выйти из программы\n";

// меню
const int BOTTOM_BORDER = 1;
const int TOP_BORDER = 4;

// создание типа для указателя на функцию в меню
typedef int(*menuPtr)();
// прототип структуры меню
struct menuMode{
    menuPtr mode;
    const char * toPrint;
};

// инициализация структуры меню
struct menuMode allModes[TOP_BORDER]{
    {userEquations, USER_EQUATIONS_VARIANT},
    {randomEquations, RANDOM_EQUATIONS_VARIANT},
    {trainerEquations, TRAINER_EQUATIONS_VARIANT},
    {NULL, EXIT_VARIANT}
};






