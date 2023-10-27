#include "tPosicao.h"
#include "tMovimento.h"
#include "tMapa.h"
#include "tPacMan.h"
#include <string.h>

tPacman *CriaPacman(tPosicao *posicao)
{
    tPacman *pacman = malloc(sizeof(tPacman)); // Aloca a estrutura do Pacman
    pacman->posicaoAtual = (tPosicao *)malloc(sizeof(tPosicao));
    pacman->historicoDeMovimentosSignificativos = (tMovimento **)malloc(sizeof(tMovimento *));

    pacman->posicaoAtual->linha = posicao->linha;
    pacman->posicaoAtual->coluna = posicao->coluna;
    pacman->estaVivo = true;
    pacman->nMovimentosBaixo = 0;
    pacman->nFrutasComidasBaixo = 0;
    pacman->nColisoesParedeBaixo = 0;
    pacman->nMovimentosCima = 0;
    pacman->nFrutasComidasCima = 0;
    pacman->nColisoesParedeCima = 0;
    pacman->nMovimentosEsquerda = 0;
    pacman->nFrutasComidasEsquerda = 0;
    pacman->nColisoesParedeEsquerda = 0;
    pacman->nMovimentosDireita = 0;
    pacman->nFrutasComidasDireita = 0;
    pacman->nColisoesParedeDireita = 0;
    pacman->nMovimentosSignificativos = 0;
    pacman->nLinhasTrilha = 0;
    pacman->nColunasTrilha = 0;
    return pacman;
}

tPacman *ClonaPacman(tPacman *pacman)
{
    tPacman *pacManClone = malloc(sizeof(tPacman));
    pacManClone->posicaoAtual = (tPosicao *)malloc(sizeof(tPosicao));
    pacManClone->historicoDeMovimentosSignificativos = (tMovimento **)malloc(sizeof(tMovimento *));

    pacManClone->posicaoAtual->linha = pacman->posicaoAtual->linha;
    pacManClone->posicaoAtual->coluna = pacman->posicaoAtual->coluna;
    pacManClone->estaVivo = pacman->estaVivo;
    pacManClone->nMovimentosBaixo = pacman->nMovimentosBaixo;
    pacManClone->nFrutasComidasBaixo = pacman->nFrutasComidasBaixo;
    pacManClone->nColisoesParedeBaixo = pacman->nColisoesParedeBaixo;
    pacManClone->nMovimentosCima = pacman->nMovimentosCima;
    pacManClone->nFrutasComidasCima = pacman->nFrutasComidasCima;
    pacManClone->nColisoesParedeCima = pacman->nColisoesParedeCima;
    pacManClone->nMovimentosEsquerda = pacman->nMovimentosEsquerda;
    pacManClone->nFrutasComidasEsquerda = pacman->nFrutasComidasEsquerda;
    pacManClone->nColisoesParedeEsquerda = pacman->nColisoesParedeEsquerda;
    pacManClone->nMovimentosDireita = pacman->nMovimentosDireita;
    pacManClone->nFrutasComidasDireita = pacman->nFrutasComidasDireita;
    pacManClone->nColisoesParedeDireita = pacman->nColisoesParedeDireita;
    pacManClone->nMovimentosSignificativos = pacman->nMovimentosSignificativos;
    pacManClone->nLinhasTrilha = pacman->nLinhasTrilha;
    pacManClone->nColunasTrilha = pacman->nColunasTrilha;
    return pacManClone;
}

tMovimento **ClonaHistoricoDeMovimentosSignificativosPacman(tPacman *pacman) {}

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
    char fantasma[50];
    char charPacMan = '>';
    char limpa = ' ';

    strcpy(comida, "pegou comida");
    strcpy(parede, "colidiu com a parede");
    strcpy(fantasma, "fim de jogo por encostar em um fantasma");

    AtualizaItemMapa(mapa, pacman->posicaoAtual, limpa);

    if (comando == MOV_BAIXO)
    {
        int anterior = pacman->posicaoAtual->linha;
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
        int anterior = pacman->posicaoAtual->linha;
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
        int anterior = pacman->posicaoAtual->coluna;
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
        int anterior = pacman->posicaoAtual->coluna;
        pacman->posicaoAtual->coluna--;
        if (EncontrouParedeMapa(mapa, pacman->posicaoAtual))
        {
            pacman->posicaoAtual->linha++;
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
    AtualizaItemMapa(mapa, pacman->posicaoAtual, charPacMan);
}

void CriaTrilhaPacman(tPacman *pacman, int nLinhas, int nColunas)
{
    pacman->trilha = (int **)malloc(nLinhas * sizeof(int *));
    for (int i = 0; i < nLinhas; i++)
    {
        pacman->trilha[i] = (int *)malloc(nColunas * sizeof(int));
    }

    for (int i = 0; i < nLinhas; i++)
    {
        for (int j = 0; j < nColunas; j++)
        {
            pacman->trilha[i][j] = -1;
        }
    }
}

void AtualizaTrilhaPacman(tPacman *pacman)
{
    pacman->trilha[pacman->posicaoAtual->linha][pacman->posicaoAtual->coluna] = ObtemNumeroAtualMovimentosPacman(pacman);
}

void SalvaTrilhaPacman(tPacman *pacman) {}

void InsereNovoMovimentoSignificativoPacman(tPacman *pacman, COMANDO comando, const char *acao) {}

void MataPacman(tPacman *pacman)
{
    pacman->estaVivo = false;
}

void DesalocaPacman(tPacman *pacman)
{
    free(pacman->historicoDeMovimentosSignificativos);
    free(pacman->posicaoAtual);
    free(pacman);
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