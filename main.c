#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tMapa.h"
#include "tPacman.h"
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
    char charPacMan = '>';
    char limpa = ' ';
    COMANDO comando;
    nLinhas = ObtemNumeroLinhasMapa(mapa);
    nColunas = ObtemNumeroColunasMapa(mapa);
    fantasma = criaFantasmas(mapa);
    CriaTrilhaPacman(pacman, nLinhas, nColunas);
    AtualizaTrilhaPacman(pacman);
    inicializaFantasmas(fantasma, mapa);

    while (1)
    {
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
        AtualizaItemMapa(mapa, rastroPacman, limpa);
        AtualizaItemMapa(mapa, pacman->posicaoAtual, charPacMan);
        devolveTunel(mapa, pacman);
        for (i = 0; i < 4; i++)
        {
            if (fantasma[i]->existeFantasma)
            {
                imprimeFantasmas(mapa, fantasma);
            }
        }

        if (verificaFimDeJogo(mapa, pacman, fantasma, comando, rastroPacman))
        {
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
    int i, j;
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
        for (j = 0; j < mapa->nColunas; j++)
        {
            fprintf(arquivo, "%c", mapa->grid[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    posicaoPacMan = ObtemPosicaoItemMapa(mapa, charPacMan);

    pacman = CriaPacman(posicaoPacMan);

    fprintf(arquivo, "Pac-Man comecara o jogo na linha %d e coluna %d\n", pacman->posicaoAtual->linha + 1, pacman->posicaoAtual->coluna + 1);

    fclose(arquivo);
    realizaJogo(diretorio, mapa, pacman);
    GerarEstatisticas(diretorio, pacman);
    GerarRanking(diretorio, pacman);
    criaResumo(diretorio, pacman);
    // desalocaHistoricoResumo(pacman);
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