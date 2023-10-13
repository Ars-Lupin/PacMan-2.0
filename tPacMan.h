#ifndef TPACMAN_H_
#define TPACMAN_H_

#include "tPosicao.h"
#include "tMovimento.h"
#include "tMapa.h"

typedef struct tPacman{
    /* Posição atual do pacman (linha,coluna) */
    tPosicao* posicaoAtual;

    /* Estado de vida do pacman: vivo ou morto */
    int estaVivo;

    /* Estatísticas para quando o pacman se move para baixo */
    int nMovimentosBaixo;
    int nFrutasComidasBaixo;
    int nColisoesParedeBaixo;

    /* Estatísticas para quando o pacman se move para cima */
    int nMovimentosCima;
    int nFrutasComidasCima;
    int nColisoesParedeCima;

    /* Estatísticas para quando o pacman se move para a esquerda */
    int nMovimentosEsquerda;
    int nFrutasComidasEsquerda;
    int nColisoesParedeEsquerda;

    /* Estatísticas para quando o pacman se move para a direita */
    int nMovimentosDireita;
    int nFrutasComidasDireita;
    int nColisoesParedeDireita;

    /* Histórico de movimentos significativos do pacman */
    int nMovimentosSignificativos;
    tMovimento** historicoDeMovimentosSignificativos;

    /* Trilha gerada pelos passos do pacman. */
    int nLinhasTrilha;
    int nColunasTrilha;
    int** trilha;
} tPacman;

/**
 * Cria o pacman dinamicamente
 * \param posicao Ponteiro para tPosicao
 */
tPacman* CriaPacman(tPosicao* posicao);

/**
 * Clona o pacman dinamicamente, construtor de cópia
 * \param pacman pacman
 */
tPacman* ClonaPacman(tPacman* pacman);

/**
 * Clona a lista historico de movimentos significativos do pacman.
 * 
 * \param pacman pacman
 */
tMovimento** ClonaHistoricoDeMovimentosSignificativosPacman(tPacman* pacman);

/**
 * Retorna a posição do pacman.
 * 
 * \param pacman pacman
 */
tPosicao* ObtemPosicaoPacman(tPacman* pacman);

/**
 * Retorna se o pacman está vivo ou morto.
 * 
 * \param pacman pacman
 */
int EstaVivoPacman(tPacman* pacman);

/**
 * Função que irá mover o pacman no mapa, atualizando sua posição.
 * 
 * \param pacman pacman
 * \param mapa o mapa que contem o pacman
 * \param comando o comando para onde irá o pacman
 */
void MovePacman(tPacman* pacman, tMapa* mapa, COMANDO comando);

/**
 * Aloca a trilha dinamicamente.
 * 
 * \param pacman pacman
 * \param nLinhas número de linhas da trilha
 * \param nColunas número de colunas da trilha
 */
void CriaTrilhaPacman(tPacman* pacman, int nLinhas, int nColunas);

/**
 * Atualiza na trilha a posição por onde passou o pacman.
 * 
 * \param pacman pacman
 */
void AtualizaTrilhaPacman(tPacman* pacman);

/**
 * Salva a trilha em um arquivo.
 * 
 * \param pacman pacman
 */
void SalvaTrilhaPacman(tPacman* pacman);

/**
 * Insere na lista de movimentos um novo movimento significativo.
 * 
 * \param pacman pacman
 * \param comando o comando do movimento
 * \param acao a ação do movimento
 */
void InsereNovoMovimentoSignificativoPacman(tPacman* pacman, COMANDO comando, const char* acao);

/**
 * Seta pacman para morto.
 * 
 * \param pacman pacman
 */
void MataPacman(tPacman* pacman);

/**
 * Libera o espaço alocado para a estrutura tPacman
 * 
 * \param pacman pacman
 */
void DesalocaPacman(tPacman* pacman);

/**
 * Retorna o número atual de movimentos do pacman
 * 
 * \param pacman pacman
 */
int ObtemNumeroAtualMovimentosPacman(tPacman* pacman);

/**
 * Retorna o número de movimentos sem pontuar do pacman
 * 
 * \param pacman pacman
 */
int ObtemNumeroMovimentosSemPontuarPacman(tPacman* pacman);

/**
 * Retorna o número de colisões com a parede do pacman
 * 
 * \param pacman pacman
 */
int ObtemNumeroColisoesParedePacman(tPacman* pacman);

/**
 * Retorna o número de movimentos para baixo do pacman
 * 
 * \param pacman pacman
 */
int ObtemNumeroMovimentosBaixoPacman(tPacman* pacman);

/**
 * Retorna o número de frutas comidas para baixo pelo pacman
 * 
 * \param pacman pacman
 */
int ObtemNumeroFrutasComidasBaixoPacman(tPacman* pacman);

/**
 * Retorna o número de colisões com a parede para baixo
 * 
 * \param pacman pacman
 */
int ObtemNumeroColisoesParedeBaixoPacman(tPacman* pacman);

/**
 * Retorna o número de movimentos para baixo do pacman
 * 
 * \param pacman pacman
 */
int ObtemNumeroMovimentosCimaPacman(tPacman* pacman);

/**
 * Retorna o número de frutas comidas para cima pelo pacman
 * 
 * \param pacman pacman
 */
int ObtemNumeroFrutasComidasCimaPacman(tPacman* pacman);

/**
 * Retorna o número de colisões com a parede para cima
 * 
 * \param pacman pacman
 */
int ObtemNumeroColisoesParedeCimaPacman(tPacman* pacman);

/**
 * Retorna o número de movimentos para a esquerda do pacman
 * 
 * \param pacman pacman
 */
int ObtemNumeroMovimentosEsquerdaPacman(tPacman* pacman);

/**
 * Retorna o número de frutas comidas para a esquerda pelo pacman
 * 
 * \param pacman pacman
 */
int ObtemNumeroFrutasComidasEsquerdaPacman(tPacman* pacman);

/**
 * Retorna o número de colisões com a parede para esquerda
 * 
 * \param pacman pacman
 */
int ObtemNumeroColisoesParedeEsquerdaPacman(tPacman* pacman);

/**
 * Retorna o número de movimentos para a direita do pacman
 * 
 * \param pacman pacman
 */
int ObtemNumeroMovimentosDireitaPacman(tPacman* pacman);

/**
 * Retorna o número de frutas comidas para a direita pelo pacman
 * 
 * \param pacman pacman
 */
int ObtemNumeroFrutasComidasDireitaPacman(tPacman* pacman);

/**
 * Retorna o número de colisões com a parede para direita
 * 
 * \param pacman pacman
 */
int ObtemNumeroColisoesParedeDireitaPacman(tPacman* pacman);

/**
 * Retorna o número de movimentos significativos do pacman
 * 
 * \param pacman pacman
 */
int ObtemNumeroMovimentosSignificativosPacman(tPacman* pacman);

/**
 * Retorna a pontuação atual do pacman
 * 
 * \param pacman pacman
 */
int ObtemPontuacaoAtualPacman(tPacman* pacman);



#endif