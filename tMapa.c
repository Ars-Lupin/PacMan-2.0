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
    mapa->nColunas = 0;

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

        // Aloca espaço para a próxima linha
        mapa->grid[mapa->nLinhas] = (char *)malloc(mapa->nColunas + 1);
        strcpy(mapa->grid[mapa->nLinhas], entrada);
        mapa->nLinhas++;

        mapa->grid = (char **)realloc(mapa->grid, (mapa->nLinhas + 1) * sizeof(char *));
    }

    fclose(arquivo);

    // Acha se tiver tem tuneis e quais suas posições
    int cont;
    for (int i = 0; i < mapa->nLinhas; i++)
    {
        for (int j = 0; j < mapa->nColunas; j++)
        {
            if ((mapa->grid[i][j] == '@') && (cont = 0))
            {
                mapa->tunel->acesso1->linha = i;
                mapa->tunel->acesso1->coluna = j;
                cont++;
            }
            else if ((mapa->grid[i][j] == '@') && (cont = 1))
            {
                mapa->tunel->acesso2->linha = i;
                mapa->tunel->acesso2->coluna = j;
            }
            else
            {
                mapa->tunel->acesso1->linha = NULL;
                mapa->tunel->acesso1->coluna = NULL;
                mapa->tunel->acesso2->linha = NULL;
                mapa->tunel->acesso2->coluna = NULL;
            }
        }
    }

    // Obtem o número de frutas do mapa
    for (int i = 0; i < mapa->nLinhas; i++)
    {
        for (int j = 0; j < mapa->nColunas; j++)
        {
            if (mapa->grid[i][j] == '*')
            {
                mapa->nFrutasAtual++;
            }
        }
    }
    return mapa;
}

tPosicao *ObtemPosicaoItemMapa(tMapa *mapa, char item)
{
    tPosicao *posicaoItem;
    for (int i = 0; i < mapa->nLinhas; i++)
    {
        for (int j = 0; j < mapa->nColunas; j++)
        {
            if (mapa->grid[i][j] == item)
            {
                posicaoItem->linha = i;
                posicaoItem->coluna = j;
            }
        }
    }
    return posicaoItem;
}

tTunel *ObtemTunelMapa(tMapa *mapa)
{
    return mapa->tunel;
}

char ObtemItemMapa(tMapa *mapa, tPosicao *posicao)
{
    char item = mapa->grid[posicao->linha][posicao->coluna];
    return item;
}

int ObtemNumeroLinhasMapa(tMapa *mapa)
{
    return mapa->nLinhas;
}

int ObtemNumeroColunasMapa(tMapa *mapa)
{
    return mapa->nColunas;
}

int ObtemQuantidadeFrutasIniciaisMapa(tMapa *mapa)
{
    int frutasIniciais = mapa->nFrutasAtual;

    return frutasIniciais;
}

int ObtemNumeroMaximoMovimentosMapa(tMapa *mapa)
{
    return mapa->nMaximoMovimentos;
}

bool EncontrouComidaMapa(tMapa *mapa, tPosicao *posicao)
{
    if (mapa->grid[posicao->linha][posicao->coluna] == '*')
    {
        return true;
    }
    return false;
}

bool EncontrouParedeMapa(tMapa *mapa, tPosicao *posicao)
{
    if (mapa->grid[posicao->linha][posicao->coluna] == '#')
    {
        return true;
    }
    return false;
}

bool AtualizaItemMapa(tMapa *mapa, tPosicao *posicao, char item) {}

bool PossuiTunelMapa(tMapa *mapa)
{
    if (mapa->tunel->acesso1->linha == NULL)
    {
        return false;
    }
    return true;
}

bool AcessouTunelMapa(tMapa *mapa, tPosicao *posicao)
{
    bool a = EntrouTunel(mapa->tunel, posicao);
    if (a == true)
    {
        return true
    }
    return false;
}

void EntraTunelMapa(tMapa *mapa, tPosicao *posicao)
{
    LevaFinalTunel(mapa->tunel, posicao);
}

void DesalocaMapa(tMapa *mapa)
{
    for (int i = 0; i < mapa->nLinhas; i++)
    {
        free(mapa->grid[i]);
    }
    free(mapa->grid);
    free(mapa);
}