#include "dominoModel.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//APENAS O QUE ENVOLVE OS DADOS DO PROGRAMA

void iniciarPecas()
{
    int contPecas = 0;

    for(int i = 0; i <= 6; i++)
    {
        for(int j = i; j <= 6; j++)
        {
            //atribuindo os valores para cada peça
            pecas[contPecas].p1 = i;
            pecas[contPecas].p2 = j;
            pecas[contPecas].Vh = j+i*10;
            //mostrando as peças
            printf("%d%d ", pecas[contPecas].p1, pecas[contPecas].p2);
            contPecas++;
        }
        printf("\n");
    }
}

//*****************
//REQ09
void iniciarP1()
{
    for(int i = 0; i <= 6; i++)
    {
        jogador1.pecasJogadores[i].p1 = 9;
        jogador1.pecasJogadores[i].p2 = 9;
    }
}

void iniciarP2()
{
    for(int i = 0; i <= 6; i++)
    {
        jogador2.pecasJogadores[i].p1 = 9;
        jogador2.pecasJogadores[i].p2 = 9;
    }
}

//REQ08
void iniciarMesaDeJogo()
{
    int contPecas = 0;

    printf("\n Mesa do jogo: \n");
    for(int i = 0; i <= 6; i++)
    {
        for(int j = i; j <= 6; j++)
        {
            //atribuindo os valores para cada peça
            mesaDeJogo[contPecas].p1 = 9;
            mesaDeJogo[contPecas].p2 = 9;

            //mostrando as peças
            printf("%d%d |", mesaDeJogo[contPecas].p1, mesaDeJogo[contPecas].p2);
            contPecas++;
        }
    }
    printf("\n \n");
}

void montarPecasJogador1()
{
    int dominoP1, dominoP2;
    int numPeca;

    for(int i = 0; i < 7; i++)
    {
        numPeca = rand() % 28;

        dominoP1 = pecas[numPeca].p1;
        dominoP2 = pecas[numPeca].p2;

        while(dominoP1 == 9 && dominoP2 == 9){

            numPeca = rand() % 28;

            dominoP1 = pecas[numPeca].p1;
            dominoP2 = pecas[numPeca].p2;
        }

        jogador1.pecasJogadores[i].p1 = dominoP1;
        jogador1.pecasJogadores[i].p2 = dominoP2;

        jogador1.pecasJogadores[i].Vh = dominoP1*10 + dominoP2;

        pecas[numPeca].p1 = 9;
        pecas[numPeca].p2 = 9;

    }
}

void montarSequenciaJogador1()
{

    printf("\n \n");
    for(int i = 0; i <=6; i++)
    {
        for(int j = 0; j < 6-i; j++)
        {
            if(jogador1.pecasJogadores[j].Vh > jogador1.pecasJogadores[j+1].Vh) //colocando as dezenas em ordem
            {
                int z = jogador1.pecasJogadores[j].Vh;

                jogador1.pecasJogadores[j].Vh = jogador1.pecasJogadores[j+1].Vh;
                jogador1.pecasJogadores[j+1].Vh = z;
            }
        }
    }

}

void montarPecasJogador2()
{

    int dominoP1, dominoP2;
    int numPeca;
    for(int i = 0; i < 7; i++)
    {

        numPeca = rand() % 28;
        dominoP1 = pecas[numPeca].p1;
        dominoP2 = pecas[numPeca].p2;

        while(dominoP1 == 9 && dominoP2 == 9){

            numPeca = rand() % 28;

            dominoP1 = pecas[numPeca].p1;
            dominoP2 = pecas[numPeca].p2;
        }

        jogador2.pecasJogadores[i].p1 = dominoP1;
        jogador2.pecasJogadores[i].p2 = dominoP2;

        jogador2.pecasJogadores[i].Vh = dominoP1*10 + dominoP2;

        pecas[numPeca].p1 = 9;
        pecas[numPeca].p2 = 9;

    }

}

void montarSequenciaJogador2()
{

    for(int i = 0; i <=6; i++)
    {
        for(int j = 0; j < 6-i; j++)
        {
            if(jogador2.pecasJogadores[j].Vh > jogador2.pecasJogadores[j+1].Vh ) //colocando as dezenas em ordem
            {
                int z = jogador2.pecasJogadores[j].Vh;

                jogador2.pecasJogadores[j].Vh = jogador2.pecasJogadores[j+1].Vh;
                jogador2.pecasJogadores[j+1].Vh = z;
            }
        }
    }
}



