#include <stdio.h>
#include <ncurses.h>
#include "lib_pacman.c"

int main(){

    struct labirinto labirinto;
    /*int seta;*/

    inicializaJogo();

    if ( !has_colors() ){
        printf("O terminal não suporta cores\n");
        finalizaJogo();
        return -1;
    }

    int maxLinhas, maxColunas;
    getmaxyx(stdscr, maxLinhas, maxColunas);
    
    if ( maxLinhas < MAX_LIN || maxColunas < MAX_COL ){
        printf("O terminal deve ter no minimo %d x %d \n", MAX_LIN, MAX_COL);
        finalizaJogo();
        return -1;
    }

    labirinto = criaLabirinto();

    mostraLabirinto(labirinto);
    mostraLayout();

    if ( getch() == 'q' )
        finalizaJogo();

    return 0;
}
