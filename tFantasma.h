#ifndef TFANTASMA_H_
#define TFANTASMA_H_

#include "tPosicao.h"
#include "tMapa.h"

typedef struct tFantasma{
    /* Posição atual do Fantasma (linha,coluna) */
    tPosicao* posicaoAtual;

    /* Verifica se existe o tipo de Fantasma */
    int existeFantasma;
    int direção;
    char tipo;
    char passoFantasma;

} tFantasma;

tFantasma** criaFantasmas(tMapa *mapa);

void achaFantasma(tFantasma *fantasma[4], int tipo, int linha, int coluna);

void movimentaFantasma(tFantasma *fantasma, tMapa *mapa);

void movimentaDirecoes(tFantasma *fantasma);

void desalocaFantasma(tFantasma *fantasma[4]);

#endif