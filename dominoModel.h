#ifndef DOMINOMODEL_H_INCLUDED
#define DOMINOMODEL_H_INCLUDED
#include <stdbool.h>

//declara��o de structs e TADs
//assinatura das fun��es para repassar como uma biblioteca

typedef struct
{
    int p1;
    int p2;
    int Vh; //tamanho das dezenas para compara��o de tamanho
} pecasDomino; //pe�a //pecasDomino

typedef struct
{
    pecasDomino pecasJogadores[14]; //7 pe�as
} jogadores; //jogadores

pecasDomino pecas[28]; //pe�as totais //

pecasDomino mesaDeJogo[42]; //mesa do jogo

pecasDomino monteComprar[14]; //pe�as restantes para compra

jogadores jogador1; //jogador 1 com 7 pe�as
jogadores jogador2; //jogador 2 (computador tamb�m) com 7 pe�as

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
bool colocandoNaMesa(int a, int b);


#endif // DOMINOMODEL_H_INCLUDED
