#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "gotoxy.h"
#include "liblistaO.h"


nodoPoke* inicListaP()
{
    return NULL;
}
nodoTipo* inicListaT()
{
    return NULL;
}
nodoPoke* crearNodoPoke(stCarta cartita)
{
    nodoPoke* aux=(nodoPoke*)malloc(sizeof(nodoPoke));
    aux->dato= cartita;
    aux->siguiente= inicListaP();
    return aux;
}
nodoTipo* crearNodoTipo(char nombre[])
{
    nodoTipo* aux=(nodoTipo*)malloc(sizeof(nodoTipo));
    strcpy(aux->tipo, nombre);
    aux->siguiente= inicListaT();
    aux->lista=inicListaT();
    return aux;
}
nodoTipo* cargarNodoTipo(nodoTipo* listaO)
{
    nodoTipo* nuevo;
    int existe=0;
    while(existe==0)
    {
        char tiPo[20];
        printf("ingrese el Tipo de cartas: ");
        fflush(stdin);
        gets(tiPo);
        nuevo= crearNodoTipo(tiPo);
        if(existeNodoTipo(listaO, nuevo->tipo)==1)
        {
            printf("El tipo de carta ya existe ingrese uno nuevo: \n");
            printf("ingrese 0 si quire ingresar otro tipo sino ingrese cualquier caracter: \n");
            fflush(stdin);
            scanf("%d", &existe);
        }
        else
        {
            listaO=agregarAlFinalTipo(listaO, nuevo);
            existe=1;
        }
    }
    return listaO;
}
nodoTipo* buscarUltimoTipo(nodoTipo* lista)
{
    nodoTipo* aux=lista;
    if(aux!=NULL)
    {
        while(aux->siguiente!=NULL)
        {
            aux=aux->siguiente;
        }
    }
    return aux;
}
nodoTipo* agregarAlFinalTipo(nodoTipo * lista,nodoTipo * nuevo)
{

    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nodoTipo * ultimo=buscarUltimoTipo(lista);
        ultimo->siguiente=nuevo;
    }
    return lista;
}
int existeNodoTipo(nodoTipo* listaO, char nombreT[])
{
    int existe=0;
    if(listaO!=NULL)
    {
        while(listaO!=NULL)
        {
            if(strcmp(listaO->tipo, nombreT)==0)
            {
                existe=1;
            }
            listaO=listaO->siguiente;
        }
    }
    return existe;
}
void mostrarListaTipo(nodoTipo* listaO)
{
    if(listaO!=NULL)
    {
        while(listaO!=NULL)
        {
            color(14);//color amarillo
            printf("\n------------\t%s\t------------ \n", listaO->tipo);
            color(15);//color blanco
            mostrarListaCarta(listaO->lista);
            listaO=listaO->siguiente;
            printf("\n");
        }
    }
}
void mostrarListaCarta(nodoPoke* lista)
{
    if(lista!=NULL)
    {
        while(lista!=NULL)
        {


            printf("Nombre: %s\n",lista->dato.nombre);
            if(lista->dato.rareza==1)
            {
                printf("Rareza: Comun.\n");
            }
            else if(lista->dato.rareza==2)
            {
                printf("Rareza: Poco Comun.\n");
            }
            else if(lista->dato.rareza==3)
            {
                printf("Rareza: Raro.\n");
            }
            else if(lista->dato.rareza==4)
            {
                printf("Rareza: Legendario.\n");
            }
            printf("hp: %d\n",lista->dato.hp);
            printf("lvl: %d\n",lista->dato.lvl);
            if(lista->dato.calidadC==1)
            {
                printf("Calidad: Comun.\n");
            }
            else if(lista->dato.calidadC==2)
            {
                printf("Calidad: Infrecuente.\n");
            }
            else if(lista->dato.calidadC==3)
            {
                printf("Calidad: Rara.\n");
            }
            else if(lista->dato.calidadC==4)
            {
                printf("Calidad: Holografica.\n");
            }
            else if(lista->dato.calidadC==5)
            {
                printf("Calidad: Luminosa.\n");
            }
            else if(lista->dato.calidadC==6)
            {
                printf("Calidad: Secreta.\n");
            }
            printf("Precio: %d",lista->dato.precio);



            lista=lista->siguiente;
        }
    }
}
void mostrarCatasMazo(nodoTipo* listaO)
{
    if(listaO!=NULL)
    {
        while(listaO!=NULL)
        {
            nodoPoke* seg=listaO->lista;
            printf("%s\n",listaO->tipo);
            while(seg!=NULL)
            {
                printf("Nombre de la carta: %s \n",seg->dato.nombre);
                seg=seg->siguiente;
            }
            listaO=listaO->siguiente;
        }
    }
}
///------------------------------------2-------------------------------------------------///
stCarta cargarCarta(char tipoC[])
{
    stCarta carta;
    strcpy(carta.tipo,tipoC);
    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(carta.nombre);
    printf("\nRarezas: \n\t\t1-comun\n\t\t2-poco comun\n\t\t3-raro\n\t\t4-legendario \nIngrese una rareza: ");
    scanf("%d",&carta.rareza);
    while(verificaRareza(carta.rareza)==1)
    {
        printf("\nRareza Ingresada Incorrecta \nRarezas: \n\t\t1-comun\n\t\t2-poco comun\n\t\t3-raro\n\t\t4-legendario \nIngrese una rareza: ");
        scanf("%d",&carta.rareza);
    }
    printf("Ingrese Nivel: ");
    scanf("%d",&carta.lvl);
    while(verificalvl(carta.lvl)==1)
    {
        printf("Ingreso Nivel Incorrecto.\nIngrese nuevo Nivel: ");
        scanf("%d",&carta.lvl);
    }
    printf("Ingrese hp: ");
    scanf("%d",&carta.hp);
    while(verificaHp(carta.hp)==1)
    {
        printf("Ingreso HP Incorrecto. \nIngrese nuevo HP: ");
        scanf("%d",&carta.hp);
    }
    printf("Ingrese el precio de la carta: ");
    scanf("%d",&carta.precio);
    while(verificaPrecio(carta.precio)==1)
    {
        printf("El precio ingresado no es valido porfavor ingrese otro:");
        scanf("%d",&carta.precio);
    }
    printf("Ingrese la calidad de la carta: ");
    printf("\nRarezas: \n\t\t1-comun\n\t\t2-Infrecuente\n\t\t3-Rara\n\t\t4-holo\n\t\t5-Luminosa\n\t\t6-Secreta \nIngrese una Calidad : ");
    scanf("%d",&carta.calidadC);
    while(verificaCalidadC(carta.calidadC)==1)
    {
        printf("La calidad de la carta no existe ingrese nuevamente: ");
        printf("\nRarezas: \n\t\t1-comun\n\t\t2-Infrecuente\n\t\t3-Rara\n\t\t4-holo\n\t\t5-Luminosa\n\t\t6-Secreta \nIngrese una Calidad : ");
        scanf("%d", &carta.calidadC);
    }
    return carta;
}

