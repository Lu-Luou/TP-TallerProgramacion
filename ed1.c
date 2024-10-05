#include "ed1.h"

void startGame(Wordle * game){
    game->try = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        game->chs[i].ch = '\0';
        game->chs[i].green = false;
        game->chs[i].yellow = false;    
    }
}

void addTry (Wordle * game, char * word, char * secret){
    for (int i = 0; i < MAX_WORDS; i++){
        game->chs[i].ch = word[i];

        if (word[i] == secret[i]){
            game->chs[i].green = true;
        } else{
            game->chs[i].green = false;

            for (int j = 0; j < MAX_WORDS; j++){
                if (word[i] == secret[j]){
                    game->chs[i].yellow = true;
                    break;  
                } else{
                    game->chs[i].yellow = false;
                }
            }
        }
    }
    game->try++;
}