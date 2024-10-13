#include "machine.h"

char usedWords[MAX_WORDS][WORD_LEN];
int usedWordsCount = 0;


void loadWordsFromFile(MaxHeap * heap, const char * filename){
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

void addUsedWord(const char * word){
    if(usedWordsCount < MAX_WORDS){
        strncpy(usedWords[usedWordsCount], word, WORD_LEN);
        usedWordsCount++;
    }
}

int isWordUsed(const char * word){
    for(int i = 0; i < usedWordsCount; i++){
        if(strcmp(usedWords[i], word) == 0){
            return 1;
        }
    }
    return 0;
}

int isValidWord(const WordData * wordData, const Wordle * game){
    if(isWordUsed(wordData->word)){
        return 0;
    }
    for(int i = 0; i < SIZE; i++){
        char letter = wordData->word[i];

        if(game->chs[i].green && letter != game->chs[i].ch){ // Filtra las letras verdes
            return 0;
        }

        if(game->chs[i].yellow){ // Filtra las letras amarillas
            int found = 0;

            for(int j = 0; j < SIZE && !found; j++){
                if(wordData->word[j] == game->chs[i].ch && i != j){
                    found = 1;
                }
            }

            if(!found){
                return 0;
            }
        }
    }
    return 1;
}

void suggestWord(MaxHeap * heap, const Wordle * game, int attempts){
    MaxHeap auxHeap;
    initHeap(&auxHeap);

    while(heap->size > 0){
        WordData candidateWord = extractMax(heap);

        if(isValidWord(&candidateWord, &game[attempts])){
            insert(&auxHeap, candidateWord.word, candidateWord.priority);
        }
    }

    *heap = auxHeap;

    if(auxHeap.size > 0){
        printf("\nSugerencia de palabra: %s (frecuencia %d)\n\n", heap->words[0].word, heap->words[0].priority);
    } else{
        printf("\nNo es posible proporcionar una sugerencia =[\n\n");
    }
}