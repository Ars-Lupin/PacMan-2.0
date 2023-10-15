#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tMapa.h"
#include "tPacMan.h"
#include "tMovimento.h"
#include "tTunel.h"
#include "tPosicao.h"

#define maxCaminho 1001 // Tamanho maximo do diretorio

void inicializarJogo(const char *diretorio)
{
    char caminho_inicializacao[maxCaminho];
    char caminho_mapa[maxCaminho];
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

    //fprintf(arquivo, "Pac-Man comecara o jogo na linha %d e coluna %d\n", local.PacMan_paclinha + 1, local.PacMan_paccoluna + 1);

    fclose(arquivo);
    //RealizaJogo(diretorio, mapa);
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
