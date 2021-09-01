#ifndef DOMINOVIEW_H_INCLUDED
#define DOMINOVIEW_H_INCLUDED
#include <stdbool.h>

//assinatura das funções para repassar como uma biblioteca

int menuInicialJogo();
int totalJogadores();
int opIniciarJogo();
int opComecarJogo();
void opcoesJogador1();
void opcoesJogador2();
void mostrarMesaDeJogo();
void montarPecasJogador1();
void mostrarSequenciaJogador1();
void montarPecasJogador2();
void mostrarSequenciaJogador2();
void pecasRestantes();
void montarMesaView();
char posicaoMesa();
bool verRegras();

#endif // DOMINOVIEW_H_INCLUDED
