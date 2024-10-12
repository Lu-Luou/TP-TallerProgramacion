#include "ed2.h"

void initHeap(MinHeap * heap){
    heap->size = 0;
}

void swap(WordData * a, WordData * b){
    WordData temp = *a;
    *a = *b;
    *b = temp;
}

/* Funciones antiguas que ordenaban el heap de forma alfabetica en vez de por prioridad
 * Esto se dejo por su mala eficiencia en la practica al jugar el wordle
void heapifyUp(MinHeap * heap, int index){
    if(index == 0) return;

    int parentIndex = (index - 1) / 2;
    if(strcmp(heap->words[index].word, heap->words[parentIndex].word) < 0){
        swap(&heap->words[index], &heap->words[parentIndex]);
        heapifyUp(heap, parentIndex);
    }
}

void heapifyDown(MinHeap * heap, int index){
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if(leftChild < heap->size && strcmp(heap->words[leftChild].word, heap->words[smallest].word) < 0){
        smallest = leftChild;
    }
    if(rightChild < heap->size && strcmp(heap->words[rightChild].word, heap->words[smallest].word) < 0){
        smallest = rightChild;
    }
    if(smallest != index){
        swap(&heap->words[index], &heap->words[smallest]);
        heapifyDown(heap, smallest);
    }
}
*/

// Funcion para "flotar" un nodo en el heap
void heapifyUp(MinHeap *heap, int index) {
    if (index == 0) return;

    int parentIndex = (index - 1) / 2;

    if (heap->words[index].priority < heap->words[parentIndex].priority) {
        swap(&heap->words[index], &heap->words[parentIndex]);
        heapifyUp(heap, parentIndex);
    }
}

// Funcion para "hundir" un nodo en el heap
void heapifyDown(MinHeap *heap, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < heap->size && heap->words[leftChild].priority < heap->words[smallest].priority) {
        smallest = leftChild;
    }
    if (rightChild < heap->size && heap->words[rightChild].priority < heap->words[smallest].priority) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&heap->words[index], &heap->words[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insert(MinHeap * heap, const char * word, int priority){
    if(heap->size >= MAX_DB_CAP){
        printf("El heap esta lleno.\n");
        return;
    }

    WordData newWord;
    strncpy(newWord.word, word, WORD_LEN);
    newWord.priority = priority;

    heap->words[heap->size] = newWord;
    heapifyUp(heap, heap->size);
    heap->size++;
}

WordData extractMin(MinHeap * heap){
    if(heap->size == 0){
        printf("El heap esta vacio.\n");
        WordData empty = {"", -1};
        return empty;
    }

    WordData minWord = heap->words[0];
    heap->words[0] = heap->words[--heap->size];
    heapifyDown(heap, 0);

    return minWord;
}