#include "dominoModel.h"
#include "dominoController.h"
#include "dominoView.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//APENAS O QUE ENVOLVE OS DADOS DO PROGRAMA
//printf() -> apenas para teste

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
            //printf("%d%d ", pecas[contPecas].p1, pecas[contPecas].p2);
            contPecas++;
        }
        //printf("\n");
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

    //printf("\n Mesa do jogo: \n");
    while(contPecas < 42)
    {

        //atribuindo os valores para cada peça
        mesaDeJogo[contPecas].p1 = 9;
        mesaDeJogo[contPecas].p2 = 9;
        contPecas++;
    }

    printf("\n \n");
}

void montarPecasJogador1()
{
    int dominoP1, dominoP2;
    int numPeca;
    int i;
    for(i = 0; i < 7; i++)
    {
        numPeca = rand() % 28;

        dominoP1 = pecas[numPeca].p1;
        dominoP2 = pecas[numPeca].p2;

        while(dominoP1 == 9 && dominoP2 == 9)
        {

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

    for(int j = i; j < 14; j++)
    {
        jogador1.pecasJogadores[j].p1 = 9;
        jogador1.pecasJogadores[j].p2 = 9;
    }
}

void montarSequenciaJogador1()
{

    //printf("\n \n");
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
    int i;

    for(i = 0; i < 7; i++)
    {
        numPeca = rand() % 28;
        dominoP1 = pecas[numPeca].p1;
        dominoP2 = pecas[numPeca].p2;

        while(dominoP1 == 9 && dominoP2 == 9)
        {

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

    for(int j = i; j < 14; j++)
    {
        jogador2.pecasJogadores[j].p1 = 9;
        jogador2.pecasJogadores[j].p2 = 9;
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

void comprarPecasJogador1()
{

    int cont = 0;
    int i;

    for(i = 0; i < 14; i++)
    {
        if(jogador1.pecasJogadores[i].p1 == 9)
            cont = i;
    }

    //for(int j = cont; j == j+1; j++){

    int numPeca = rand() % 28;
    int dominoP1 = pecas[numPeca].p1;
    int dominoP2 = pecas[numPeca].p2;

    while(dominoP1 == 9 && dominoP2 == 9)
    {

        numPeca = rand() % 28;

        dominoP1 = pecas[numPeca].p1;
        dominoP2 = pecas[numPeca].p2;
    }

    jogador1.pecasJogadores[cont].p1 = dominoP1;
    jogador1.pecasJogadores[cont].p2 = dominoP2;
    jogador1.pecasJogadores[cont].Vh = dominoP1*10 + dominoP2;

    pecas[numPeca].p1 = 9;
    pecas[numPeca].p2 = 9;
    // }

}

void comprarPecasJogador2()
{

    int cont = 0;
    int i;

    for(i = 0; i < 14; i++)
    {
        if(jogador2.pecasJogadores[i].p1 == 9)
            cont = i;
    }

    //for(int j = cont; j == j+1; j++){

    int numPeca = rand() % 28;
    int dominoP1 = pecas[numPeca].p1;
    int dominoP2 = pecas[numPeca].p2;

    while(dominoP1 == 9 && dominoP2 == 9)
    {

        numPeca = rand() % 28;

        dominoP1 = pecas[numPeca].p1;
        dominoP2 = pecas[numPeca].p2;
    }

    jogador2.pecasJogadores[cont].p1 = dominoP1;
    jogador2.pecasJogadores[cont].p2 = dominoP2;
    jogador2.pecasJogadores[cont].Vh = dominoP1*10 + dominoP2;

    pecas[numPeca].p1 = 9;
    pecas[numPeca].p2 = 9;
    // }

}

bool jogadaJogador1(int a, int b) //jogador 1 jogando
{
    bool jogou = false;
    bool pecaOk = false;

    int p1 = a;
    int p2 = b;

    //verficar se a peça é válida
    for(int i = 0; i < 14; i++)
        if(jogador1.pecasJogadores[i].p1 == p1 && jogador1.pecasJogadores[i].p2 == p2)
            pecaOk = true;

    //colocar peça na mesa de jogo
    if(pecaOk == true)
        jogou = verificandoNaMesa(p1, p2);

    return jogou;
}

void trocarSentinelasJ1(int a, int b){

    int p1 = a;
    int p2 = b;

    //trocar sentinela nas peças
        for(int i = 0; i < 14; i++)
            if(jogador1.pecasJogadores[i].p1 == p1 && jogador1.pecasJogadores[i].p2 == p2)
            {
                jogador1.pecasJogadores[i].p1 = 9;
                jogador1.pecasJogadores[i].p2 = 9;
            }
}

bool jogadaJogador2(int a, int b) //jogador 1 jogando
{
    bool jogou = false;

    int p1 = a;
    int p2 = b;
    int pecaOk = false;

    //verficar se a peça é válida na mão do jogador
    for(int i = 0; i < 14; i++)
        if(jogador2.pecasJogadores[i].p1 == p1 && jogador2.pecasJogadores[i].p2 == p2)
            pecaOk = true;

    //colocar peça na mesa de jogo
    if(pecaOk == true)
        jogou = verificandoNaMesa(p1, p2);


    return jogou;
}

void trocarSentinelasJ2(int a, int b){

    int p1 = a;
    int p2 = b;
    //trocar sentinela nas peças
        for(int i = 0; i < 14; i++)
            if(jogador2.pecasJogadores[i].p1 == p1 && jogador2.pecasJogadores[i].p2 == p2)
            {
                jogador2.pecasJogadores[i].p1 = 9;
                jogador2.pecasJogadores[i].p2 = 9;
            }
}

//COLOCANDO PEÇAS NA MESA
//AINDA COM PROBLEMAS PRA IR PARA O LADO QUE O JOGADOR QUER QUANDO É POSSÍVEL

void colocandoNaMesa(int l, int p, int a, int b){ //lado, posição, p1, p2

    int lado = l;
    int pos = p;
    int p1 = a;
    int p2 = b;

    if(lado == 1){
        mesaDeJogo[pos].p1 = p1;
        mesaDeJogo[pos].p2 = p2;
    }
    else if(lado == 2){
        mesaDeJogo[pos].p1 = p1;
        mesaDeJogo[pos].p2 = p2;
    }
}


///////////////////////


void gravarJogo(int jogador){

    FILE *jogo;
    jogadorSalvar.j = jogador;

    jogo = fopen("dominoSalvar.dat", "w+b");

    if(jogo != NULL){
        fwrite(&pecas, sizeof(pecas), 1, jogo);
        fwrite(&mesaDeJogo, sizeof(mesaDeJogo), 1, jogo);
        fwrite(&jogador1, sizeof(jogador1), 1, jogo);
        fwrite(&jogador2, sizeof(jogador2), 1, jogo);
        fwrite(&jogadorSalvar, sizeof(int), 1, jogo); //quem jogou por último
    }

    fclose(jogo);
}

int lerJogo(){

    FILE *jogo;
    int j;
    jogo = fopen("dominoSalvar.dat", "r+b");

    if(jogo != NULL){
        fread(&pecas, sizeof(pecas), 1, jogo);
        fread(&mesaDeJogo, sizeof(mesaDeJogo), 1, jogo);
        fread(&jogador1, sizeof(jogador1), 1, jogo);
        fread(&jogador2, sizeof(jogador2), 1, jogo);
        j = fread(&jogadorSalvar, sizeof(int), 1, jogo); //lê quem jogou por último
    }

    fclose(jogo);
    return j;
}





