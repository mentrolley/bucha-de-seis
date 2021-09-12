#include "dominoModel.h"
#include "dominoView.h"
#include "dominoController.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

//CONTROLE DO JOGO


void inicializarController()
{
    bool fim = true;
    do
    {
        int opcao = menuInicialJogo(); //retornando a opção para fazer o switch do menu

        switch (opcao)
        {
            int jogador;
            case 1:
                fim = comecarJogo();
                break;
            case 2:
                jogador = carregarJogo();
                    if (jogador == 1 || jogador == 2)
                        movimentosJogadores(jogador);
                    else
                        fim = false;
                break;
            case 3:
                fim = verRegras();
                system("cls");
                break;
            case 4:
                fim = false;
                break;

            default:
                printOpcaoInvalida();
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
        printOpcaoInvalida();
        prepararJogo();
    }

    return voltarMenu;
}

void jogoPrincipal()
{
    //verificar peça maior
    int jogador = verificarPecaInicial(); //quem começa

    //Jogo
    movimentosJogadores(jogador);
}

void movimentosJogadores(int jogador){

    bool jogador1Ganhou = false;
    bool jogador2Ganhou = false;
    int jg = jogador;

    do
    {
        //JOGADOR 1
        if(jg == 2)  //invertendo quem começa a jogar, pois quem tem a mais alta joga primeiro
        {
            bool jogador1Jogou = false;

            do
            {
                limparMesa();
                mostrarPecasJogador1();

                char op = opcoesJogador1();

                if(op == 'V' || op == 'v')
                {
                    mostrarSequenciaJogador1();
                }

                else if(op == 'B' || op == 'b')
                {
                    comprarPecasJogador1();
                }

                else if(op == 'S' || op == 's'){
                    salvarJogo(jogador);
                }

                else if(op == 'M' || op == 'm'){
                    system("cls");
                    inicializarController();
                }

                else if((op == 'C' || op == 'c'))
                {
                    int p1, p2;

                    //selecionar peça para jogar
                        printSelectPecas();
                        mostrarPecasJogador1();

                        scanf("%d%d", &p1, &p2);

                        jogador1Jogou = jogadaJogador1(p1, p2);

                    if(jogador1Jogou == true)
                        trocarSentinelasJ1(p1, p2); //trocar peças jogadas pelo jogador
                    else
                    {
                        printErroPecas();
                        opcoesJogador1();
                    }
                }
            }
            while(jogador1Jogou == false);

            //contar peças na sentinela, para verificar quem ganhou
            int contRestantesJ1 = contarRestantesJ1();

            if(contRestantesJ1 == 0)
                jogador1Ganhou = true;
            else
                jg = 1; //trocando a vez
        }

        //JOGADOR 2
        else if(jg == 1)
        {
            bool jogador2Jogou = false;

            do
            {
                limparMesa();
                mostrarPecasJogador2();

                char op = opcoesJogador2();

                if(op == 'V' || op == 'v')
                {
                    mostrarSequenciaJogador2();
                }

                else if(op == 'B' || op == 'b')
                {
                    comprarPecasJogador2();
                }

                else if(op == 'M' || op == 'm'){
                    system("cls");
                    inicializarController();
                }

                else if(op == 'S' || op == 's'){
                    salvarJogo(jogador);
                }

                else if((op == 'C' || op == 'c'))
                {
                    int p1, p2;

                    //selecionar peça para jogar
                        printSelectPecas();
                        mostrarPecasJogador2();

                        scanf("%d%d", &p1, &p2);

                        jogador2Jogou = jogadaJogador2(p1, p2);

                    if(jogador2Jogou == true)
                        trocarSentinelasJ2(p1, p2); //trocar peças jogadas pelo jogador
                    else
                    {
                        printErroPecas();
                        opcoesJogador2();
                    }
                }
            }
            while(jogador2Jogou == false);

            //contar peças na sentinela, para verificar quem ganhou
            int contRestantesJ2 = contarRestantesJ2();

            if(contRestantesJ2 == 0)
                jogador2Ganhou = true;
            else
                jg = 2; //trocando a vez

        }
    }
    while (jogador1Ganhou == false || jogador2Ganhou == false);


}

int verificarPecaInicial(){
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
        if(jogador1.pecasJogadores[i].p1 != 9 && jogador1.pecasJogadores[i].p2 != 9)
                cont++;
    }

    return cont;
}

int contarRestantesJ2(){

    int cont = 0;
    for(int i = 0; i < 14; i++){
        if(jogador2.pecasJogadores[i].p1 != 9 && jogador2.pecasJogadores[i].p2 != 9)
                cont++;
    }

    return cont;
}

bool verificandoNaMesa(int a, int b){

        bool colocou = true;
        int lado;
        int p1 = a;
        int p2 = b;

        //pega as primeiras peças livres na esquerda e direita
        int contEsquerda = 0;
        int contDireita = 27;

        while(mesaDeJogo[contEsquerda].p1 == 9)
            contEsquerda++;

        while(mesaDeJogo[contDireita].p1 == 9)
            contDireita--;

        int pecaEsq = mesaDeJogo[contEsquerda].p1;
        int pecaDir = mesaDeJogo[contDireita].p2;

        if(pecaEsq == pecaDir){

            lado = posicaoMesa();

                if(lado == 1)
                {
                    if(pecaEsq == p2)
                    {
                        colocandoNaMesa(lado, contEsquerda-1, p1, p2);
                    }
                    else if(pecaEsq == p1)
                    {
                        colocandoNaMesa(lado, contEsquerda-1, p2, p1);
                    }

                }
                else if(lado == 2)
                {
                    if(pecaDir == p2)
                    {
                        colocandoNaMesa(lado, contDireita+1, p2, p1);
                    }
                    else if(pecaDir == p1)
                    {
                        colocandoNaMesa(lado, contDireita+1, p1, p2);
                    }
                }
        }

        else if((pecaEsq == p1 || pecaEsq == p2) && (pecaDir == p1 || pecaDir == p2)){

            lado = posicaoMesa();

                if(lado == 1)
                {
                    if(pecaEsq == p2)
                    {
                        colocandoNaMesa(lado, contEsquerda-1, p1, p2);
                    }
                    else if(pecaEsq == p1)
                    {
                        colocandoNaMesa(lado, contEsquerda-1, p2, p1);
                    }

                }
                else if(lado == 2)
                {
                    if(pecaDir == p2)
                    {
                        colocandoNaMesa(lado, contDireita+1, p2, p1);
                    }
                    else if(pecaDir == p1)
                    {
                        colocandoNaMesa(lado, contDireita+1, p1, p2);
                    }
                }
        }

        else if(pecaEsq == p1 && !(pecaDir == p1))
            colocandoNaMesa(1, contEsquerda-1, p2, p1);

        else if(pecaEsq == p2 && !(pecaDir == p2))
            colocandoNaMesa(1, contEsquerda-1, p1, p2);

        else if(!(pecaEsq == p1) && pecaDir == p1)
            colocandoNaMesa(2, contDireita+1, p1, p2);

        else if(!(pecaEsq == p2) && pecaDir == p2)
            colocandoNaMesa(2, contDireita+1, p2, p1);

        else
            colocou = false;

    return colocou;
}

void salvarJogo(int jogador){
    int simNao = opSalvar();

    if(simNao == 1)
        gravarJogo(jogador);
}

int carregarJogo(){
    int simNao = opCarregar();
    int jogador;

    if(simNao == 1)
        jogador = lerJogo();

    return jogador;
}
