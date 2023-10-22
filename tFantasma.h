#ifndef TPACMAN_H_
#define TPACMAN_H_

#include "tPosicao.h"
#include "tMapa.h"

typedef struct tFantasma{
    /* Posição atual do Fantasma (linha,coluna) */
    tPosicao* posicaoAtual;

    /* Verifica se existe o tipo de Fantasma */
    int existeFantasma;
    char tipo;
    int direção;

} tFantasma;

tFantasma** criaFantasmas(tMapa mapa);

void *achaFantasma(tFantasma *fantasma[4], char tipo, int linha, int coluna);

void *movimentaFantasma(tFantasma *fantasma, tMapa mapa);

void *movimentaDireções(tFantasma *fantasma);

void desalocaFantasma(tFantasma *fantasma[4]);

#endif