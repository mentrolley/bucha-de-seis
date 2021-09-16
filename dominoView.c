#include "dominoModel.h"
#include "dominoView.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

//TUDO O QUE VAMOS MOSTRAR NA TELA

int menuInicialJogo(){
    int op;

    printf("\n \n Jogo de Domino (PUC-SP)\n");
    printf("\n  (1) - Iniciar novo jogo \n");
    printf("  (2) - Continuar a jogar\n");
    printf("  (3) - Regras do jogo\n");
    printf("  (4) - Sair do jogo \n");
    printf("  ");

    scanf("%d",&op);
    return op;
}

int opIniciarJogo(){
    int op;

    printf("\n Deseja iniciar um novo jogo?");
    printf("\n (7) - Sim | (8) - Voltar ao menu principal ");
    scanf("%d", &op);

    return op;
}

int opComecarJogo(){
    int op;

    printf("\n Começar novo jogo?");
    printf("\n (7) - Sim | (8) - Voltar ao menu principal ");
    scanf("%d", &op);

    return op;
}

int totalJogadores(){
    int qtd = 0;

    printf("\n    (1) - Jogador vs. Computador\n    (2) - Jogador vs. Jogador ");
    scanf("%d", &qtd);

    if(qtd > 2 && qtd < 0){
        printf("\n  É permitido no máximo 2 jogadores!!! ");
    }

    return qtd;
}

void mostrarMesaDeJogo(){

    for(int i = 0; i < 42; i++){
        if(mesaDeJogo[i].p1 == 9)
            printf("  |");
        else
            if (i == 21)
                printf("*%d%d*|", mesaDeJogo[i].p1, mesaDeJogo[i].p2);
            else
                printf(" %d%d |", mesaDeJogo[i].p1, mesaDeJogo[i].p2);
    }

}

char opcoesJogador1(){
    char op;
    printf("\n   Jogador 1: \n    (C) - Jogar | (V) - Ver Peças | (B) - Comprar Peças | (S) - Salvar jogo | (M) - Voltar ao menu  "); //comprar -> apenas para a etapa 3
    printf("\n \n");
    scanf("   %c", &op);

    return op;
}

char opcoesJogador2(){
    char op;
    printf("\n   Jogador 2: \n    (C) - Jogar | (V) - Ver Peças | (B) - Comprar Peças | (S) - Salvar jogo | (M) - Voltar ao menu  "); //comprar -> apenas para a etapa 3
    printf("\n \n");
    scanf("   %c", &op);

    return op;
}

void mostrarPecasJogador1(){
    printf("\n   Jogador 1: |");
    for(int i = 0; i < 14; i++)
        if(jogador1.pecasJogadores[i].p1 != 9 && jogador1.pecasJogadores[i].p2 != 9)
            printf("%d%d |", jogador1.pecasJogadores[i].p1, jogador1.pecasJogadores[i].p2);
    printf("\n");
}

void mostrarSequenciaJogador1(){
    printf("\n   Jogador 1: |");
    for(int i =0 ; i < 14; i++)
        if(jogador1.pecasJogadores[i].p1 != 9 && jogador1.pecasJogadores[i].p2 != 9)
            printf("%02d |",jogador1.pecasJogadores[i].Vh);
    printf("\n");
}

void mostrarPecasJogador2(){
    printf("\n   Jogador 2: |");
    for(int i = 0; i < 14; i++)
        if(jogador2.pecasJogadores[i].p1 != 9 && jogador2.pecasJogadores[i].p2 != 9)
            printf("%d%d |", jogador2.pecasJogadores[i].p1, jogador2.pecasJogadores[i].p2);
    printf("\n");

}

void mostrarSequenciaJogador2(){
    printf("\n   Jogador 2: |");
    for(int i =0 ; i < 14; i++)
        if(jogador2.pecasJogadores[i].p1 != 9 && jogador2.pecasJogadores[i].p2 != 9)
            printf("%02d |",jogador2.pecasJogadores[i].Vh);
    printf("\n");
}

