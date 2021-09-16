#ifndef DOMINOCONTROLLER_H_INCLUDED
#define DOMINOCONTROLLER_H_INCLUDED

void inicializarController();
void prepararPecasJogo();
bool comecarJogo();
bool prepararJogo(int jogadores);
void jogoPrincipal(int jogadores);
int verificarPecaInicial();
int contarRestantesJ1();
int contarRestantesJ2();
bool verificandoNaMesa(int a, int b, bool computador);
void salvarJogo(int jogador);
int carregarJogo();
void jogadorVsJogador(int jogador);
void jogadorVsComputador(int jogador);
void temporizador();

#endif // DOMINOCONTROLLER_H_INCLUDED
