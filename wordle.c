#include "wordle.h"

void start(Wordle *game) {
    for (int i = 0; i < MAX_WORDS; i++){
        for (int j = 0; j < SIZE; j++){
            game[i].chs[j].ch = '\0';
            game[i].chs[j].green = 0;
            game[i].chs[j].yellow = 0;    
        }
    }
}

void plays(Wordle * game, char * word, char * secret, int try){
    for(int i = 0; i < SIZE; i++){
        game[try].chs[i].ch = word[i];
        isGreen(&game[try].chs[i], word[i], secret[i]);
    }

    for(int i = 0; i < SIZE; i++){
        isYellow(&game[try], word[i], secret, i);
    }
}

int isGreen(Letter * chs, char ch, char secret){
    if(ch == secret)
        chs->green = 1;
    return chs->green;
}

int isYellow(Wordle * game, char ch, char * secret, int i){
    if(!game->chs[i].green){
        for(int j = 0; j < SIZE; j++){
            if(secret[j] == ch && !game->chs[j].green){
                game->chs[i].yellow = 1;
                return 1;
            }
        }
    }
    return 0;
}

void board(Wordle * game, int try){
    system(CLEAR);
    printf(BG_RED "Intentos restantes: %d\n" RESET, MAX_WORDS - try);

    for(int i = 0; i <= try; i++){
        for(int j = 0; j < SIZE; j++){
            Letter letter = game[i].chs[j];

            if(letter.green){
                printf(GREEN "%c " RESET, letter.ch);
            } else if(letter.yellow){
                printf(YELLOW "%c " RESET, letter.ch);
            } else{
                printf(CYAN "%c " RESET, letter.ch);
            }
        }
        printf("\n");
    }
}

int win(Wordle * flags){
    for (int i = 0; i < SIZE; i++){
        if (!flags->chs[i].green){
            return 0;
        }
    }
    return 1;
}

void debugFlags(Wordle * flags){
    for(int j = 0; j < SIZE; j ++){
        printf("%c - %d  ",
            flags->chs[j].ch,
            flags->chs[j].green ? 1 : (flags->chs[j].yellow ? 5 : 0)
            );
    }
    printf("\n");
}