#include "tad_pacman.h"

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

struct pacman criaPacman(){

    struct pacman temp;

    temp.largura = temp.altura = TAM_PACMAN;

    temp.vidas = temp.vivo = 1;

    return temp;
}