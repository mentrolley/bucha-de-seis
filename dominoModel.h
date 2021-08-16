#ifndef DOMINOMODEL_H_INCLUDED
#define DOMINOMODEL_H_INCLUDED

typedef struct
{
    int p1;
    int p2;
    int Vh; //tamanho das dezenas para compara��o de tamanho
} nomePecas; //pe�a

typedef struct
{
    nomePecas pecasPlayers[7]; //7 pe�as
} players; //jogadores

nomePecas pecas[28]; //pe�as totais
players player1; //jogador 1 com 7 pe�as
players player2; //jogador 2 com 7 pe�as

void iniciarP1();
void iniciarP2();
void iniciarPecas();
void montarPecasPlayer1();
void montarPecasPlayer2();
void montarSeqPlayer1();
void montarSeqPlayer2();
void mostrarPecasPlayer1();
void mostrarPecasPlayer2();



#endif // DOMINOMODEL_H_INCLUDED
