#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tPosicao.h"

tPosicao *CriaPosicao(int linha, int coluna)
{
    tPosicao *posicao = malloc(sizeof(tPosicao));
    posicao->linha = linha;
    posicao->coluna = coluna;
    return posicao;
}

tPosicao *ClonaPosicao(tPosicao *posicao)
{
    tPosicao *posicao2 = malloc(sizeof(tPosicao));
    posicao2->linha = posicao->linha;
    posicao2->coluna = posicao->coluna;
    return posicao2;
}

int ObtemLinhaPosicao(tPosicao *posicao)
{
    return posicao->linha;
}

int ObtemColunaPosicao(tPosicao *posicao)
{
    return posicao->coluna;
}

void AtualizaPosicao(tPosicao *posicaoAtual, tPosicao *posicaoNova)
{
    posicaoAtual->linha = posicaoNova->linha;
    posicaoAtual->coluna = posicaoNova->coluna;
}

bool SaoIguaisPosicao(tPosicao *posicao1, tPosicao *posicao2)
{
    if ((posicao1->linha == posicao2->coluna) && (posicao1->coluna == posicao2->coluna))
    {
        return true;
    }
    return false;
}

void DesalocaPosicao(tPosicao *posicao)
{
    free(posicao);
}
