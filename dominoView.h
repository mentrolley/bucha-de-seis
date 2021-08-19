#ifndef DOMINOVIEW_H_INCLUDED
#define DOMINOVIEW_H_INCLUDED
#include <stdbool.h>

//assinatura das funções para repassar como uma biblioteca

int menuInicialJogo();
int totalJogadores();
int opIniciarJogo();
bool comecarJogo();
void jogoMain();
void montarPecasJogador1();
void mostrarSequenciaJogador1();
void montarPecasJogador2();
void mostrarSequenciaJogador2();
void pecasRestantes();
void montarMesaView();

#endif // DOMINOVIEW_H_INCLUDED
