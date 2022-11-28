//блок объявления библиотек 
#include <stdio.h>

//блок функций
int max(int a, int b){
	return (a >= b) ? a : b;
}

int min(int a, int b){
	return (a < b) ? a : b;
}

int abs(int a){
	return (a >= 0) ? a : 0 - a;
}

int ne_pow(int a, int b){
	for (int i = 1; i < b; i++)
		a *= a;
	return a;
}

//проверка попадания
int EstLiProbitie(int i, int j) {
    return ((10 <= i && i <= 30) && (-5 <= j && j <= 5));
}

//отрисовка движения
int otrisovkaDvizjenia(int i, int j, int l) {
    int ni, nj, nl, k = 0;
    while (k <= 50) {
        if (EstLiProbitie(i, j) == 1) {
            printf("Есть пробитие i=%d j=%d l=%d k=%d", i, j, l, k);
            return 1;
        }
        
        ni = abs(max(min(i + j, i + l) % 30, max(i + l, j + k) % 25));
		nj = abs(i + k) % 10 + abs(j + k) % 10 + abs(l + k) % 10;
		nl = (ne_pow(i, 3) + ne_pow(j, 3) + ne_pow(l, 3) - k) % 35;
		
		i = ni;
		j = nj;
		l = nl;
		
        ++k;
    }

    printf("Нет пробития i=%d j=%d l=%d k=%d", i, j, l, k);
    return 0;
}

//функция main
int main()
{
    otrisovkaDvizjenia(-10, -10, 6);
    return 0;
}
