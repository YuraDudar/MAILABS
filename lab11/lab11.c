/*********************************************************************************
Если Яндекс показывает совершенно ясную погоду, а на небе собирается грозовая туча 
                          - не верь своим глазам .
**********************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    NewWord,
    Number
} State; 

bool max_of(int a, int b){
    return (a > b) ? 1 : 0;
}

bool is_NewWord(char symbol) {
    return (symbol == '\n' || symbol == '\t' || symbol == ',' || symbol == ' ') ? 1 : 0;
}

bool is_Number(char symbol) {
    return (symbol >= '0' && symbol <= '9' || symbol >= 'a' && symbol <= 'f') ? 1 : 0;
}

char append(char str1[], char str2[]){
    strcat(str1, str2);
}

int numbers_counter(int n, char binNumber[n]){
    bool flag = true;
    int num_counter = 0;
    for(int i = 0; i < n*4; i++){
        if((binNumber[i] != '0') && (flag == true)){
            flag = false;
        }   
        if(flag == false){
            num_counter++;
        }
    }
    return num_counter;
}

char hex_to_bin(int n, char * hexNumber){
    char binNumber[1000] = "";
    char c;
    for (int i = 0; i < n*4; i++){
        c = hexNumber[i];
        switch (c){
            case '0' : append(binNumber,"0000");
            case '1' : append(binNumber,"0001");
            case '2' : append(binNumber,"0010");
            case '3' : append(binNumber,"0011");
            case '4' : append(binNumber,"0100");
            case '5' : append(binNumber,"0101");
            case '6' : append(binNumber,"0110");
            case '7' : append(binNumber,"0111");
            case '8' : append(binNumber,"1000");
            case '9' : append(binNumber,"1001");
            case 'a' : append(binNumber,"1010");
            case 'b' : append(binNumber,"1011");
            case 'c' : append(binNumber,"1100");
            case 'd' : append(binNumber,"1101");
            case 'e' : append(binNumber,"1110");
            case 'f' : append(binNumber,"1111");
        }
    }
    return numbers_counter(n,binNumber);
}

void printArray (int n, char array [n]) {
    for (int i = 0; i < n; i++) {
        printf("%c", array [i]);
    }
    printf("\n");
}

void test_max_of() {
    assert(max_of(5,4) == 1);
    assert(max_of(4,5) == 0);
}

void test_is_NewWord() {
    assert(is_NewWord(' ') == 1);
    assert(is_NewWord('4') == 0);
}

void test_is_Number() {
    assert(is_Number('4') == 1);
    assert(is_Number(']') == 0);
}

void test_hex_to_bin() {
    assert(hex_to_bin(6,"adadad") == 24);
    assert(hex_to_bin(2,"cc") == 8);
}

void super_tests() {
    test_max_of();
    test_is_NewWord();
    test_is_Number();
    test_hex_to_bin();
}

int main () {
    super_tests();
    int max_value = 0;
    int ch_num = 0;
    State state = NewWord;
    char symbol, *number, *largest_number;
    largest_number = (char *) malloc(1);
    int i = 0, summ = 0, firstZero = 0;
    bool flag = true;
    while ((symbol = tolower(getchar())) != '+') {
        switch (state) {
            case NewWord:
                number = (char *) malloc(1);
                if (is_Number(symbol)) {
                    firstZero = symbol - '0';
                    if (firstZero == 0) {
                        break;
                    }
                    else {
                        flag = false;
                    }
                    state = Number;
                    number [i] = symbol;
                    i++;
                    number = (char *) realloc(number, i + 1);
                    break;
                }
            case Number:
                if (is_Number(symbol)) {
                    if (flag) {
                        firstZero = symbol - '0';
                        if (firstZero == 0) {
                            flag = true;
                            break;
                        }
                        else {
                            flag = false;
                        }
                    }
                    number [i] = symbol;
                    i++;
                    if(i > 8){
                        printf("I accept only 8 numbers for input");
                        return 0;
                    }
                    number = (char *) realloc(number, i + 1);
                    break;
                }
                if (is_NewWord(symbol)) {
                    ch_num = hex_to_bin(i,number);
                    if(max_of(ch_num,max_value)){
                        max_value = ch_num;
                        strcpy(largest_number, number);
                    }
                    printf("%d ",hex_to_bin(i,number));
                    state = NewWord;
                    printArray(i, number);
                    i = 0;
                    free(number);
                }else{
                    printf("Oops, something superfluous, I'm coming to an end");
                    return 0;
                }
                break;
                
        }
    }
    printArray(strlen(largest_number),largest_number);
    return 0;
}
