#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tPosicao.h"
#include "tTunel.h"
#include "tMapa.h"

#define maxCaminho 1001 // Tamanho maximo do diretorio

tMapa *CriaMapa(const char *caminhoConfig)
{
    char caminhoMapa[maxCaminho];
    tMapa *mapa = malloc(sizeof(tMapa)); // Aloca a estrutura do mapa

    sprintf(caminhoMapa, "%s/mapa.txt", caminhoConfig);

    FILE *arquivo = fopen(caminhoMapa, "r");
    if (arquivo == NULL)
    {
        printf("ERRO: Não foi possível ler o arquivo '%s'\n", caminhoMapa);
        exit(1);
    }

    mapa->nLinhas = 0;
    int maxColunas = 0;

    fscanf(arquivo, "%d\n", &mapa->nMaximoMovimentos);

    // Aloca espaço para as linhas iniciais da matriz
    mapa->grid = (char **)malloc(sizeof(char *));

    char entrada[1000]; // Suponha um tamanho máximo para cada linha

    while (1)
    {
        if (fscanf(arquivo, "%[^\n]\n", entrada) == EOF)
        {
            break; // caso chegue ao fim do arquivo, o loop para
        }

        mapa->nColunas = strlen(entrada);

        if (mapa->nColunas > maxColunas)
        {
            maxColunas = mapa->nColunas;
        }

        // Aloca espaço para a próxima linha
        mapa->grid[mapa->nLinhas] = (char *)malloc(mapa->nColunas + 1);
        strcpy(mapa->grid[mapa->nLinhas], entrada);
        mapa->nLinhas++;

        mapa->grid = (char **)realloc(mapa->grid, (mapa->nLinhas + 1) * sizeof(char *));
    }

    fclose(arquivo);

    return mapa;
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

void DesalocaMapa(tMapa *mapa)
{
    for (int i = 0; i < mapa->nLinhas; i++)
    {
        free(mapa->grid[i]);
    }
}