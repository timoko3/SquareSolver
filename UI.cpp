
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include "nRoots.h"
#include "UI.h"
#include "modes.h"
#include "unitTests.h"

// static
void showTopMenu();
mode get_mode();
void clearBuffer();
void print_with_specifiers(nDescription curOutput, roots* roots);

mode chooseMode(){
    showTopMenu();
    return get_mode();
}

const char*const TO_PRINT_TESTS_RESULT = "Пройдено %d/%d тестов\n";
void showTestsResult(int nPassed,const int nAllTests){
    printf(TO_PRINT_TESTS_RESULT, nPassed, nAllTests);
}

void showTopMenu(){
    printf("%s", WELCOME);
    printf("%s", CHOOSE_MODE);
    for(int curMode = 0; curMode < MENU_TOP_BORDER; curMode++){
        printf("%d) %s", curMode + 1, allModes[curMode].toPrint);
    }
}

mode get_mode(){
    mode choose = 0;
    while(!(scanf("%d", &choose)) || choose < MENU_BOTTOM_BORDER || choose > MENU_TOP_BORDER){
        printf("%s", ALLERT_INCORRECT);
        clearBuffer();
    }
    assert(!(choose < MENU_BOTTOM_BORDER || choose > MENU_TOP_BORDER));
    return choose - 1;
}

void printFinalOutput(roots* userRoots,
                      numRoots curOutput){
    for(int curOutputStruct = 0; curOutputStruct < nRootsCases; curOutputStruct++){
        if(allOutputs[curOutputStruct].quantity == curOutput){
            print_with_specifiers(allOutputs[curOutputStruct], userRoots);
        }
    }
}

void print_with_specifiers(nDescription curOutput,
                           roots* userRoots){
    int curSymbol = 0;
    double* rootsArray[] = {&userRoots->x1, &userRoots->x2};
    int printedRoots = 0;
    int ch = 0;
    while((/*int*/ ch = curOutput.toPrint[curSymbol]) != '\0'){
        /// подразумевается, что встречается только % для обозначения спецификатора
        if(ch == BEGIN_SPECIFIER){
            printf("%lf", (*rootsArray[printedRoots++]));
            curSymbol += 3;
        }
        else{
            putchar(ch);
            curSymbol++;
        }
    }
}

successStatus get_coefficents(coefficents* userCoefficents) {
    assert(userCoefficents != NULL);
    printf("%s", INSTRUCTION);
    while(scanf("%lf %lf %lf", &(userCoefficents->a), &(userCoefficents->b), &(userCoefficents->c)) != 3){
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
    assert(isfinite(userCoefficents->a));
    assert(isfinite(userCoefficents->b));  
    assert(isfinite(userCoefficents->c));          
    
    return SUCCESS_CHOOSE_MODE; 
}

void clearBuffer(){
    while(getchar() != '\n'){
        continue;
    }
}

