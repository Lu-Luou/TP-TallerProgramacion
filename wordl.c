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
        system(CLEAR);
        printf("ERROR: Ingrese una palabra de 5 letras: \n");
        scanf("%5s",word);
    }
    return word;
}

void debugFlags(Wordle * flags){
    for(int j = 0; j < SIZE; j ++){
        printf("%c - %d",
            flags->chs[j].ch,
            flags->chs[j].green ? 1 : (flags->chs[j].yellow ? 5 : 0)
            );
    }
    printf("\n");
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

    char* secret = getSecret(argv);
    char* word = (char *) malloc(SIZE * sizeof(char));

    Wordle flags[MAX_WORDS];
    start(flags);

    for(int i = 0; i < MAX_WORDS; i ++){
        //board(flags);

        word = getWord();

        plays(&flags[i], word, secret);
        //debugFlags(&flags[i]);

        if(win(flags)){
            board(flags);
            printf("\nWinner!!\n");
            return 0;
        }
    }
    board(flags);
    printf("\nLoser boo boo\n");

    free(word);
    free(secret);
    return 0;
}