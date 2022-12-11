/******************************************************************************

Нововведенная рубрика "анегдот": Был один парень, которого заколдовал колдун и
он мог говорить только одно слово в год. Вот не говорил он 6 лет, накопил слов,
приходит к колдуну и говорит: -приходят русский,немец,еврей в бар... Колдун не 
                          выдержал и расколдовал его

*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <inttypes.h>
#include <assert.h>

const uint64_t consonanst = (
        1u << ('b' - 'a') | 1u << ('c' - 'a') | 1u << ('d' - 'a') | 1u << ('f' - 'a') | 1u << ('g' - 'a') |
        1u << ('h' - 'a') | 1u << ('j' - 'a') | 1u << ('k' - 'a') | 1u << ('l' - 'a') | 1u << ('m' - 'a') |
        1u << ('n' - 'a') | 1u << ('p' - 'a') | 1u << ('q' - 'a') | 1u << ('r' - 'a') | 1u << ('s' - 'a') |
        1u << ('t' - 'a') | 1u << ('v' - 'a') | 1u << ('w' - 'a') | 1u << ('x' - 'a') | 1u << ('z' - 'a')
);

bool is_NewWord (char symbol) {
    if (symbol == '\n' || symbol == ' ') {
        return 1;
    }
    return 0;
}

bool is_consonanst(char c) {
    uint64_t cNum = 1u << (c - 'a');

    if ((cNum & ~consonanst) == 0) return 1;
    return 0;
}

bool is_vowels(char c) {
    uint64_t cNum = 1u << (c - 'a');

    if ((cNum & consonanst) == 0) return 1;
    return 0;
}

bool is_letter(char c) {
    return ((c < 'a' || c > 'z') && (is_NewWord(c) == false));
}

typedef enum {
    NewWord,
    Word
} State; 

void test_is_NewWord() {
    assert(is_NewWord('\n') == 1);
    assert(is_NewWord(' ') == 1);
    assert(is_NewWord('a') == 0);
    assert(is_NewWord('f') == 0);
}

void test_is_consonanst() {
    assert(is_consonanst('z') == 1);
    assert(is_consonanst('x') == 1);
    assert(is_consonanst('s') == 1);
    assert(is_consonanst('i') == 0);
}

void test_is_vowels() {
    assert(is_vowels('z') == 0);
    assert(is_vowels('x') == 0);
    assert(is_vowels('s') == 0);
    assert(is_vowels('i') == 1);
}

void test_is_letter() {
    assert(is_letter('5') == 1);
    assert(is_letter('[') == 1);
    assert(is_letter('+') == 1);
    assert(is_letter('i') == 0);
}

void super_tests() {
    test_is_NewWord();
    test_is_consonanst();
    test_is_vowels();
    test_is_letter();
}

int main()
{
    super_tests();
    State state = NewWord;
    char c;
    int consonanst_counter = 0,
        vowels_counter = 0,
        n_words_counter = 0;
    while ((c = tolower(getchar())) != '1') {
        if(is_letter(c)){
            printf("Oops, something superfluous, I'm coming to an end");
            return 0;
        }
        switch (state){
            case NewWord:
                consonanst_counter = 0,
                vowels_counter = 0;
                state = Word;
            case Word:
                if(is_consonanst(c) && (is_NewWord(c) == 0)){
                    consonanst_counter++;
                }
                if(is_vowels(c) && (is_NewWord(c) == 0)){
                    
                    vowels_counter++;
                }
                if(is_NewWord(c)) {
                    state = NewWord;
                    if (consonanst_counter == 1 || vowels_counter == 1){
                        n_words_counter++;
                    }
                }
        }
    }
    printf("Numbers according to your parameters %d", n_words_counter);
}
