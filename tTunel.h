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
 * Cria o tunel dinamicamente.
 * Dadas as posições de linha e coluna dos 2 acessos do tunel,
 * cria duas instancias tPosicao dinamicamente, uma pra cada acesso, insere as
 * inforações das posições passadas como parâmetro. Cria o tTunel dinamicamente.
 * Atribui as duas instancias tPosicao aos acessos do túnel, retorna o ponteiro para
 * o túnel.
 * \param linhaAcesso1 linha da posição do acesso 1 do túnel
 * \param colunaAcesso1 coluna da posição do acesso 1 do túnel
 * \param linhaAcesso2 linha da posição do acesso 2 do túnel
 * \param colunaAcesso2 coluna da posição do acesso 2 do túnel
 */
tTunel* CriaTunel(int linhaAcesso1, int colunaAcesso1, int linhaAcesso2, int colunaAcesso2);

/**
 * Verifica se entrou no túnel pela posição.
 * Dado o túnel e a posição atual do pacman,
 * verifica se a posição do pacman é a mesma de algum dos 
 * dois acessos do túnel.
 * \param tunel tunel
 * \param posicao posição
 */
bool EntrouTunel(tTunel* tunel, tPosicao* posicao);

/**
 * Atualiza a posição para o final do túnel.
 * Caso a posição do pacman seja a mesma de algum dos 2 
 * acessos do túnel, atualiza ela para o outro acesso do túnel.
 * \param tunel tunel
 * \param posicao posição
 */
void LevaFinalTunel(tTunel* tunel, tPosicao* posicao);

/**
 * Caso o túnel seja diferente de NULL, libera o espaço alocado 
 * para a estrutura tTunel.
 * \param tunel tunel
 */
void DesalocaTunel(tTunel* tunel);

#endif