int verificalvl(int lvl)
{
    int flag=0;
    if(lvl<1 || lvl>100)
        flag=1;
    return flag;
}
int verificaHp(int hp)
{
    int flag=0;
    if(hp<0 || hp>99)
        flag=1;
    return flag;
}
int verificaRareza(int rareza)
{
    int flag=0;
    if(rareza < 1 || rareza > 4)
        flag=1;
    return flag;
}
int verificaPrecio(int precio)
{
    int flag=0;
    if(precio<0)
    {
        flag=1;
    }
    return flag;
}
int verificaCalidadC(int calidad)
{
    int flag=0;
    if(calidad<0||calidad>6)
    {
        flag=1;
    }
    return flag;
}
nodoTipo* agregarCarta(nodoTipo * listaO,nodoPoke * nuevoPOke,char tipo[])
{
    if(listaO!=NULL)
    {
        nodoTipo * lugar=buscarTipoLugar(listaO,tipo);
        lugar->lista=agregarAlFinalPoke(lugar->lista,nuevoPOke);
    }
    return listaO;
}
nodoPoke* agregarAlFinalPoke (nodoPoke* lista,nodoPoke* nuevo)
{
    if(lista==NULL)
    {
        lista=nuevo;
    }
    else
    {
        nodoPoke* ultimo=buscarUltimo(lista);
        ultimo->siguiente=nuevo;
    }
    return lista;
}
nodoTipo* buscarTipoLugar(nodoTipo * lista,char tipo[20])
{
    nodoTipo * aux=lista;

    if(aux!=NULL)
    {
        while(strcmp(aux->tipo,tipo)!=0&&aux!=NULL)
        {
            aux=aux->siguiente;
        }
    }

    return aux;
}
nodoPoke * buscarUltimo(nodoPoke * lista)
{
    nodoPoke * aux=lista;
    if(aux!=NULL)
    {
        while(aux->siguiente!=NULL)
        {
            aux=aux->siguiente;
        }
    }
    return aux;
}
nodoTipo* cargarUnaCarta(nodoTipo* listaO)///funcion main
{
    if(listaO!=NULL)
    {
        char tipo[20];
        printf("ingrese el tipo que pertenece la carta: ");
        fflush(stdin);
        gets(tipo);
        if(existeNodoTipo(listaO, tipo)==1)
        {
            stCarta cartita = cargarCarta(tipo);
            nodoPoke* carta = crearNodoPoke(cartita);
            listaO=agregarCarta(listaO, carta, tipo);
        }
        else
        {
            printf("El tipo no exite :\n");
        }
    }
    else
    {
        printf("no hay colecciones cargadas porfavor ingrese al inciso 1 y carge un tipo: \n");
    }
    return listaO;
}

///----------------------------------------punto 3-busqueda de carta-------------------------------///

nodoPoke* buscarCartaNombreO(nodoTipo* listaO)
{
    nodoPoke* cBuscada=inicListaP();
    nodoPoke* auxPoke;
    char nombreBuscado[20];
    printf("ingrese el nombre de la carta a buscar: ");
    fflush(stdin);
    gets(nombreBuscado);
    if(listaO!=NULL)
    {
        while(listaO!=NULL)
        {
            auxPoke=listaO->lista;
            while(auxPoke!=NULL)
            {
                if(strcmp(auxPoke->dato.nombre,nombreBuscado)==0)
                {
                    cBuscada=auxPoke;
                }
                auxPoke=auxPoke->siguiente;
            }
            listaO=listaO->siguiente;
        }
    }
    else
    {
        printf("El mazo esta vacio:\n");
    }

    return cBuscada;
}

nodoPoke* buscarCartaNombreYTipo(nodoTipo* listaO,char nombreBuscado[])
{
    nodoPoke* cBuscada=inicListaP();
    nodoPoke* auxPoke;
    if(listaO!=NULL)
    {
        while(listaO!=NULL)
        {
            auxPoke=listaO->lista;
            while(auxPoke!=NULL)
            {
                if(strcmp(auxPoke->dato.nombre,nombreBuscado)==0)
                {
                    cBuscada=auxPoke;
                }
                auxPoke=auxPoke->siguiente;
            }
            listaO=listaO->siguiente;
        }
    }
    else
    {
        printf("El mazo esta vacio:\n");
    }

    return cBuscada;
}


///------------------punto 4-eliminar una carta---------------------------///
nodoTipo* eliminarCarta(nodoTipo* listaO)
{
    nodoPoke* cBuscada;
    nodoTipo* seg= listaO;
    nodoPoke* auxPoke;
    nodoPoke* antePoke;
    int flagBorrado = 0;
    char nombreBuscado[20];
    printf("Usted tiene estas cartas :");
    mostrarListaTipo(listaO);
    printf("ingrese el nombre de la carta a eliminar: ");
    fflush(stdin);
    gets(nombreBuscado);
    if(seg!=NULL)
    {
        while((seg!=NULL) && (flagBorrado == 0))
        {
            auxPoke=seg->lista;
            if(strcmp(auxPoke->dato.nombre, nombreBuscado)==0)
            {
                cBuscada=auxPoke;
                free(cBuscada);
                seg->lista=auxPoke->siguiente;
                flagBorrado=1;
            }
            else
            {
                while((auxPoke!=NULL)  && (flagBorrado == 0))
                {
                    if(strcmp(auxPoke->dato.nombre,nombreBuscado)==0)
                    {
                        cBuscada=auxPoke;
                        auxPoke=auxPoke->siguiente;
                        antePoke->siguiente= auxPoke;
                        free(cBuscada);
                        flagBorrado = 1;
                    }
                    else
                    {
                        antePoke= auxPoke;
                        auxPoke=auxPoke->siguiente;
                    }
                }

            }
            seg=seg->siguiente;
        }
    }
    else
    {
        printf("El mazo esta bacio:\n");
    }
    return listaO;
}

