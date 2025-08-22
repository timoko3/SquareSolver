//main_quad.c — Решение квадратного уравнения
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
// Задание констант. Не следует менять!
#define INFINITY_OF_ROOTS -1
#define NO_VALID_NUMBERS -2
#define TWO_ROOTS 2
#define ONE_ROOT 1
#define NO_ANY_ROOTS 0
#define INFELICITY 0.000001
#define modes 4 // можно менять

// прототипы функций

// функции режима
void userEquations();
void randomEquations();
void trainerEquations();
void quit();
// функции внутри режимов
int solveQuadEqua(double a, double b, double c, double* x1, double* x2);
void finalOutput(double* x1, double* x2, int nRoots);
void clearBuffer();
int solveLinear(double b, double c, double* x1);
int topMenu();
bool isZero(double number);

int main(void){
    // Инициализация переменных
    int choose = 0;
    // создание меню для выбора режима
    void (*mode[modes])() = {userEquations, randomEquations, trainerEquations,quit};
    choose = topMenu();
    (mode[choose])();
    return 0;
}
int solveQuadEqua(double a, double b, double c,
                  double* x1, double* x2){
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
        // обработка случая a = 0
        if(isZero(a)){
            return solveLinear(b,c,x1);
        }
        else{
            *x1 = (-b + sqrt(D)) / (2 * a);
            *x2 = (-b - sqrt(D)) / (2 * a);
            return TWO_ROOTS;
        }
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
            printf("Данное уравнение не имеет решений в действительных числах");
            break;
        case INFINITY_OF_ROOTS:
            printf("Данное уравнение имеет бесконечное количество решений\n");
            break;
        default:
            printf("Произошла ошибка, кол-во корней — %d\n", nRoots);
    }
}
// очистка буфера
void clearBuffer(){
    while(getchar() != '\n'){
        continue;
    }
}
// решение линейного варианта квадратного уравнения
int solveLinear(double b, double c, double * x1){
    if(isZero(b)){
        if(isZero(c)){
            return INFINITY_OF_ROOTS;
        }
        else{
            return NO_ANY_ROOTS;
        }
    }
    else{
        *x1 = c;
        return ONE_ROOT;
    }
}
int topMenu(){
    char choose = '\0';
    printf("Добро пожаловать!\n");
    printf("Выберите один из режимов:\n");
    printf("a) Решение введенных вами квадратных уравнений\t"
           "b) Решение множества квадратных уравнений со случайными коэффицентами\n"
           "c) Тренажер по решению квадртаных уарвнений\t"
           "d) Выйти из программы\n");

    // Обработка правильности ввода
    while(scanf("%c", &choose) != 1 || choose < 'a' || choose > 'd'){
        printf("Выбирайте из предложенных вариантов\n");
    }
    return (choose - 'a');
}
// проверка double на равенство нулю
bool isZero(double number){
    if((fabs(number) - 0.0) < INFELICITY){
        return true;
    }
    else{
        return false;
    }
}
// выход из программы
void quit(){
    exit(0);
}
void userEquations(){
    double a = 0,b = 0,c = 0;
    double x1 = 0, x2 = 0;
    // Ввод парметров квадратного уравнения
    printf("Введите парметры приведенного квадратного уравнения ax^2+bx+c:\n");
    while(scanf("%lf %lf %lf", &a, &b, &c) != 3){
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
   printf("В разработке");
}




