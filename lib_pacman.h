
#ifndef _PACMAN_H_

#define MAX_LIN 45 /*45 linhas*/
#define MAX_COL 81 /*81 colunas*/
#define BARREIRA "="
#define VAZIO " "
#define PASTILHA_NORMAL "."
#define PASTILHA_ESPECIAL "0"

struct labirinto {
    int qtdLin;
    int qtdCol; 
    int **matriz;
};

void mostraLayout();
void mostraLabirinto();
void criaBarreira(struct labirinto *labirinto, int linha, int qtdLinhas,
 int coluna, int qtdColunas);
void adicionaBarreiras(struct labirinto *labirinto); 
struct labirinto criaLabirinto();
void finalizaJogo();
void inicializaJogo();

#endif