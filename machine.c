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

// REVISAR
int isValidWord(const WordData * wordData, const Wordle * game){
    for(int i = 0; i < SIZE; i++){
        char letter = wordData->word[i];

        if(game->chs[i].green && letter != game->chs[i].ch){
            return 0;
        }

        if(game->chs[i].yellow){
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

        if(!game->chs[i].green && !game->chs[i].yellow){
            for(int j = 0; j < SIZE; j++){
                if(wordData->word[j] == game->chs[i].ch){
                    return 0;
                }
            }
        }
    }
    return 1;
}

void suggestWord(MaxHeap * heap, const Wordle * game){
    WordData bestWord;
    int found = 0;

    while(heap->size > 0 && !found){ //found(); (?
        WordData candidateWord = extractMax(heap);

        if(isValidWord(&candidateWord, game)){
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


/*int main(void){ //testing
    MaxHeap heap;
    initHeap(&heap);
    loadWordsFromFile(&heap, "DB/3.txt"); // nombre/del/directorio/archivo.txt

    suggestWord(&heap);

    return 0;
}
*/