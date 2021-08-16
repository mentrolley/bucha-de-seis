#include "dominoModel.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//APENAS O QUE ENVOLVE OS DADOS DO PROGRAMA

void iniciarP1()
{
    for(int i = 0; i <= 6; i++)
    {
        player1.pecasPlayers[i].p1 = 9;
        player1.pecasPlayers[i].p2 = 9;
    }
}

void iniciarP2()
{
    for(int i = 0; i <= 6; i++)
    {
        player2.pecasPlayers[i].p1 = 9;
        player2.pecasPlayers[i].p2 = 9;
    }
}

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

void montarPecasPlayer1()
{
    int dominoP1, dominoP2;
    int numPeca;

    for(int i = 0; i < 7; i++)
    {
        numPeca = rand() % 28;

        dominoP1 = pecas[numPeca].p1;
        dominoP2 = pecas[numPeca].p2;

        if(dominoP1 == 9 && dominoP2 == 9)
        {
            numPeca = rand() % 28;

            dominoP1 = pecas[numPeca].p1;
            dominoP2 = pecas[numPeca].p2;
        }

        player1.pecasPlayers[i].p1 = dominoP1;
        player1.pecasPlayers[i].p2 = dominoP2;

        player1.pecasPlayers[i].Vh = dominoP1*10 + dominoP2;

        pecas[numPeca].p1 = 9;
        pecas[numPeca].p2 = 9;

    }
}



void montarSeqPlayer1()
{

    printf("\n \n");
    for(int i = 0; i <=6; i++)
    {
        for(int j = 0; j < 6-i; j++)
        {
            if(player1.pecasPlayers[j].Vh > player1.pecasPlayers[j+1].Vh) //colocando as dezenas em ordem
            {
                int z = player1.pecasPlayers[j].Vh;

                player1.pecasPlayers[j].Vh = player1.pecasPlayers[j+1].Vh;
                player1.pecasPlayers[j+1].Vh = z;
            }
        }
    }

}

void montarPecasPlayer2()
{

    int dominoP1, dominoP2;
    int numPeca;
    for(int i = 0; i < 7; i++)
    {

        numPeca = rand() % 28;
        dominoP1 = pecas[numPeca].p1;
        dominoP2 = pecas[numPeca].p2;


        if(dominoP1 == 9 && dominoP2 == 9)
        {
            numPeca = rand() % 28;

            dominoP1 = pecas[numPeca].p1;
            dominoP2 = pecas[numPeca].p2;
        }

        player2.pecasPlayers[i].p1 = dominoP1;
        player2.pecasPlayers[i].p2 = dominoP2;

        player2.pecasPlayers[i].Vh = dominoP1*10 + dominoP2;

        pecas[numPeca].p1 = 9;
        pecas[numPeca].p2 = 9;

    }

}

void montarSeqPlayer2()
{

    for(int i = 0; i <=6; i++)
    {
        for(int j = 0; j < 6-i; j++)
        {
            if(player2.pecasPlayers[j].Vh > player2.pecasPlayers[j+1].Vh ) //colocando as dezenas em ordem
            {
                int z = player2.pecasPlayers[j].Vh;

                player2.pecasPlayers[j].Vh = player2.pecasPlayers[j+1].Vh;
                player2.pecasPlayers[j+1].Vh = z;
            }
        }
    }
}



