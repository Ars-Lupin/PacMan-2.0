#ifndef TJOGO_H_
#define TJOGO_H_

#include "tPosicao.h"
#include "tMapa.h"
#include "tFantasma.h"
#include "tPacman.h"

typedef struct
{
    char letra[2];
    int comidas;
    int colisoes;
    int jogadas;
} tRanking; 

bool verificaFimDeJogo(tMapa *mapa, tPacman *pacman, tFantasma **fantasmas, COMANDO comando, tPosicao *rastroPacman);

bool fimDosMovimentos(tMapa *mapa, tPacman *pacman);

bool colisaoFantasma(tPacman *pacman, tFantasma **fantasma, tPosicao *rastroPacman, tMapa *mapa, COMANDO comando);

char atribuiJogada(COMANDO comando);

void gameOver(int pontos);

void saidaVitoria(int pontos);

void imprimeSaida(tMapa *mapa, char jogada, int pontos);

bool venceu(int pontosAtuais, int pontosMaximos);

void atribuiComidaJogada(COMANDO comando, tPacman *pacman);

bool encontrouComidaNaMorte(tFantasma *fantasma);

void GerarEstatisticas(const char *diretorio, tPacman *pacman);

void GerarRanking(const char *diretorio, tPacman *pacman);

void resumoComida(const char *diretorio, char jogada, tPacman *pacman);

void resumoParede(const char *diretorio, char jogada, tPacman *pacman);

void resumoFantasma(const char *diretorio, char jogada, tPacman *pacman);

bool comeuFruta(int frutasPreJogada, tPacman *pacman);

bool bateuParede(int colisoesPreJogada, tPacman *pacman);



#endif