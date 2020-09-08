#ifndef _PACMAN_H_

#include <stdlib.h>
#include <ncurses.h>

#define PACMAN 1
#define TAM_PACMAN 3

struct pacman {

    int altura;
    int largura;
    int posiCol; /* valor referente ao ncurses */
    int posiLin; /* valor referente ao ncurses */
    int vidas;
    int vivo;
};

void movePacman(int direcao, struct pacman *pacman);
void mostraPacman(int linha, int coluna);
struct pacman *criaPacman();

#endif