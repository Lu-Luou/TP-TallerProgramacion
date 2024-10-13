#ifndef __WORDL_H__
#define __WORDL_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "wordle.h"
#include "machine.h"

//funciones
char* getSecret(char const **arg);

char* getWord();

void debugFlags(Wordle * flags);


#endif