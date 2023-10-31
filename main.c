#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tMapa.h"
#include "tPacMan.h"
#include "tMovimento.h"
#include "tTunel.h"
#include "tPosicao.h"
#include "tFantasma.h"
#include "tJogo.h"

#define maxCaminho 1001 // Tamanho maximo do diretorio

// void geraEstastisticas{}

// void geraResumo{}

// void geraRanking{}

void realizaJogo(const char *diretorio, tMapa *mapa, tPacman *pacman)
{
    tFantasma **fantasma;
    tPosicao *rastroPacman;
    int nLinhas, nColunas, i;
    char jogada;
    COMANDO comando;
    nLinhas = ObtemNumeroLinhasMapa(mapa);
    nColunas = ObtemNumeroColunasMapa(mapa);
    fantasma = criaFantasmas(mapa);
    CriaTrilhaPacman(pacman, nLinhas, nColunas);
    inicializaFantasmas(fantasma, mapa);

    while (1)
    {
        int comidaPreJogada = ObtemPontuacaoAtualPacman(pacman);
        int colisaoPreJogada = ObtemNumeroColisoesParedePacman(pacman);

        AtualizaTrilhaPacman(pacman);
        scanf(" %c", &jogada);
        if (jogada == 'w')
        {
            comando = MOV_CIMA;
        }
        else if (jogada == 'a')
        {
            comando = MOV_ESQUERDA;
        }
        else if (jogada == 's')
        {
            comando = MOV_BAIXO;
        }
        else if (jogada == 'd')
        {
            comando = MOV_DIREITA;
        }

        for (i = 0; i < 4; i++)
        {
            if (fantasma[i]->existeFantasma)
            {
                fantasma[i]->posicaoAntiga = ClonaPosicao(fantasma[i]->posicaoAtual);
                movimentaFantasma(fantasma[i], mapa);
            }
        }
        rastroPacman = ClonaPosicao(pacman->posicaoAtual);
        MovePacman(pacman, mapa, comando);
        for (i = 0; i < 4; i++)
        {
            if (fantasma[i]->existeFantasma)
            {
                imprimeFantasmas(mapa, fantasma);
            }
        }

        if(comeuFruta(comidaPreJogada, pacman))
        {
            resumoComida(diretorio, jogada, pacman);
        }
        else if(bateuParede(colisaoPreJogada, pacman))
        {
            resumoParede(diretorio, jogada, pacman);
        }

        if (verificaFimDeJogo(mapa, pacman, fantasma, comando, rastroPacman))
        {
            resumoFantasma(diretorio, jogada, pacman);
            for (i = 0; i < 4; i++)
            {
                if (fantasma[i]->existeFantasma)
                {
                    DesalocaPosicao(fantasma[i]->posicaoAntiga);
                }
            }
            DesalocaPosicao(rastroPacman);
            break;
        }
        for (i = 0; i < 4; i++)
        {
            if (fantasma[i]->existeFantasma)
            {
                DesalocaPosicao(fantasma[i]->posicaoAntiga);
            }
        }
        devolveItem(fantasma, mapa);
        DesalocaPosicao(rastroPacman);
    }
    SalvaTrilhaPacman(pacman);
    desalocaFantasma(fantasma);
}

void inicializarJogo(const char *diretorio)
{
    char caminho_inicializacao[maxCaminho];
    char charPacMan = '>';
    int i;
    tPosicao *posicaoPacMan;
    tPacman *pacman;
    tMapa *mapa;
    mapa = CriaMapa(diretorio);
    sprintf(caminho_inicializacao, "%s/saida/inicializacao.txt", diretorio);
    FILE *arquivo = fopen(caminho_inicializacao, "w");
    if (arquivo == NULL)
    {
        printf("ERRO: Nao foi possivel criar o arquivo de inicializacao\n");
        exit(1);
    }

    for (i = 0; i < mapa->nLinhas; i++)
    {
        fprintf(arquivo, "%s\n", mapa->grid[i]);
    }

    posicaoPacMan = ObtemPosicaoItemMapa(mapa, charPacMan);

    pacman = CriaPacman(posicaoPacMan);

    fprintf(arquivo, "Pac-Man comecara o jogo na linha %d e coluna %d\n", posicaoPacMan->linha + 1, posicaoPacMan->coluna + 1);

    fclose(arquivo);
    realizaJogo(diretorio, mapa, pacman);
    GerarEstatisticas(diretorio, pacman);
    DesalocaPosicao(posicaoPacMan);
    DesalocaPacman(pacman);
    DesalocaMapa(mapa);
}

int main(int argv, char *caminhoConfig[])
{
    if (argv < 2) // caso o diretorio nao seja informado
    {
        printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
        return 1;
    }
    char diretorio[maxCaminho];
    strcpy(diretorio, caminhoConfig[1]);
    inicializarJogo(diretorio);
    return 0;
}