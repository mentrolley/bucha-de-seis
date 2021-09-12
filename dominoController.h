#ifndef DOMINOCONTROLLER_H_INCLUDED
#define DOMINOCONTROLLER_H_INCLUDED

void inicializarController();
void prepararPecasJogo();
bool comecarJogo();
bool prepararJogo();
void jogoPrincipal();
int verificarPecaInicial();
int contarRestantesJ1();
int contarRestantesJ2();
bool verificandoNaMesa(int a, int b);
void salvarJogo(int jogador);
int carregarJogo();
void movimentosJogadores(int jogador);

#endif // DOMINOCONTROLLER_H_INCLUDED
