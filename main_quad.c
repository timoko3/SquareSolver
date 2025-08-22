//main_quad.c — Решение квадратного уравнения
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
// создание типа для указателя на функцию в меню
typedef void(*menuPtr)();
// Задание констант. Не следует менять!

// Константы для функции решения квадратных уравнений
enum quadEqConst{
    INFINITY_OF_ROOTS = -1,
    NO_VALID_NUMBERS = -2,
    TWO_ROOTS = 2,
    ONE_ROOT = 1,
    NO_ANY_ROOTS = 0
};
// константы для меню
enum menuConst{
    MODES = 3
};
const double INFELICITY = 0.000001;


// прототипы функций
int topMenu();
// функции режима
void userEquations();
void randomEquations();
void trainerEquations();
// функции внутри режима userEquations
int solveQuadEqua(double a, double b, double c, double* x1, double* x2);
void finalOutput(double* x1, double* x2, int nRoots);
int solveLinear(double b, double c, double* x);
bool isZero(double number);
void clearBuffer();

int main(void){
    // создание меню для выбора режима
    menuPtr mode[MODES] = {
        userEquations,
        randomEquations,
        trainerEquations
    };
    int choose = topMenu();
    bool flag = true;
    while(flag){
        if(choose == 4){
            flag = false;
        }
        else{
            (mode[choose])();
        }
    }
    return 0;
}

int topMenu(){
    int choose = 0;
    printf("Добро пожаловать!\n");
    printf("Выберите один из режимов:\n");
    printf("1) Решение введенных вами квадратных уравнений\t"
           "2) Решение множества квадратных уравнений со случайными коэффицентами\n"
           "3) Тренажер по решению квадртаных уарвнений\t"
           "4) Выйти из программы\n");

    // Обработка правильности ввода
    while((scanf("%d", &choose) != 1) || choose < 1 || choose > 4){
        printf("Выбирайте из предложенных вариантов\n");
    }
    return choose - 1;
}

// Режимы
void userEquations(){
    double a = 0,b = 0,c = 0;
    double x1 = 0, x2 = 0;
    // Ввод парметров квадратного уравнения
    printf("Введите парметры приведенного квадратного уравнения ax^2+bx+c:"
           "(для возврата к выбору режима нажмите q)\n");
    while(scanf("%lf %lf %lf", &a, &b, &c) != 3){
        int ch = '\0';
        // Выход из программы
        if((ch = getchar()) == 'q'){
            exit(0);
        }
        printf("Необходимо вводить парметры в виде: a b c(a,b,c — действительные числа)\n");
        clearBuffer();// очистка буфера
    }

    int nRoots = solveQuadEqua(a,b,c, &x1, &x2); // Вызов основной функции
    finalOutput(&x1, &x2, nRoots); // вызов функции вывода
}

void randomEquations(){
    printf("В разработке\n");
}

void trainerEquations(){
   printf("В разработке\n");
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
                 int nRoots){
    switch(nRoots){
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
    }
}

// решение линейного варианта квадратного уравнения
int solveLinear(double b, double c, double * x){
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








