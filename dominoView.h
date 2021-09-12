#ifndef DOMINOVIEW_H_INCLUDED
#define DOMINOVIEW_H_INCLUDED
#include <stdbool.h>

//assinatura das funções para repassar como uma biblioteca

int menuInicialJogo();
int totalJogadores();
int opIniciarJogo();
int opComecarJogo();
char opcoesJogador1();
char opcoesJogador2();
void mostrarMesaDeJogo();
void montarPecasJogador1();
void mostrarSequenciaJogador1();
void montarPecasJogador2();
void mostrarSequenciaJogador2();
void pecasRestantes();
void limparMesa();
int posicaoMesa();
int opSalvar();
int opCarregar();
bool verRegras();
void printOpcaoInvalida();
void printSelectPecas();
void printErroPecas();


#endif // DOMINOVIEW_H_INCLUDED
