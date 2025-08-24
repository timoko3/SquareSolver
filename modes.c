#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "modes.h"

// константы
const char* INSTRUCTION = "Введите парметры приведенного квадратного уравнения ax^2+bx+c:(для возврата к выбору режима нажмите q)\n";
const char* HOW_TO_USE = "Необходимо вводить парметры в виде: a b c(a,b,c — действительные числа)\n";
const char* WORK_IN_PROGRESS = "В разработке\n";

// Режимы
int userEquations(){
    // инициализация необходимых локальных переменных и структур
    double a = 0,b = 0,c = 0;
    double x1 = 0, x2 = 0;

    // Ввод парметров квадратного уравнения
    printf("%s", INSTRUCTION);

    while(scanf("%lf %lf %lf", &a, &b, &c) != 3){
        int ch = '\0';
        // Возвращение в "верхнее" меню
        if((ch = getchar()) == 'q'){
            clearBuffer();
            return RETURN_TO_TOP_MENU;
        }
        else{
            printf("%s", HOW_TO_USE);
            clearBuffer();
        }
    }

    quadEqConst curOutput = solveQuadEqua(a,b,c, &x1, &x2); // Вызов основной функции
    printFinalOutput(&x1, &x2, curOutput); // вызов функции вывода
    return 0;
}

int randomEquations(){
    printf("%s", WORK_IN_PROGRESS);
    return 0;
}

int trainerEquations(){
   printf("%s", WORK_IN_PROGRESS);
   return 0;
}
