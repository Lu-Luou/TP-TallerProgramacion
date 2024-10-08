#include "ed1.h"

void start(Wordle * game){
    game->try = 0;
    for(int i = 0; i < MAX_WORDS; i++){
        game->chs[i].ch = '\0';
        game->chs[i].green = 0;
        game->chs[i].yellow = 0;    
    }
}

void plays(Wordle * game, char * word, char * secret){
    for(int i = 0; i < SIZE; i++){
        game->chs[i].ch = word[i];
        
        isGreen(&game->chs[i], word[i], secret[i]);
        isYellow(game, word[i], secret, i);
    }
    game->try++;//dudoso
}

void isGreen(Letter * chs, char ch, char secret){
    if(ch == secret)
        chs->green = 1;
}

void isYellow(Wordle * game, char ch, char * secret, int i){
    if(!(game->chs[i].green)){
        int j = 0;
        for(; j < SIZE && (secret[j] != ch); j++){
            if(secret[j] == ch && (ch != game->chs[j].ch))
                game->chs[i].yellow = 1;
        }
    }
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