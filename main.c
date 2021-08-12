#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct
{
    int p1;
    int p2;
    int Vh; //tamanho das dezenas para comparação de tamanho
} nomePecas; //peça

typedef struct
{
    nomePecas pecasPlayers[7]; //7 peças
} players; //jogadores

int main()
{
    setlocale(LC_ALL, "");
    setlocale(LC_CTYPE, "");

    nomePecas pecas[28]; //peças totais
    players player1; //jogador 1 com 7 peças
    players player2; //jogador 2 com 7 peças

    srand(time(NULL)); //para que os números aleatórios não repitam

    //***************************

    //REQ1 + REQ4
    //mostrar as 28 peças

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

    //***************************
    //REQ2
    //distribuir/embaralhar peças para cada jogador

    printf("\n");
    printf(" Jogador 1: |");

    for(int i = 0; i < 7; i++){

        int numPeca = rand() % 28;
        player1.pecasPlayers[i].p1 = pecas[numPeca].p1;
        player1.pecasPlayers[i].p2 = pecas[numPeca].p2;

        if(pecas[numPeca].p1 == 9 && pecas[numPeca].p2 == 9){ //verifica se a peça já foi usada

            int numPecaTemp = rand() % 28;

            player1.pecasPlayers[i].p1 = pecas[numPecaTemp].p1;
            player1.pecasPlayers[i].p2 = pecas[numPecaTemp].p2;

            pecas[numPecaTemp].p1 = 9; //sent
            pecas[numPecaTemp].p2 = 9;
        }

        else{

            pecas[numPeca].p1 = 9;
            pecas[numPeca].p2 = 9;
        }

        player1.pecasPlayers[i].Vh = player1.pecasPlayers[i].p1*10 + player1.pecasPlayers[i].p2;
        printf("%d%d |", player1.pecasPlayers[i].p1, player1.pecasPlayers[i].p2);

    }

    printf("\n Jogador 2: |");

    for(int i = 0; i < 7; i++){

        int numPeca = rand() % 28;

        player2.pecasPlayers[i].p1 = pecas[numPeca].p1;
        player2.pecasPlayers[i].p2 = pecas[numPeca].p2;

        if(pecas[numPeca].p1 == 9 && pecas[numPeca].p2 == 9){

            int numPecaTemp = rand() % 28;

            player2.pecasPlayers[i].p1 = pecas[numPecaTemp].p1;
            player2.pecasPlayers[i].p2 = pecas[numPecaTemp].p2;


            pecas[numPecaTemp].p1 = 9;
            pecas[numPecaTemp].p2 = 9;
        }

        else{

            pecas[numPeca].p1 = 9;
            pecas[numPeca].p2 = 9;
        }


        player2.pecasPlayers[i].Vh = player2.pecasPlayers[i].p1*10 + player2.pecasPlayers[i].p2;
        printf("%d%d |", player2.pecasPlayers[i].p1, player2.pecasPlayers[i].p2);
    }

    printf("\n");
    printf("\n");

    //***************************

    //REQ3
    //sequência correta

    //jogador 1

    printf("\n Jogador 1: |");

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6-i; j++)
        {
            if(player1.pecasPlayers[j].Vh > player1.pecasPlayers[j+1].Vh ) //colocando as dezenas em ordem
            {
                int z = player1.pecasPlayers[j].Vh;

                player1.pecasPlayers[j].Vh = player1.pecasPlayers[j+1].Vh;
                player1.pecasPlayers[j+1].Vh = z;
            }
        }
    }

    for(int i =0 ; i < 7; i++)
    {
        printf("%02d |",player1.pecasPlayers[i].Vh);
    }

    //jogador 2

    printf("\n Jogador 2: |");

    for(int i = 0; i < 6; i++)
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

    for(int i =0 ; i < 7; i++)
    {
        printf("%02d |",player2.pecasPlayers[i].Vh);
    }

    contPecas = 0;
    printf("\n \n");

    for(int i = 0; i <= 6; i++)
    {
        for(int j = i; j <= 6; j++)
        {
            //mostrando as peças
            printf("%d%d ", pecas[contPecas].p1, pecas[contPecas].p2);
            contPecas++;
        }
        printf("\n");
    }


    return 0;
}
