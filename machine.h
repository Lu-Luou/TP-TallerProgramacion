#ifndef __MACHINE_H__
#define __MACHINE_H__

#include <stdio.h>
#include <stdlib.h>     
#include "ed2.h"

void loadWordsFromFile(MinHeap *heap, const char *filename);

void suggestWord(MinHeap *heap);


#endif