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
} Letter;

typedef struct palabras {
    Letter chs[SIZE];
    int try;
} Wordle;


void start(Wordle * game);

void plays(Wordle * game, char * word, char * secret);

void isGreen(Letter * game, char ch, char secret);

void isYellow(Wordle * game, char ch, char * secret, int i);

void board(Wordle * flags);

int win(Wordle * flags);


#endif