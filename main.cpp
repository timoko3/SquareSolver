#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "solve.h"
#include "UI.h"
#include "unitTests.h"

int main(void){
    int nAllTests = 0;
    int nPassed = RunTest(&nAllTests);
    showTestsResult(nPassed, nAllTests);

    while(true){
        menu_mode_t mode = chooseMode();

        if(mode == EXIT){
            break;
        }

        (allModes[mode].function)();
    }

    return 0;
}
