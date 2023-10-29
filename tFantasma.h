#ifndef TFANTASMA_H_
#define TFANTASMA_H_

#include "tPosicao.h"
#include "tMapa.h"

typedef struct tFantasma
{
    /* Posição atual do Fantasma (linha,coluna) */
    tPosicao *posicaoAtual;
    tPosicao *posicaoAntiga;

    /* Verifica se existe o tipo de Fantasma */
    int existeFantasma;
    int direcao;
    char tipo;
    char passoFantasma;

} tFantasma;

tFantasma **criaFantasmas(tMapa *mapa);

void achaFantasma(tFantasma *fantasma[4], int tipo, int linha, int coluna);

void movimentaFantasma(tFantasma *fantasma, tMapa *mapa);

void devolveItem(tFantasma **fantasma, tMapa *mapa);

void inicializaFantasmas(tFantasma **fantasma, tMapa *mapa);

void movimentaDirecoes(tFantasma *fantasma);

void desalocaFantasma(tFantasma *fantasma[4]);

void imprimeFantasmas(tMapa *mapa, tFantasma **fantasmas);

#endif