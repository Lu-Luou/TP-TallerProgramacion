#include "machine.h"

void loadWordsFromFile(MinHeap * heap, const char * filename){
    FILE * file = fopen(filename, "r");
    if(!file){
        perror("No se pudo abrir el archivo");
        return;
    }

    char word[WORD_LEN];
    int priority;
    while(fscanf(file, "%5[^,],%d\n", word, &priority) == 2){
        insert(heap, word, priority);
    }

    fclose(file);
}

// Funcion que va a sugerir la palabra alfabeticamente menor
// Se necesita armar alguna clase de "filtro" para que sugiera la palabra en base a un "Wordle game" especifico
void suggestWord(MinHeap * heap){
    if(heap->size == 0){
        printf("No hay palabras en el heap.\n");
        return;
    }

    WordData bestWord = extractMin(heap);
    printf("Sugerencia de palabra: %s (indice %d)\n", bestWord.word, bestWord.priority);
}

/*int main(void){ //testing
    MinHeap heap;
    initHeap(&heap);
    loadWordsFromFile(&heap, "DB/3.txt"); // nombre/del/directorio/archivo.txt

    suggestWord(&heap);

    return 0;
}
*/