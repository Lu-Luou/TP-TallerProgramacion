#include "wordl.h"

char* getSecret(char const ** arg){
    if(strlen(arg[1]) != SIZE){
        printf("Necesitamos una palabra de 5 letras");
        return NULL;
    }

    char* str = (char *) malloc(SIZE * sizeof(char));
    strcpy(str, arg[1]);
    return str;
}

char* getWord(){
    char * word = (char *) malloc(SIZE * sizeof(char));

    printf("Ingrese una palabra de 5 letras: \n");
    scanf("%s",word);
    while(strlen(word) != 5){
        printf("ERROR: Ingrese una palabra de 5 letras: \n");
        scanf("%5s",word);
    }
    return word;
}


int main(int argc, const char ** argv){
    if(argc < 1){
        printf("Se necesita una palabra de 5 letras");
        return 0;
    }
    if(strlen(argv[1]) != 5){
        printf("Se necesita una palabra de 5 letras");
        return 0;
    }       

    char * secret = getSecret(argv);
    char * word = (char *) malloc(SIZE * sizeof(char));

    Wordle flags[MAX_WORDS];
    start(flags);

    int intentos = 0;
    for(; intentos < MAX_WORDS; intentos ++){
        //board(flags, intentos);

        word = getWord();

        plays(&flags[intentos], word, secret, intentos);
        debugFlags(&flags[intentos]);

        if(win(&flags[intentos])){
            board(flags, intentos);
            printf("\nWinner!!\n");
            return 0;
        }
    }

    board(flags, intentos);
    printf("\nLoser boo boo\n");

    free(word);
    free(secret);
    return 0;
}