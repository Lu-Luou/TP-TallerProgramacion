#include "maxHeap.h"

void initHeap(MaxHeap * heap){
    heap->size = 0;
}

void swap(WordData * a, WordData * b){
    WordData temp = *a;
    *a = *b;
    *b = temp;
}

// Funcion para "flotar" un nodo en el heap al insertar
void heapifyUp(MaxHeap *heap, int index){
    if(index == 0) return;

    int parentIndex = (index - 1) / 2;

    if(heap->words[index].priority > heap->words[parentIndex].priority){
        swap(&heap->words[index], &heap->words[parentIndex]);
        heapifyUp(heap, parentIndex);
    }
}

// Funcion para "hundir" un nodo en el heap al eliminar
void heapifyDown(MaxHeap *heap, int index){
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if(leftChild < heap->size && heap->words[leftChild].priority > heap->words[smallest].priority){
        smallest = leftChild;
    }
    if(rightChild < heap->size && heap->words[rightChild].priority > heap->words[smallest].priority){
        smallest = rightChild;
    }

    if(smallest != index){
        swap(&heap->words[index], &heap->words[smallest]);
        heapifyDown(heap, smallest);
    }
}

void insert(MaxHeap * heap, const char * word, int priority){
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

WordData extractMax(MaxHeap * heap){
    if(heap->size == 0){
        printf("El heap esta vacio.\n");
        WordData empty = {"", -1};
        return empty;
    }

    WordData maxWord = heap->words[0];
    heap->words[0] = heap->words[--heap->size];
    heapifyDown(heap, 0);

    return maxWord;
}