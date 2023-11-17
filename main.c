#include "liblistaO.h"

int main()
{


    nodoTipo* listaO=inicListaT();
    listaO=leerMazo2(listaO);
    nodoPila*pila=inicPila();

    menu(listaO,pila);

    return 0;
}
