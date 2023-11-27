#ifndef TJOGO_H_
#define TJOGO_H_

#include "tPosicao.h"
#include "tMapa.h"
#include "tFantasma.h"
#include "tPacman.h"

typedef struct
{
    /* Caracter para a jogada */
    char letra[2];

    /* Numero de frutas comida por jogada */
    int comidas;

    /* Numero de colisoes por jogada */
    int colisoes;

    /* Numero de vezes que a direcao foi jogada */
    int jogadas;

} tRanking;

/**
 * Verifica as possibilidades de fim de jogo, e imprime a saida para qual delas for verdadeira, se acabar o jogo, retorna true
 * \param mapa Ponteiro para tMapa
 * \param pacman Ponteiro para tPacman
 * \param fantasmas Ponteiro para tFantasma
 * \param comando Numero do comando COMANDO
 * \param rastroPacman Ponteiro para tPosicao
 */
bool verificaFimDeJogo(tMapa *mapa, tPacman *pacman, tFantasma **fantasmas, COMANDO comando, tPosicao *rastroPacman);

/**
 * Verifica se acabou o numero de movimentos possiveis, se sim, retorna true
 * \param mapa Ponteiro para tMapa
 * \param pacman Ponteiro para tPacman
 */
bool fimDosMovimentos(tMapa *mapa, tPacman *pacman);

/**
 * Verifica se colidiu com fantasma, se sim, retorna true
 * \param mapa Ponteiro para tMapa
 * \param pacman Ponteiro para tPacman
 * \param fantasmas Ponteiro para tFantasma
 * \param comando Numero do comando COMANDO
 * \param rastroPacman Ponteiro para tPosicao
 */
bool colisaoFantasma(tPacman *pacman, tFantasma **fantasma, tPosicao *rastroPacman, tMapa *mapa, COMANDO comando);

/**
 * Obtem o caracter do comando
 * \param comando Numero do comando COMANDO
 */
char atribuiJogada(COMANDO comando);

/**
 * Saida se perdeu
 * \param pontos Pontos atuais
 */
void gameOver(int pontos);

/**
 * Saida se ganhou
 * \param pontos Pontos atuais
 */
void saidaVitoria(int pontos);

/**
 * Imprime a saida
 * \param mapa Ponteiro para tMapa
 * \param jogada jogada atual
 * \param pontos Pontos atuais
 */
void imprimeSaida(tMapa *mapa, char jogada, int pontos);

/**
 * Verifica se venceu, se sim, retorna true
 * \param pontosMaximos Pontuacao maxima
 * \param pontosAtuais Pontos atuais
 */
bool venceu(int pontosAtuais, int pontosMaximos);

/**
 * Atribui a comida na jogada
 * \param comando Comando atual
 * \param pacman Ponteiro para tPacman
 */
void atribuiComidaJogada(COMANDO comando, tPacman *pacman);

/**
 * Verifica se comeu a fruta antes de morrer
 * \param pacman Ponteiro para tPacman
 * \param fantasmas Ponteiro para tFantasma
 * \param comando Numero do comando COMANDO
 */
bool encontrouComidaNaMorte(tFantasma *fantasma, tPacman *pacman, COMANDO comando);

/**
 * Gera as estatisticas do jogo
 * \param pacman Ponteiro para tPacman
 */
void gerarEstatisticas(tPacman *pacman);

/**
 * Gera as ranking do jogo
 * \param pacman Ponteiro para tPacman
 */
void gerarRanking(tPacman *pacman);

/**
 * Gera as resumo do jogo
 * \param pacman Ponteiro para tPacman
 */
void criaResumo(tPacman *pacman);

/**
 * Gera as estatisticas do jogo
 * \param pacman Ponteiro para tPacman
 * \param mapa Ponteiro para tMapa
 */
void devolveTunel(tMapa *mapa, tPacman *pacman);

/**
 * Desaloca Player
 * \param pacman Ponteiro para tPacman
 */
void desalocaPlayer(tPacman *pacman);

#endif