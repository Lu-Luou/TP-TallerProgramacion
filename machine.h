#ifndef __MACHINE_H__
#define __MACHINE_H__

#include <stdio.h>
#include <stdlib.h>
#include "ed1.h"
#include "ed2.h"


void loadWordsFromFile(MinHeap *heap, const char *filename);

int isValidWord(const WordData *wordData, const Wordle *game);

void suggestWord(MinHeap *heap, const Wordle *game);


#endif