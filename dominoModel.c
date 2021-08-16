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


    bool sentinela99 = false;
    int dominoP1;
    int dominoP2;

    for(int i = 0; i <= 6; i++)
    {
        do
        {
            if(player1.pecasPlayers[i].p1 == 9 && player1.pecasPlayers[i].p2 == 9)
            {

                int numPeca = rand() % 28;

                if(pecas[numPeca].p1 == 9)
                {
                    sentinela99 = true;
                }

                else
                {

                    dominoP1 = pecas[numPeca].p1;
                    dominoP2 = pecas[numPeca].p2;

                    player2.pecasPlayers[i].p1 = dominoP1;
                    player2.pecasPlayers[i].p2 = dominoP2;
                }
            }
        }
        while(!sentinela99);

        player2.pecasPlayers[i].Vh = dominoP1*10 + dominoP2;
        sentinela99 = false;
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

    // bool sentinela99 = false;

    /*for(int i = 0; i <= 6; i++){

        int numPeca2 = rand() % 28;
        int dominoP1 = pecas[numPeca2].p1;
        int dominoP2 = pecas[numPeca2].p2;

        if(dominoP1 == 9 && dominoP2 == 9)
        {
            numPeca2 = rand() % 28;
            dominoP1 = pecas[numPeca2].p1;
            dominoP2 = pecas[numPeca2].p2;

            player2.pecasPlayers[i].p1 = dominoP1;
            player2.pecasPlayers[i].p2 = dominoP2;
            player2.pecasPlayers[i].Vh = dominoP1*10 + dominoP2;
        }
        else{

            player2.pecasPlayers[i].p1 = dominoP1;
            player2.pecasPlayers[i].p2 = dominoP2;
            player2.pecasPlayers[i].Vh = dominoP1*10 + dominoP2;

        }
        pecas[numPeca2].p1 = 9;
        pecas[numPeca2].p2 = 9;
    }*/





    for(int i = 0; i <= 6; i++)
    {

        bool sentinela99 = false;
        int dominoP1;
        int dominoP2;

        do
        {
            if(player2.pecasPlayers[i].p1 == 9 && player2.pecasPlayers[i].p2 == 9)
            {

                int numPeca = rand() % 28;

                if(pecas[numPeca].p1 == 9)
                {
                    sentinela99 = true;
                }

                else
                {

                    dominoP1 = pecas[numPeca].p1;
                    dominoP2 = pecas[numPeca].p2;

                    player2.pecasPlayers[i].p1 = dominoP1;
                    player2.pecasPlayers[i].p2 = dominoP2;
                }
            }
        }
        while(!sentinela99);

        player2.pecasPlayers[i].Vh = dominoP1*10 + dominoP2;
        sentinela99 = false;
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



