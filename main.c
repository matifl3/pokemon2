#include "liblistaO.h"
int main()
{

    printf("Hello world!\n");
    nodoTipo* listaO=inicListaT();
//    listaO=cargarNodoTipo(listaO);
//    listaO=cargarNodoTipo(listaO);
//    listaO=cargarNodoTipo(listaO);
//    listaO=cargarNodoTipo(listaO);
//    listaO=cargarNodoTipo(listaO);
//    listaO=cargarUnaCarta(listaO);
//    listaO=cargarUnaCarta(listaO);
//    listaO=cargarUnaCarta(listaO);
//    listaO=cargarUnaCarta(listaO);

////    listaO=eliminarCarta(listaO);
//////    printf("\n");
//////    mostrarListaTipo(listaO);
//////    nodoPoke* aux= buscarCartaNombreO(listaO);
//////    printf("\n");
//////    listaO=leerMazo(listaO);
//////    mostrarListaTipo(listaO);


//   guardarMazo2(listaO);

    listaO=leerMazo2(listaO);
    //mostrarCatasMazo(listaO);
    mostrarListaTipo(listaO);

    mostrarPrecios(listaO);
    mostrarPromedioCartasxTipo(listaO);
    mostrarCantidadRarezas(listaO);
////    printf("\n");

    return 0;
}
