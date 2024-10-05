#include "ed1.h"

void start(Wordle * game){
    game->try = 0;
    for (int i = 0; i < MAX_WORDS; i++){
        game->chs[i].ch = '\0';
        game->chs[i].green = 0;
        game->chs[i].yellow = 0;    
    }
}

void plays(Wordle * game, char * word, char * secret){
    for (int i = 0; i < MAX_WORDS; i++){
        game->chs[i].ch = word[i];

        if (word[i] == secret[i]){
            game->chs[i].green = 1;
        } else{
            game->chs[i].green = 0;

            for (int j = 0; j < MAX_WORDS; j++){
                if (word[i] == secret[j]){
                    game->chs[i].yellow = 1;
                    break;  
                } else{
                    game->chs[i].yellow = 0;
                }
            }
        }
    }
    game->try++;
}

void board(Wordle * flags){
    system(CLEAR);
}

int win(Wordle * flags){
    int count = 0;
    for(int i = 0; i < SIZE; i ++){
        count += flags->chs[i].green;              
    }
    return count == 5 ? 1 : 0;
}