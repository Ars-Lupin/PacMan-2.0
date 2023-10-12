#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tMapa.h"
#include "tPacMan.h"
#include "tMovimento.h"
#include "tTunel.h"
#include "tPosicao.h"

#define MAX_PATH_SIZE 1001 // Tamanho maximo do diretorio

int main(int argc, char *argv[])
{
    if (argc < 2) // caso o diretorio nao seja informado
    {
        printf("ERRO: O diretorio de arquivos de configuracao nao foi informado\n");
        return 1;
    }

    char diretorio[MAX_PATH_SIZE];
    strcpy(diretorio, argv[1]);

    return 0;
}
