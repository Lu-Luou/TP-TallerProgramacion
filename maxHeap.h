#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__

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
} MaxHeap;

void initHeap(MaxHeap *heap);

void swap(WordData *a, WordData *b);

void heapifyUp(MaxHeap *heap, int index);

void heapifyDown(MaxHeap *heap, int index);

void insert(MaxHeap *heap, const char *word, int priority);

WordData extractMax(MaxHeap *heap);


#endif