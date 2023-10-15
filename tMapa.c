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
    tTunel *tuneis;
    int cont;
    for (int i = 0; i < mapa->nLinhas; i++)
    {
        for (int j = 0; j < mapa->nColunas; j++)
        {
            if ((mapa->grid[i][j] == '@') && (cont = 0))
            {
                tuneis->acesso1->linha = i;
                tuneis->acesso1->coluna = j;
                cont++;
            }
            else if ((mapa->grid[i][j] == '@') && (cont = 1))
            {
                tuneis->acesso2->linha = i;
                tuneis->acesso2->coluna = j;
            }
        }
    }
    return tuneis;
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
    int frutasIniciais = 0;
    for (int i = 0; i < mapa->nLinhas; i++)
    {
        for (int j = 0; j < mapa->nColunas; j++)
        {
            if (mapa->grid[i][j] == '*')
            {
                frutasIniciais++;
            }
        }
    }
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
    for (int i = 0; i < mapa->nLinhas; i++)
    {
        for (int j = 0; j < mapa->nColunas; j++)
        {
            if (mapa->grid[i][j] == '@')
            {
                return true;
            }
        }
    }
    return false;
}

bool AcessouTunelMapa(tMapa *mapa, tPosicao *posicao)
{
    if (mapa->grid[posicao->linha][posicao->coluna] == '@')
    {
        return true;
    }
    return false;
}

void EntraTunelMapa(tMapa *mapa, tPosicao *posicao)
{

    if ((posicao->linha == mapa->tunel->acesso1->linha) &&
        (posicao->coluna == mapa->tunel->acesso1->coluna))
    {
        posicao->linha = mapa->tunel->acesso2->linha;
        posicao->coluna = mapa->tunel->acesso2->coluna;
    }
    else if ((posicao->linha == mapa->tunel->acesso2->linha) &&
             (posicao->coluna == mapa->tunel->acesso2->coluna))
    {
        posicao->linha = mapa->tunel->acesso1->linha;
        posicao->coluna = mapa->tunel->acesso1->coluna;
    }
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