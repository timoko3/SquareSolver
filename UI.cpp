
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "nRoots.h"
#include "UI.h"
#include "modes.h"
#include "unitTests.h"
#include "consoleColors.h"
#include "common.h"


static void showTopMenu();
static menu_mode_t get_mode();

// 3 режим 

static int getRandMax();
static numRoots getNRoots();
static bool getAnswer(char* answer);
static void setAnswers(testsData_t* data, double conversion1, double conversion2);


void showTestsResult(int nPassed, int nAllTests){
    if(nPassed == nAllTests){
        printf(TO_PRINT_TESTS_RESULT_SUCCESS, nPassed, nAllTests);
    }
    else{
        printf(TO_PRINT_TESTS_RESULT_FAILURE, nPassed, nAllTests);
    }
}

menu_mode_t chooseMode(){
    showTopMenu();
    return get_mode();
}

bool get_coefficients(coefs_t* coefs) {
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

// 3 режим

int chooseRandMaxModule(){
    printf(INSTRUCTION_ENTER_RAND_MAX);
    return getRandMax();
}

bool userEnterSolution(testsData_t* data){
    assert(data);

    double conversion1 = 0, conversion2 = 0;
    while(true){
        answers answers = {"\0", "\0"};

        data->nRootsRef = getNRoots();
        
        if(data->nRootsRef == INFINITY_OF_ROOTS){
            return true;
        }
        else if(data->nRootsRef == NO_VALID_ROOTS){
            return true;
        }
        else if(data->nRootsRef == ONE_ROOT){
            printf(ENTER_FIRST_ROOT);
            if(!getAnswer(answers.ans1)) return false;
        }
        else if(data->nRootsRef == TWO_ROOTS){
            printf(ENTER_FIRST_ROOT);
            if(!getAnswer(answers.ans1)) return false;
            printf(ENTER_SECOND_ROOT);
            if(!getAnswer(answers.ans2)) return false;
        }

        sscanf(answers.ans1, "%lf", &conversion1);
        sscanf(answers.ans2, "%lf", &conversion2);

        break;
    }

    setAnswers(data, conversion1, conversion2); // roots

    return true;
}

bool isSolutionRight(testsData_t* reference, testsData_t* userData){
    assert(reference);
    assert(userData);

    if(userData->nRootsRef == reference->nRootsRef && 
       isEqualDoubles(userData->equationData.roots.x1, reference->equationData.roots.x1, INFELICITY_TRAINER) &&
       isEqualDoubles(userData->equationData.roots.x2, reference->equationData.roots.x2, INFELICITY_TRAINER)){
        return true;
    }

    printf("%d %d %d\n", userData->nRootsRef == reference->nRootsRef, 
                         isEqualDoubles(userData->equationData.roots.x1, reference->equationData.roots.x1, INFELICITY_TRAINER),
                         isEqualDoubles(userData->equationData.roots.x2, reference->equationData.roots.x2, INFELICITY_TRAINER)
                    );

    return false;
}

void printDependingOnResult(bool isRight){
    if(isRight){
        printf(PRAISE);
    }
    else{
        printf(COMFORT);
    }
}

static void showTopMenu(){
    printf("%s", CHOOSE_MODE);
    for(int i = 0; i < EXIT; i++){
        printf("%d) %s", i + MENU_FIRST_ITEM, allModes[i].stringDescription);
    }
}

static menu_mode_t get_mode(){
    menu_mode_t mode = 0;
    while(!(scanf("%d", &mode)) || mode < MENU_FIRST_ITEM || mode > EXIT){
        printf("%s", ALERT_INCORRECT);
        clearBuffer();
    }

    assert(!(mode < MENU_FIRST_ITEM || mode > EXIT));

    return mode - MENU_FIRST_ITEM;
}



static int getRandMax(){
    int randMaxModule = 0;
    while(scanf("%d", &randMaxModule)  != 1){
        printf(ALERT_INCORRECT_RAND_MAX);
        printf(TRY_AGAIN);
        clearBuffer();
    }
    return randMaxModule;
}

static bool getAnswer(char* answer){
    int ch = 0;
    int i = 0;

    ch = getchar();
    if(ch == '\r');
    else{
         answer[i] = ch;
         i++;
    }

    while(!isspace(ch = getchar())){ // [-1; 256)
        if(ch == RETURN_TO_TOP_MENU){
            clearBuffer();
            return false;
        }
        answer[i] = (char)ch;
        i++;
    }
    i++;
    answer[i] = '\0';
    return true;
}

static void setAnswers(testsData_t* data, double conversion1, double conversion2){
    if(data->nRootsRef == TWO_ROOTS){
        sortRoots(&conversion1, &conversion2);
        data->equationData.roots.x1 = conversion1;
        data->equationData.roots.x2 = conversion2;
    }
    else if(data->nRootsRef == ONE_ROOT){
        data->equationData.roots.x1 = conversion1;
    }
}

static numRoots getNRoots(){
    char nRoots = 0;
    while(!scanf(" %c", &nRoots) || nRoots <  'a' || nRoots > 'd') {
        if(nRoots == '\n' || nRoots == '\r') continue;
        printf(ALERT_INCORRECT);
        clearBuffer();
    }

    switch(nRoots){
        case 'a' : return ONE_ROOT;
        case 'b' : return TWO_ROOTS;
        case 'c' : return NO_VALID_ROOTS;
        case 'd' : return INFINITY_OF_ROOTS;
        default: printf(ALERT_INCORRECT); assert(false);
    }
}