nodoTipo* eliminarCartaTipo(nodoTipo* listaO,char nombreBuscado[])
{
    nodoPoke* cBuscada;
    nodoTipo* seg= listaO;
    nodoPoke* auxPoke;
    nodoPoke* antePoke;
    int flagBorrado = 0;
    printf("Usted tiene estas cartas :");
    mostrarListaTipo(listaO);
    if(seg!=NULL)
    {
        while((seg!=NULL) && (flagBorrado == 0))
        {
            auxPoke=seg->lista;
            if(strcmp(auxPoke->dato.nombre, nombreBuscado)==0)
            {
                cBuscada=auxPoke;
                free(cBuscada);
                seg->lista=auxPoke->siguiente;
                flagBorrado=1;
            }
            else
            {
                while((auxPoke!=NULL)  && (flagBorrado == 0))
                {
                    if(strcmp(auxPoke->dato.nombre,nombreBuscado)==0)
                    {
                        cBuscada=auxPoke;
                        auxPoke=auxPoke->siguiente;
                        antePoke->siguiente= auxPoke;
                        free(cBuscada);
                        flagBorrado = 1;
                    }
                    else
                    {
                        antePoke= auxPoke;
                        auxPoke=auxPoke->siguiente;
                    }
                }

            }
            seg=seg->siguiente;
        }
    }
    else
    {
        printf("El mazo esta bacio:\n");
    }
    return listaO;
}
///---------------------------------punto 5-Guardado de mazo--------------------------------///
int contarCantidadCartasT(nodoPoke* lista)
{
    int contador=0;
    if(lista!=NULL)
    {
        while(lista!=NULL)
        {
            contador++;
            lista=lista->siguiente;
        }
    }
    return contador;
}
void guardarMazo(nodoTipo* listaO)
{
    FILE* fp= fopen("DatosJugador1.bin","ab");
    if(fp!=NULL)
    {
        while(listaO!=NULL)
        {
            int contador=contarCantidadCartasT(listaO->lista);
            fwrite(&contador,sizeof(int),1,fp);
            fwrite(&listaO->tipo,sizeof(char),20,fp);
            nodoPoke* seg=listaO->lista;
            while(seg!=NULL)
            {
                fwrite(&seg->dato,sizeof(stCarta),1,fp);
                seg=seg->siguiente;
            }
            listaO=listaO->siguiente;
        }
    }
    fclose(fp);
}
nodoTipo* leerMazo(nodoTipo* listaO)
{
    nodoPoke* auxP=inicListaP();
    nodoTipo* auxT=inicListaT();
    stCarta cartaAux;
    char tipoA[20];
    FILE* ficherp=fopen("DatosJugador1.bin","rb");
    int i=0;
    int contadorC=0;
    if(ficherp!=NULL)
    {
        while(fread(&contadorC,sizeof(int),1,ficherp)>0)
        {
            fread(&tipoA,sizeof(char),20,ficherp);
            auxT=crearNodoTipo(tipoA);
            listaO=agregarAlFinalTipo(listaO,auxT);
            nodoTipo* ultimoT=buscarUltimoTipo(listaO);
            while(contadorC>i)
            {
                fread(&cartaAux,sizeof(stCarta),1,ficherp);
                auxP=crearNodoPoke(cartaAux);
                i++;
                ultimoT->lista=agregarAlFinalPoke(ultimoT->lista,auxP);
            }
            i=0;
        }
        fclose(ficherp);
    }

    return listaO;
}
///----guardarMazos----///
void guardarMIJ1(nodoA* arbol,FILE* ficher)
{
    if(ficher!=NULL)
    {
        if(arbol!=NULL)
        {
            fwrite(&arbol->mazoI,sizeof(stCarta),1,ficher);
            guardarMIJ1(arbol->dere,ficher);
            guardarMIJ1(arbol->izq,ficher);
        }
    }
}
void guardarMIJ2(nodoA* arbol,FILE* ficher)
{
    if(ficher!=NULL)
    {
        if(arbol!=NULL)
        {
            printf("gola\n");
            fwrite(&arbol->mazoI,sizeof(stCarta),1,ficher);
            guardarMIJ2(arbol->dere,ficher);
            guardarMIJ2(arbol->izq,ficher);
        }
    }
}
nodoA* leerMIJ1(nodoA* arbol,FILE* ficher)
{
    nodoA* aux=inicArbol();
    stCarta cartita;
    if(ficher!=NULL)
    {

        while(fread(&cartita,sizeof(stCarta),1,ficher)>0)
        {
            aux=crearNodoA(cartita);
            arbol=agregarArbol(arbol,aux);
        }
    }
    return arbol;
}
nodoA* leerMIJ2(nodoA* arbol,FILE* ficher)
{
    nodoA* aux=inicArbol();
    stCarta cartita;
    if(ficher!=NULL)
    {
        while(fread(&cartita,sizeof(stCarta),1,ficher)>0)
        {
            aux=crearNodoA(cartita);
            arbol=agregarArbol(arbol,aux);
        }
    }
    return arbol;
}
///mazo memoria///
void guardarMazoMemo1(filaIter* filita)
{
    nodoDPoke* lista=filita->inicioF;
    FILE* fpJugador=fopen("MazoMemoria1.bin","wb");
    if(fpJugador!=NULL)
    {
        while(lista!=NULL)
        {

            fwrite(&lista->mazoI,sizeof(stCarta),1,fpJugador);
            lista=lista->siguiente;
        }
    }
}
void guardarMazoMemo2(filaIter* filita)
{
    nodoDPoke* lista=filita->inicioF;
    FILE* fpJugador=fopen("MazoMemoria2.bin","wb");
    if(fpJugador!=NULL)
    {
        while(lista!=NULL)
        {
            fwrite(&lista->mazoI,sizeof(stCarta),1,fpJugador);
            lista=lista->siguiente;
        }
    }
}

