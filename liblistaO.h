#ifndef LIBLISTAO_H_INCLUDED
#define LIBLISTAO_H_INCLUDED

typedef struct
{
    char nombre[20];
    char tipo[20];
    int rareza;//-comun -poco comun -raro -legendario
    int hp;//0-100
    int lvl;//1-100
    int calidadC;//-comu -infrecuente -rara -Holo -Luminosa -Secr66eta
    int precio;
} stCarta;

typedef struct
{
    stCarta dato;
    struct nodoPoke* siguiente;
} nodoPoke;

typedef struct
{
    char tipo[20];// agua - fuego - planta - tierra - roca
    nodoPoke* lista;
    struct nodoTipo* siguiente;
} nodoTipo;


typedef struct
{
    stCarta dato;
    int cantidad;
    struct nodoPila* sig;
} nodoPila;


nodoTipo* inicListaT();
nodoPoke* inicListaP();
nodoPoke* crearNodoPoke(stCarta);
nodoTipo* crearNodoTipo(char[]);
nodoTipo* cargarNodoTipo(nodoTipo*);
nodoTipo* buscarUltimoTipo(nodoTipo*);
nodoTipo* agregarAlFinalTipo(nodoTipo*,nodoTipo*);
int existeNodoTipo(nodoTipo*,char[]);
void mostrarListaTipo(nodoTipo*);
void mostrarListaCarta(nodoPoke*);
void mostrarCatasMazo(nodoTipo*);
///------------------------------------2-agregar carta-------------------------------------------------///
stCarta cargarCarta(char[]);
int verificalvl(int);
int verificaHp(int);
int verificaRareza(int);
int verificaCalidadC(int);
int verificaPrecio(int);
nodoTipo* buscarTipoLugar(nodoTipo*,char[50]);
nodoTipo* agregarCarta(nodoTipo*,nodoPoke*,char[50]);
nodoTipo* cargarUnaCarta(nodoTipo*);
nodoPoke* agregarAlFinalPoke (nodoPoke*,nodoPoke*);
nodoPoke* buscarUltimo(nodoPoke*);
///----------------------------------------punto 3-busqueda de carta-------------------------------///
nodoPoke* buscarCartaNombreO(nodoTipo*);
///------------------punto 4-eliminar una carta---------------------------///
nodoTipo* eliminarCarta(nodoTipo*);
///---------------------------------------purto 5-guardado de cartas----------///
///---extra funcion para contar la cantidad de cartas en un tipo-----------------///
int contarCantidadCartasT(nodoPoke* );
///--------------------------------
void guardarMazo(nodoTipo*);
nodoTipo* leerMazo(nodoTipo* listaO);
///-----------------------------------------///
void guardarMazo2(nodoTipo*);
nodoTipo* leerMazo2(nodoTipo* listaO);
///-------------------------------------punto 6-Filtrar cartas por tipo-------------/////

void filtrarCartasPTipo(nodoTipo*);
///----------------------------punto 7-darEstadistica del Mazo----------------------///
void estadisticasMazo(nodoTipo*);
///--------------------------------punto 8---intercambio de cartas entre jugadores------///
nodoA* inicArbol();
nodoA* crearNodoA(stCarta);
nodoA* agregarArbol(nodoA*,nodoA*);
void elegirCartaInter(nodoA**, nodoTipo**);
void mostrarArbol(nodoA*);
///--///
void intercanbiarJ1yJ2(nodoA**, nodoA**);
nodoA* buscarNodoYExtraer(nodoA*,stCarta*,char[20]);
int existeNodoA(nodoA*,char[20]);
nodoA* masDerecha(nodoA*);
nodoA* masIzquierda(nodoA*);
///--pasar de intercambio a lista--///
nodoTipo* mazoIaMazoO(nodoTipo*,nodoA**);
///--------------------------------------punto 9 genera estadisticas---------------------------------///
int statsRarezaComun(nodoTipo* lista);
int statsRarezaPocoComun(nodoTipo* lista);
int statsRarezaRaro(nodoTipo* lista);
int statsRarezaLegendario(nodoTipo* lista);
float promedioHP(nodoTipo* lista);
float promediolvl(nodoTipo* lista);
void mostrarPromedioCartasxTipo(nodoTipo* lista);
void mostrarCantidadRarezas(nodoTipo* lista);
float promedioPrecio(nodoTipo* lista);
int totalPrecio(nodoTipo* lista);
void mostrarPrecios(nodoTipo* lista);
void mostrarStats(nodoTipo* lista);
///---------------------------- interfaz---------------------------------------//

void mostradorDeMazos(nodoTipo* lista);
void menu(nodoTipo* lista,nodoPila*pila);
void menu1(nodoTipo* lista,nodoPila* pila);
int movertecla(int tecla,int opcionSeleccionada,int opcionSalida);


///-----------------------------competitivo--------------------------////
stCarta cargarCarta();
nodoPila* inicPila();
nodoPila* crearNodoPila(stCarta dato);
nodoPila* buscaUltimo(nodoPila*lista);
nodoPila* agregarAlfinal(nodoPila*pila,nodoPila*nuevo);
nodoPila* apilar(nodoPila* pila,stCarta a);
nodoPila* apilar(nodoPila* pila,stCarta a);
int incrementaCantidad(nodoPila* pila);
nodoPila* desapilar(nodoPila** pila);
nodoPila* muchosApila(nodoPila*pila,nodoPoke*lista);
nodoPila*mostrarPila(nodoPila* pila);






#endif // LIBLISTAO_H_INCLUDED
