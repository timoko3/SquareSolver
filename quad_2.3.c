//main_quad.c — Решение квадратного уравнения
//assert
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
// создание типа для указателя на функцию в меню
typedef int(*menuPtr)();
// Задание констант. Не следует менять!

// Константы для функции решения квадратных уравнений
enum quadEqConst{
    INFINITY_OF_ROOTS = -1,
    NO_VALID_NUMBERS = -2,
    TWO_ROOTS = 2,
    ONE_ROOT = 1,
    NO_ANY_ROOTS = 0
};
struct quadEqCase{
    int quantity;
    char * toPrint;
};
struct menuMode{
    menuPtr mode;
    char * toPrint;
};

// константы для меню
enum menuConst{
    MODES = 4,
    RETURN_TO_TOP_MENU = -1
};

//для проверки равенства нулю
const double INFELICITY = 0.000001;

// прототипы функций
int topMenu(struct menuMode* allModes);

// функции режима
int userEquations();
int randomEquations();
int trainerEquations();

// функции внутри режима userEquations
int solveQuadEqua(double a, double b, double c, double* x1, double* x2);
void finalOutput(double* x1, double* x2, int nRoots, struct quadEqCase* allOutputs);
int solveLinear(double b, double c, double* x);
bool isZero(double number);
void clearBuffer();
void print_with_specifiers(int right, struct quadEqCase* allOutputs, double* x1, double* x2);

int main(void){
    // создание меню для выбора режима
    struct menuMode allModes[MODES]{
        {userEquations, "1) Решение введенных вами квадратных уравнений\t"},
        {randomEquations, "2) Решение множества квадратных уравнений со случайными коэффицентами\n"},
        {trainerEquations, "3) Тренажер по решению квадртаных уарвнений\t"},
        {NULL, "4) Выйти из программы\n"}
    };
    bool flagOutOfMode = true;
    while(flagOutOfMode){
        int choose = topMenu(allModes);
        bool flagInMode = true;
        while(flagInMode){
            if(choose == 4){
                flagOutOfMode = false;
            }
            else{
                if(((allModes[choose].mode)()) == RETURN_TO_TOP_MENU){
                    flagInMode = false;
                }
            }
        }
    }
    return 0;
}

int topMenu(struct menuMode* allModes){
    int choose = 0;
    printf("Добро пожаловать!\n");
    printf("Выберите один из режимов:\n");
    int i = 0;
    for(i = 0; i < MODES; i++){
        printf("%s",allModes[i].toPrint);
    }

    // Обработка правильности ввода
    while((scanf("%d", &choose) != 1) || choose < 1 || choose > 4){
        printf("Выбирайте из предложенных вариантов\n");
    }
    return choose - 1;
}

// Режимы
int userEquations(){
    double a = 0,b = 0,c = 0;
    double x1 = 0, x2 = 0;
    struct quadEqCase allOutputs[6]{
        {INFINITY_OF_ROOTS, "Данное уравнение имеет бесконечное количество решений\n"},
        {NO_VALID_NUMBERS, "Данное уравнение не имеет решений в действительных числах\n"},
        {TWO_ROOTS, "Данное уравнение имеет два корня x1 = %lf, x2 = %lf\n"},
        {ONE_ROOT, "Данное уравнение имеет один корень x1 = %lf\n"},
        {NO_ANY_ROOTS, "Данное уравнения не имеет решений\n"}
    };
    // Ввод парметров квадратного уравнения
    printf("Введите парметры приведенного квадратного уравнения ax^2+bx+c:"
           "(для возврата к выбору режима нажмите q)\n");
    while(scanf("%lf %lf %lf", &a, &b, &c) != 3){
        int ch = '\0';
        // Выход из программы
        if((ch = getchar()) == 'q'){
            clearBuffer();
            return RETURN_TO_TOP_MENU;
        }
        else{
            printf("Необходимо вводить парметры в виде: a b c(a,b,c — действительные числа)\n");
            clearBuffer();
        }
    }

    int nRoots = solveQuadEqua(a,b,c, &x1, &x2); // Вызов основной функции
    finalOutput(&x1, &x2, nRoots, allOutputs); // вызов функции вывода
    return 0;
}

int randomEquations(){
    printf("В разработке\n");
    return 0;
}

int trainerEquations(){
   printf("В разработке\n");
   return 0;
}

int solveQuadEqua(double a, double b, double c,
                  double* x1, double* x2){
    if(isZero(a)){
        return solveLinear(b, c, x1);
    }

    double D = b * b - 4 * a * c; //вычисление дискриминанта

    // условие отстуствия дейстивтельных корней
    if(D < 0){
        return NO_VALID_NUMBERS;
    }
    else if (isZero(D)){
        *x1 = (-b) / (2 * a);
        return ONE_ROOT;
    }
    else{
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        return TWO_ROOTS;
    }
}

// функция вывода в зависимости от кол-ва корней уравнения
void finalOutput(double * x1, double*x2,
                 int nRoots, struct quadEqCase* allOutputs){
/*    switch(nRoots){
        case NO_ANY_ROOTS:
            printf("Данное уравнения не имеет решений\n");
            break;
        case ONE_ROOT:
            printf("Данное уравнение имеет один корень x1 = %lf\n", *x1);
            break;
        case TWO_ROOTS:
            printf("Данное уравнение имеет два корня x1 = %lf, x2 = %lf\n", *x1,*x2);
            break;
        case NO_VALID_NUMBERS:
            printf("Данное уравнение не имеет решений в действительных числах\n");
            break;
        case INFINITY_OF_ROOTS:
            printf("Данное уравнение имеет бесконечное количество решений\n");
            break;
        default:
            printf("Произошла ошибка, кол-во корней — %d\n", nRoots);
    }*/

    // новый вариант(не уверен, что лучше)
    int i = 0;
    for(i = 0; i < 5; i++){
        if(allOutputs[i].quantity == nRoots){
            print_with_specifiers(i, allOutputs, x1, x2);
        }
    }

}

// решение линейного варианта квадратного уравнения
int solveLinear(double b, double c, double* x){
    if(isZero(b)){
        if(isZero(c)){
            return INFINITY_OF_ROOTS;
        }
        else{
            return NO_ANY_ROOTS;
        }
    }
    else{
        *x = c;
        return ONE_ROOT;
    }
}

// проверка double на равенство нулю
bool isZero(double number){
    if(fabs(number) < INFELICITY){
        return true;
    }
    else{
        return false;
    }
}

// очистка буфера
void clearBuffer(){
    while(getchar() != '\n'){
        continue;
    }
}

// печать строки с поиском в ней спецификаторов %lf и заменой на переменные
void print_with_specifiers(int right, struct quadEqCase* allOutputs, double* x1, double* x2){
    int j = 0;
    char ch = '\0';
    double* roots[] = {x1,x2}; // массив указателей на корни для печати
    int printedRoots = 0;
    while((ch = allOutputs[right].toPrint[j]) != '\0'){
        // подразумевается, что встречается только % для обозначения спецификатора
        if(ch == '%'){
            j += 3;
            printf("%lf", *(roots[printedRoots++]));
        }
        else{
            j++;
            putchar(ch);
        }
    }
}








