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

tFantasma **criaFantasmas(tMapa mapa)
{
    tFantasma *fantasma[4];
    char tipo;

    for (int i = 0; i < 4; i++)
    {
        fantasma[i] = (tFantasma *)malloc(sizeof(tFantasma));
    }

    for (int i = 0; i < mapa.nLinhas; i++)
    {
        for (int j = 0; j < mapa.nColunas; j++)
        {
            if (mapa.grid[i][j] == ('B' || 'P' || 'I' || 'C'))
            {
                tipo = mapa.grid[i][j];
                achaFantasma(fantasma, tipo, i, j);
            }
        }
    }

    return fantasma;
}

void *achaFantasma(tFantasma *fantasma[4], char tipo, int linha, int coluna)
{
    fantasma[tipo]->existeFantasma = 1;
    fantasma[tipo]->posicaoAtual->linha = linha;
    fantasma[tipo]->posicaoAtual->coluna = coluna;
}

void *movimentaFantasma(tFantasma *fantasma, tMapa mapa)
{
    int i = 0;
    movimentaDireções(fantasma);
    if (mapa.grid[fantasma->posicaoAtual->linha][fantasma->posicaoAtual->coluna] == '#')
    {
        fantasma->direção = fantasma->direção * -1;
        for (int i = 0; i < 2; i++)
        {
            movimentaDireções(fantasma);
        }
    }
}

void *movimentaDireções(tFantasma *fantasma)
{
    if (fantasma->direção == DIR)
    {
        fantasma->posicaoAtual->coluna++;
    }
    else if (fantasma->direção == ESQ)
    {
        fantasma->posicaoAtual->coluna--;
    }
    else if (fantasma->direção == CIM)
    {
        fantasma->posicaoAtual->linha++;
    }
    else if (fantasma->direção == BAI)
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
