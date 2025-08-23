#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "funcDefinitions.h"
int showTopMenu(struct menuMode* allModes){
    int choose = 0;
    printf("Добро пожаловать!\n");
    printf("Выберите один из режимов:\n");
    int i = 0;
    for(i = 0; i < MODES; i++){
        printf("%s",allModes[i].toPrint);
    }
    isCorrect(&choose);

    return choose - 1;
}

// Обработка правильности ввода в меню
void isCorrect(int* choose){
    while((scanf("%d", choose) != 1) || *choose < 1 || *choose > 4){
        printf("Выбирайте из предложенных вариантов\n");
        clearBuffer();
    }
}

// функция вывода в зависимости от кол-ва корней уравнения
void printFinalOutput(double * x1, double*x2,
                 int nRoots, struct quadEqCase* allOutputs){
/*    switch(nRoots){
        case NO_ANY_ROOTS:
            printf("Данное уравнения не имеет решений\n");
            break;
        case ONE_ROOT:
            printf("Данное уравнение имеет один корень x1 = %lf\n", *x1);
            break;
        case TWO_ROOTS:
            printf("Данное уравнение имеет два корня x1 = %lf, x2 = %lf\n", *x1,*x2);
            break;
        case NO_VALID_NUMBERS:
            printf("Данное уравнение не имеет решений в действительных числах\n");
            break;
        case INFINITY_OF_ROOTS:
            printf("Данное уравнение имеет бесконечное количество решений\n");
            break;
        default:
            printf("Произошла ошибка, кол-во корней — %d\n", nRoots);
    }*/

    // новый вариант(не уверен, что лучше)
    int i = 0;
    for(i = 0; i < 5; i++){
        if(allOutputs[i].quantity == nRoots){
            print_with_specifiers(i, allOutputs, x1, x2);
        }
    }

}

// печать строки с поиском в ней спецификаторов %lf и заменой на переменные
void print_with_specifiers(int right, struct quadEqCase* allOutputs, double* x1, double* x2){
    int j = 0;
    char ch = '\0';
    double* roots[] = {x1,x2}; // массив указателей на корни для печати
    int printedRoots = 0;
    while((ch = allOutputs[right].toPrint[j]) != '\0'){
        // подразумевается, что встречается только % для обозначения спецификатора
        if(ch == '%'){
            j += 3;
            printf("%lf", *(roots[printedRoots++]));
        }
        else{
            j++;
            putchar(ch);
        }
    }
}
