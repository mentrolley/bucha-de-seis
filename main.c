#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#include "dominoModel.h"
#include "dominoView.h"
#include "dominoController.h"


#include "dominoModel.h"
#include "dominoView.h"
#include "dominoController.h"

int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL)); //para que os números aleatórios não repitam
    inicializarController();
    return 0;
}
