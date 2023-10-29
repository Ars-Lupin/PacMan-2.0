#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tPosicao.h"
#include "tMapa.h"
#include "tFantasma.h"

#define B 0
#define P 1
#define I 2
#define C 3
#define ESQ -10
#define DIR 10
#define BAI -11
#define CIM 11

tFantasma **criaFantasmas(tMapa *mapa)
{
    int tamanho = 4, i, j;
    tFantasma **fantasma = (tFantasma **)malloc(tamanho * sizeof(tFantasma *));
    int tipo;

    for (i = 0; i < 4; i++)
    {
        fantasma[i] = (tFantasma *)malloc(sizeof(tFantasma));
        fantasma[i]->posicaoAtual = (tPosicao *)malloc(sizeof(tPosicao));
        // fantasma[i]->posicaoAntiga = (tPosicao *)malloc(sizeof(tPosicao));
    }

    fantasma[B]->direcao = ESQ;
    fantasma[P]->direcao = CIM;
    fantasma[I]->direcao = BAI;
    fantasma[C]->direcao = DIR;
    fantasma[B]->existeFantasma = false;
    fantasma[P]->existeFantasma = false;
    fantasma[I]->existeFantasma = false;
    fantasma[C]->existeFantasma = false;
    fantasma[B]->tipo = 'B';
    fantasma[P]->tipo = 'P';
    fantasma[I]->tipo = 'I';
    fantasma[C]->tipo = 'C';

    for (i = 0; i < mapa->nLinhas; i++)
    {
        for (j = 0; j < mapa->nColunas; j++)
        {
            if (mapa->grid[i][j] == 'B')
            {
                tipo = B;
                achaFantasma(fantasma, tipo, i, j);
            }
            else if (mapa->grid[i][j] == 'P')
            {
                tipo = P;
                achaFantasma(fantasma, tipo, i, j);
            }
            else if (mapa->grid[i][j] == 'I')
            {
                tipo = I;
                achaFantasma(fantasma, tipo, i, j);
            }
            else if (mapa->grid[i][j] == 'C')
            {
                tipo = C;
                achaFantasma(fantasma, tipo, i, j);
            }
        }
    }

    return fantasma;
}

void achaFantasma(tFantasma **fantasma, int tipo, int linha, int coluna)
{
    fantasma[tipo]->existeFantasma = true;
    fantasma[tipo]->posicaoAtual->linha = linha;
    fantasma[tipo]->posicaoAtual->coluna = coluna;
}

void movimentaFantasma(tFantasma *fantasma, tMapa *mapa)
{
    int i = 0;
    movimentaDirecoes(fantasma);
    if (EncontrouParedeMapa(mapa, fantasma->posicaoAtual) == false)
    {
        fantasma->passoFantasma = ObtemItemMapa(mapa, fantasma->posicaoAtual);
    }

    if (EncontrouParedeMapa(mapa, fantasma->posicaoAtual))
    {
        fantasma->direcao = fantasma->direcao * -1;
        movimentaDirecoes(fantasma);
        AtualizaItemMapa(mapa, fantasma->posicaoAtual, fantasma->passoFantasma);
        movimentaDirecoes(fantasma);
        fantasma->passoFantasma = ObtemItemMapa(mapa, fantasma->posicaoAtual);
    }
    AtualizaItemMapa(mapa, fantasma->posicaoAtual, fantasma->tipo);
}

void devolveItem(tFantasma **fantasma, tMapa *mapa)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (fantasma[i]->existeFantasma)
        {
            if (fantasma[i]->passoFantasma = '>')
            {
                fantasma[i]->passoFantasma = ' ';
            }
            AtualizaItemMapa(mapa, fantasma[i]->posicaoAtual, fantasma[i]->passoFantasma);
        }
    }
}

void inicializaFantasmas(tFantasma **fantasma, tMapa *mapa)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (fantasma[i]->existeFantasma)
        {
            fantasma[i]->passoFantasma = ' ';
            AtualizaItemMapa(mapa, fantasma[i]->posicaoAtual, fantasma[i]->passoFantasma);
        }
    }
}

void movimentaDirecoes(tFantasma *fantasma)
{
    if (fantasma->direcao == DIR)
    {
        fantasma->posicaoAtual->coluna++;
    }
    else if (fantasma->direcao == ESQ)
    {
        fantasma->posicaoAtual->coluna--;
    }
    else if (fantasma->direcao == CIM)
    {
        fantasma->posicaoAtual->linha++;
    }
    else if (fantasma->direcao == BAI)
    {
        fantasma->posicaoAtual->linha--;
    }
}

void imprimeFantasmas(tMapa *mapa, tFantasma **fantasmas)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (fantasmas[i]->existeFantasma)
        {
            AtualizaItemMapa(mapa, fantasmas[i]->posicaoAtual, fantasmas[i]->tipo);
        }
    }
}

void desalocaFantasma(tFantasma **fantasma)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        DesalocaPosicao(fantasma[i]->posicaoAtual);
        free(fantasma[i]);
    }
    free(fantasma);
}
