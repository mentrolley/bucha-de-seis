#include "dominoModel.h"
#include "dominoView.h"
#include "dominoController.h"

#include <stdbool.h>
#include <stdio.h>
//CONTROLE DO JOGO

int opcao;
bool fim = true;
bool entradaValida = false;

void inicializarController(){
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
