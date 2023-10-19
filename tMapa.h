#ifndef TMAPA_H_
#define TMAPA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tPosicao.h"
#include "tTunel.h"

typedef struct tMapa{
    /* Número de linhas e de colunas do mapa
       que deverão ser preenchidos com as informações 
       no arquivo de configurações 
       do mapa, passado na função CriaMapa */
    int nLinhas, nColunas;

    /* Número atual de frutas no mapa 
       que deverá ser preenchido com a informação no arquivo 
       de configurações do mapa, passado na função CriaMapa.
       Deverá ser atualizada a medida que o jogo prossegue */
    int nFrutasAtual;

    /* Número máximo permitido de movimentos do pacman no mapa
       que deverá ser preenchido com a informação no arquivo 
       de configurações do mapa, passado na função CriaMapa */
    int nMaximoMovimentos;

    /* O grid (matriz) de informações do mapa
       que deverá ser alocado dinamicamente e preenchido
       com as informações do arquivo de configurações 
       do mapa, passado na função CriaMapa */
    char** grid;

    /* O tunel do mapa contendo 2 acessos 
       que deverão ser preenchidos com as informações 
       no arquivo de configurações 
       do mapa, passado na função CriaMapa*/
    tTunel* tunel;
} tMapa;

/**
 * Dado o arquivo de configurações, cria o mapa dinamicamente e 
 * retorna um ponteiro para o tipo tMapa.
 * Caso o arquivo de configurações não exista, retorna NULL.
 * \param caminho caminho do arquivo com as configurações do mapa
 */
tMapa* CriaMapa(const char* caminhoConfig);

/**
 * Obtem a posição de um item do mapa.
 * Dado um item do tipo char, o mapa deverá ser varrido até encontrar o item.
 * Caso o item seja encontrado cria um tipo tPosição e retorna.
 * Caso o item não seja encontrado, retorna NULL.
 * \param mapa mapa
 * \param item item a ser procurado no mapa
 */
tPosicao* ObtemPosicaoItemMapa(tMapa* mapa, char item);

/**
 * Retorna um ponteiro para o túnel da estrutura tMapa.
 * \param mapa mapa
 */
tTunel* ObtemTunelMapa(tMapa* mapa);

/**
 * Dado o mapa e uma posição, retorna o item do mapa relacionado a aquela posição.
 * Caso o mapa ou o grid do mapa seja NULL, ou a posição esteja fora dos limites do mapa,
 * retorna '\0'.
 * \param mapa mapa
 * \param posicao posicao do item a ser retornado
 */
char ObtemItemMapa(tMapa* mapa, tPosicao* posicao);

/**
 * Retorna o número de linhas do mapa.
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
 * Retorna se a posição passada como parâmetro representa uma comida no mapa.
 * Caso o grid do mapa seja NULL, ou a posição esteja fora dos limites do mapa,
 * retorna falso.
 * Caso a posição não represente uma comida, também retorna falso.
 * \param mapa mapa
 * \param posicao posicao a ser verificada
 */
bool EncontrouComidaMapa(tMapa* mapa, tPosicao* posicao);

/**
 * Retorna se a posição passada como parâmetro representa uma parede no mapa.
 * Caso o grid do mapa seja NULL, ou a posição esteja fora dos limites do mapa,
 * retorna falso.
 * Caso a posição não represente uma parede, também retorna falso.
 * \param mapa mapa
 * \param posicao posicao a ser verificada
 */
bool EncontrouParedeMapa(tMapa* mapa, tPosicao* posicao);

/**
 * Dado o mapa, uma posição e um item, atualiza a posição do mapa com aquele item.
 * Caso o mapa ou o grid do mapa seja NULL, ou a posição esteja fora dos limites do mapa,
 * retorna falso. 
 * Se conseguiu atualizar o item com sucesso, retorna verdadeiro.
 * \param mapa mapa
 * \param posicao posicao do item
 * \param item posicao item que vai atualizar o mapa
 */
bool AtualizaItemMapa(tMapa* mapa, tPosicao* posicao, char item);

/**
 * Verifica se o mapa possui tunel ou não.
 * Caso o campo tunel seja NULL retorna falso.
 * Caso contrário retorna verdadeiro.
 * \param mapa mapa
 */
bool PossuiTunelMapa(tMapa* mapa);

/**
 * Apenas chama a função EntrouTunel na estrutura tTunel.h
 * \param mapa mapa
 * \param posicao posicao a ser verificada
 */
bool AcessouTunelMapa(tMapa* mapa, tPosicao* posicao);

/**
 * Apenas chama a função LevaFinalTunel na estrutura tTunel.h
 * \param mapa mapa
 * \param posicao posicao que vai entrar no túnel
 */
void EntraTunelMapa(tMapa* mapa, tPosicao* posicao);

/**
 * Libera o espaço alocado para a estrutura tMapa.
 * Apenas desaloca o mapa caso o mapa seja diferente de NULL.
 * \param mapa mapa
 */
void DesalocaMapa(tMapa* mapa);

#endif
