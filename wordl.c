#include "wordl.h"

char* getWord(char const **arg){
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
            if (strstr(word + i, secret))
                buff[i] = 2;
            else
                buff[i] = 0;
        }
    }
    return buff;
}

int main (int argc, char const **argv){
    if(argc < 1){
        printf("Se necesita una base de datos");
        return 0;
    }

    char* secret = getWord(argv);
    char word[SIZE];
    int* flags;

    for(int i = 0; i < MAX_WORDS && strcmp(word, secret) ; i ++){
        printf("Ingrese una palabra para empezar: \n");
        scanf("%s",word);

        flags = review(word, secret);
        
        for(int i = 0; i < SIZE; i++){
            printf("%d", flags[i]);
        }
        printf("\n");
    }
    
    return 0;
}