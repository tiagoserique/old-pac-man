#include "lib_jogo.h"


/* configuracoes inciais do ncurses */
int inicializaJogo(){

    initscr();

    if ( !has_colors() ){
        finalizaJogo();
        printf("O terminal não suporta cores\n");
        return 0;
    }

    int maxLinhas, maxColunas;
    getmaxyx(stdscr, maxLinhas, maxColunas);
    
    if ( maxLinhas < MAX_LIN + 2|| maxColunas < MAX_COL + 2 ){
        finalizaJogo();
        printf("O terminal deve ter no minimo %d x %d \n", MAX_LIN + 2, MAX_COL + 2);
        return 0;
    }

    start_color();
    init_color(COLOR_BLACK, 0, 0, 0);
    init_color(COLOR_BLUE, 0, 0, 650);
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);

    /*cbreak();*/               /* desabilita buffer na entrada */
    noecho();               /* nao mostra o que foi digitado na tela */
    nodelay(stdscr, TRUE);  /* nao aguarda a digitacao */
    keypad(stdscr, TRUE);   /* habilita as setas do teclado*/
    curs_set(FALSE);        /* n mostra o cursor na tela */

    return 1;
}

/* configuracoes para finalizacao do jogo */
void finalizaJogo(){

    endwin();

    return;
}

/* cria labirinto */
struct labirinto *criaLabirinto(){
   
    struct labirinto *temp;
    int linha;

    temp = malloc(sizeof(struct labirinto));

    temp->qtdLin = MAX_LIN;
    temp->qtdCol = MAX_COL;

    temp->matriz = calloc(temp->qtdLin, sizeof(int *));

    for (linha = 0; linha < temp->qtdLin; linha++)
        temp->matriz[linha] = calloc(temp->qtdCol, sizeof(int));

    adicionaBarreiras(temp);
    adicionaPastilha(temp);

    return temp;
}

/* adiciona barreiras do labirinto */
void adicionaBarreiras(struct labirinto *labirinto){

    /*
        1 linha/coluna do jogo = 3 linhas/colunas da matriz
        As barreiras tem tamanho 3x3
    */

    /*=======================================================================*/
    /* barreiras inicio fantasmas*/ 

    criaBarreira(labirinto, 19, 27, 34, 36);
    criaBarreira(labirinto, 19, 21, 37, 39);
    criaBarreira(labirinto, 19, 21, 43, 45);
    criaBarreira(labirinto, 19, 27, 46, 48);
    criaBarreira(labirinto, 25, 27, 37, 45);
    /*=======================================================================*/
    /* barreiras da primeira e ultima linha*/ 

    criaBarreira(labirinto, 1, 3, 1, MAX_COL);
    criaBarreira(labirinto, MAX_LIN - 2, MAX_LIN, 1, MAX_COL);
    /*=======================================================================*/
    /* barreiras da primeira e ultima coluna*/ 

    criaBarreira(labirinto, 1, 21, 1, 3);
    criaBarreira(labirinto, 25, MAX_LIN, 1, 3);
    criaBarreira(labirinto, 1, 21, MAX_COL - 2, MAX_COL);
    criaBarreira(labirinto, 25, MAX_LIN, MAX_COL - 2, MAX_COL);
    /*=======================================================================*/   
    /* barreiras quadradas */
    /* seguindo ordem de aparicao */

    criaBarreira(labirinto, 7, 12, 7, 12);

    criaBarreira(labirinto, 7, 12, 22, 27);

    criaBarreira(labirinto, 7, 15, 31, 36);
    criaBarreira(labirinto, 10, 15, 31, 39);

    criaBarreira(labirinto, 7, 15, 46, 51);
    criaBarreira(labirinto, 10, 15, 43, 51);

    criaBarreira(labirinto, 7, 12, 55, 60);

    criaBarreira(labirinto, 7, 12, 70, 75);

    criaBarreira(labirinto, 16, 21, 16, 21);

    criaBarreira(labirinto, 19, 27, 25, 30);

    criaBarreira(labirinto, 19, 27, 52, 57);

    criaBarreira(labirinto, 16, 21, 61, 66);

    criaBarreira(labirinto, 31, 36, 7, 12);
    criaBarreira(labirinto, 28, 33, 13, 21);
    criaBarreira(labirinto, 25, 33, 16, 21);

    criaBarreira(labirinto, 31, 36, 25, 33);

    criaBarreira(labirinto, 31, 36, 37, 45);

    criaBarreira(labirinto, 31, 36, 49, 57);

    criaBarreira(labirinto, 25, 33, 61, 66);
    criaBarreira(labirinto, 28, 33, 61, 69);
    criaBarreira(labirinto, 31, 36, 70, 75);
    /*=======================================================================*/
    /* outras barreiras */ 
    /* seguindo ordem dos quadrados */

    criaBarreira(labirinto, 4, 6, 16, 18);
    criaBarreira(labirinto, 4, 6, 40, 42);
    criaBarreira(labirinto, 4, 6, 64, 66);

    criaBarreira(labirinto, 10, 12, 13, 18);
    criaBarreira(labirinto, 13, 15, 7, 9);

    criaBarreira(labirinto, 13, 15, 25, 27);

    criaBarreira(labirinto, 13, 15, 55, 57);

    criaBarreira(labirinto, 13, 15, 73, 75);
    criaBarreira(labirinto, 10, 12, 64, 69);

    criaBarreira(labirinto, 16, 18, 13, 15);

    criaBarreira(labirinto, 16, 18, 67, 69);

    criaBarreira(labirinto, 19, 27, 7, 9); /* t */
    criaBarreira(labirinto, 22, 24, 10, 12);

    criaBarreira(labirinto, 22, 24, 70, 72); /* t */
    criaBarreira(labirinto, 19, 27, 73, 75);

    criaBarreira(labirinto, 37, 39, 16, 21);

    criaBarreira(labirinto, 37, 39, 40, 42);

    criaBarreira(labirinto, 37, 39, 61, 66);

    criaBarreira(labirinto, 40, 42, 7, 12);
    criaBarreira(labirinto, 40, 42, 25, 36);
    criaBarreira(labirinto, 40, 42, 46, 57);
    criaBarreira(labirinto, 40, 42, 70, 75);


    return;
} 

