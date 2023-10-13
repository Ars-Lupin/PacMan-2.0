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
    int numeroDoMovimento;
    COMANDO comando;
    char acao[50];
} tMovimento;

/**
 * Cria o movimento dinamicamente
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