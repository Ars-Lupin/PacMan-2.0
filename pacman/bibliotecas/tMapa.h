#ifndef TMAPA_H_
#define TMAPA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tPosicao.h"
#include "tTunel.h"

typedef struct tMapa{
    /* Número de linhas e de colunas do mapa */
    int nLinhas, nColunas;
    /* Número atual de frutas no mapa */
    int nFrutasAtual;
    /* Número máximo permitido de movimentos do pacman no mapa */
    int nMaximoMovimentos;
    /* O grid (matriz) de informações do mapa */
    char** grid;
    /* O tunel do mapa contendo 2 acessos */
    tTunel* tunel;
} tMapa;

/**
 * Cria o mapa dinamicamente
 * \param caminho caminho do arquivo com as configurações do mapa
 */
tMapa* CriaMapa(const char* caminhoConfig);

/**
 * Obtem a posição de um item do mapa
 * \param mapa mapa
 * \param item item a ser procurado no mapa
 */
tPosicao* ObtemPosicaoItemMapa(tMapa* mapa, char item);

/**
 * Retorna o túnel do mapa com os 2 acessos
 * \param mapa mapa
 */
tTunel* ObtemTunelMapa(tMapa* mapa);

/**
 * Obtem o item do mapa dada a posição
 * \param mapa mapa
 * \param posicao posicao do item a ser retornado
 */
char ObtemItemMapa(tMapa* mapa, tPosicao* posicao);

/**
 * Retorna o número de linhas do mapa
 * \param mapa mapa
 */
int ObtemNumeroLinhasMapa(tMapa* mapa);

/**
 * Retorna o número de colunas do mapa
 * \param mapa mapa
 */
int ObtemNumeroColunasMapa(tMapa* mapa);

/**
 * Retorna a quantidade de frutas iniciais do mapa
 * \param mapa mapa
 */
int ObtemQuantidadeFrutasIniciaisMapa(tMapa* mapa);

/**
 * Retorna o número máximo de movimentos permitidos do mapa
 * \param mapa mapa
 */
int ObtemNumeroMaximoMovimentosMapa(tMapa* mapa);

/**
 * Retorna se a posição passada como parâmetro representa uma comida no mapa
 * \param mapa mapa
 * \param posicao posicao a ser verificada
 */
bool EncontrouComidaMapa(tMapa* mapa, tPosicao* posicao);

/**
 * Retorna se a posição passada como parâmetro representa uma parede no mapa
 * \param mapa mapa
 * \param posicao posicao a ser verificada
 */
bool EncontrouParedeMapa(tMapa* mapa, tPosicao* posicao);

/**
 * Atualiza um item do mapa
 * \param mapa mapa
 * \param posicao posicao do item
 * \param item posicao item que vai atualizar o mapa
 */
bool AtualizaItemMapa(tMapa* mapa, tPosicao* posicao, char item);

/**
 * Verifica se o mapa possui tunel ou não
 * \param mapa mapa
 */
bool PossuiTunelMapa(tMapa* mapa);

/**
 * Retorna se o tunel foi acessado ou não
 * \param mapa mapa
 * \param posicao posicao a ser verificada
 */
bool AcessouTunelMapa(tMapa* mapa, tPosicao* posicao);

/**
 * Entra no túnel do mapa.
 * \param mapa mapa
 * \param posicao posicao que vai entrar no túnel
 */
void EntraTunelMapa(tMapa* mapa, tPosicao* posicao);

/**
 * Libera o espaço alocado para a estrutura tMapa
 * \param mapa mapa
 */
void DesalocaMapa(tMapa* mapa);

#endif