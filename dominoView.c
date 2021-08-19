#include "dominoModel.h"
#include "dominoView.h"
#include "dominoController.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//TUDO O QUE VAMOS MOSTRAR NA TELA
int menuInicialJogo()
{
    int op;

    printf("\n \n Jogo de Domino (PUC-SP)\n");
    printf("\n(1) - Iniciar novo jogo !\n");
    printf("(2) - Continuar a jogar\n");
    printf("(3) - Salvar jogo\n");
    printf("(4) - Carregar jogo\n");
    printf("(5) - Regras do jogo\n");
    printf("(6) - Sair do jogo ");

    scanf("%d",&op);
    return op;
}

int opIniciarJogo()
{
    int op;

    printf("\n Deseja iniciar um novo jogo?");
    printf("\n 7- Sim  8- Voltar ao menu principal \n");
    scanf("%d", &op);

    return op;
}

int totalJogadores()
{
    int qtd = 0;

    printf("\n Quantos jogadores? ");
    scanf("%d", &qtd);

    return qtd;
}

bool comecarJogo()
{
    int iniciar = opIniciarJogo();
    bool jogoRolando = true;

    //REQ07
    if(iniciar == 7)
    {
        int jogadores = totalJogadores();
        if(jogadores <= 2 && jogadores > 0)
        {
            jogoMain();
        }
        else
        {
            printf("É permitido no máximo 2 jogadores!!");
            comecarJogo();
        }
    }
    else if(iniciar == 8)
        jogoRolando = false;

    else
    {
        printf("Opção inválida");
        iniciar = opIniciarJogo();
    }

    return jogoRolando;
}

void jogoMain(){

    //testando as funções
    //modificar para os lugares certo depois

    iniciarPecas();
    iniciarP1();
    iniciarP2();
    iniciarMesaDeJogo();

    montarMesaView();

    //JOGADOR 1
    montarPecasJogador1(); //model
    mostrarPecasJogador1();

    //JOGADOR 2
    montarPecasJogador2(); //model
    mostrarPecasJogador2();

    //JOGADOR 1
    montarSequenciaJogador1(); //model
    mostrarSequenciaJogador1();

    //JOGADOR 2
    montarSequenciaJogador2(); //model
    mostrarSequenciaJogador2();

    //peças restantes
    pecasRestantes();

}

void mostrarPecasJogador1()
{
    printf("\n Jogador 1: |");
    for(int i = 0; i < 7; i++)
        printf("%d%d |", jogador1.pecasJogadores[i].p1, jogador1.pecasJogadores[i].p2);

}
void mostrarSequenciaJogador1()
{
    printf("\n Jogador 1: |");
    for(int i =0 ; i < 7; i++)
        printf("%02d |",jogador1.pecasJogadores[i].Vh);

}

void mostrarPecasJogador2()
{
    printf("\n Jogador 2: |");
    for(int i = 0; i < 7; i++)
        printf("%d%d |", jogador2.pecasJogadores[i].p1, jogador2.pecasJogadores[i].p2);

}

void mostrarSequenciaJogador2()
{
    printf("\n Jogador 2: |");
    for(int i =0 ; i < 7; i++)
        printf("%02d |",jogador2.pecasJogadores[i].Vh);

}

void pecasRestantes()
{
    int contPecas = 0;
    int monteCompra = 0;

    printf("\n \n");
    for(int i = 0; i <= 6; i++)
    {
        for(int j = i; j <= 6; j++)
        {
            //mostrando as peças
            printf("%d%d ", pecas[contPecas].p1, pecas[contPecas].p2);
            contPecas++;

            if(pecas[contPecas].p1 != 9)
            {
                monteComprar[monteCompra].p1 = pecas[contPecas].p1;
                monteComprar[monteCompra].p2 = pecas[contPecas].p2;
            }
        }
        printf("\n");
    }
}

void montarMesaView()
{
    int r,c;

    for(r = 0; r < 19; ++r)
    {
        for(c = 0; c < 19; ++c)
        {
            if( r == 0 )
            {
                if( c == 0 ) printf("┏");
                else if( c == 18 ) printf("┓");
                else printf("-");
            }
            else if( r == 18 )
            {
                if( c == 0 ) printf("┗");
                else if( c == 18 ) printf("┛");
                else printf("-");
            }
            else
            {
                if( c == 0 ) printf("|");
                else if( c == 18 ) printf("|");
                else printf("+");
            }
        }
        printf("\n");
    }
}
