#ifndef TJOGO_H_
#define TJOGO_H_

#include "tPosicao.h"
#include "tMapa.h"
#include "tFantasma.h"
#include "tPacMan.h"

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

#endif