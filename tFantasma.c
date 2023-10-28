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
    int tamanho = 4;
    tFantasma **fantasma = (tFantasma **)malloc(tamanho * sizeof(tFantasma *));
    int tipo;

    for (int i = 0; i < 4; i++)
    {
        fantasma[i] = (tFantasma *)malloc(sizeof(tFantasma));
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
    fantasma[B]->passoFantasma = ' ';
    fantasma[P]->passoFantasma = ' ';
    fantasma[I]->passoFantasma = ' ';
    fantasma[C]->passoFantasma = ' ';

    for (int i = 0; i < mapa->nLinhas; i++)
    {
        for (int j = 0; j < mapa->nColunas; j++)
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
    int i;
    fantasma[tipo]->posicaoAtual = (tPosicao *)malloc(sizeof(tPosicao));
    fantasma[tipo]->existeFantasma = true;
    fantasma[tipo]->posicaoAtual->linha = linha;
    fantasma[tipo]->posicaoAtual->coluna = coluna;
}

void movimentaFantasma(tFantasma *fantasma, tMapa *mapa)
{
    int i = 0;
    AtualizaItemMapa(mapa, fantasma->posicaoAtual, fantasma->passoFantasma);
    movimentaDirecoes(fantasma);
    fantasma->passoFantasma = ObtemItemMapa(mapa, fantasma->posicaoAtual);
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

void desalocaFantasma(tFantasma *fantasma[4])
{
    for (int i = 0; i < 4; i++)
    {
        free(fantasma[i]);
    }
}
