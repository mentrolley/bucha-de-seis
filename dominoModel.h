#ifndef DOMINOMODEL_H_INCLUDED
#define DOMINOMODEL_H_INCLUDED

//declara��o de structs e TADs
//assinatura das fun��es para repassar como uma biblioteca

typedef struct
{
    int p1;
    int p2;
    int Vh; //tamanho das dezenas para compara��o de tamanho
} nomePecas; //pe�a

typedef struct
{
    nomePecas pecasJogadores[7]; //7 pe�as
} jogadores; //jogadores

nomePecas pecas[28]; //pe�as totais

nomePecas mesaDeJogo[28]; //mesa do jogo

nomePecas monteComprar[14]; //pe�as restantes para compra

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

#endif // DOMINOMODEL_H_INCLUDED
