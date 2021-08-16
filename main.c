#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#include "dominoModel.h"
#include "dominoView.h"
#include "dominoController.h"

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL)); //para que os números aleatórios não repitam
    inicializarController();

    //***************************
    //REQ1 + REQ4
    //mostrar as 28 peças


    //***************************
    //REQ2
    //distribuir/embaralhar peças para cada jogador


    //***************************
    //REQ3
    //sequência correta


    //********************


    return 0;
}
