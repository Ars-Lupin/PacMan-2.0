#include "tPosicao.h"
#include "tMovimento.h"
#include "tMapa.h"
#include "tPacman.h"
#include <string.h>

tPacman *CriaPacman(tPosicao *posicao)
{
    if(posicao == NULL)
    {
        return NULL;
    }
    tPacman *pacman = calloc(1, sizeof(tPacman)); // Aloca a estrutura do Pacman
    pacman->posicaoAtual = (tPosicao *)malloc(sizeof(tPosicao));
    
    if(pacman->posicaoAtual == NULL)
    {
        return NULL;
    }
    pacman->historicoDeMovimentosSignificativos = (tMovimento **)malloc(sizeof(tMovimento *));
    pacman->posicaoAtual->linha = posicao->linha;
    pacman->posicaoAtual->coluna = posicao->coluna;
    pacman->estaVivo = true;
    return pacman;
}

tPacman *ClonaPacman(tPacman *pacman)
{
    tPacman *pacManClone = calloc(1, sizeof(tPacman)); // Aloca a estrutura do Pacman
    pacManClone->posicaoAtual = (tPosicao *)malloc(sizeof(tPosicao));
    pacManClone->posicaoAtual->linha = pacman->posicaoAtual->linha;
    pacManClone->posicaoAtual->coluna = pacman->posicaoAtual->coluna;
    pacManClone->estaVivo = true;
    return pacManClone;
}

tMovimento **ClonaHistoricoDeMovimentosSignificativosPacman(tPacman *pacman)
{
    int i;
    if (pacman != NULL || pacman->historicoDeMovimentosSignificativos != NULL)
    {
        tMovimento **clone = (tMovimento **)malloc((pacman->nMovimentosSignificativos) * sizeof(tMovimento *));
        if (clone != NULL)
        {
            for (i = 0; i < pacman->nMovimentosSignificativos; i++)
            {
                clone[i] = NULL;
            }
            for (i = 0; i < pacman->nMovimentosSignificativos; i++)
            {
                clone[i] = pacman->historicoDeMovimentosSignificativos[i];
            }
        }
        return clone;
    }
    return NULL;
}

tPosicao *ObtemPosicaoPacman(tPacman *pacman)
{
    return pacman->posicaoAtual;
}

int EstaVivoPacman(tPacman *pacman)
{
    return pacman->estaVivo;
}

