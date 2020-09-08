#include "lib_jogo.h"

int main(){

    struct labirinto *labirinto;
    int direcao, direcaoAnterior, sucesso;

    if ( !inicializaJogo() ){
        return 1;
    }

/* ========================================================================== */
    

    /**/
    struct pacman *pacman = criaPacman();
    pacman->posiLin = POSI_LIN_INICIAL;
    pacman->posiCol = POSI_COL_INICIAL;
    /**/
    
    /*struct fantasma vermelho = criaFantasma();*/
    
    /*struct fantasma azul = criaFantasma();*/
    
    /*struct fantasma amarelo = criaFantasma();*/
    
    /*struct fantasma rosa = criaFantasma();*/
/* ========================================================================== */
    
    labirinto = criaLabirinto();

    direcao = direcaoAnterior = KEY_LEFT;
    sucesso = 1;

    clear();
    mostraLabirinto(labirinto);
    mostraLayout();
    mostraPacman(pacman->posiLin, pacman->posiCol);
    refresh();

    while ( pacman->vivo && pacman->vidas > 0 && temPastilha(labirinto) ){

        if ( pegaTecla() ){
            direcao = getch();
        }

        if ( direcao == 'q' )
            break;

        switch ( direcao ){
            case KEY_UP :
                sucesso = checaColizao(labirinto, KEY_UP, pacman);
                if ( sucesso )            
                    movePacman(KEY_UP, pacman);
                else if ( checaColizao(labirinto, direcaoAnterior, pacman) )
                    movePacman(direcaoAnterior, pacman);
                
                break;

            case KEY_DOWN :
                sucesso = checaColizao(labirinto, KEY_DOWN, pacman);
                if ( sucesso )            
                    movePacman(KEY_DOWN, pacman);
                else if ( checaColizao(labirinto, direcaoAnterior, pacman) )
                    movePacman(direcaoAnterior, pacman);
            
                break;

            case KEY_LEFT :
                sucesso = checaColizao(labirinto, KEY_LEFT, pacman);
                if ( sucesso )            
                    movePacman(KEY_LEFT, pacman);
                else if ( checaColizao(labirinto, direcaoAnterior, pacman) )
                    movePacman(direcaoAnterior, pacman);
            
                break;

            case KEY_RIGHT :
                sucesso = checaColizao(labirinto, KEY_RIGHT, pacman);
                if ( sucesso )       
                    movePacman(KEY_RIGHT, pacman);
                else if ( checaColizao(labirinto, direcaoAnterior, pacman) )
                    movePacman(direcaoAnterior, pacman);
                            
                break;

        }

        if ( sucesso )
            direcaoAnterior = direcao;

        clear();
        mostraLabirinto(labirinto);
        mostraLayout();
        mostraPacman(pacman->posiLin, pacman->posiCol);
        usleep(DELAY); /* usleep() pra dar delay no jogo, talvez ajude com a velocidade  */
        refresh();
        
    }

    free(labirinto->matriz);
    free(labirinto);
    finalizaJogo();

    return 0;
}
