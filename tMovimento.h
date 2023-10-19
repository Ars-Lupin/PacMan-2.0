#ifndef TMOVIMENTO_H_
#define TMOVIMENTO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {MOV_ESQUERDA = 0, 
              MOV_CIMA = 1, 
              MOV_BAIXO = 2, 
              MOV_DIREITA = 3} COMANDO;

typedef struct tMovimento {
    /* Número do movimento do pacman que aconteceu 
       a ação significativa */
    int numeroDoMovimento;

    /* Sentido pra onde foi o pacman no movimento */
    COMANDO comando;

    /* Ação significativa do movimento que podem ser 3: 
        - pegou comida
        - colidiu com a parede
        - fim de jogo por encostar em um fantasma
    */
    char acao[50];
} tMovimento;

/**
 * Dado o número do movimento, o comando e a ação, cria aloca 
 * a estrutura tMovimento e retorna o ponteiro pra ela.
 * \param numeroDoMovimento número do movimento
 * \param comando comando que foi dado para o movimento
 * \param acao a ação gerada pelo movimento
 */
tMovimento* CriaMovimento(int numeroDoMovimento, COMANDO comando, const char* acao);

/**
 * Retorna o número do movimento
 * \param movimento movimento
 */
int ObtemNumeroMovimento(tMovimento* movimento);

/**
 * Retorna o comando do movimento
 * \param movimento movimento
 */
COMANDO ObtemComandoMovimento(tMovimento* movimento);

/**
 * Retorna a ação do movimento
 * \param movimento movimento
 */
char* ObtemAcaoMovimento(tMovimento* movimento);

/**
 * Libera o espaço alocado para a estrutura tMovimento
 * 
 * \param movimento movimento
 */
void DesalocaMovimento(tMovimento* movimento);

#endif
