#ifndef __WORDL_H__
#define __WORDL_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
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

//funciones
char* getWord(char const **arg);


#endif