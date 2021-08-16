#include "dominoModel.h"
#include "dominoView.h"
#include <stdio.h>
#include <stdlib.h>

//TUDO O QUE VAMOS MOSTRAR NA TELA
void totalJogadores(){
    int qtd = 0;

    printf("\n Quantos jogadores? ");
    scanf("%d", &qtd);

    iniciarPecas();

    iniciarP1();
    iniciarP2();

    //JOGADOR 1
    montarPecasPlayer1();
    mostrarPecasPlayer1();

    //JOGADOR 2
    montarPecasPlayer2();
    mostrarPecasPlayer2();

    //JOGADOR 1
    montarSeqPlayer1();
    mostrarSeqPlayer1();

    //JOGADOR 2
    montarSeqPlayer2();
    mostrarSeqPlayer2();

    //peças restantes
    pecasRestantes();

}

int menuInicialJogo(){

        int op;

        printf("Jogo de Domino (PUC-SP)\n");
        printf("\n(1) - Iniciar novo jogo !\n");
        printf("(2) - Continuar a jogar\n");
        printf("(3) - Salvar jogo\n");
        printf("(4) - Carregar jogo\n");
        printf("(5) - Regras do jogo\n");
        printf("(6) - Sair do jogo\n");

        scanf("%d",&op);
        return op;
}

void mostrarPecasPlayer1(){
    printf("\n Jogador 1: |");
    for(int i = 0; i < 7; i++)
        printf("%d%d |", player1.pecasPlayers[i].p1, player1.pecasPlayers[i].p2);

}
void mostrarSeqPlayer1(){
    printf("\n Jogador 1: |");
    for(int i =0 ; i < 7; i++)
        printf("%02d |",player1.pecasPlayers[i].Vh);

}

void mostrarPecasPlayer2(){
    printf("\n Jogador 2: |");
    for(int i = 0; i < 7; i++)
        printf("%d%d |", player2.pecasPlayers[i].p1, player2.pecasPlayers[i].p2);

}

void mostrarSeqPlayer2(){
    printf("\n Jogador 2: |");
    for(int i =0 ; i < 7; i++)
        printf("%02d |",player2.pecasPlayers[i].Vh);

}

void pecasRestantes(){
    int contPecas = 0;

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
}
