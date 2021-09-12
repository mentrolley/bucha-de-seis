#ifndef DOMINOMODEL_H_INCLUDED
#define DOMINOMODEL_H_INCLUDED
#include <stdbool.h>

//declaração de structs e TADs
//assinatura das funções para repassar como uma biblioteca

typedef struct
{
    int p1;
    int p2;
    int Vh; //tamanho das dezenas para comparação de tamanho
} pecasDomino; //peça //pecasDomino

typedef struct
{
    pecasDomino pecasJogadores[14]; //7 peças
} jogadores; //jogadores

typedef struct{
    int j;
} salvarJogador; //salvar quem jogou por último

pecasDomino pecas[28]; //peças totais //

pecasDomino mesaDeJogo[42]; //mesa do jogo

pecasDomino monteComprar[14]; //peças restantes para compra

salvarJogador jogadorSalvar;

jogadores jogador1; //jogador 1 com 7 peças
jogadores jogador2; //jogador 2 (computador também) com 7 peças

void iniciarPecas();
void iniciarP1();
void iniciarP2();
void iniciarMesaDeJogo();
void montarPecasJogador1();
void montarPecasJogador2();
void montarSequenciaJogador1();
void montarSequenciaJogador2();
void mostrarPecasJogador1();
void mostrarPecasJogador2();
void comprarPecasJogador1();
void comprarPecasJogador2();
bool jogadaJogador1(int a, int b);
void trocarSentinelasJ1(int a, int b);
bool jogadaJogador2(int a, int b);
void trocarSentinelasJ2(int a, int b);
void colocandoNaMesa(int l, int pos, int a, int b);
void gravarJogo();
int lerJogo();


#endif // DOMINOMODEL_H_INCLUDED
