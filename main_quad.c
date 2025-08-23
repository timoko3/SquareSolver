//main_quad.c — Решение квадратного уравнения
//assert
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "funcDefinitions.h"

int main(void){
    // иницивлизация необходимых структур и переменных
    struct menuMode allModes[MODES]{
        {userEquations, "1) Решение введенных вами квадратных уравнений\t"},
        {randomEquations, "2) Решение множества квадратных уравнений со случайными коэффицентами\n"},
        {trainerEquations, "3) Тренажер по решению квадртаных уарвнений\t"},
        {NULL, "4) Выйти из программы\n"}
    };
    bool flagOutOfMode = true;

    // главная часть от куда начинается выполнение всей программы
    while(flagOutOfMode){
        int choose = showTopMenu(allModes);
        bool flagInMode = true;
        while(flagInMode){
            if(choose == 4){
                flagOutOfMode = false;
                flagInMode = false;
            }
            else{
                if(((allModes[choose].mode)()) == RETURN_TO_TOP_MENU){
                    flagInMode = false;
                }
            }
        }
    }

    return 0;
}
// Режимы
int userEquations(){
    // инициализация необходимых локальных переменных и структур
    double a = 0,b = 0,c = 0;
    double x1 = 0, x2 = 0;
    struct quadEqCase allOutputs[6]{
        {INFINITY_OF_ROOTS, "Данное уравнение имеет бесконечное количество решений\n"},
        {NO_VALID_NUMBERS, "Данное уравнение не имеет решений в действительных числах\n"},
        {TWO_ROOTS, "Данное уравнение имеет два корня x1 = %lf, x2 = %lf\n"},
        {ONE_ROOT, "Данное уравнение имеет один корень x1 = %lf\n"},
        {NO_ANY_ROOTS, "Данное уравнения не имеет решений\n"}
    };

    // Ввод парметров квадратного уравнения
    printf("Введите парметры приведенного квадратного уравнения ax^2+bx+c:"
           "(для возврата к выбору режима нажмите q)\n");

    while(scanf("%lf %lf %lf", &a, &b, &c) != 3){
        int ch = '\0';
        // Выход из программы
        if((ch = getchar()) == 'q'){
            clearBuffer();
            return RETURN_TO_TOP_MENU;
        }
        else{
            printf("Необходимо вводить парметры в виде: a b c(a,b,c — действительные числа)\n");
            clearBuffer();
        }
    }

    int nRoots = solveQuadEqua(a,b,c, &x1, &x2); // Вызов основной функции
    printFinalOutput(&x1, &x2, nRoots, allOutputs); // вызов функции вывода
    return 0;
}

int randomEquations(){
    printf("В разработке\n");
    return 0;
}

int trainerEquations(){
   printf("В разработке\n");
   return 0;
}











