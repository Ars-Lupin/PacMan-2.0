#ifndef TFANTASMA_H_
#define TFANTASMA_H_

#include "tPosicao.h"
#include "tMapa.h"

typedef struct tFantasma
{
    /* Posicao atual do Fantasma (linha,coluna) */
    tPosicao *posicaoAtual;
    tPosicao *posicaoAntiga;

    /* Verifica se existe o tipo de Fantasma */
    int existeFantasma;

    /* Direcao que se move */
    int direcao;

    /* Sua aparencia*/
    char tipo;

    /* Caracter que passou */
    char passoFantasma;

} tFantasma;

/**
 * Cria os fantasmas
 * \param mapa Ponteiro para tMapa
 */
tFantasma **criaFantasmas(tMapa *mapa);

/**
 * Atribui possicao e ver existencia
 * \param fantasmas Ponteiro para tFantasma
 * \param tipo Caracter do fantasma
 * \param linha Numero da linha
 * \param coluna Numero da coluna
 */
void achaFantasma(tFantasma **fantasma, int tipo, int linha, int coluna);

/**
 * Move fantasmas
 * \param mapa Ponteiro para tMapa
 * \param fantasmas Ponteiro para tFantasma
 */
void movimentaFantasma(tFantasma *fantasma, tMapa *mapa);

/**
 * Devolve item que passou
 * \param mapa Ponteiro para tMapa
 * \param fantasmas Ponteiro para tFantasma
 */
void devolveItem(tFantasma **fantasma, tMapa *mapa);

/**
 * Inicializa primeiro movimento do fantasmas
 * \param mapa Ponteiro para tMapa
 * \param fantasmas Ponteiro para tFantasma
 */
void inicializaFantasmas(tFantasma **fantasma, tMapa *mapa);

/**
 * Move a direção do fantasma
 * \param fantasmas Ponteiro para tFantasma
 */
void movimentaDirecoes(tFantasma *fantasma);

/**
 * Desaloca os fantasmas
 * \param fantasmas Ponteiro para tFantasma
 */
void desalocaFantasma(tFantasma **fantasma);

/**
 * Imprime os fantasmas
 * \param mapa Ponteiro para tMapa
 * \param fantasmas Ponteiro para tFantasma
 */
void imprimeFantasmas(tMapa *mapa, tFantasma **fantasmas);

#endif