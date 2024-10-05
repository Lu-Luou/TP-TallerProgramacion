#ifndef __ED1_H__
#define __ED1_H__

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define MAX_WORDS 6

#ifdef _WIN32_
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

typedef struct letras {
    char ch;
    int green;
    int yellow;
} Words;

typedef struct palabras {
    Words chs[SIZE];
    int try;
} Wordle;


void start(Wordle * game);

void plays(Wordle * game, char * word, char * secret);

void board(Wordle * flags);

int win(Wordle * flags);


#endif