#ifndef TTUNEL_H_
#define TTUNEL_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "tPosicao.h"

typedef struct tTunel{
    tPosicao* acesso1;
    tPosicao* acesso2;
} tTunel;

/**
 * Cria o tunel dinamicamente
 * \param linhaAcesso1 linha da posição do acesso 1 do túnel
 * \param colunaAcesso1 coluna da posição do acesso 1 do túnel
 * \param linhaAcesso2 linha da posição do acesso 2 do túnel
 * \param colunaAcesso2 coluna da posição do acesso 2 do túnel
 */
tTunel* CriaTunel(int linhaAcesso1, int colunaAcesso1, int linhaAcesso2, int colunaAcesso2);

/**
 * Verifica se entrou no túnel pela posição
 * \param tunel tunel
 * \param posicao posição
 */
bool EntrouTunel(tTunel* tunel, tPosicao* posicao);

/**
 * Atualiza a posição para o final do túnel
 * \param tunel tunel
 * \param posicao posição
 */
void LevaFinalTunel(tTunel* tunel, tPosicao* posicao);

/**
 * Libera o espaço alocado para a estrutura tTunel
 * 
 * \param tunel tunel
 */
void DesalocaTunel(tTunel* tunel);

#endif