/* cria as barreiras do labirinto na matriz */
void criaBarreira(struct labirinto *labirinto, int linha, int qtdLinhas,
 int coluna, int qtdColunas){

    /*  
        recebe valores comecando com 1
        mas faz a correcao para atribuir na matriz
    */

    int x, y;

    for (x = convertePosicoes(linha) ; x <= convertePosicoes(qtdLinhas) ; x++){
        for (y = convertePosicoes(coluna) ; y <= convertePosicoes(qtdColunas) ; y++){
            if ( labirinto->matriz[x][y] != BARREIRA )
                labirinto->matriz[x][y] = BARREIRA;
            else
                continue;
        }
    }

    return;
}

/* exibe o labirinto */
void mostraLabirinto(struct labirinto *labirinto){

    int linha, coluna, atributo;

    for (linha = 0; linha < labirinto->qtdLin; linha++){
        for (coluna = 0; coluna < labirinto->qtdCol; coluna++){
            
            if ( labirinto->matriz[linha][coluna] == VAZIO ){

                atributo = COLOR_PAIR(1);
                attron(atributo);
                mvprintw(linha + 1, coluna + 1, " ");
                attroff(atributo);
            }
            else if ( labirinto->matriz[linha][coluna] == PASTILHA_NORMAL ){

                atributo = A_REVERSE | COLOR_PAIR(3);
                attron(atributo);
                mvprintw(linha + 1, coluna + 1, " ");
                attroff(atributo);
            }
            else if ( labirinto->matriz[linha][coluna] == PASTILHA_ESPECIAL ){

                atributo = A_REVERSE | COLOR_PAIR(4);
                attron(atributo);
                mvprintw(linha + 1, coluna + 1, " ");
                attroff(atributo);
            }
            else if ( labirinto->matriz[linha][coluna] == BARREIRA ){

                atributo = A_REVERSE | COLOR_PAIR(1); 
                attron(atributo);
                mvprintw(linha + 1, coluna + 1, " ");
                attroff(atributo);
            }
        }
    }

    return;
}

/* exibe o layout do jogo */
void mostraLayout(){

    attron(COLOR_PAIR(1));
    move(0, 0); addch(ACS_ULCORNER);
    move(0, 1); hline(ACS_HLINE, MAX_COL);
    move(1, 0); vline(ACS_VLINE, MAX_LIN);
    move(0, MAX_COL + 1); addch(ACS_URCORNER);

    move(MAX_LIN + 1, 0); addch(ACS_LLCORNER);
    move(MAX_LIN + 1, 1); hline(ACS_HLINE, MAX_COL);
    move(1, MAX_COL + 1); vline(ACS_VLINE, MAX_LIN);
    move(MAX_LIN + 1, MAX_COL + 1); addch(ACS_LRCORNER);

    return;
}

