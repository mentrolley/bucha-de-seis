#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

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

int main()
{
    setlocale(LC_ALL, "");
    setlocale(LC_CTYPE, "");

    nomePecas pecas[28]; //pe�as totais
    players player1; //jogador 1 com 7 pe�as
    players player2; //jogador 2 com 7 pe�as

    srand(time(NULL)); //para que os n�meros aleat�rios n�o repitam

    //***************************

    //REQ1 + REQ4
    //mostrar as 28 pe�as

    int contPecas = 0;

    for(int i = 0; i <= 6; i++)
    {
        for(int j = i; j <= 6; j++)
        {
            //atribuindo os valores para cada pe�a
            pecas[contPecas].p1 = i;
            pecas[contPecas].p2 = j;
            pecas[contPecas].Vh = j+i*10;
            //mostrando as pe�as
            printf("%d%d ", pecas[contPecas].p1, pecas[contPecas].p2);
            contPecas++;
        }
        printf("\n");
    }

    //***************************

    //REQ2
    //embaralhar pe�as para cada jogador

    printf("\n");
    printf(" Jogador 1: |");

    //jogador 1

    for(int i = 0; i < 7; i++)
    {
        player1.pecasPlayers[i].p1 = rand() % 7;
        player1.pecasPlayers[i].p2 = rand() % 7;

        for(int j = i-1; j >= 0; j--) //comparando com pe�as j� existentes
        {
            if(player1.pecasPlayers[i].p1 == player1.pecasPlayers[j].p1)
            {
                player1.pecasPlayers[i].p1 = rand() % 7;
                j++;
            }

        }

        for(int k = i-1; k >= 0; k--) //comparando com pe�as j� existentes
        {
            if(player1.pecasPlayers[i].p2 == player1.pecasPlayers[k].p2)
            {
                player1.pecasPlayers[i].p2 = rand() % 7;
                k++;
            }

        }
        player1.pecasPlayers[i].Vh = player1.pecasPlayers[i].p2 + (player1.pecasPlayers[i].p1*10); //transformando em dezenas
        printf("%d%d |", player1.pecasPlayers[i].p1, player1.pecasPlayers[i].p2);
    }


    //jogador 2

    printf("\n");
    printf(" Jogador 2: |");

    for(int i = 0; i < 7; i++)
    {
        player2.pecasPlayers[i].p1 = rand() % 7;
        player2.pecasPlayers[i].p2 = rand() % 7;

        for(int j = i-1; j >= 0; j--) //comparando com pe�as j� existentes
        {
            if(player2.pecasPlayers[i].p1 == player2.pecasPlayers[j].p1)
            {
                player2.pecasPlayers[i].p1 = rand() % 7;
                j++;
            }

        }

        for(int k = i-1; k >= 0; k--) //comparando com pe�as j� existentes
        {
            if(player2.pecasPlayers[i].p2 == player2.pecasPlayers[k].p2)
            {
                player2.pecasPlayers[i].p2 = rand() % 7;
                k++;
            }

        }
        player2.pecasPlayers[i].Vh = player2.pecasPlayers[i].p2 + (player2.pecasPlayers[i].p1*10); //transformando em dezenas
        printf("%d%d |", player2.pecasPlayers[i].p1, player2.pecasPlayers[i].p2);
    }

    printf("\n");
    printf("\n");

    //***************************

    //REQ3
    //sequ�ncia correta

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


    return 0;
}
