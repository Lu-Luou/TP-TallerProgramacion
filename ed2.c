#include "ed2.h"

void initQueue(PriorityQueue * pq){
    pq->size = 0;
}

void enqueue(PriorityQueue * pq, const char * word, int prio){
    if(pq->size >= MAX_DB_CAP){
        printf("La cola de prioridad está llena.\n");
        return;
    }

    WordData newWord;
    strncpy(newWord.word, word, SIZE);
    newWord.priority = prio;

    int i = pq->size - 1;
    while(i >= 0 && pq->words[i].priority < prio){
        pq->words[i + 1] = pq->words[i];
        i--;
    }
    pq->words[i + 1] = newWord;
    pq->size++;
}

WordData dequeue(PriorityQueue * pq){
    if(pq->size == 0){
        printf("La cola de prioridad está vacía.\n");
        WordData empty = {"", -1};
        return empty;
    }
    return pq->words[--pq->size];
}

void loadWordsFromFile(PriorityQueue * pq, const char * filename){
    FILE *file = fopen(filename, "r");
    if(!file){
        perror("No se pudo abrir el archivo");
        return;
    }

    char word[SIZE];
    int priority;
    while(fscanf(file, "%5[^,],%d\n", word, &priority) == 2){
        enqueue(pq, word, priority);
    }

    fclose(file);
}

void suggestWord(PriorityQueue * pq){
    if(pq->size == 0){
        printf("No hay palabras en la cola.\n");
        return;
    }
    //necesitaríamos armar un filtro antes de desencolar la palabra con mayor prioridad
    WordData bestWord = dequeue(pq);
    printf("Sugerencia de palabra: %s (prioridad %d)\n", bestWord.word, bestWord.priority);
}