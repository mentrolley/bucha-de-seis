#include "dominoModel.h"
#include "dominoView.h"
#include "dominoController.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//CONTROLE DO JOGO

int opcao;
bool fim = true;
bool entradaValida = false;

void inicializarController()
{
    do
    {
        int opcao = menuInicialJogo(); //retornando a opção para fazer o switch do menu

        switch (opcao)
        {
        case 1:
            fim = comecarJogo();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
            fim = verRegras();
            system("cls");
            break;
        case 6:
            fim = false;
            break;

        default:
            printf("Opcão do menu inválida! \n");
        }
    }
    while (!fim);
}

void prepararPecasJogo()
{

    iniciarPecas();
    iniciarP1();
    iniciarP2();
    iniciarMesaDeJogo();
}

bool comecarJogo()
{
    bool jogoRolando = true;
    int jogadores = totalJogadores();

    if(jogadores <= 2 && jogadores > 0)
    {
        jogoRolando = prepararJogo();
    }
    else
    {
        printf("\n  É permitido no máximo 2 jogadores!!! ");
        comecarJogo();
    }

    return jogoRolando;
}

bool prepararJogo()
{
    prepararPecasJogo();
    montarPecasJogador1();
    montarPecasJogador2();

    bool voltarMenu = true;

    int op = opComecarJogo(); //(7) - Sim

    if(op == 7)
        jogoPrincipal();

    else if (op == 8)
        voltarMenu = false;

    else if(op != 7 && op != 8)
    {
        printf("\n   Opção inválida!!! ");
        prepararJogo();
    }

    return voltarMenu;
}

void jogoPrincipal()
{

    bool jogador1Ganhou = false;
    bool jogador2Ganhou = false;

    char op;
    //verificar peça maior
    int jogador = verificarPecaInicial(); //quem começa

    //Jogo
    do
    {
        //JOGADOR 1
        if(jogador == 2)  //invertendo quem começa a jogar, pois quem tem a mais alta joga primeiro
        {

            system("cls");
            printf("    Mesa de jogo:  \n");
            mostrarMesaDeJogo();

            printf("\n \n");
            mostrarPecasJogador1();


            bool jogador1Jogou = false;

            do
            {
                system("cls");
                printf("    Mesa de jogo:  \n");
                mostrarMesaDeJogo();
                printf("\n \n");
                mostrarPecasJogador1();

                opcoesJogador1();
                printf("\n \n");
                scanf("   %c", &op);

                if(op == 'V' || op == 'v')
                {
                    mostrarSequenciaJogador1();
                }

                else if(op == 'B' || op == 'b')
                {
                    comprarPecasJogador1();
                    mostrarPecasJogador1();
                }

                else if((op == 'C' || op == 'c'))
                {
                    int p1, p2;

                    //selecionar peça para jogar
                        printf("\n   Selecione uma peça:  \n");
                        mostrarPecasJogador1();

                        scanf("%d%d", &p1, &p2);

                    jogador1Jogou = jogadaJogador1(p1, p2); //jogada do jogador

                    if(jogador1Jogou == true){
                        trocarSentinelasJ1(p1, p2); //trocar peças jogadas pelo jogador
                    }
                    else{
                        printf("\n    Não há peças, é necessário comprar!");
                        opcoesJogador1();
                    }
                }
            }
            while(jogador1Jogou == false);

            //contar peças na sentinela, para verificar quem ganhou
                int contRestantesJ1 = contarRestantesJ1();
                    if(contRestantesJ1 == 0)
                        jogador1Ganhou = true;

            jogador = 1; //trocando a vez
        }

        //JOGADOR 2
        else if(jogador == 1)
        {
            system("cls");

            bool jogador2Jogou = false;

            do
            {
                system("cls");
                printf("    Mesa de jogo:  \n");
                mostrarMesaDeJogo();
                printf("\n \n");
                mostrarPecasJogador2();

                opcoesJogador2();
                printf("\n \n");
                scanf("   %c", &op);

                if(op == 'V' || op == 'v')
                {
                    mostrarSequenciaJogador2();
                }

                else if(op == 'B' || op == 'b')
                {
                    comprarPecasJogador2();
                }
                else if((op == 'C' || op == 'c'))
                {
                    int p1, p2;

                    //selecionar peça para jogar
                        printf("\n   Selecione uma peça:  \n");
                        mostrarPecasJogador2();

                        scanf("%d%d", &p1, &p2);

                        jogador2Jogou = jogadaJogador2(p1, p2);

                    if(jogador2Jogou){
                        trocarSentinelasJ2(p1, p2); //trocar peças jogadas pelo jogador
                    }

                    else
                    {
                        printf("\n    Não há peças, é necessário comprar!");
                        opcoesJogador2();
                    }
                }
            }
            while(jogador2Jogou == false);

            //contar peças na sentinela, para verificar quem ganhou
                int contRestantesJ2 = contarRestantesJ2();

                if(contRestantesJ2 == 0)
                jogador2Ganhou = true;

            jogador = 2; //trocando a vez
        }
    }
    while (!jogador1Ganhou || !jogador2Ganhou);
}

