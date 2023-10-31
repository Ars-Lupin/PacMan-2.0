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
    char caracter;
    bool acabou = false;
    int tunel1Coluna = -1, tunel1Linha = -1, tunel2Coluna = -1, tunel2Linha = -1, i, j;
    tMapa *mapa = (tMapa *)malloc(sizeof(tMapa)); // Aloca a estrutura do mapa

    sprintf(caminhoMapa, "%s/mapa.txt", caminhoConfig);

    FILE *arquivo = fopen(caminhoMapa, "r");
    if (arquivo == NULL)
    {
        printf("ERRO: Não foi possível ler o arquivo '%s'\n", caminhoMapa);
        exit(1);
    }

    mapa->nLinhas = 0;
    mapa->nColunas = 0;
    int colunaAtual = 0;
    mapa->nFrutasAtual = 0;

    fscanf(arquivo, "%d\n", &mapa->nMaximoMovimentos);

    // Aloca espaço para as linhas iniciais da matriz
    mapa->grid = (char **)malloc(sizeof(char *));

    while (!feof(arquivo))
    {
        mapa->grid[mapa->nLinhas] = (char *)malloc(mapa->nColunas + 1);
        while (1)
        {
            fscanf(arquivo, "%c", &caracter);
            if (caracter == '\0')
            {
                mapa->grid[mapa->nLinhas][colunaAtual] = caracter;
                acabou = true;
                break; // caso chegue ao fim do arquivo, o loop para
            }

            if (caracter == '\n')
            {
                caracter = '\0';
                mapa->grid[mapa->nLinhas][colunaAtual] = caracter;
                break; // caso chegue ao fim do arquivo, o loop para
            }
            mapa->grid[mapa->nLinhas][colunaAtual] = caracter;
            if (mapa->nLinhas == 0)
            {
                mapa->nColunas++;
            }
            colunaAtual++;
            mapa->grid[mapa->nLinhas] = (char *)realloc(mapa->grid[mapa->nLinhas], mapa->nColunas + 1);
        }
        if (acabou)
        {
            break;
        }
        colunaAtual = 0;
        // Aloca espaço para a próxima linha
        mapa->nLinhas++;

        mapa->grid = (char **)realloc(mapa->grid, (mapa->nLinhas + 1) * sizeof(char *));
    }

    fclose(arquivo);

    // Acha se tiver tem tuneis e quais suas posições
    int cont = 0;
    for (i = 0; i < mapa->nLinhas; i++)
    {
        for (j = 0; j < mapa->nColunas; j++)
        {
            if ((mapa->grid[i][j] == '@') && (cont == 0))
            {
                tunel1Linha = i;
                tunel1Coluna = j;
                cont++;
            }
            else if ((mapa->grid[i][j] == '@') && (cont == 1))
            {
                tunel2Linha = i;
                tunel2Coluna = j;
            }
        }
    }
    if (tunel1Linha > 0)
    {
        mapa->tunel = CriaTunel(tunel1Linha, tunel1Coluna, tunel2Linha, tunel2Coluna);
    }
    else if (tunel1Linha < 0)
    {
        mapa->tunel = NULL;
    }

    // Obtem o número de frutas do mapa
    for (i = 0; i < mapa->nLinhas; i++)
    {
        for (j = 0; j < mapa->nColunas; j++)
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
    int i, j;
    for (i = 0; i < mapa->nLinhas; i++)
    {
        for (j = 0; j < mapa->nColunas; j++)
        {
            if (mapa->grid[i][j] == item)
            {
                // tPosicao *posicaoItem;
                // posicaoItem = CriaPosicao(i, j);
                // posicaoItem->linha = i;
                // posicaoItem->coluna = j;
                return CriaPosicao(i, j);
            }
        }
    }
    return NULL;
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

bool AtualizaItemMapa(tMapa *mapa, tPosicao *posicao, char item)
{
    if ((mapa->grid == NULL) || ((posicao->linha > mapa->nLinhas) && (posicao->coluna > mapa->nColunas) && (posicao->linha < 0) && (posicao->coluna < 0)))
    {
        return false;
    }
    mapa->grid[posicao->linha][posicao->coluna] = item;
    return true;
}

bool PossuiTunelMapa(tMapa *mapa)
{
    if (mapa->tunel == NULL)
    {
        return false;
    }
    return true;
}

bool AcessouTunelMapa(tMapa *mapa, tPosicao *posicao)
{
    if (EntrouTunel(mapa->tunel, posicao))
    {
        return true;
    }
    return false;
}

void EntraTunelMapa(tMapa *mapa, tPosicao *posicao)
{
    LevaFinalTunel(mapa->tunel, posicao);
}

void DesalocaMapa(tMapa *mapa)
{
    if (mapa != NULL)
    {
        int i;

        if (mapa->grid != NULL)
        {
            for (i = 0; i <= mapa->nLinhas; i++)
            {
                if (mapa->grid[i] != NULL)
                {
                    free(mapa->grid[i]);
                }
            }
            free(mapa->grid);
        }

        if (mapa->tunel != NULL)
        {
            DesalocaTunel(mapa->tunel);
        }

        free(mapa);
    }
}