#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tPosicao.h"
#include "tMapa.h"
#include "tFantasma.h"
#include "tPacman.h"
#include "tJogo.h"

#define maxCaminho 1001

bool verificaFimDeJogo(tMapa *mapa, tPacman *pacman, tFantasma **fantasmas, COMANDO comando, tPosicao *rastroPacman)
{
    char jogada = atribuiJogada(comando);
    char colisao[50];

    int pontos = ObtemPontuacaoAtualPacman(pacman);
    int pontuacaoMaxima = ObtemQuantidadeFrutasIniciaisMapa(mapa);
    strcpy(colisao, "fim de jogo por encostar em um fantasma");

    if (colisaoFantasma(pacman, fantasmas, rastroPacman, mapa, comando))
    {
        pontos = ObtemPontuacaoAtualPacman(pacman);
        imprimeSaida(mapa, jogada, pontos);
        InsereNovoMovimentoSignificativoPacman(pacman, comando, colisao);
        gameOver(pontos);
        return true;
    }
    else if (fimDosMovimentos(mapa, pacman))
    {
        imprimeSaida(mapa, jogada, pontos);
        gameOver(pontos);
        return true;
    }
    else if (venceu(pontos, pontuacaoMaxima))
    {
        imprimeSaida(mapa, jogada, pontos);
        saidaVitoria(pontos);
        return true;
    }
    else
    {
        imprimeSaida(mapa, jogada, pontos);
    }
    return false;
}

bool fimDosMovimentos(tMapa *mapa, tPacman *pacman)
{
    int maxMov = ObtemNumeroMaximoMovimentosMapa(mapa);
    int atualMov = ObtemNumeroAtualMovimentosPacman(pacman);
    if (maxMov == atualMov)
    {
        return true;
    }
    return false;
}

bool colisaoFantasma(tPacman *pacman, tFantasma **fantasma, tPosicao *rastroPosicao, tMapa *mapa, COMANDO comando)
{
    int i;
    char vazio = ' ';
    for (i = 0; i < 4; i++)
    {
        if (fantasma[i]->existeFantasma)
        {

            if ((SaoIguaisPosicao(pacman->posicaoAtual, fantasma[i]->posicaoAntiga)) && (SaoIguaisPosicao(rastroPosicao, fantasma[i]->posicaoAtual)))
            {
                AtualizaItemMapa(mapa, pacman->posicaoAtual, vazio);
                AtualizaItemMapa(mapa, fantasma[i]->posicaoAtual, fantasma[i]->tipo);
                MataPacman(pacman);
                if (encontrouComidaNaMorte(fantasma[i], pacman, comando))
                {
                    atribuiComidaJogada(comando, pacman);
                }
                return true;
            }
            else if (SaoIguaisPosicao(pacman->posicaoAtual, fantasma[i]->posicaoAtual))
            {
                AtualizaItemMapa(mapa, fantasma[i]->posicaoAtual, fantasma[i]->tipo);
                MataPacman(pacman);
                if (encontrouComidaNaMorte(fantasma[i], pacman, comando))
                {
                    atribuiComidaJogada(comando, pacman);
                }
                return true;
            }
        }
    }
    return false;
}

bool venceu(int pontosAtuais, int pontosMaximos)
{
    if (pontosMaximos == pontosAtuais)
    {
        return true;
    }
    return false;
}

void imprimeSaida(tMapa *mapa, char jogada, int pontos)
{
    int i, j;
    printf("Estado do jogo apos o movimento '%c':\n", jogada);
    for (i = 0; i < mapa->nLinhas; i++)
    {
        for (j = 0; j < mapa->nColunas; j++)
        {
            printf("%c", mapa->grid[i][j]);
        }
        printf("\n");
    }
    printf("Pontuacao: %d\n\n", pontos);
}

void saidaVitoria(int pontos)
{
    printf("Voce venceu!\nPontuacao final: %d\n", pontos);
}

void gameOver(int pontos)
{
    printf("Game over!\nPontuacao final: %d\n", pontos);
}

char atribuiJogada(COMANDO comando)
{
    char jogada;
    if (comando == MOV_CIMA)
    {
        jogada = 'w';
    }
    else if (comando == MOV_ESQUERDA)
    {
        jogada = 'a';
    }
    else if (comando == MOV_BAIXO)
    {
        jogada = 's';
    }
    else if (comando == MOV_DIREITA)
    {
        jogada = 'd';
    }
    return jogada;
}

bool encontrouComidaNaMorte(tFantasma *fantasma, tPacman *pacman, COMANDO comando)
{
    if (fantasma->passoFantasma == '*')
    {
        char comida[50];
        strcpy(comida, "pegou comida");
        InsereNovoMovimentoSignificativoPacman(pacman, comando, comida);
        return true;
    }
    return false;
}

void atribuiComidaJogada(COMANDO comando, tPacman *pacman)
{
    if (comando == MOV_CIMA)
    {
        pacman->nFrutasComidasCima++;
    }
    else if (comando == MOV_ESQUERDA)
    {
        pacman->nFrutasComidasEsquerda++;
    }
    else if (comando == MOV_BAIXO)
    {
        pacman->nFrutasComidasBaixo++;
    }
    else if (comando == MOV_DIREITA)
    {
        pacman->nFrutasComidasDireita++;
    }
}

