#ifndef _JOGO_H_

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include "tad_pacman.h"

#define DELAY 70000
#define POSI_LIN_INICIAL 41/* posicao do centro do pacman no ncurses */
#define POSI_COL_INICIAL 41 /* posicao do centro do pacman no ncurses */

#define MAX_LIN 45 
#define MAX_COL 81 

#define BARREIRA -1
#define VAZIO 0
#define PASTILHA_NORMAL "."
#define PASTILHA_ESPECIAL "0"

struct labirinto {

    int qtdLin;
    int qtdCol; 
    int **matriz;
};

int inicializaJogo();
void finalizaJogo();
struct labirinto criaLabirinto();
void adicionaBarreiras(struct labirinto *labirinto); 
void criaBarreira(struct labirinto *labirinto, int linha, int qtdLinhas,
 int coluna, int qtdColunas);
void mostraLabirinto();
void mostraLayout();
void movePacman(int direcao, struct pacman *pacman);
int pegaTecla();
int checaColizao(struct labirinto *labirinto, int direcao, struct pacman *pacman);
int posicaoNcursesParaMatriz(int posicao);

#endif