#include "machine.h"

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

int isValidWord(const WordData * wordData, const Wordle * game){
    for(int i = 0; i < SIZE; i++){
        char letter = wordData->word[i];

        if(game->chs[i].green && letter != game->chs[i].ch){ //filtra las letras verdes
            return 0;
        }

        if(game->chs[i].yellow){ // filtra las letras amarillas
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

void suggestWord(MaxHeap * heap, const Wordle * game, int attemps){
    WordData bestWord;
    int found = 0;

    while(heap->size > 0 && !found){
        WordData candidateWord = extractMax(heap);

        if(isValidWord(&candidateWord, &game[attemps])){
            bestWord = candidateWord;
            found = 1;
        }
    }

    if(found){
        printf("\nSugerencia de palabra: %s (frecuencia %d)\n\n", bestWord.word, bestWord.priority);
    } else{
        printf("\nNo es posible proporcionar una sugerencia =[\n\n");
    }
}