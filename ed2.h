#ifndef __ED2_H__
#define __ED2_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
#define MAX_DB_CAP 1000

typedef struct{
    char word[SIZE];
    int priority;
} WordData;

typedef struct{
    WordData words[MAX_DB_CAP];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue * pq);

void enqueue(PriorityQueue * pq, const char * word, int prio);

WordData dequeue(PriorityQueue * pq);

void loadWordsFromFile(PriorityQueue * pq, const char * filename);

void suggestWord(PriorityQueue * pq);


#endif