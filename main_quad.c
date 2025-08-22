//main_quad.c — Решение квадратного уравнения
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define INFINITY_OF_ROOTS -1
#define NO_VALID_NUMBERS 3

// прототипы функций
int solveQuadEqua(double a, double b, double c, double *x1, double *x2);
void finalOutput(double * x1, double * x2, int nRoots);
void clearBuffer();

int main(void){
    // Инициализация переменных
    double a = 0,b = 0,c = 0;
    double x1 = 0, x2 = 0;
    // Ввод парметров квадратного уравнения
    printf("Введите парметры приведенного квадратного уравнения ax^2+bx+c:\n");
    while(scanf("%lf %lf %lf", &a, &b, &c) != 3){
        printf("Необходимо вводить парметры в виде: a b c\n");
        // очистка буфера
        clearBuffer();
    }
    // *******************************
    int nRoots = solveQuadEqua(a,b,c, &x1, &x2); // Вызов основной функции
    finalOutput(&x1, &x2, nRoots);
    return 0;
}
int solveQuadEqua(double a, double b, double c,
                  double * x1, double * x2){
    double D = b * b - 4 * a * c;
    // условие отстуствия дейстивтельных корней
    if(D < 0){
        return NO_VALID_NUMBERS;
    }
    else if ((D - 0)  < 0.000001){
        *x1 = (-b) / (2 * a);
        return 10;
    }
    else{
        // решение неполного квадратного уравнения
        if(a == 0){
            if(b == 0){
                if(c == 0){
                    return INFINITY_OF_ROOTS;
                }
                else{
                    return 0;
                }
            }
            else{
                *x1 = c;
                return 1;
            }
        }
        // решение квадратного уравнения с a != 0
        else{

            *x1 = (-b + sqrt(D)) / (2 * a);
            *x2 = (-b - sqrt(D)) / (2 * a);
            return 2;
        }
    }


}

// функция вывода в зависимости от кол-ва корней уравнения
void finalOutput(double * x1, double*x2,
                 int nRoots){
    switch(nRoots){
        case 0: printf("Данное уравнения не имеет решений\n");break;
        case 1:
            printf("Данное уравнение имеет один корень x1 = %lf\n", *x1);
            break;
        case 2: printf("Данное уравнение имеет два корня x1 = %lf, x2 = %lf\n", *x1,*x2);break;
        case NO_VALID_NUMBERS: printf("Данное уравнение не имеет решений в действительных числах");break;
        case INFINITY_OF_ROOTS: printf("Данное уравнение имеет бесконечное количество решений\n");break;
        default: exit(1);
    }
}
void clearBuffer(){
    while(getchar() != '\n'){
        continue;
    }
}