void gerarEstatisticas(tPacman *pacman)
{
    char caminho_estatisticas[maxCaminho];

    sprintf(caminho_estatisticas, "estatisticas.txt");
    FILE *arquivo = fopen(caminho_estatisticas, "a");

    fprintf(arquivo, "Numero de movimentos: %d\n", ObtemNumeroAtualMovimentosPacman(pacman));
    fprintf(arquivo, "Numero de movimentos sem pontuar: %d\n", ObtemNumeroMovimentosSemPontuarPacman(pacman));
    fprintf(arquivo, "Numero de colisoes com parede: %d\n", ObtemNumeroColisoesParedePacman(pacman));
    fprintf(arquivo, "Numero de movimentos para baixo: %d\n", ObtemNumeroMovimentosBaixoPacman(pacman));
    fprintf(arquivo, "Numero de movimentos para cima: %d\n", ObtemNumeroMovimentosCimaPacman(pacman));
    fprintf(arquivo, "Numero de movimentos para esquerda: %d\n", ObtemNumeroMovimentosEsquerdaPacman(pacman));
    fprintf(arquivo, "Numero de movimentos para direita: %d\n", ObtemNumeroMovimentosDireitaPacman(pacman));

    fclose(arquivo);
}

void gerarRanking(tPacman *pacman) // analisa os dados e forma o ranking
{
    char caminho_ranking[maxCaminho];
    tRanking maior[4];
    maior[0].letra[0] = 'w'; // Define como strings as jogadas
    maior[1].letra[0] = 's';
    maior[2].letra[0] = 'a';
    maior[3].letra[0] = 'd';
    // ###########################-Jogada w -##############################//
    maior[0].comidas = ObtemNumeroFrutasComidasCimaPacman(pacman);
    maior[0].colisoes = ObtemNumeroColisoesParedeCimaPacman(pacman);
    maior[0].jogadas = ObtemNumeroMovimentosCimaPacman(pacman);
    // ###########################-Jogada s -##############################//
    maior[1].comidas = ObtemNumeroFrutasComidasBaixoPacman(pacman);
    maior[1].colisoes = ObtemNumeroColisoesParedeBaixoPacman(pacman);
    maior[1].jogadas = ObtemNumeroMovimentosBaixoPacman(pacman);
    // ###########################-Jogada a -##############################//
    maior[2].comidas = ObtemNumeroFrutasComidasEsquerdaPacman(pacman);
    maior[2].colisoes = ObtemNumeroColisoesParedeEsquerdaPacman(pacman);
    maior[2].jogadas = ObtemNumeroMovimentosEsquerdaPacman(pacman);
    // ###########################-Jogada d -##############################//
    maior[3].comidas = ObtemNumeroFrutasComidasDireitaPacman(pacman);
    maior[3].colisoes = ObtemNumeroColisoesParedeDireitaPacman(pacman);
    maior[3].jogadas = ObtemNumeroMovimentosDireitaPacman(pacman);

    tRanking temp;
    int i, j;

    // Ordenar em ordem decrescente
    for (i = 0; i < 3; i++)
    {
        for (j = i + 1; j < 4; j++)
        {
            if (maior[j].comidas > maior[i].comidas ||
                (maior[j].comidas == maior[i].comidas &&
                 maior[j].colisoes < maior[i].colisoes) ||
                (maior[j].comidas == maior[i].comidas &&
                 maior[j].colisoes == maior[i].colisoes &&
                 maior[j].jogadas > maior[i].jogadas) ||
                (maior[j].comidas == maior[i].comidas &&
                 maior[j].colisoes == maior[i].colisoes &&
                 maior[j].jogadas == maior[i].jogadas &&
                 strcmp(maior[j].letra, maior[i].letra) < 0))
            {
                temp = maior[i];
                maior[i] = maior[j];
                maior[j] = temp;
            }
        }
    }

    sprintf(caminho_ranking, "ranking.txt");
    FILE *arquivo = fopen(caminho_ranking, "a");
    for (i = 0; i < 4; i++)
    {
        fprintf(arquivo, "%c,%d,%d,%d\n", maior[i].letra[0], maior[i].comidas, maior[i].colisoes, maior[i].jogadas);
    }

    fclose(arquivo);
}


void criaResumo(tPacman *pacman)
{
    char caminho_resumo[maxCaminho];
    int i;
    int nMovimentos = ObtemNumeroMovimentosSignificativosPacman(pacman);
    sprintf(caminho_resumo, "resumo.txt");
    FILE *arquivo = fopen(caminho_resumo, "a");

    for (i = 0; i < nMovimentos; i++)
    {
        int numjogadas = ObtemNumeroMovimento(pacman->historicoDeMovimentosSignificativos[i]);
        COMANDO comando = ObtemComandoMovimento(pacman->historicoDeMovimentosSignificativos[i]);
        char jogada = atribuiJogada(comando);
        char acao[50];
        strcpy(acao, ObtemAcaoMovimento(pacman->historicoDeMovimentosSignificativos[i]));

        fprintf(arquivo, "Movimento %d (%c) %s\n", numjogadas, jogada, acao);
    }
    fclose(arquivo);
}

void devolveTunel(tMapa *mapa, tPacman *pacman)
{
    char tunel = '@';
    if ((PossuiTunelMapa(mapa)))
    {
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
}

void desalocaPlayer(tPacman *pacman)
{
    int i;
    if (pacman != NULL)
    {
        if (pacman->posicaoAtual != NULL)
        {
            DesalocaPosicao(pacman->posicaoAtual);
        }
    }
    for (i = 0; i < pacman->nMovimentosSignificativos; i++)
    {
        DesalocaMovimento(pacman->historicoDeMovimentosSignificativos[i]);
    }
    if (pacman->historicoDeMovimentosSignificativos != NULL)
    {
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