int verificarPecaInicial()
{
    int jogador;
    int pecaMaisAltaJ1 = 0;
    int pecaMaisAltaJ2 = 0;
    bool pecaDupla = false;

    for(int j = 11; j == 66; j=j+11) //verificando se a peça é dupla
    {
        if(jogador1.pecasJogadores[j].Vh == j)
            pecaMaisAltaJ1 = j;

        if(jogador2.pecasJogadores[j].Vh == j)
            pecaMaisAltaJ2 = j;

    }
    if(pecaMaisAltaJ1 != 0 || pecaMaisAltaJ2 != 0)
        pecaDupla = true;

    if(pecaDupla == true) //se for dupla, ver a maior
    {
        if(pecaMaisAltaJ1 > pecaMaisAltaJ2)
        {
            for(int i = 0; i < 14; i++)
            {
                if(pecaMaisAltaJ1 == jogador1.pecasJogadores[i].Vh)
                {
                    mesaDeJogo[21].p1 = jogador1.pecasJogadores[i].p1;
                    mesaDeJogo[21].p2 = jogador1.pecasJogadores[i].p2;

                    jogador1.pecasJogadores[i].p1 = 9;
                    jogador1.pecasJogadores[i].p2 = 9;
                }
            }

            jogador = 1;
        }
        else
        {
            for(int i = 0; i < 14; i++)
            {
                if(pecaMaisAltaJ2 == jogador2.pecasJogadores[i].Vh)
                {
                    mesaDeJogo[21].p1 = jogador2.pecasJogadores[i].p1;
                    mesaDeJogo[21].p2 = jogador2.pecasJogadores[i].p2;

                    jogador2.pecasJogadores[i].p1 = 9;
                    jogador2.pecasJogadores[i].p2 = 9;
                }
            }
            jogador = 2;
        }

    }

    else //senão, sem ser dupla
    {
        for(int i = 0; i < 14; i++)
        {
            if(jogador1.pecasJogadores[i].p1 != 9)
            {
                if(jogador1.pecasJogadores[i].Vh > pecaMaisAltaJ1)
                    pecaMaisAltaJ1 = jogador1.pecasJogadores[i].Vh;
            }
        }

        for(int i = 0; i < 14; i++)
        {
            if(jogador2.pecasJogadores[i].p1 != 9)
            {
                if(jogador2.pecasJogadores[i].Vh > pecaMaisAltaJ2)
                    pecaMaisAltaJ2 = jogador2.pecasJogadores[i].Vh;
            }
        }

        if(pecaMaisAltaJ1 > pecaMaisAltaJ2)
        {
            jogador = 1;
        }
        else
        {
            jogador = 2;
        }
    }


    //mudando a peça na mão de quem tirou a mais alta
    if(jogador == 1)
    {
        for(int i = 0; i < 14; i++)
        {
            if(pecaMaisAltaJ1 == jogador1.pecasJogadores[i].Vh)
            {
                mesaDeJogo[21].p1 = jogador1.pecasJogadores[i].p1;
                mesaDeJogo[21].p2 = jogador1.pecasJogadores[i].p2;

                jogador1.pecasJogadores[i].p1 = 9;
                jogador1.pecasJogadores[i].p2 = 9;
            }
        }
    }

    else if(jogador == 2)
    {
        for(int i = 0; i < 14; i++)
        {
            if(pecaMaisAltaJ2 == jogador2.pecasJogadores[i].Vh)
            {
                mesaDeJogo[21].p1 = jogador2.pecasJogadores[i].p1;
                mesaDeJogo[21].p2 = jogador2.pecasJogadores[i].p2;

                jogador2.pecasJogadores[i].p1 = 9;
                jogador2.pecasJogadores[i].p2 = 9;
            }
        }
    }

    return jogador; //retorna quem possui a peça 66 ou a mais alta
}

int contarRestantesJ1(){
    int cont = 0;
    for(int i = 0; i < 14; i++){
        if(jogador1.pecasJogadores[i].p1 == 9 && jogador1.pecasJogadores[i].p2 == 9)
                cont++;
    }

    return cont;

}

int contarRestantesJ2(){

    int cont = 0;
    for(int i = 0; i < 14; i++){
        if(jogador2.pecasJogadores[i].p1 == 9 && jogador2.pecasJogadores[i].p2 == 9)
                cont++;
    }

    return cont;

}
