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

#define maxCaminho 1001 // Tamanho maximo do diretorio

// void geraEstastisticas{}

// void geraResumo{}

// void geraRanking{}

void imprimeSaida(tMapa *mapa, char jogada, int pontos)
{
        printf("Estado do jogo apos o movimento '%c':\n", jogada);
        for (int i = 0; i < mapa->nLinhas; i++)
        {
            printf("%s\n", mapa->grid[i]);
        }
        printf("Pontuacao: %d\n\n", pontos);
    
}

void realizaJogo(tMapa *mapa, tPacman *pacMan)
{
    tFantasma **fantasma;
    int nLinhas, nColunas;
    char jogada;
    COMANDO comando;
    nLinhas = ObtemNumeroLinhasMapa(mapa);
    nColunas = ObtemNumeroColunasMapa(mapa);
    fantasma = criaFantasmas(mapa);
    CriaTrilhaPacman(pacMan, nLinhas, nColunas);
    while (1)
    {
        AtualizaTrilhaPacman(pacMan);
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
        for (int i = 0; i < 4; i++)
        {
            if (fantasma[i]->existeFantasma)
            {
                movimentaFantasma(fantasma[i], mapa);
            }
        }
        int pontos = ObtemPontuacaoAtualPacman(pacMan);
        MovePacman(pacMan, mapa, comando);
        imprimeSaida(mapa, jogada, pontos);
    }
}

void inicializarJogo(const char *diretorio)
{
    char caminho_inicializacao[maxCaminho];
    char caminho_mapa[maxCaminho];
    char charPacMan = '>';
    tPosicao *posicaoPacMan;
    tPacman *pacMan;
    tMapa *mapa;
    mapa = CriaMapa(diretorio);
    sprintf(caminho_inicializacao, "%s/saida/inicializacao.txt", diretorio);
    FILE *arquivo = fopen(caminho_inicializacao, "w");
    if (arquivo == NULL)
    {
        printf("ERRO: Nao foi possivel criar o arquivo de inicializacao\n");
        exit(1);
    }

    for (int i = 0; i < mapa->nLinhas; i++)
    {
        fprintf(arquivo, "%s\n", mapa->grid[i]);
    }

    posicaoPacMan = ObtemPosicaoItemMapa(mapa, charPacMan);

    pacMan = CriaPacman(posicaoPacMan);

    fprintf(arquivo, "Pac-Man comecara o jogo na linha %d e coluna %d\n", posicaoPacMan->linha + 1, posicaoPacMan->coluna + 1);

    fclose(arquivo);
    realizaJogo(mapa, pacMan);
    DesalocaMapa(mapa);
}

int main(int argv, char *caminhoConfig[])
{
    // if (argv < 2) // caso o diretorio nao seja informado
    // {
    //     printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
    //     return 1;
    // }
    char diretorio[maxCaminho];
    // strcpy(diretorio, caminhoConfig[1]);
    strcpy(diretorio, "template-TP-1-etapa-1/Casos/01");
    inicializarJogo(diretorio);
    return 0;
}