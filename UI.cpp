
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
static void clearBuffer();

// 3 режим 

static int getRandMax();
static void getAnswer(char* answer);

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

void userEnterSolution(testsData_t* data){
    assert(data);

    char buffer[100];
    fgets(buffer, 100, stdin);

    answers answers = {"\0", "\0"};
    bool flag = true;
    while(flag){
        getAnswer(answers.ans1);
        getAnswer(answers.ans2);

        double conversion1 = 0,conversion2 = 0;
        if(sscanf(answers.ans1, "%lf", &conversion1)){
            if(sscanf(answers.ans2, "%lf", &conversion2)){
                printf("GAF\n");
                data->equationData.roots.x1 = conversion1;
                data->equationData.roots.x2 = conversion2;
                data->nRootsRef = TWO_ROOTS;
            }
            else if(!strcmp(answers.ans2,"\0")){
                data->equationData.roots.x1 = conversion1;
                data->nRootsRef = ONE_ROOT;
            }
            else{
                printf("MEOW\n");
                printf(ALERT_INCORRECT_ANS_ENTER);
                continue;
            }

        }
        else if(!strcmp(answers.ans1, INF)){
            data->nRootsRef = INFINITY_OF_ROOTS;
        }
        else if(!strcmp(answers.ans1, NOT_A_NUM)){
            data->nRootsRef = NO_VALID_ROOTS;
        }
        else{
            printf("%s — %s", answers.ans1, NOT_A_NUM);
            printf(ALERT_INCORRECT_ANS_ENTER);
            continue;
        }

        flag = false;
    }
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

static void clearBuffer(){
    while(getchar() != '\n'){
        continue;
    }
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

static void getAnswer(char* answer){
    char ch = 0;
    int i = 0;
    while(!isspace(ch = getchar())){
        answer[i] = ch;
        i++;
    }
    i++;
    answer[i] = '\0';
}
