#include <stdio.h>
#include <math.h>
#include <float.h>

//Метод дихотомии
long double func_18(long double x){
    // x + sqrtl(x) + cbrtl(x) - 2.5
    return x + sqrtl(x) + cbrtl(x) - 2.5;
}

long double dixit(long double (*f)(long double), long double a, long double b){
    long double c;
    long double ans;
    while (fabsl(a - b) > LDBL_EPSILON) {
        c = (a + b) / 2.0;
        if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    ans = c;
    return ans;
}

//Метод итерации
//Численное вырожение первой производной 
long double derive(long double (*f)(long double), long double x){
    long double prib = 1e-6;
    long double ans = (f(x + prib) - f(x)) / prib;
    return ans;
}

long double func_19(long double x) {
    // x = 1 / (3 + sinl(3.6 * x))
    return 1 / (3 + sinl(3.6 * x));
}

long double func_19_hands(long double x) {
    return -(18*cosl(3.6*x)/(5*powl((3+sinl(3.6*x)),2)));
}

//Проверка на сходимость итерации
int is_iterat(long double (*f)(long double), long double (*hands)(long double), long double a, long double b) {
    long double step = (b-a)/100000;
    for (long double x=a; x<=b; x+=step) {
        if (derive(f, x) >= 1 || hands(x) >= 1) {
            return 0;
        }
    }
    return 1;
}

//Компьютерный метод
long double iterat(long double (*f)(long double), long double a, long double b) {
    long double x = (a + b) / 2.0;
    long double x1 = f(x);
    while (fabsl(x1 - x) >= LDBL_EPSILON) {
        x = x1;
        x1 = f(x);
    }
    return x1;
}

int main() {
    //18 функция
    long double a = 0.4, 
                b = 1;
    printf("Func 18: x + sqrtl(x) + cbrtl(x) - 2.5 = 0 Method: dixit.\n%.19Lf", dixit(func_18, a, b));
    
    printf("\n\n");
    
    //19 функция
    a = 0.0;
    b = 0.85;
    printf("Func 19: x - 1 / (3 + sin(3.6x)) = 0 Method: iterations.\n");
    if (is_iterat(func_19, func_19_hands, a, b)) {
        printf("Method is covergent.\n");
        printf("Approximated root of the equation: %.19Lf\n", iterat(func_19, a, b));
    } else {
        printf("Method is not covergent.\n");
    }
    return 0;
}