void pecasRestantes(){
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

int posicaoMesa(){
    int lado;

    printf("\n   Posicionar na esquerda (1) ou direita (2)?: \n");
    scanf("%d", &lado);

    return lado;
}

int opSalvar(){

    printf("\n    Deseja salvar o jogo salvo?\n        (1) - Sim | (2) - Não");

    int simNao = scanf("  %d", &simNao);

    return simNao;
}

int opCarregar(){

    printf("\n    Deseja carregar o último jogo salvo?\n        (1) - Sim | (2) - Não ");

    int simNao = scanf("  %d", &simNao);

    return simNao;
}

void limparMesa(){

    system("cls");
    printf("    Mesa de jogo:  \n");
    mostrarMesaDeJogo();
    printf("\n \n");

}

bool verRegras(){

    bool fechar;
    system("cls");

    printf("\n      As regras do jogo são bem simples: cada jogador pega sete peças e pode comprar sempre que precisar de uma peça para poder jogar e quantas vezes for necessário. ");
    printf("\n  Dá-se início ao jogo o jogador que tirar a pedra 'seis-seis'. \n Caso ninguém tenha o tirado, inicia-se o jogador que tiver a peça  com  os  números  repetidos  mais  altos,  ou  seja,  “cinco-cinco”,  “quatro-quatro”,  e  assim sucessivamente. ");
    printf("\n  O jogo acontece no sentido anti-horário e os jogadores devem colocar peças que tenham os mesmos números das peças que se encontram na ponta do jogo. O jogador que começa a partida leva vantagem. Este é um conceito importante para a estratégia do dominó, pois o jogador que começa, normalmente, é o que leva a vantagem durante a partida. ");

    printf("\n\n      Cada jogador, no seu turno, deve colocar uma das suas peças em uma das 2 extremidades abertas, de forma que os pontos de um dos lados coincidamcom os pontos da extremidade onde está  sendo  colocada. ");
    printf("\n  As  dobradas  são  colocadas  de  maneira  transversal  para  facilitar  sua localização. Quando o jogador coloca sua peça sobre a mesa, seu turno se acaba e passa-se ao seguinte jogador. ");

    printf("\n\n      Se um jogador não puder jogar, deverá “comprar” do monte tantas peças como forem necessárias. Se não houver peças no monte, passará o turno ao seguinte jogador. ");
    printf("\n      A partida continua com os jogadores colocando suas peças sobre a mesa até que se apresente alguma das seguintes situações: ");
    printf("\n\n          * Quando um jogador coloca sua última pedra na mesa, essa ação é chamada de bater. \nQuando joga-se sozinho, o jogador que ganhou a partida soma os pontos de todos os seus adversários.");
    printf("\n      Jogando em dupla, somam-se os pontos de todos os jogadores incluindo os do seu companheiro. ");
    printf("\n\n          * Existem casos onde nenhum dos jogadores pode continuar a partida. Isto ocorre quando o número das extremidades saiu 7 vezes antes. Nesse momento se diz que a partida está fechada.");
    printf("\n      Os jogadores contarão os pontos das pedras que ficaram; o jogador ou dupla com menos pontos vencem e somam-se os pontos da maneira habitual. ");

    printf("\n \n   (7) - Fechar ");
    int op = scanf("%d", &op);

    if(op == 7)
        fechar = true;

    return fechar;
}

void printOpcaoInvalida(){
    printf("\n   Opcão do menu inválida! \n");
}

void printSelectPecas(){
    printf("\n   Selecione uma peça:  \n");
}

void printErroPecas(){
    printf("\n    Não há peças, é necessário comprar!");
}

int printPecasRestantesComp(){
    int cont = 0;

    for(int i = 0; i < 7; i++){
        if(jogador2.pecasJogadores[i].p1 != 9 && jogador2.pecasJogadores[i].p2 != 9){
            cont++;
        }

    }

    printf("                 Computador: %d peças restantes\n", cont);

    return cont;
}

void printComputador(){
    printf("\n    Computador jogando...");
}

void printVencedor(int jogador, bool computador){
    int jg = jogador;
    bool comp = computador;

    if(comp == false){
        if(jg== 1)
            printf("\n \n JOGADOR 1 VENCEU!!!");
        else
            printf("\n \n JOGADOR 2 VENCEU!!!");
    }
    else
        printf("\n \n COMPUTADOR VENCEU!!!");

}
