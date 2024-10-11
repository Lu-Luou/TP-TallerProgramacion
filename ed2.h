#ifndef __ED2_H__
#define __ED2_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 6 // 5 + '\0' = 6
#define MAX_DB_CAP 5000

typedef struct{
    char word[WORD_LEN];
    int priority;
} WordData;

typedef struct{
    WordData words[MAX_DB_CAP];
    int size;
} MinHeap;

void initHeap(MinHeap *heap);

void swap(WordData *a, WordData *b);

void heapifyUp(MinHeap *heap, int index);

void heapifyDown(MinHeap *heap, int index);

void insert(MinHeap *heap, const char *word, int priority);

WordData extractMin(MinHeap *heap);


#endif