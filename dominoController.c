#include "dominoModel.h"
#include "dominoView.h"
#include "dominoController.h"

#include <stdbool.h>
#include <stdio.h>
//CONTROLE DO JOGO

int opcao;
bool fim = false;
bool entradaValida = false;

void inicializarController(){
    do
    {
        int op = menuInicialJogo();

        switch (op)
        {
            case 1:
                    totalJogadores();
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:
                    //view
                break;
            case 6:
                fim = true;
                break;

            default:
                printf("Opcão do menu inválida! \n");
        }
    }
    while (!fim);
}
