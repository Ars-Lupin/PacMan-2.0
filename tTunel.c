#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "tPosicao.h"
#include "tTunel.h"

tTunel *CriaTunel(int linhaAcesso1, int colunaAcesso1, int linhaAcesso2, int colunaAcesso2)
{
    tTunel *tuneis = malloc(sizeof(tTunel));
    tuneis->acesso1->linha = linhaAcesso1;
    tuneis->acesso1->coluna = colunaAcesso1;
    tuneis->acesso2->linha = linhaAcesso2;
    tuneis->acesso2->coluna = colunaAcesso2;

    return tuneis;
}

bool EntrouTunel(tTunel *tunel, tPosicao *posicao)
{
    if (((posicao->linha == tunel->acesso1->linha) && (posicao->coluna == tunel->acesso1->coluna)) ||
        ((posicao->linha == tunel->acesso2->linha) && (posicao->coluna == tunel->acesso2->coluna)))
    {
        return true;
    }
    return false;
}

void LevaFinalTunel(tTunel *tunel, tPosicao *posicao)
{
    if ((posicao->linha == tunel->acesso1->linha) &&
        (posicao->coluna == tunel->acesso1->coluna))
    {
        posicao->linha = tunel->acesso2->linha;
        posicao->coluna = tunel->acesso2->coluna;
    }
    else if ((posicao->linha == tunel->acesso2->linha) &&
             (posicao->coluna == tunel->acesso2->coluna))
    {
        posicao->linha = tunel->acesso1->linha;
        posicao->coluna = tunel->acesso1->coluna;
    }
}

void DesalocaTunel(tTunel *tunel)
{
        free(tunel);
}
