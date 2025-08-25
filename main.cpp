#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "solve.h"
#include "UI.h"
#include "unitTests.h"

// poriadoc

int main(void){
    int passedTests = RunTest();
    showTestsResult(passedTests, NUMBER_OF_TESTS);

    while(true){
        menu_mode_t mode = chooseMode();

        if(mode == EXIT){
            break;
        }

        (allModes[mode].function)();
    }

    return 0;
}
