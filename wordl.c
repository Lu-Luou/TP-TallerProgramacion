#include "wordl.h"
#include "ed1.c"
#include "machine.c"

char* getWord(char const **arg){
    if(strlen(arg[1]) != SIZE){
        printf("Se necesita una palabra de 5 letras");
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

int main (int argc, char const **argv){
    if(argc < 1){
        printf("Se necesita una base de datos");
        return 0;
    }

    char* secret = getWord(argv);
    char word[SIZE];
    int* flags;

    for(int i = 0; i < MAX_WORDS; i ++){
        printf("Ingrese una palabra para empezar de 5 letras: \n");
        scanf("%s",word);
        if(strlen(word) != 5){
            while(strlen(word) != 5){
                printf("Ingrese una palabra para empezar de 5 letras: \n");
                scanf("%5s",word);
            }
        }

        flags = review(word, secret);

        for(int i = 0; i < SIZE; i++){
            printf("%d", flags[i]);
        }
        printf("\n");

        if(win(flags)){
            printf("\nWinner!!\n");
            return 0;
        }
    }

    printf("\nLoser boo boo\n");
    return 0;
}