void MovePacman(tPacman *pacman, tMapa *mapa, COMANDO comando)
{
    char comida[50];
    char parede[50];
    char charPacMan = '>';
    char limpa = ' ';
    char tunel = '@';

    strcpy(comida, "pegou comida");
    strcpy(parede, "colidiu com a parede");

    AtualizaItemMapa(mapa, pacman->posicaoAtual, limpa);

    if (comando == MOV_BAIXO)
    {
        pacman->posicaoAtual->linha++;
        if (EncontrouParedeMapa(mapa, pacman->posicaoAtual))
        {
            pacman->posicaoAtual->linha--;
            pacman->nColisoesParedeBaixo++;
            InsereNovoMovimentoSignificativoPacman(pacman, comando, parede);
        }
        else if (EncontrouComidaMapa(mapa, pacman->posicaoAtual))
        {
            pacman->nFrutasComidasBaixo++;
            InsereNovoMovimentoSignificativoPacman(pacman, comando, comida);
        }
        pacman->nMovimentosBaixo++;
    }
    else if (comando == MOV_CIMA)
    {
        pacman->posicaoAtual->linha--;
        if (EncontrouParedeMapa(mapa, pacman->posicaoAtual))
        {
            pacman->posicaoAtual->linha++;
            pacman->nColisoesParedeCima++;
            InsereNovoMovimentoSignificativoPacman(pacman, comando, parede);
        }
        else if (EncontrouComidaMapa(mapa, pacman->posicaoAtual))
        {
            pacman->nFrutasComidasCima++;
            InsereNovoMovimentoSignificativoPacman(pacman, comando, comida);
        }
        pacman->nMovimentosCima++;
    }
    else if (comando == MOV_DIREITA)
    {
        pacman->posicaoAtual->coluna++;
        if (EncontrouParedeMapa(mapa, pacman->posicaoAtual))
        {
            pacman->posicaoAtual->coluna--;
            pacman->nColisoesParedeDireita++;
            InsereNovoMovimentoSignificativoPacman(pacman, comando, parede);
        }
        else if (EncontrouComidaMapa(mapa, pacman->posicaoAtual))
        {
            pacman->nFrutasComidasDireita++;
            InsereNovoMovimentoSignificativoPacman(pacman, comando, comida);
        }
        pacman->nMovimentosDireita++;
    }
    else if (comando == MOV_ESQUERDA)
    {
        pacman->posicaoAtual->coluna--;
        if (EncontrouParedeMapa(mapa, pacman->posicaoAtual))
        {
            pacman->posicaoAtual->coluna++;
            pacman->nColisoesParedeEsquerda++;
            InsereNovoMovimentoSignificativoPacman(pacman, comando, parede);
        }
        else if (EncontrouComidaMapa(mapa, pacman->posicaoAtual))
        {
            pacman->nFrutasComidasEsquerda++;
            InsereNovoMovimentoSignificativoPacman(pacman, comando, comida);
        }
        pacman->nMovimentosEsquerda++;
    }
    if (PossuiTunelMapa(mapa))
    {
        if (EntrouTunel(mapa->tunel, pacman->posicaoAtual))
        {
            LevaFinalTunel(mapa->tunel, pacman->posicaoAtual);
        }
        if (SaoIguaisPosicao(pacman->posicaoAtual, mapa->tunel->acesso1))
        {
            AtualizaItemMapa(mapa, mapa->tunel->acesso2, tunel);
        }
        else if (SaoIguaisPosicao(pacman->posicaoAtual, mapa->tunel->acesso2))
        {
            AtualizaItemMapa(mapa, mapa->tunel->acesso1, tunel);
        }
        else
        {
            AtualizaItemMapa(mapa, mapa->tunel->acesso2, tunel);
            AtualizaItemMapa(mapa, mapa->tunel->acesso1, tunel);
        }
    }
    AtualizaItemMapa(mapa, pacman->posicaoAtual, charPacMan);
}

void CriaTrilhaPacman(tPacman *pacman, int nLinhas, int nColunas)
{
    int i, j;
    pacman->nLinhasTrilha = nLinhas;
    pacman->nColunasTrilha = nColunas;
    if(pacman->trilha == NULL){
    pacman->trilha = (int **)malloc(nLinhas * sizeof(int *));
    
        for (i = 0; i < nLinhas; i++)
        {
            pacman->trilha[i] = (int *)malloc(nColunas * sizeof(int));
        }
    }
    for (i = 0; i < nLinhas; i++)
    {
        for (j = 0; j < nColunas; j++)
        {
            pacman->trilha[i][j] = -1;
        }
    }
}

void AtualizaTrilhaPacman(tPacman *pacman)
{
    pacman->trilha[pacman->posicaoAtual->linha][pacman->posicaoAtual->coluna] = ObtemNumeroAtualMovimentosPacman(pacman);
}

void SalvaTrilhaPacman(tPacman *pacman)
{
    FILE *fTrilha = fopen("trilha.txt", "w");
    int i, j;
    for (i = 0; i < pacman->nLinhasTrilha; i++)
    {
        for (j = 0; j < pacman->nColunasTrilha; j++)
        {
            if (pacman->trilha[i][j] == -1)
            {
                if (j != (pacman->nColunasTrilha - 1))
                {
                    fprintf(fTrilha, "# ");
                }
                else
                {
                    fprintf(fTrilha, "#");
                }
            }
            else
            {
                if (j != (pacman->nColunasTrilha - 1))
                {
                    fprintf(fTrilha, "%d ", pacman->trilha[i][j]);
                }
                else
                {
                    fprintf(fTrilha, "%d", pacman->trilha[i][j]);
                }
            }
        }
        fprintf(fTrilha, "\n");
    }
    fclose(fTrilha);
}

void InsereNovoMovimentoSignificativoPacman(tPacman *pacman, COMANDO comando, const char *acao)
{
    int movimento = ObtemNumeroAtualMovimentosPacman(pacman);
    pacman->historicoDeMovimentosSignificativos = (tMovimento **)realloc(pacman->historicoDeMovimentosSignificativos, (pacman->nMovimentosSignificativos + 1) * sizeof(tMovimento *));
    pacman->historicoDeMovimentosSignificativos[pacman->nMovimentosSignificativos] = CriaMovimento(movimento, comando, acao);
    pacman->nMovimentosSignificativos++;
}

