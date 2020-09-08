#include "tad_pacman.h"

/* faz a movimentacao do pacman */
void movePacman(int direcao, struct pacman *pacman){

    switch ( direcao ){
        case KEY_UP :
            pacman->posiLin -= 1;
            break;

        case KEY_DOWN :
            pacman->posiLin += 1;
            break;
        
        case KEY_LEFT :
            pacman->posiCol -= 1;
            break;
        
        case KEY_RIGHT :
            pacman->posiCol += 1;
            break;
    }

    return;
}

/* mostra o pacman */
void mostraPacman(int linha, int coluna){
    int x, y;

    for (y = linha - 1; y <= linha + 1 ; y++){
        for (x = coluna - 1; x <= coluna + 1 ; x++){
            attron( A_REVERSE | COLOR_PAIR(2));
            mvprintw(y, x, " ");
            attroff(COLOR_PAIR(2));
        }
    }

    mvprintw(y, x, "%d %d", linha, coluna);

    return;
}

/* cria pacman */
struct pacman *criaPacman(){

    struct pacman *temp;

    temp = malloc(sizeof(struct pacman));

    temp->largura = temp->altura = TAM_PACMAN;

    temp->vidas = temp->vivo = 1;

    return temp;
}