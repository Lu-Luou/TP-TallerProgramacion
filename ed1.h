#ifndef ed1_H
#define ed1_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 5
#define MAX_WORDS 6

typedef struct letras {
    char ch;
    bool green;
    bool yellow;
} Words;

typedef struct palabras {
    Words chs[SIZE];
    int try;
} Wordle;


void start(Wordle * game);

void flags(Wordle * game, char * word, char * secret);


#endif