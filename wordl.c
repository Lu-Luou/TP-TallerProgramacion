#include "wordl.h"

char* getWord(char const **arg){
    if(strlen(arg[1]) != SIZE){
        printf("Necesitamos una palabra de 5 letras");
        return NULL;
    }

    char* str = (char *) malloc(SIZE * sizeof(char));
    strcpy(str, arg[1]);
    return str;
}

int* review(char * word, char * secret){
    int * buff = (int *) malloc(SIZE * sizeof(int));

    for(int i = 0; i < SIZE; i ++){    
        if(word[i] == secret[i])
            buff[i] = 1;
        else{
            buff[i] = (strchr(secret, word[i]) != NULL) ? 5 : 0;
        }
    }
    return buff;
}

int win(int * flags){
    int count = 0;
    for(int i = 0; i < SIZE; i++){
        count += flags[i];
    }

    return count == 5 ? 1 : 0;
}

void showBoard (char * word, int * flags){
    system(CLEAR);
}

void freeMemory(char * arg1, int * arg2){
    free(arg1);
    arg1 = NULL;

    free(arg2);
    arg2 = NULL;
}

int main (int argc, char const **argv){ //aun no se implemento la estructura de datos from "ed1"
    if(argc < 1){
        printf("Se necesita una palabra de 5 letras");
        return 0;
    }
    if(strlen(argv[1]) != 5){
        printf("Se necesita una palabra de 5 letras");
        return 0;
    }       

    char* secret = getWord(argv);
    char word[SIZE];
    int* flags = NULL;

    for(int i = 0; i < MAX_WORDS; i ++){
        showBoard(word, flags);

        printf("Ingrese una palabra de 5 letras: \n");
        scanf("%s",word);
        if(strlen(word) != 5){
            while(strlen(word) != 5){
                system(CLEAR);
                printf("ERROR: Ingrese una palabra de 5 letras: \n");
                scanf("%5s",word);
            }
        }

        flags = review(word, secret);

        if(win(flags)){
            showBoard(word, flags);
            printf("\nWinner!!\n");
            return 0;
        }
    }
    showBoard(word, flags);
    printf("\nLoser boo boo\n");

    freeMemory(secret, flags); //consultar si funciona
    return 0;
}