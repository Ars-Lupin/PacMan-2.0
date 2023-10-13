#include "tPosicao.h"
#include "tMovimento.h"
#include "tMapa.h"
#include "tPacMan.h"


tPacman* CriaPacman(tPosicao* posicao){}


tPacman* ClonaPacman(tPacman* pacman){}


tMovimento** ClonaHistoricoDeMovimentosSignificativosPacman(tPacman* pacman){}


tPosicao* ObtemPosicaoPacman(tPacman* pacman){}


int EstaVivoPacman(tPacman* pacman){}


void MovePacman(tPacman* pacman, tMapa* mapa, COMANDO comando){}


void CriaTrilhaPacman(tPacman* pacman, int nLinhas, int nColunas){}


void AtualizaTrilhaPacman(tPacman* pacman){}


void SalvaTrilhaPacman(tPacman* pacman){}


void InsereNovoMovimentoSignificativoPacman(tPacman* pacman, COMANDO comando, const char* acao){}


void MataPacman(tPacman* pacman){}


void DesalocaPacman(tPacman* pacman){}


int ObtemNumeroAtualMovimentosPacman(tPacman* pacman){}


int ObtemNumeroMovimentosSemPontuarPacman(tPacman* pacman){}


int ObtemNumeroColisoesParedePacman(tPacman* pacman){}


int ObtemNumeroMovimentosBaixoPacman(tPacman* pacman){}


int ObtemNumeroFrutasComidasBaixoPacman(tPacman* pacman){}


int ObtemNumeroColisoesParedeBaixoPacman(tPacman* pacman){}


int ObtemNumeroMovimentosCimaPacman(tPacman* pacman){}


int ObtemNumeroFrutasComidasCimaPacman(tPacman* pacman){}


int ObtemNumeroColisoesParedeCimaPacman(tPacman* pacman){}


int ObtemNumeroMovimentosEsquerdaPacman(tPacman* pacman){}


int ObtemNumeroFrutasComidasEsquerdaPacman(tPacman* pacman){}


int ObtemNumeroColisoesParedeEsquerdaPacman(tPacman* pacman){}


int ObtemNumeroMovimentosDireitaPacman(tPacman* pacman){}


int ObtemNumeroFrutasComidasDireitaPacman(tPacman* pacman){}


int ObtemNumeroColisoesParedeDireitaPacman(tPacman* pacman){}


int ObtemNumeroMovimentosSignificativosPacman(tPacman* pacman){}


int ObtemPontuacaoAtualPacman(tPacman* pacman){}