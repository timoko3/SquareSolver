
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "nRoots.h"
#include "UI.h"
#include "modes.h"
#include "unitTests.h"



void showTopMenu();
void get_mode(int* choose);
void clearBuffer();
void print_with_specifiers(nOutput curOutput, double* x1, double* x2);

typedef int mode;

mode chooseMode(){
    showTopMenu();
    mode choose = 0;
    get_mode(&choose);
    return choose - 1;
}

void showTestsResult(int passed){
    printf("Пройдено %d/%d тестов\n", passed, NUMBER_OF_TESTS);
}

void showTopMenu(){
    printf("%s", WELCOME);
    printf("%s", CHOOSE_MODE);
    for(int curMode = 0; curMode < MENU_TOP_BORDER; curMode++){
        printf("%d) %s", curMode + 1, allModes[curMode].toPrint);
    }
}

void get_mode(int* choose){
    while(!(scanf("%d", choose)) || *choose < MENU_BOTTOM_BORDER || *choose > MENU_TOP_BORDER){
        printf("%s", ALLERT_INCORRECT);
        clearBuffer();
    }
    assert(!(*choose < MENU_BOTTOM_BORDER || *choose > MENU_TOP_BORDER));
}

void clearBuffer(){
    while(getchar() != '\n'){
        continue;
    }
}

void printFinalOutput(double* x1, double* x2,
                 numRoots curOutput){
    for(int curOutputStruct = 0; curOutputStruct < countOutputCases; curOutputStruct++){
        if(allOutputs[curOutputStruct].quantity == curOutput){
            print_with_specifiers(allOutputs[curOutputStruct], x1, x2);
        }
    }
}

void print_with_specifiers(nOutput curOutput,
                            double* x1, double* x2){
    int curSymbol = 0;
    double* roots[] = {x1, x2}; // массив указателей на корни для печати
    int printedRoots = 0;
    int ch = 0;
    while((/*int*/ ch = curOutput.toPrint[curSymbol]) != '\0'){
        // подразумевается, что встречается только % для обозначения спецификатора
        if(ch == BEGIN_SPECIFIER){
            printf("%lf", *(roots[printedRoots++]));
            curSymbol += 3;
        }
        else{
            putchar(ch);
            curSymbol++;
        }
    }
}

int get_coefficents(double* a, double* b, double* c) {
    printf("%s", INSTRUCTION);
    while(scanf("%lf %lf %lf", a, b, c) != 3){
        int symbol = '\0';
        // Возвращение в "верхнее" меню
        if((symbol = getchar()) == QUIT){
            clearBuffer();
            return RETURN_TO_TOP_MENU;
        }
        else{
            printf("%s", HOW_TO_USE);
            clearBuffer();
        }
    }
    assert(*a < __DBL_MAX__);
    assert(*b < __DBL_MAX__);
    assert(*c < __DBL_MAX__);
    return SUCCESS_CHOOSE_MODE; 
}

