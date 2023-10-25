#include "tPosicao.h"
#include "tMovimento.h"
#include "tMapa.h"
#include "tPacMan.h"

tPacman *CriaPacman(tPosicao *posicao)
{
    tPacman *pacman = malloc(sizeof(tPacman)); // Aloca a estrutura do mapa
    pacman->posicaoAtual->linha = posicao->linha;
    pacman->posicaoAtual->coluna = posicao->coluna;
    pacman->estaVivo = 1;
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
    tPacman *pacmanClone = malloc(sizeof(tPacman));
    pacmanClone->posicaoAtual->linha = pacman->posicaoAtual->linha;
    pacmanClone->posicaoAtual->coluna = pacman->posicaoAtual->coluna;
    pacmanClone->estaVivo = pacman->estaVivo;
    pacmanClone->nMovimentosBaixo = pacman->nMovimentosBaixo;
    pacmanClone->nFrutasComidasBaixo = pacman->nFrutasComidasBaixo;
    pacmanClone->nColisoesParedeBaixo = pacman->nColisoesParedeBaixo;
    pacmanClone->nMovimentosCima = pacman->nMovimentosCima;
    pacmanClone->nFrutasComidasCima = pacman->nFrutasComidasCima;
    pacmanClone->nColisoesParedeCima = pacman->nColisoesParedeCima;
    pacmanClone->nMovimentosEsquerda = pacman->nMovimentosEsquerda;
    pacmanClone->nFrutasComidasEsquerda = pacman->nFrutasComidasEsquerda;
    pacmanClone->nColisoesParedeEsquerda = pacman->nColisoesParedeEsquerda;
    pacmanClone->nMovimentosDireita = pacman->nMovimentosDireita;
    pacmanClone->nFrutasComidasDireita = pacman->nFrutasComidasDireita;
    pacmanClone->nColisoesParedeDireita = pacman->nColisoesParedeDireita;
    pacmanClone->nMovimentosSignificativos = pacman->nMovimentosSignificativos;
    pacmanClone->nLinhasTrilha = pacman->nLinhasTrilha;
    pacmanClone->nColunasTrilha = pacman->nColunasTrilha;
    return pacmanClone;
}

tMovimento **ClonaHistoricoDeMovimentosSignificativosPacman(tPacman *pacman) {}

tPosicao *ObtemPosicaoPacman(tPacman *pacman) {}

int EstaVivoPacman(tPacman *pacman) {}

void MovePacman(tPacman *pacman, tMapa *mapa, COMANDO comando) {}

void CriaTrilhaPacman(tPacman *pacman, int nLinhas, int nColunas) {}

void AtualizaTrilhaPacman(tPacman *pacman) {}

void SalvaTrilhaPacman(tPacman *pacman) {}

void InsereNovoMovimentoSignificativoPacman(tPacman *pacman, COMANDO comando, const char *acao) {}

void MataPacman(tPacman *pacman) {}

void DesalocaPacman(tPacman *pacman) {}

int ObtemNumeroAtualMovimentosPacman(tPacman *pacman) {}

int ObtemNumeroMovimentosSemPontuarPacman(tPacman *pacman) {}

int ObtemNumeroColisoesParedePacman(tPacman *pacman) {}

int ObtemNumeroMovimentosBaixoPacman(tPacman *pacman) {}

int ObtemNumeroFrutasComidasBaixoPacman(tPacman *pacman) {}

int ObtemNumeroColisoesParedeBaixoPacman(tPacman *pacman) {}

int ObtemNumeroMovimentosCimaPacman(tPacman *pacman) {}

int ObtemNumeroFrutasComidasCimaPacman(tPacman *pacman) {}

int ObtemNumeroColisoesParedeCimaPacman(tPacman *pacman) {}

int ObtemNumeroMovimentosEsquerdaPacman(tPacman *pacman) {}

int ObtemNumeroFrutasComidasEsquerdaPacman(tPacman *pacman) {}

int ObtemNumeroColisoesParedeEsquerdaPacman(tPacman *pacman) {}

int ObtemNumeroMovimentosDireitaPacman(tPacman *pacman) {}

int ObtemNumeroFrutasComidasDireitaPacman(tPacman *pacman) {}

int ObtemNumeroColisoesParedeDireitaPacman(tPacman *pacman) {}

int ObtemNumeroMovimentosSignificativosPacman(tPacman *pacman) {}

int ObtemPontuacaoAtualPacman(tPacman *pacman) {}