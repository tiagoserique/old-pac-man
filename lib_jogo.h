#ifndef _JOGO_H_

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "tad_pacman.h"

#define DELAY 70000
#define POSI_LIN_INICIAL 41 /* posicao do centro do pacman no ncurses */
#define POSI_COL_INICIAL 41 /* posicao do centro do pacman no ncurses */

#define MAX_LIN 45 /* maximo de linhas da matriz */
#define MAX_COL 81 /* maximo de colunas da matriz */

#define BARREIRA -1
#define VAZIO 0
#define PASTILHA_NORMAL 1
#define PASTILHA_ESPECIAL 2

struct labirinto {

    int qtdLin;
    int qtdCol; 
    int **matriz;
};

int inicializaJogo();
void finalizaJogo();
struct labirinto *criaLabirinto();
void adicionaBarreiras(struct labirinto *labirinto); 
void criaBarreira(struct labirinto *labirinto, int linha, int qtdLinhas,
 int coluna, int qtdColunas);
void mostraLabirinto(struct labirinto *labirinto);
void mostraLayout();
int pegaTecla();
int checaColizao(struct labirinto *labirinto, int direcao, struct pacman *pacman);
int convertePosicoes(int posicao);
void adicionaPastilha(struct labirinto *labirinto);
void criaPastilha(struct labirinto *labirinto, int linha, int coluna);
int temPastilha(struct labirinto *labirinto);

void atravessaMapa(struct pacman *pacman);


#endif