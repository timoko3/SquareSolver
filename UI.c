#include <stdio.h>
#include "UI.h"

const char* WELCOME = "Добро пожаловать!\n";
const char* CHOOSE_MODE = "Выберите один из режимов:\n";
const char* ALLERT_INCORRECT = "Выбирайте из предложенных вариантов\n";

// "верхнее" меню

// меняет mode на int
typedef int mode;      // name

mode showTopMenu(menuMode* allModes){
    printf("%s", WELCOME);
    printf("%s", CHOOSE_MODE);
    for(int curMode = 0; curMode < TOP_BORDER; curMode++){
        printf("%d) %s", curMode + 1, allModes[curMode].toPrint);
    }
    int choose = 0;
    isCorrect(&choose);
    return choose - 1;
}

// Ввод choose и обработка правильности ввода в меню
void isCorrect(int* choose){
// assert
    while(!(scanf("%d", choose)) || *choose < BOTTOM_BORDER || *choose > TOP_BORDER){
        printf("%s", ALLERT_INCORRECT);
        clearBuffer();
    }
}

// вывод результатов

// функция вывода в зависимости от кол-ва корней уравнения
void printFinalOutput(double* x1, double* x2,
                 quadEqConst curOutput){
    for(int i = 0; i < countOutputCases; i++){
        if(allOutputs[i].quantity == curOutput){
            print_with_specifiers(allOutputs[i], x1, x2);
        }
    }
}

// печать строки с поиском в ней спецификаторов %lf и заменой на переменные
void print_with_specifiers(quadEqCase curOutput,
                            double* x1, double* x2){
    int curSymbol = 0;
    double* roots[] = {x1, x2}; // массив указателей на корни для печати
    int printedRoots = 0;
    int ch = 0;
    while((/*int*/ ch = curOutput.toPrint[curSymbol]) != '\0'){
        // подразумевается, что встречается только % для обозначения спецификатора
        if(ch == '%'){
            printf("%lf", *(roots[printedRoots++]));
            curSymbol += 3;
        }
        else{
            putchar(ch);
            curSymbol++;
        }
    }
}
