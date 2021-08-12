int opcao,i;
bool fim = false;
bool entradaValida;

do
{
    printf("Jogo de Domino(puc-sp)\n");
    printf("\n(1) - Iniciar novo jogo !\n");
    printf("(2) - Continuar a jogar\n");
    printf("(3) - Salvar jogo\n");
    printf("(4) - Carregar jogo\n");
    printf("(5) - Rrgras do jogo\n");
    printf("(6) - Sair do jogo\n");;
    scanf("%d",&opcao);

    entradaValida= false;

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

        break;

    case 6:

        fim = true;

        break;

    default:
        printf("Opcao do menu invalida\n");
    }
}
while (!fim);
