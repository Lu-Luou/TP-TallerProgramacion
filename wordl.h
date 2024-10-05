#ifndef world_H
#define world_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "ed1.h"
#include "machine.h"

//colores letra
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define CYAN    "\x1b[36m"
#define RESET   "\033[0m"
//colores background
#define BG_RED    "\x1b[41m"
#define BG_GREEN  "\x1b[42m"
#define BG_YELLOW "\x1b[43m"
#define BG_BLACK  "\033[40m"
#define BG_WHITE  "\x1b[47m"

//consts
#ifdef _WIN32_
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

//funciones
char* getWord(char const **arg);

int* review(char * word, char * secret);

int win(int * flags);

void showBoard (char * word, int * flags);

void freeMemory(char * arg1, int * arg2);


#endif