void MataPacman(tPacman *pacman)
{
    pacman->estaVivo = false;
}

void DesalocaPacman(tPacman *pacman)
{
    int i;
    if (pacman != NULL)
    {
        DesalocaPosicao(pacman->posicaoAtual);
        if (pacman->historicoDeMovimentosSignificativos != NULL)
        {

            for (i = 0; i < pacman->nMovimentosSignificativos; i++)
            {
                if (pacman->historicoDeMovimentosSignificativos[i] != NULL)
                {
                    DesalocaMovimento(pacman->historicoDeMovimentosSignificativos[i]);
                }
            }
            free(pacman->historicoDeMovimentosSignificativos);
        }
        if (pacman->trilha != NULL)
        {
            for (i = 0; i < pacman->nLinhasTrilha; i++)
            {
                if (pacman->trilha[i] != NULL)
                {
                    free(pacman->trilha[i]);
                }
            }
            free(pacman->trilha);
        }
        free(pacman);
    }
}

int ObtemNumeroAtualMovimentosPacman(tPacman *pacman)
{
    return pacman->nMovimentosBaixo + pacman->nMovimentosCima + pacman->nMovimentosDireita + pacman->nMovimentosEsquerda;
}

int ObtemNumeroMovimentosSemPontuarPacman(tPacman *pacman)
{
    return (pacman->nMovimentosBaixo + pacman->nMovimentosCima + pacman->nMovimentosDireita + pacman->nMovimentosEsquerda) - (pacman->nFrutasComidasBaixo + pacman->nFrutasComidasCima + pacman->nFrutasComidasDireita + pacman->nFrutasComidasEsquerda);
}

int ObtemNumeroColisoesParedePacman(tPacman *pacman)
{
    return pacman->nColisoesParedeBaixo + pacman->nColisoesParedeCima + pacman->nColisoesParedeDireita + pacman->nColisoesParedeEsquerda;
}

int ObtemNumeroMovimentosBaixoPacman(tPacman *pacman)
{
    return pacman->nMovimentosBaixo;
}

int ObtemNumeroFrutasComidasBaixoPacman(tPacman *pacman)
{
    return pacman->nFrutasComidasBaixo;
}

int ObtemNumeroColisoesParedeBaixoPacman(tPacman *pacman)
{
    return pacman->nColisoesParedeBaixo;
}

int ObtemNumeroMovimentosCimaPacman(tPacman *pacman)
{
    return pacman->nMovimentosCima;
}

int ObtemNumeroFrutasComidasCimaPacman(tPacman *pacman)
{
    return pacman->nFrutasComidasCima;
}

int ObtemNumeroColisoesParedeCimaPacman(tPacman *pacman)
{
    return pacman->nColisoesParedeCima;
}

int ObtemNumeroMovimentosEsquerdaPacman(tPacman *pacman)
{
    return pacman->nMovimentosEsquerda;
}

int ObtemNumeroFrutasComidasEsquerdaPacman(tPacman *pacman)
{
    return pacman->nFrutasComidasEsquerda;
}

int ObtemNumeroColisoesParedeEsquerdaPacman(tPacman *pacman)
{
    return pacman->nColisoesParedeEsquerda;
}

int ObtemNumeroMovimentosDireitaPacman(tPacman *pacman)
{
    return pacman->nMovimentosDireita;
}

int ObtemNumeroFrutasComidasDireitaPacman(tPacman *pacman)
{
    return pacman->nFrutasComidasDireita;
}

int ObtemNumeroColisoesParedeDireitaPacman(tPacman *pacman)
{
    return pacman->nColisoesParedeDireita;
}

int ObtemNumeroMovimentosSignificativosPacman(tPacman *pacman)
{
    return pacman->nMovimentosSignificativos;
}

int ObtemPontuacaoAtualPacman(tPacman *pacman)
{
    return (pacman->nFrutasComidasBaixo + pacman->nFrutasComidasCima + pacman->nFrutasComidasDireita + pacman->nFrutasComidasEsquerda);
}