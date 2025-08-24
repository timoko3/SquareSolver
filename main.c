 //main_quad.c — Решение квадратного уравнения
//assert
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "main.h"

int main(void){
    // главная часть от куда начинается выполнение всей программы
    bool flagOutOfMode = true;
    while(flagOutOfMode){
        int choose = showTopMenu(allModes);
        bool flagInMode = true;
        if(choose == TOP_BORDER){
            flagInMode = false;
            flagOutOfMode = false;
        }
        while(flagInMode){
            if(((allModes[choose].mode)()) == RETURN_TO_TOP_MENU){
                flagInMode = false;
            }
        }
    }
    return 0;
}












