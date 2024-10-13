#ifndef __WORDLE_H__
#define __WORDLE_H__

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define MAX_WORDS 6

#define RESET   "\x1b[0m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define CYAN    "\x1b[36m"
#define BG_RED  "\x1b[41m"

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
} Wordle;


void start(Wordle * game);

void plays(Wordle * game, const char * word, const char * secret, int try);

int isGreen(Letter * game, const char ch, const char secret);

int isYellow(Wordle * game, const char ch, const char * secret, int i);

void board(const Wordle * flags, int try);

int win(const Wordle * flags);

void debugFlags(Wordle * flags);


#endif