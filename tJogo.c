#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tPosicao.h"
#include "tMapa.h"
#include "tFantasma.h"
#include "tPacMan.h"
#include "tJogo.h"

bool verificaFimDeJogo(tMapa *mapa, tPacman *pacman, tFantasma **fantasmas, COMANDO comando, tPosicao *rastroPacman)
{
    char jogada = atribuiJogada(comando);
    char colisao[50];

    int pontos = ObtemPontuacaoAtualPacman(pacman);
    int pontuacaoMaxima = ObtemQuantidadeFrutasIniciaisMapa(mapa);
    strcpy(colisao, "fim de jogo por encostar em um fantasma");

    if (colisaoFantasma(pacman, fantasmas, rastroPacman, mapa))
    {
        imprimeSaida(mapa, jogada, pontos);
        InsereNovoMovimentoSignificativoPacman(pacman, comando, colisao);
        gameOver(pontos);
        return true;
    }
    else if (fimDosMovimentos(mapa, pacman))
    {
        imprimeSaida(mapa, jogada, pontos);
        gameOver(pontos);
        return true;
    }
    else if (venceu(pontos, pontuacaoMaxima))
    {
        imprimeSaida(mapa, jogada, pontos);
        saidaVitoria(pontos);
        return true;
    }
    else
    {
        imprimeSaida(mapa, jogada, pontos);
    }
    return false;
}

bool fimDosMovimentos(tMapa *mapa, tPacman *pacman)
{
    int maxMov = ObtemNumeroMaximoMovimentosMapa(mapa);
    int atualMov = ObtemNumeroAtualMovimentosPacman(pacman);
    if (maxMov == atualMov)
    {
        return true;
    }
    return false;
}

bool colisaoFantasma(tPacman *pacman, tFantasma **fantasma, tPosicao *rastroPosicao, tMapa *mapa)
{
    int i;
    char vazio = ' ';
    for (i = 0; i < 4; i++)
    {
        if (fantasma[i]->existeFantasma)
        {

            if ((SaoIguaisPosicao(pacman->posicaoAtual, fantasma[i]->posicaoAntiga)) && (SaoIguaisPosicao(rastroPosicao, fantasma[i]->posicaoAtual)))
            {
                AtualizaItemMapa(mapa, pacman->posicaoAtual, vazio);
                AtualizaItemMapa(mapa, fantasma[i]->posicaoAtual, fantasma[i]->tipo);
                MataPacman(pacman);
                return true;
            }
            else if (SaoIguaisPosicao(pacman->posicaoAtual, fantasma[i]->posicaoAtual))
            {
                AtualizaItemMapa(mapa, fantasma[i]->posicaoAtual, fantasma[i]->tipo);
                MataPacman(pacman);
                return true;
            }
        }
    }
    return false;
}

bool venceu(int pontosAtuais, int pontosMaximos)
{
    if (pontosMaximos == pontosAtuais)
    {
        return true;
    }
    return false;
}

void imprimeSaida(tMapa *mapa, char jogada, int pontos)
{
    int i;
    printf("Estado do jogo apos o movimento '%c':\n", jogada);
    for (i = 0; i < mapa->nLinhas; i++)
    {
        printf("%s\n", mapa->grid[i]);
    }
    printf("Pontuacao: %d\n\n", pontos);
}

void saidaVitoria(int pontos)
{
    printf("Voce venceu!\nPontuacao final: %d\n", pontos);
}

void gameOver(int pontos)
{
    printf("Game over!\nPontuacao final: %d\n", pontos);
}

char atribuiJogada(COMANDO comando)
{
    char jogada;
    if (comando == MOV_CIMA)
    {
        jogada = 'w';
    }
    else if (comando == MOV_ESQUERDA)
    {
        jogada = 'a';
    }
    else if (comando == MOV_BAIXO)
    {
        jogada = 's';
    }
    else if (comando == MOV_DIREITA)
    {
        jogada = 'd';
    }
    return jogada;
}