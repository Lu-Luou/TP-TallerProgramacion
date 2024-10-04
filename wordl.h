#ifndef world_H
#define world_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

//colores
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_CYAN    "\x1b[36m"

//consts
#define SIZE 5
#define MAX_WORDS 6
#ifdef _WIN32_
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

//funciones
char* getWord(char const **arg);

int* review(char * word, char * secret);


#endif