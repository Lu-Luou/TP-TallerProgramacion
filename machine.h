#ifndef __MACHINE_H__
#define __MACHINE_H__

#include <stdio.h>
#include <stdlib.h>
#include "wordle.h"
#include "maxHeap.h"


void loadWordsFromFile(MaxHeap *heap, const char *filename);

int isValidWord(const WordData *wordData, const Wordle *game);

void suggestWord(MaxHeap *heap, const Wordle *game);


#endif