void leerMazoMemo1(filaIter* filita)
{
    nodoDPoke* lista=filita->inicioF;
    nodoDPoke* aux=inicListaD();
    stCarta cartita;
    FILE* fpJugador=fopen("MazoMemoria1.bin","rb");
    if(fpJugador!=NULL)
    {
        while(fread(&cartita,sizeof(stCarta),1,fpJugador)>0)
        {
            aux=crearNodoD(cartita);
            lista=agregarFinalNodoD(lista,aux);
        }
    }
    fclose(fpJugador);
    filita->inicioF=lista;
}
void leerMazoMemo2(filaIter* filita)
{
    nodoDPoke* lista=filita->inicioF;
    nodoDPoke* aux=inicListaD();
    stCarta cartita;
    FILE* fpJugador=fopen("MazoMemoria2.bin","rb");
    if(fpJugador!=NULL)
    {
        while(fread(&cartita,sizeof(stCarta),1,fpJugador)>0)
        {
            aux=crearNodoD(cartita);
            lista=agregarFinalNodoD(lista,aux);
        }
    }
    fclose(fpJugador);
    filita->inicioF=lista;
}
///--------------------------------------------------------////
void guardarMazo2(nodoTipo* listaO)
{
    FILE* fp= fopen("DatosJugador2.bin","ab");
    if(fp!=NULL)
    {
        while(listaO!=NULL)
        {
            int contador=contarCantidadCartasT(listaO->lista);
            fwrite(&contador,sizeof(int),1,fp);
            fwrite(&listaO->tipo,sizeof(char),20,fp);
            nodoPoke* seg=listaO->lista;
            while(seg!=NULL)
            {
                fwrite(&seg->dato,sizeof(stCarta),1,fp);
                seg=seg->siguiente;
            }
            listaO=listaO->siguiente;
        }
    }
    fclose(fp);
}
nodoTipo* leerMazo2(nodoTipo* listaO)
{
    nodoPoke* auxP=inicListaP();
    nodoTipo* auxT=inicListaT();
    stCarta cartaAux;
    char tipoA[20];
    FILE* ficherp=fopen("DatosJugador2.bin","rb");
    int i=0;
    int contadorC=0;
    if(ficherp!=NULL)
    {
        while(fread(&contadorC,sizeof(int),1,ficherp)>0)
        {
            fread(&tipoA,sizeof(char),20,ficherp);
            auxT=crearNodoTipo(tipoA);
            listaO=agregarAlFinalTipo(listaO,auxT);
            nodoTipo* ultimoT=buscarUltimoTipo(listaO);
            while(contadorC>i)
            {
                fread(&cartaAux,sizeof(stCarta),1,ficherp);
                auxP=crearNodoPoke(cartaAux);
                i++;
                ultimoT->lista=agregarAlFinalPoke(ultimoT->lista,auxP);
            }
            i=0;
        }
        fclose(ficherp);
    }

    return listaO;
}
///------------------------punto6 ------------------------////
void filtrarCartasPTipo(nodoTipo* listaO)
{
    if(listaO!=NULL)
    {
        char tipobuscado[20];
        printf("ingrese el tipo de cartas que se desea filtrar: ");
        fflush(stdin);
        gets(tipobuscado);
        while(listaO!=NULL&&(strcmp(listaO->tipo,tipobuscado)!=0))
        {
            listaO=listaO->siguiente;
        }
        if(listaO!=NULL)
        {
            mostrarListaCarta(listaO->lista);
        }
    }
}
///-----------punto7-estadisticadeMazo-----------///
///--------------punto8---cargar cartasMazoMemoria--////
nodoDPoke* inicListaD()
{
    return NULL;
}
void inicFila(filaIter* filita)
{
    filita->inicioF=inicListaD();
    filita->finalF=inicListaD();
}
nodoDPoke* crearNodoD(stCarta carta)
{
    nodoDPoke* aux=(nodoDPoke*)malloc(sizeof(nodoDPoke));
    aux->mazoI=carta;
    aux->siguiente=inicListaD();
    aux->anterior=inicListaD();
    return aux;
}
nodoDPoke* agregarFinalNodoD(nodoDPoke* lista, nodoDPoke* nuevoN)
{
    if(lista==NULL)
    {
        lista=nuevoN;
    }
    else
    {
        nodoDPoke* seg=lista;
        while(seg->siguiente!=NULL)
        {
            seg=seg->siguiente;
        }
        if(seg!=NULL)
        {
            seg->siguiente=nuevoN;
            nuevoN->anterior=seg;
        }
    }
    return lista;
}
int existeNodoFila(nodoDPoke* lista,nodoPoke* cartaB)
{
    int existe=0;

    if(lista!=NULL)
    {
        while(lista!=NULL)
        {
            if(lista->mazoI.calidadC==cartaB->dato.calidadC)
            {
                if(lista->mazoI.hp==cartaB->dato.hp)
                {
                    if(lista->mazoI.lvl==cartaB->dato.lvl)
                    {
                        if(strcmp(lista->mazoI.nombre,cartaB->dato.nombre)==0)
                        {
                            if(lista->mazoI.precio==cartaB->dato.precio)
                            {
                                if(lista->mazoI.rareza==cartaB->dato.rareza)
                                {
                                    if(strcmp(lista->mazoI.tipo,cartaB->dato.tipo)==0)
                                    {
                                        existe++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            lista=lista->siguiente;
        }
    }
    return existe;
}
void cargarMazoMemoria(filaIter* filita, nodoTipo* listaO)
{
    char continuar='s';
    char cartaI [20];
    nodoPoke* cartaB;
    char nombreBuscado[20];
    if(listaO!=NULL)
    {
        do
        {
            printf("Usted tiene estas cartas:\n");
            mostrarCatasMazo(listaO);
            printf("ingrese el nombre de la carta a buscar: ");
            fflush(stdin);
            gets(nombreBuscado);
            if((buscarCartaNombreYTipo(listaO,nombreBuscado))!=NULL)
            {
                cartaB=buscarCartaNombreYTipo(listaO, nombreBuscado);
                stCarta cartaCambio=cartaB->dato;
                nodoDPoke* aux=crearNodoD(cartaCambio);
                if(existeNodoFila(filita->inicioF,aux)==0)
                {
                    pasarListaAFila(filita,aux);
                    printf("La carta se ingreso en el mazo Memoria Correctamente:\n");
                    printf("Desea ingresar otra carta al mazo de Memoria:?\n");
                    printf("Ingrese 's'");
                    scanf("%c",&continuar);
                }
                else
                {
                    printf("La carta que se desea ingresar ya exsiste en el mazo:\n");
                    printf("Desea ingresar otra carta al mazo de Memoria:?\n");
                    printf("Ingrese 's'");
                    scanf("%c",&continuar);
                }
            }
            else
            {
                printf("El nombre de la carta buscada no existe:\n");
                printf("Desea ingresar otra carta al mazo de Memoria:?\n");
                printf("Ingrese 's'");
                scanf("%c",&continuar);
            }
        }
        while(continuar=='s'||continuar=='S');

    }
    return filita;
}
void pasarListaAFila(filaIter* filita, nodoDPoke* nuevoN)
{

    if(filita->inicioF==NULL)
    {
        filita->inicioF=nuevoN;
        filita->finalF=nuevoN;
    }
    else
    {
        filita->inicioF=agregarFinalNodoD(filita->inicioF,nuevoN);
        filita->finalF=nuevoN;
    }
    return filita;
}
void mostrarfila(filaIter* filita)
{
    if(filita->inicioF!=NULL)
    {
        mostrarListaD(filita->inicioF);
    }
}
void mostrarListaD(nodoDPoke* lista)
{
    if(lista!=NULL)
    {
        printf("Nombre: %s\n",lista->mazoI.nombre);
        if(lista->mazoI.rareza==1)
        {
            printf("Rareza: Comun.\n");
        }
        else if(lista->mazoI.rareza==2)
        {
            printf("Rareza: Poco Comun.\n");
        }
        else if(lista->mazoI.rareza==3)
        {
            printf("Rareza: Raro.\n");
        }
        else if(lista->mazoI.rareza==4)
        {
            printf("Rareza: Legendario.\n");
        }
        printf("hp: %d\n",lista->mazoI.hp);
        printf("lvl: %d\n",lista->mazoI.lvl);
        if(lista->mazoI.calidadC==1)
        {
            printf("Calidad: Comun.\n");
        }
        else if(lista->mazoI.calidadC==2)
        {
            printf("Calidad: Infrecuente.\n");
        }
        else if(lista->mazoI.calidadC==3)
        {
            printf("Calidad: Rara.\n");
        }
        else if(lista->mazoI.calidadC==4)
        {
            printf("Calidad: Holografica.\n");
        }
        else if(lista->mazoI.calidadC==5)
        {
            printf("Calidad: Luminosa.\n");
        }
        else if(lista->mazoI.calidadC==6)
        {
            printf("Calidad: Secreta.\n");
        }
        mostrarListaD(lista->siguiente);
    }
}
///________intercambiojugadosres____________-////
nodoA* inicArbol()
{
    return NULL;
}
nodoA* crearNodoA(stCarta cartita)
{
    nodoA* auxA=(nodoA*)malloc(sizeof(nodoA));
    auxA->mazoI=cartita;
    auxA->dere=inicArbol();
    auxA->izq=inicArbol();
    return auxA;
}
nodoA* agregarArbol(nodoA* arbol, nodoA* nuevoN)
{
    if(arbol==NULL)
    {
        arbol=nuevoN;
    }
    else
    {
        if(strcmp(arbol->mazoI.nombre,nuevoN->mazoI.nombre)<0)
        {
            arbol->izq=agregarArbol(arbol->izq,nuevoN);
        }
        else
        {
            arbol->dere=agregarArbol(arbol->dere,nuevoN);
        }
    }
    return arbol;
}
void elegirCartaInter(nodoA**arbolA, nodoTipo** listaO)
{
    char continuar='s';
    char nombreB[20];
    nodoPoke* nodoL;
    stCarta cartita;
    nodoA* nodoArbol;
    if(*listaO!=NULL)
    {
        do
        {
            printf("Usted tiene estas cartas:\n");
            mostrarCatasMazo(*listaO);
            printf("Cual quiere ingresar el en mazo de intercambion:\n");
            fflush(stdin);
            gets(nombreB);
            if(buscarCartaNombreYTipo(*listaO,nombreB)!=NULL)
            {
                nodoL=buscarCartaNombreYTipo(*listaO, nombreB);
                cartita=nodoL->dato;
                (*listaO)=eliminarCartaTipo(*listaO, nombreB);
                nodoArbol=crearNodoA(cartita);
                (*arbolA)=agregarArbol(*arbolA,nodoArbol);
                printf("Desea cargar otra carta en el mazo de intercambio ingrese 's':");
                fflush(stdin);
                scanf("%c",&continuar);
            }
            else
            {
                printf("La carta no se encontro desea buscar otra? ingrese 's':");
                fflush(stdin);
                scanf("%c",&continuar);
            }
        }
        while(continuar=='s'||continuar=='S');

    }
}
void mostrarStcarta(stCarta cartita)
{
    printf("Nombre: %s\n",cartita.nombre);
    printf("Tipo: %s\n",cartita.tipo);
    if(cartita.rareza==1)
    {
        printf("Rareza: Comun.\n");
    }
    else if(cartita.rareza==2)
    {
        printf("Rareza: Poco Comun.\n");
    }
    else if(cartita.rareza==3)
    {
        printf("Rareza: Raro.\n");
    }
    else if(cartita.rareza==4)
    {
        printf("Rareza: Legendario.\n");
    }
    printf("hp: %d\n",cartita.hp);
    printf("lvl: %d\n",cartita.lvl);
    printf("Precio: %d\n",cartita.precio);

    if(cartita.calidadC==1)
    {
        printf("Calidad: Comun.\n");
    }
    else if(cartita.calidadC==2)
    {
        printf("Calidad: Infrecuente.\n");
    }
    else if(cartita.calidadC==3)
    {
        printf("Calidad: Rara.\n");
    }
    else if(cartita.calidadC==4)
    {
        printf("Calidad: Holografica.\n");
    }
    else if(cartita.calidadC==5)
    {
        printf("Calidad: Luminosa.\n");
    }
    else if(cartita.calidadC==6)
    {
        printf("Calidad: Secreta.\n");
    }
}
void mostrarArbol(nodoA* arbol)
{
    if(arbol!=NULL)
    {
        mostrarStcarta(arbol->mazoI);
        mostrarArbol(arbol->dere);
        mostrarArbol(arbol->izq);
    }
}
int existeNodoA(nodoA* arbol,char nombreB[20])
{
    int hay=0;
    if(arbol!=NULL)
    {
        if(strcmp(arbol->mazoI.nombre,nombreB)==0)
        {
            hay=1;
        }
        else
        {
            hay=existeNodoA(arbol->dere,nombreB);
            if(hay==0)
            {
                hay=existeNodoA(arbol->izq,nombreB);
            }
        }
    }
    return hay;
}
void intercanbiarJ1yJ2(nodoA** jugadorA,nodoA** jugadorC)
{
    char nombreC1[20];
    char nombreC2[20];
    char continuar='s';
    stCarta auxJugador1;
    stCarta auxJugador2;
    if(*jugadorA==NULL)
    {
        printf("Usted no cargo su mazo de intercambio porfavor vulva y cargue el mazo:\n");
    }
    else if(*jugadorC==NULL)
    {
        printf("El otro jugador no cargo su mazo de intercambio porfavor vulva y cargue el mazo:\n");
    }
    else
    {
        do
        {
            printf("Su mazo para intercambiar es:\n ");
            mostrarArbol(*jugadorA);
            printf("El mazo del ortro juegador es :\n");
            mostrarArbol(*jugadorC);
            printf("Ingrese la carta de su mazo que quiere cambiar:\n");
            fflush(stdin);
            gets(nombreC1);
            if(existeNodoA(*jugadorA,nombreC1)==1)
            {
                printf("Ingrese el Nombre de la carta que desea eligir del mazo del otro jugador:");
                fflush(stdin);
                gets(nombreC2);
                if(existeNodoA(*jugadorC,nombreC2)==1)
                {
                    (*jugadorA)=buscarNodoYExtraer((*jugadorA),&auxJugador1,nombreC1);
                    (*jugadorC)=agregarArbol((*jugadorC),crearNodoA(auxJugador1));
                    (*jugadorC)=buscarNodoYExtraer((*jugadorC),&auxJugador2,nombreC2);
                    (*jugadorA)=agregarArbol((*jugadorA),crearNodoA(auxJugador2));
                    printf("Las cartas se intercambiaron si quiere intercambiar otras cartas ingrese 's':");
                    scanf("%c",&continuar);
                }
                else
                {
                    printf("La carta buscada del otro jugador no existe si desea intercambiar\n");
                    printf("orta carta ingrese 's':");
                    fflush(stdin);
                    scanf("%c",&continuar);
                }
            }
            else
            {
                printf("La carta buscada de tu mazo intercambiable no existe:\n");
                printf("Deseabuscar otras cartas ingrese 's':");
                fflush(stdin);
                scanf("%c",&continuar);
            }
        }
        while(continuar=='s'||continuar=='S');
    }
}
nodoA* buscarNodoYExtraer(nodoA* arbol,stCarta* cartabuscada,char nombreB[20])
{

    if(arbol!=NULL)
    {
        if(strcmp(arbol->mazoI.nombre,nombreB)==0)
        {
            if((arbol->dere!=NULL)&&(arbol->izq!=NULL))
            {
                nodoA* arbolAux=masIzquierda(arbol->dere);
                arbol->mazoI=arbolAux->mazoI;
                arbol->dere=buscarNodoYExtraer(arbol->dere,cartabuscada,nombreB);
            }
            else
            {
                nodoA* aux=arbol;
                *cartabuscada=aux->mazoI;
                if(arbol->dere!=NULL && arbol->izq==NULL)
                {
                    arbol=arbol->dere;
                }
                else if(arbol->izq!=NULL && arbol->dere==NULL)
                {
                    arbol=arbol->izq;
                }
                else if(arbol->dere==NULL && arbol->izq==NULL)
                {
                    arbol=NULL;
                }
                free(aux);
            }
        }
        else
        {
            if(strcmp(arbol->mazoI.nombre,nombreB)>0)
            {

                arbol->dere=buscarNodoYExtraer(arbol->dere,cartabuscada,nombreB);
            }
            else
            {
                arbol->izq=buscarNodoYExtraer(arbol->izq,cartabuscada,nombreB);
            }
        }
    }
    return arbol;
}
nodoA* masDerecha(nodoA* arbol)
{
    if(arbol!=NULL && arbol->dere!=NULL)
    {
        arbol=masDerecha(arbol->dere);
    }
    return arbol;
}
nodoA* masIzquierda(nodoA* arbol)
{
    if(arbol!=NULL && arbol->izq!=NULL)
    {
        arbol=masIzquierda(arbol->izq);
    }
    return arbol;
}
nodoTipo* mazoIaMazoO(nodoTipo* listaO,nodoA** arbolI)
{
    char continuar='s';
    char nombreB[20];
    if(arbolI!=NULL)
    {
        do
        {
            printf("Su mazo de intercambio es :\n");
            mostrarArbol(*arbolI);
            printf("Ingrese el nombre de la carta que quiere extraer ");
            printf("del mazo intercambiable al mazo general:");
            fflush(stdin);
            gets(nombreB);
            if(existeNodoA(*arbolI,nombreB)==1)
            {
                stCarta cartita;
                *arbolI=buscarNodoYExtraer(*arbolI,&cartita,nombreB);
                if(existeNodoTipo(listaO,cartita.nombre)==1)
                {
                    nodoTipo* auxTipo=buscarTipoLugar(listaO,nombreB);
                    nodoPoke* nuevoN=crearNodoPoke(cartita);
                    auxTipo->lista=agregarAlFinalPoke(auxTipo->lista,nuevoN);
                }
                else
                {
                    nodoTipo* nuevoT=crearNodoTipo(cartita.tipo);
                    nodoPoke* nuevoP=crearNodoPoke(cartita);
                    listaO=agregarAlFinalTipo(listaO,nuevoT);
                    nodoTipo* auxT=buscarTipoLugar(listaO,cartita.tipo);
                    auxT->lista=agregarAlFinalPoke(auxT->lista,nuevoP);
                }
            }
            else
            {
                printf("La carta buscada no se a encontrado quiere extraer otro ingrese 's':");
                fflush(stdin);
                scanf("%c",&continuar);
            }
            printf("Quiere extraer otra carta al mazo general ingrese 's':");
            fflush(stdin);
            scanf("%c",&continuar);
        }
        while(continuar=='s'||continuar=='S');

    }
    return listaO;
}

///--------------------------------------punto 9 genera estadisticas---------------------------------///

int statsRarezaComun(nodoTipo* lista)
{
    int i=0;
    nodoTipo* auxTipo=lista;
    nodoPoke* aux;
    if(auxTipo!=NULL)
    {
        while(auxTipo!=NULL)
        {
            aux=auxTipo->lista;
            while(aux!=NULL)
            {
                if(aux->dato.rareza==1)
                {
                    i++;
                }
                aux=aux->siguiente;
            }
            auxTipo=auxTipo->siguiente;
        }

    }
    return i;
}
int statsRarezaPocoComun(nodoTipo* lista)
{
    int i=0;
    nodoTipo* auxTipo=lista;
    nodoPoke* aux;
    if(auxTipo!=NULL)
    {
        aux=auxTipo->lista;
        while(auxTipo!=NULL)
        {
            aux=auxTipo->lista;
            while(aux!=NULL)
            {
                if(aux->dato.rareza==2)
                {
                    i++;
                }
                aux=aux->siguiente;
            }
            auxTipo=auxTipo->siguiente;
        }
    }


    return i;
}
int statsRarezaRaro(nodoTipo* lista)
{
    int i=0;
    nodoTipo* auxTipo=lista;
    nodoPoke* aux;
    if(auxTipo!=NULL)
    {
        while(auxTipo!=NULL)
        {
            aux=auxTipo->lista;
            while(aux!=NULL)
            {
                if(aux->dato.rareza==3)
                {
                    i++;
                }
                aux=aux->siguiente;
            }
            auxTipo=auxTipo->siguiente;
        }
    }
    return i;
}

int statsRarezaLegendario(nodoTipo* lista)
{
    int i=0;
    nodoTipo* auxTipo=lista;
    nodoPoke* aux;
    if(auxTipo!=NULL)
    {
        while(auxTipo!=NULL)
        {
            aux=auxTipo->lista;
            while(aux!=NULL)
            {
                if(aux->dato.rareza==4)
                {
                    i++;
                }
                aux=aux->siguiente;
            }
            auxTipo=auxTipo->siguiente;
        }
    }
    return i;
}


float promedioPrecio(nodoTipo* lista)
{
    nodoTipo* auxTipo=lista;
    nodoPoke* auxPoke;
    float i=0;
    float suma=0;
    float totalPrecio=0;
    float promedio;
    if(auxTipo!=NULL)
    {
        while(auxTipo!=NULL)
        {
            auxPoke=auxTipo->lista;
            while(auxPoke!=NULL)
            {
                suma=auxPoke->dato.precio;
                totalPrecio=totalPrecio+suma;
                i++;
                auxPoke=auxPoke->siguiente;
            }
            auxTipo=auxTipo->siguiente;
        }
        promedio=totalPrecio/i;
    }
    return promedio;
}
int totalPrecio(nodoTipo* lista)
{
    nodoTipo* auxTipo=lista;
    nodoPoke* auxPoke;
    int suma=0;
    int totalPrecio=0;
    if(auxTipo!=NULL)
    {
        while(auxTipo!=NULL)
        {
            auxPoke=auxTipo->lista;
            while(auxPoke!=NULL)
            {
                suma=auxPoke->dato.precio;
                totalPrecio=totalPrecio+suma;
                auxPoke=auxPoke->siguiente;
            }
            auxTipo=auxTipo->siguiente;
        }
    }
    return totalPrecio;
}
void mostrarPrecios(nodoTipo* lista)
{
    float promedioprecios=promedioPrecio(lista);
    int totalprecio=totalPrecio(lista);

    printf("\nEL valor total de tu mazo es: %d",totalprecio);
    printf("\nEl promedio de precio por carta de tu mazo es: %.2f",promedioprecios);
}


float promedioHP(nodoTipo* lista)
{
    nodoTipo* auxTipo=lista;
    nodoPoke* auxPoke;
    float i=0;
    float suma=0;
    float totalHp=0;
    float promedio;
    if(auxTipo!=NULL)
    {
        while(auxTipo!=NULL)
        {
            auxPoke=auxTipo->lista;
            while(auxPoke!=NULL)
            {
                suma=auxPoke->dato.hp;
                totalHp=totalHp+suma;
                i++;
                auxPoke=auxPoke->siguiente;
            }
            auxTipo=auxTipo->siguiente;
        }
        promedio=totalHp/i;
    }
    return promedio;
}

float promediolvl(nodoTipo* lista)
{
    nodoTipo* auxTipo=lista;
    nodoPoke* auxPoke;
    float i=0;
    float suma=0;
    float totalvl=0;
    float promedio;
    if(auxTipo!=NULL)
    {
        while(auxTipo!=NULL)
        {
            auxPoke=auxTipo->lista;
            while(auxPoke!=NULL)
            {
                suma=auxPoke->dato.lvl;
                totalvl=totalvl+suma;
                i++;
                auxPoke=auxPoke->siguiente;
            }
            auxTipo=auxTipo->siguiente;
        }
        promedio=totalvl/i;
    }
    return promedio;
}

void mostrarPromedioCartasxTipo(nodoTipo* lista)
{
    float promelvl=promediolvl(lista);
    float promehp=promedioHP(lista);

    printf("\nEste es el promedio del nivel tus cartas: %.2f",promelvl);
    printf("\nEste es el promedio del HP de tu cartas: %.2f",promehp);
}

void mostrarCantidadRarezas(nodoTipo* lista)
{
    int comun=statsRarezaComun(lista);
    int pocoComun=statsRarezaPocoComun(lista);
    int raro=statsRarezaRaro(lista);
    int legendario=statsRarezaLegendario(lista);
    int cantidadTotal=comun+pocoComun+raro+legendario;

    comun = comun * 100 / cantidadTotal;
    pocoComun = pocoComun * 100 / cantidadTotal;
    raro = raro * 100 / cantidadTotal;
    legendario = legendario * 100 / cantidadTotal;

    printf("\nEste es el porcentaje de comunes: %d%%",comun);
    printf("\nEste es el porcentaje de cartas poco comunes: %d%%",pocoComun);
    printf("\nEste es el porcentaje de raras que hay: %d%%",raro);
    printf("\nEsta es el porcentaje de legendarios: %d%%",legendario);
}

void mostrarStats(nodoTipo* lista)
{
    color(14);
    printf("\nSTATS\n");
    color(15);

    mostrarCantidadRarezas(lista);
    printf("\n");

    mostrarPrecios(lista);
    printf("\n");
    mostrarPromedioCartasxTipo(lista);
    printf("\n");
}



///------------------------------11 interfaz---------------------------------///
int movertecla(int tecla,int opcionSeleccionada,int opcionSalida)
{

    switch (tecla)
    {
    case 72:
        opcionSeleccionada--;
        if (opcionSeleccionada < 0)
        {
            opcionSeleccionada = opcionSalida -1;
        }
        break;
    case 80:
        opcionSeleccionada++;
        if (opcionSeleccionada >= opcionSalida)
        {
            opcionSeleccionada = 0;
        }
        break;
    }

    return opcionSeleccionada;
}

void menu(nodoTipo* lista,nodoPila*pila,nodoA**jugadorA,nodoA**juegdorC,filaIter* fila)
{
    int opcionSeleccionada = 0;
    int tecla;
    int opcionSalida=3;
    hidecursor(0);
    int flag=0;

    do
    {
        do
        {
            system("cls");
            color(14); // Color amarillo
            gotoxy(35, 5);
            printf("BIENVENIDO");
            color(15); // Color blanco
            gotoxy(30, 7);
            printf("1. Jugador 1");
            gotoxy(30, 8);
            printf("2. Juagador 2");
            gotoxy(30, 9);
            printf("3. Salir");



            gotoxy(28, 7 + opcionSeleccionada);
            printf("->");


            tecla = getch();

            opcionSeleccionada=movertecla(tecla,opcionSeleccionada,opcionSalida);

        }
        while (tecla != 13);



        switch(opcionSeleccionada)
        {
        case 0:
            system("cls");
            menu1(lista,pila,jugadorA,juegdorC,fila);

            break;
        case 1:
            system("cls");
            menu2(lista,pila,jugadorA,juegdorC,fila);
            break;
        }


        if(opcionSeleccionada==2)
            flag=-1;
    }
    while (flag!=-1);

}


void menu1(nodoTipo* lista,nodoPila* pila,nodoA**jugadorA,nodoA**juegdorC,filaIter* fila)
{
    int opcionSeleccionada = 0;
    int tecla;
    int opcionSalida=13;
    hidecursor(0);
    int flag=0;

    do
    {
        do
        {
            system("cls");
            color(14); // Color amarillo
            gotoxy(35, 5);
            printf("BIENVENIDO JUGADOR 1");
            color(15); // Color blanco
            gotoxy(30, 7);
            printf("1. Cargar el Mazo");
            gotoxy(30, 8);
            printf("2. Mostrar Mazos");
            gotoxy(30, 9);
            printf("3. Guardar Mazo");
            gotoxy(30,10);
            printf("4. Eliminar carta");
            gotoxy(30,11);
            printf("5. Intercambiar cartas");
            gotoxy(30,12);
            printf("6. Cargar Mazo Intercambio");
            gotoxy(30,13);
            printf("7. Cargar Mazo Competitivo");
            gotoxy(30,14);
            printf("8. Cargar Tipo de carta");
            gotoxy(30,15);
            printf("9. Elegir mazo intercambio");
            gotoxy(30,16);
            printf("10. Carga mazo memoria");
            gotoxy(30,17);
            printf("11. De mazo intercambio a mazo o");
            gotoxy(30,18);
            printf("12. Leer");
            gotoxy(30,19);
            printf("13. Salir");

            gotoxy(28, 7 + opcionSeleccionada);
            printf("->");


            tecla = getch();

            opcionSeleccionada=movertecla(tecla,opcionSeleccionada,opcionSalida);

        }
        while (tecla != 13);



        switch(opcionSeleccionada)
        {
        case 0:
            system("cls");
            lista=cargarUnaCarta(lista);
            break;
        case 1:
            system("cls");
            mostradorDeMazos(lista,pila,fila);
            break;
        case 2:
            system("cls");
            guardarMazo(lista);
            printf("\n\nEl mazo se a guardado existosamente\n\n\n");
            system("pause");
            break;
        case 3:
            system("cls");
            lista=eliminarCarta(lista);
            mostradorDeMazos(lista,pila,fila);
            printf("\n\n\n");
            system("pause");
            break;
        case 4:
            system("cls");
            intercanbiarJ1yJ2(jugadorA,juegdorC);
            break;
        case 5:
            system("cls");
            elegirCartaInter(jugadorA,lista);
            break;
        case 6:
            system("cls");
            pila=muchosApila(pila,lista);
            break;
        case 7:
            system("cls");
            lista=cargarNodoTipo(lista);
            break;
        case 8:
            system("cls");
            break;
        case 9:
            system("cls");
            cargarMazoMemoria(fila,lista);
            break;
        case 10 :

            break;
        case 11:
            break;
        }




        if(opcionSeleccionada==13)
            flag=-1;
    }
    while (flag!=-1);

}

void menu2(nodoTipo* lista,nodoPila* pila,nodoA**jugadorA,nodoA**juegdorC,filaIter* fila)
{
    int tecla;
    int opcionSalida=13;
    hidecursor(0);
    int flag=0;

    do
    {
        do
        {
            system("cls");
            color(14); // Color amarillo
            gotoxy(35, 5);
            printf("BIENVENIDO JUGADOR 1");
            color(15); // Color blanco
            gotoxy(30, 7);
            printf("1. Cargar el Mazo");
            gotoxy(30, 8);
            printf("2. Mostrar Mazos");
            gotoxy(30, 9);
            printf("3. Guardar Mazo");
            gotoxy(30,10);
            printf("4. Eliminar carta");
            gotoxy(30,11);
            printf("5. Intercambiar cartas");
            gotoxy(30,12);
            printf("6. Cargar Mazo Intercambio");
            gotoxy(30,13);
            printf("7. Cargar Mazo Competitivo");
            gotoxy(30,14);
            printf("8. Cargar Tipo de carta");
            gotoxy(30,15);
            printf("9. Elegir mazo intercambio");
            gotoxy(30,16);
            printf("10. Carga mazo memoria");
            gotoxy(30,17);
            printf("11. De mazo intercambio a mazo o");
            gotoxy(30,18);
            printf("12. Leer");
            gotoxy(30,19);
            printf("13. Salir");

            gotoxy(28, 7 + opcionSeleccionada);
            printf("->");


            tecla = getch();

            opcionSeleccionada=movertecla(tecla,opcionSeleccionada,opcionSalida);

        }
        while (tecla != 13);



        switch(opcionSeleccionada)
        {
        case 0:
            system("cls");
            lista=cargarUnaCarta(lista);
            break;
        case 1:
            system("cls");
            mostradorDeMazos(lista,pila,fila);
            break;
        case 2:
            system("cls");
            guardarMazo(lista);
            printf("\n\nEl mazo se a guardado existosamente\n\n\n");
            system("pause");
            break;
        case 3:
            system("cls");
            lista=eliminarCarta(lista);
            mostradorDeMazos(lista,pila,fila);
            printf("\n\n\n");
            system("pause");
            break;
        case 4:
            system("cls");
            intercanbiarJ1yJ2(jugadorA,juegdorC);
            break;
        case 5:
            system("cls");
            elegirCartaInter(jugadorA,lista);
            break;
        case 6:
            system("cls");
            pila=muchosApila(pila,lista);
            break;
        case 7:
            system("cls");
            lista=cargarNodoTipo(lista);
            break;
        case 8:
            system("cls");
            break;
        case 9:
            system("cls");
            cargarMazoMemoria(fila,lista);
            break;
        case 10 :

            break;
        case 11:
            break;
        }




        if(opcionSeleccionada==13)
            flag=-1;
    }
    while (flag!=-1);

}

void mostradorDeMazos(nodoTipo* lista,nodoPila*pila,filaIter*fila)
{
    int opcionSeleccionada = 0;
    int tecla;
    int opcionSalida=6;
    hidecursor(0);
    int flag=0;
    do
    {
        do
        {
            system("cls");
            color(14); // Color amarillo
            gotoxy(35, 5);
            printf("MOSTRADOR DE MAZO");
            color(15); // Color blanco
            gotoxy(30, 7);
            printf("1. Mostrar mazo completo");
            gotoxy(30, 8);
            printf("2. Mostrar Stats");
            gotoxy(30, 9);
            printf("3. Mostrar Mazo competitivo");
            gotoxy(30, 10);
            printf("4. Mostrar Mazo memoria");
            gotoxy(30, 11);
            printf("5. Mostrar Mazo intercambio");
            gotoxy(30, 12);
            printf("6. Salir");



            gotoxy(28, 7 + opcionSeleccionada);
            printf("->");


            tecla = getch();

            opcionSeleccionada=movertecla(tecla,opcionSeleccionada,opcionSalida);

        }
        while (tecla != 13);


        switch(opcionSeleccionada)
        {
        case 0:
            system("cls");
            mostrarListaTipo(lista);
            printf("\n\n\n");
            system("pause");
            break;
        case 1:
            system("cls");
            mostrarStats(lista);
            printf("\n\n\n");
            system("pause");
            break;
        case 2:
            system("cls");
            mostrarPila(pila);
            printf("\n\n\n");
            system("pause");
            break;
        case 3:
            system("cls");
            mostrarfila(fila);
            printf("\n\n\n");
            system("pause");
            break;
        case 5:

            break;
        case 6:
            flag=-1;
        }
    }
    while (flag!=-1);

}


///----------------------------------mazo competitivo---------------------------------------///
nodoPila* inicPila()
{
    return NULL;
}

nodoPila* crearNodoPila(stCarta dato)
{
    nodoPila* aux=(nodoPila*)malloc(sizeof(nodoPila));
    aux->dato=dato;
    aux->sig=NULL;
    return aux;
}
nodoPila* buscaUltimo(nodoPila*lista)
{
    nodoPila*aux=lista;
    if(aux!=NULL)
    {
        while(aux->sig!=NULL)
        {
            aux=aux->sig;
        }
    }
    return aux;
}

nodoPila* agregarAlfinal(nodoPila*pila,nodoPila*nuevo)
{
    if(pila==NULL)
    {
        pila=nuevo;
    }
    else
    {
        nodoPila* ultimo=buscaUltimo(pila);
        ultimo->sig=nuevo;
    }
    return pila;
}

nodoPila* apilar(nodoPila* pila,stCarta a)
{
    nodoPila* nuevo=crearNodoPila(a);
    nuevo->cantidad=incrementaCantidad(pila);
    if(nuevo->cantidad<=2)
    {
        pila=agregarAlfinal(pila,nuevo);
    }
    else
    {
        printf("No se puede apilar mas cartas");
    }
    return pila;
}

int incrementaCantidad(nodoPila* pila)
{
    int cant;
    if(pila==NULL)
    {
        cant=1;
    }
    else
    {
        nodoPila* ultimo=buscaUltimo(pila);
        cant=ultimo->cantidad+1;
    }
    return cant;
}

nodoPila* desapilar(nodoPila** pila)
{
    nodoPila*aBorrar=pila;
    nodoPila*ante;
    while(aBorrar->sig!=NULL)
    {
        ante=aBorrar;
        aBorrar=aBorrar->sig;
    }
    nodoPila* aux=aBorrar;
    ante->sig=NULL;

    return aux;
}


nodoPila* muchosApila(nodoPila*pila,nodoPoke*lista)
{
    stCarta dato;
    char control;
    printf("Quiere cargar? s/n: ");
    fflush(stdin);
    scanf("%c",&control);
    while(control=='s')
    {
        nodoPoke*aux=buscarCartaNombreO(lista);
        dato=aux->dato;
        pila=apilar(pila,dato);
        printf("Quiere seguir apilando? ");
        fflush(stdin);
        scanf("%c",&control);
    }
    return pila;
}

nodoPila*mostrarPila(nodoPila* pila)
{
    nodoPila* aux=pila;
    if(aux!=NULL)
    {
        color(14);
        printf("Inicio\n");
        color(15);
        while(aux!=NULL)
        {
            printf("\n");
            printf("|Cantidad: %d\t|\n",aux->cantidad);
            printf("|Rareza: %d.\t|\n",aux->dato.rareza);
            printf("|Calidad: %d.\t|\n",aux->dato.calidadC);
            printf("|hp: %d\t\t|\n",aux->dato.hp);
            printf("|lvl: %d\t|\n",aux->dato.lvl);
            printf("|Precio: %d\t|\n",aux->dato.precio);
            printf("|Nombre: %s\t|\n",aux->dato.nombre);
            aux=aux->sig;
        }
        color(14);
        printf("Tope");
        color(15);
    }
}
