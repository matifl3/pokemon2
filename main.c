#include "liblistaO.h"

int main()
{


    nodoTipo* listaO=inicListaT();
    listaO=leerMazo2(listaO);
    nodoPila*pila=inicPila();
    nodoA*jugador1=inicArbol();
    nodoA*jugador2=inicArbol();
    filaIter* fila;

    menu(listaO,pila,jugador1,jugador2,fila);

    return 0;
}
