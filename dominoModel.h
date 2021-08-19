#ifndef DOMINOMODEL_H_INCLUDED
#define DOMINOMODEL_H_INCLUDED

//declaração de structs e TADs
//assinatura das funções para repassar como uma biblioteca

typedef struct
{
    int p1;
    int p2;
    int Vh; //tamanho das dezenas para comparação de tamanho
} nomePecas; //peça

typedef struct
{
    nomePecas pecasJogadores[7]; //7 peças
} jogadores; //jogadores

nomePecas pecas[28]; //peças totais

nomePecas mesaDeJogo[28]; //mesa do jogo

nomePecas monteComprar[14]; //peças restantes para compra

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

#endif // DOMINOMODEL_H_INCLUDED
