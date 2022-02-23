#include <iostream>
#include "computador.h"
#include <stdlib.h>

using namespace std;

int main()
{
    Computador* C1=new Computador();
    C1->imprimir();
    //system("clear");
    C1->abrir_app();
    
    C1->download_arquivo();
    C1->excluir_arquivo();
    C1->imprimir();
    return 0;
}
