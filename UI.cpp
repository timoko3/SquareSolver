
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <math.h>

#include "nRoots.h"
#include "UI.h"
#include "modes.h"
#include "unitTests.h"
#include "consoleColors.h"

static void showTopMenu();
static menu_mode_t get_mode();
static void clearBuffer();

void showTestsResult(int nPassed, int nAllTests){
    printf(TO_PRINT_TESTS_RESULT, nPassed, nAllTests);
}

menu_mode_t chooseMode(){ // to modes
    showTopMenu();
    return get_mode();
}

bool get_coefficents(coefs_t* coefs) {
    assert(coefs);

    printf("%s", INSTRUCTION);
    while(scanf("%lf %lf %lf", &(coefs->a), &(coefs->b), &(coefs->c)) != 3){
        if(getchar() == RETURN_TO_TOP_MENU){
            clearBuffer();
            return false;
        }
        else{
            printf("%s", HOW_TO_USE);
            clearBuffer();
        }
    }

    assert(isfinite(coefs->a));
    assert(isfinite(coefs->b));  
    assert(isfinite(coefs->c));   

    return true;    
}

void printFinalOutput(roots_t* roots,
                      numRoots nRoots){
    assert(roots);
    
    for(int i = 0; i < nRootsCases; i++){
        if(allRootsDescription[i].quantity == nRoots){
            printf(allRootsDescription[i].stringDescription, roots->x1, roots->x2);
        }
    }
}

static void showTopMenu(){
    printf("%s", WELCOME);
    printf("%s", CHOOSE_MODE);
    for(int i = 0; i < EXIT; i++){
        printf("%d) %s", i + MENU_FIRST_ITEM, allModes[i].stringDescription);
    }
}

static menu_mode_t get_mode(){
    menu_mode_t mode = 0;
    while(!(scanf("%d", &mode)) || mode < MENU_FIRST_ITEM || mode > EXIT){
        printf("%s", ALLERT_INCORRECT);
        clearBuffer();
    }

    assert(!(mode < MENU_FIRST_ITEM || mode > EXIT));

    return mode - MENU_FIRST_ITEM;
}

static void clearBuffer(){
    while(getchar() != '\n'){
        continue;
    }
}

