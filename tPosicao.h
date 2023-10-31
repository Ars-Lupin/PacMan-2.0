#ifndef TPOSICAO_H_
#define TPOSICAO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tPosicao{
    int linha;
    int coluna;
}tPosicao;

/**
 * Cria a posição dinamicamente.
 * Dados os valores de linha e coluna, 
 * aloca dinamicamente o tipo tPosicao e retorna o ponteiro.
 * \param linha linha da posição
 * \param coluna coluna da posição
 */
tPosicao* CriaPosicao(int linha, int coluna);

/**
 * Clona a posição (construtor de cópia)
 * Aloca outra posicao com as informaçoes da original (passada como parâmetro).
 * \param posicao posição
 */
tPosicao* ClonaPosicao(tPosicao* posicao);

/**
 * Retorna a linha da posição
 * \param posicao posição
 */
int ObtemLinhaPosicao(tPosicao* posicao);

/**
 * Retorna a coluna da posição
 * \param posicao posição
 */
int ObtemColunaPosicao(tPosicao* posicao);

/**
 * Atualiza a posição a atual por uma nova posição.
 * Dada a posição atual, atualiza as informações da posição 
 * nova com a da posição atual.
 * \param posicaoAtual posição atual
 * \param posicaoNova posição nova
 */
void AtualizaPosicao(tPosicao* posicaoAtual, tPosicao* posicaoNova);

/**
 * Verifica se 2 posições são iguais comparando seus atributos.
 * Retorna verdadeiro caso são iguais, e falso caso contrário.
 * \param posicao1 posição 1
 * \param posicao2 posição 2
 */
bool SaoIguaisPosicao(tPosicao* posicao1, tPosicao* posicao2);

/**
 * Libera o espaço alocado para a estrutura tPosicao.
 * Sempre verificar se é NULL antes de dar free.
 * 
 * \param posicao posicao
 */
void DesalocaPosicao(tPosicao* posicao);

#endif