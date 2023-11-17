#include "liblistaO.h"

int main()
{


    nodoTipo* listaO=inicListaT();
    listaO=leerMazo2(listaO);
    nodoPila*pila=inicPila();
    nodoA*jugador1=inicArbol();
    nodoA*jugador2=inicArbol();

    menu(listaO,pila,jugador1,jugador2);

    return 0;
}