/* checa se uma tecla foi pressionada */
int pegaTecla(){

    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

/* faz a checagem da colizao do personagem na direcao do movimento */
int checaColizao(struct labirinto *labirinto, int direcao, struct pacman *pacman){

    int linha, coluna, limite;

    switch ( direcao ){
        case KEY_UP :
            linha = convertePosicoes(pacman->posiLin - 2); 
            coluna = convertePosicoes(pacman->posiCol - 1);
            limite = convertePosicoes(pacman->posiCol + 1);
            break;

        case KEY_DOWN :
            linha = convertePosicoes(pacman->posiLin + 2);
            coluna = convertePosicoes(pacman->posiCol - 1);
            limite = convertePosicoes(pacman->posiCol + 1);
            break;

        case KEY_LEFT :
            linha = convertePosicoes(pacman->posiLin - 1);
            coluna = convertePosicoes(pacman->posiCol - 2);
            limite = convertePosicoes(pacman->posiLin + 1);
            break;

        case KEY_RIGHT :
            linha = convertePosicoes(pacman->posiLin - 1);
            coluna = convertePosicoes(pacman->posiCol + 2);
            limite = convertePosicoes(pacman->posiLin + 1);
            break;

    }

    if ( direcao == KEY_UP || direcao == KEY_DOWN){
        for ( ; coluna <= limite ; coluna++){

            if ( labirinto->matriz[linha][coluna] == BARREIRA )
                return 0;
            else if ( labirinto->matriz[linha][coluna] == PASTILHA_NORMAL ){
                labirinto->matriz[linha][coluna] = VAZIO;
                /* adiciona score */
            }
        }
    }
    else if ( direcao == KEY_LEFT || direcao == KEY_RIGHT){
        for ( ; linha <= limite ; linha++){

            if ( labirinto->matriz[linha][coluna] == BARREIRA )
                return 0;
            else if ( labirinto->matriz[linha][coluna] == PASTILHA_NORMAL ){
                labirinto->matriz[linha][coluna] = VAZIO;
                /* adiciona score */
            }
        }
    }

    return 1;
}

/* transforma posicao do ncurses para matriz */
int convertePosicoes(int posicao){
    return posicao - 1; 
}

/* adiciona as pastilhas normais no labirinto */
void adicionaPastilha(struct labirinto *labirinto){

    int linha, coluna;

    for (linha = 1; linha <= labirinto->qtdLin - 2 ; linha += 3){
        for (coluna = 1; coluna <= labirinto->qtdCol - 2 ; coluna += 3){

            if ( !( convertePosicoes(linha) >= 18 
            && convertePosicoes(linha) <= 24 
            && convertePosicoes(coluna) >= 36 
            && convertePosicoes(coluna) <= 45 ) ) 
                criaPastilha(labirinto, linha, coluna);
        }
    }

    return;
}

/* cria as pastilhas normais do labirinto na matriz */
void criaPastilha(struct labirinto *labirinto, int linha, int coluna){

    int x, y, limiteLinha, limiteColuna, ok;
    
    limiteLinha = convertePosicoes(linha) + 2;
    limiteColuna = convertePosicoes(coluna) + 2;
    ok = 1;

    for (y = convertePosicoes(linha); y <= limiteLinha ; y++){
        for (x = convertePosicoes(coluna) ; x <= limiteColuna ; x++){
            if ( labirinto->matriz[y][x] == BARREIRA
            || ( y == POSI_LIN_INICIAL && x == POSI_COL_INICIAL ) ){
                ok = 0;
                break;
            }
        }
    }

    if ( ok )
        labirinto->matriz[limiteLinha - 1][limiteColuna - 1] = PASTILHA_NORMAL;

    return;
}

int temPastilha(struct labirinto *labirinto){
    
    int linha, coluna;

    for (linha = 0; linha < labirinto->qtdLin ; linha ++){
        for (coluna = 0; coluna < labirinto->qtdCol ; coluna ++){
            
            if ( labirinto->matriz[linha][coluna] == PASTILHA_NORMAL
            || labirinto->matriz[linha][coluna] == PASTILHA_ESPECIAL )
                return 1;
        }
    }

    return 0;
}