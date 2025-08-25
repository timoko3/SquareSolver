//assert
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "solve.h"
#include "modes.h"
#include "UI.h"
#include "unitTests.h"
int main(void){
    int passed = RunTest();
    showTestsResult(passed);
    bool menuFLag = true;
    while(menuFLag){
        int choose = chooseMode();
        bool modeFlag = true;
        if(choose == MENU_TOP_BORDER){
            modeFlag = false;
            menuFLag = false;
        }
        while(modeFlag){
            if(((allModes[choose].mode)()) == RETURN_TO_TOP_MENU){
                modeFlag = false;
            }
        }
    }
    return 0;
}
