#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include "dominoModel.h"
#include "dominoView.h"
#include "dominoController.h"

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    system("mode con:cols=140 lines=36");
    srand(time(NULL)); //para que os números aleatórios não repitam
    inicializarController();
    return 0;
}
