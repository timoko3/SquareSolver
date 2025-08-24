//assert
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "solve.h"
#include "modes.h"
#include "UI.h"

int main(void){
    bool flagOutOfMode = true;
    while(flagOutOfMode){
        int choose = chooseMode();
        bool flagInMode = true;
        if(choose == MENU_TOP_BORDER){
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
