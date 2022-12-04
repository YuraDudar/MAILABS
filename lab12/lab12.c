#include <stdio.h>
#include <assert.h>

long long int my_abs(long long int n){
	return (n >= 0) ? n : 0 - n;
}

long long int counters_search(long long int n){
    n = my_abs(n);
    long long int temp = n%10,
                         k = 0;
    n/=10;
    while(n>0){
        if(n%10 == temp){
            k++;
        }
        temp = n%10;
        n /= 10;
    }
    return k;
}

int main(){
    long long int n = 0,
                  k = 0;
    printf("Enter number:");
    scanf("%lld", &n);
    k = counters_search(n);
    printf("Number of pairs: %lld", k);
    return 0;
}

void test_my_abs() {
    assert(my_abs(-1) == 1);
    assert(my_abs(-5) == 5);
    assert(my_abs(5) == 5);
    assert(my_abs(1) == 1);
    assert(my_abs(-10000000000) == 10000000000);
}

void test_counters_search() {
    assert(counters_search(-1) == 0);
    assert(counters_search(0) == 0);
    assert(counters_search(11) == 1);
    assert(counters_search(1114111234) == 4);
    assert(counters_search(11223344) == 4);
}

