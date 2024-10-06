#include "wordl.h"

char* getWord(char const ** arg){
    if(strlen(arg[1]) != SIZE){
        printf("Necesitamos una palabra de 5 letras");
        return NULL;
    }

    char* str = (char *) malloc(SIZE * sizeof(char));
    strcpy(str, arg[1]);
    return str;
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

    char* secret = getWord(argv);
    char word[SIZE];

    Wordle flags[MAX_WORDS];
    start(flags);

    for(int i = 0; i < MAX_WORDS; i ++){
        //board(flags);

        printf("Ingrese una palabra de 5 letras: \n");
        scanf("%s",word);
        while(strlen(word) != 5){
            system(CLEAR);
            printf("ERROR: Ingrese una palabra de 5 letras: \n");
            scanf("%5s",word);
        }

        plays(&flags[i], word, secret);
        // debug flags
        /*for(int j = 0; j < SIZE; j ++){
            printf("%c - %d", flags[i].chs[j].ch, flags[i].chs[j].green ? 1 : (flags[i].chs[j].yellow ? 5 : 0));
        }
        printf("\n");*/

        if(win(flags)){
            board(flags);
            printf("\nWinner!!\n");
            return 0;
        }
    }
    board(flags);
    printf("\nLoser boo boo\n");

    free(secret);
    return 0;
}