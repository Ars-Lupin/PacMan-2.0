#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tPosicao.h"
#include "tTunel.h"
#include "tMapa.h"

tMapa *CriaMapa(const char *caminhoConfig)
{
}

tPosicao *ObtemPosicaoItemMapa(tMapa *mapa, char item) {}

tTunel *ObtemTunelMapa(tMapa *mapa) {}

char ObtemItemMapa(tMapa *mapa, tPosicao *posicao) {}

int ObtemNumeroLinhasMapa(tMapa *mapa) {}

int ObtemNumeroColunasMapa(tMapa *mapa) {}

int ObtemQuantidadeFrutasIniciaisMapa(tMapa *mapa) {}

int ObtemNumeroMaximoMovimentosMapa(tMapa *mapa) {}

bool EncontrouComidaMapa(tMapa *mapa, tPosicao *posicao) {}

bool EncontrouParedeMapa(tMapa *mapa, tPosicao *posicao) {}

bool AtualizaItemMapa(tMapa *mapa, tPosicao *posicao, char item) {}

bool PossuiTunelMapa(tMapa *mapa) {}

bool AcessouTunelMapa(tMapa *mapa, tPosicao *posicao) {}

void EntraTunelMapa(tMapa *mapa, tPosicao *posicao) {}

void DesalocaMapa(tMapa *mapa) {}