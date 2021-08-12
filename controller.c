#include "model.h"
#include "view.h"
#include "controller.h"

int opcao;
bool fim = false;
bool entradaValida = false;

void inicializarController(){
    do
    {
        printf("Jogo de Dominó (PUC-SP)\n");
        printf("\n(1) - Iniciar novo jogo !\n");
        printf("(2) - Continuar a jogar\n");
        printf("(3) - Salvar jogo\n");
        printf("(4) - Carregar jogo\n");
        printf("(5) - Regras do jogo\n");
        printf("(6) - Sair do jogo\n");

        scanf("%d",&opcao);

        switch (opcao)
        {
            case 1:
                    
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
