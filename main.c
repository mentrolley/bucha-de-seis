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
    srand(time(NULL)); //para que os n�meros aleat�rios n�o repitam
    inicializarController();

    //***************************
    //REQ1 + REQ4
    //mostrar as 28 pe�as


    //***************************
    //REQ2
    //distribuir/embaralhar pe�as para cada jogador


    //***************************
    //REQ3
    //sequ�ncia correta


    //********************


    return 0;
}
