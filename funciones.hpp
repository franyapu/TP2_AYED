#include <iostream>
#include <string>
using namespace std;

struct Nodo {
	int info;
	Nodo* sig;
};

struct InfoProducto{
	int id;
	char nombre[50+1];
	float precio;
	int umbral;
	int disponibles;	
};

struct NodoProducto{
	InfoProducto info;
	NodoProducto* sig;
};

struct InfoProveedor{
	int id;
	char nombre[50+1];
	char domicilio[50+1];
	char telefono[15+1];
	NodoProducto* productosProveedor;
};

struct NodoProveedor{
	InfoProveedor info;
	NodoProveedor* sig;
};

struct InfoItem{
	int idProducto;
	char nombreProducto[50+1];
	int cantidad;
	float precio;
	float totalItem;
};

struct NodoItem{
	InfoItem info;
	NodoItem* sig;
};


struct InfoPedido{
	int id;
	bool estado;
	NodoItem* productos;
	float totalPedido;
	int idCliente;	
};

struct NodoPedido{
	InfoPedido info;
	NodoPedido* sig;
};

struct InfoCliente{
	int id;
	char nombre[50+1];
	char domicilio[50+1];
	char telefono[15+1];
	NodoPedido* historialCompras;
};

struct NodoCliente{
	InfoCliente info;
	NodoCliente* sig;
};

#ifndef funciones
#define funciones

void agregar(int arr[], int n, int& len, int v); 
void mostrar(int arr[], int len);
int buscar(int arr[], int len, int v);
void eliminar(int arr[], int& len, int pos);
void insertar(int arr[], int& len, int v, int pos); 
int insertarOrdenado(int arr[], int& len, int v);
int buscaEInserta(int arr[], int& len, int v, bool& enc); 
void inicializar(int arr[],int n);
int busquedaBinaria(int vec[],int len, int valor); // devuelve la pos del vector dónde está el valor buscado
void burbuja(int vec[],int len);
//listas
void agregarNodo(Nodo*& lista, int x);
void mostrar(Nodo* lista);
void liberar(Nodo*& lista);
Nodo* buscar(Nodo* lista, int v);
void eliminar(Nodo*& lista, int v);
int eliminarPrimerNodo(Nodo*& lista);
Nodo* insertarOrdenado(Nodo*& lista, int v);
void ordenar(Nodo*& lista);
Nodo* buscaEInsertaOrdenado(Nodo*& lista, int v, bool& enc);
//pilas
void push(Nodo*& pila, int valor);
int pop(Nodo*& pila);
//Colas
void encolar(Nodo*& colafte, Nodo*& colafin, int v);
int desencolar(Nodo*& colafte, Nodo*& colafin);

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------TP2----------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

//------------------------MENUES-----------------------
void msgl(string mensaje);
void msg(string mensaje);

void menuPrincipal(NodoProducto*& productos, NodoProveedor*& proveedores, NodoCliente*& clientes, NodoPedido*& pedidosFte, NodoPedido*& pedidosFin, NodoPedido*& pedidosTerminados);
void menuProductos(NodoProducto*& lista, NodoProveedor*& listaProv);
void menuProveedores(NodoProveedor*& lista);
void menuClientes(NodoCliente*& lista);
void menuPedidos(NodoPedido*& pedidosFte, NodoPedido*& pedidosFin, NodoPedido* pedidosTerminados, NodoCliente*& clientes, NodoProducto*& productos);
void menuStock();


//--------------------PRODUCTOS--------------------------

void agregarNodo(NodoProducto*& lista, InfoProducto info);
void mostrar(NodoProducto* lista);
NodoProducto* buscar(NodoProducto* lista, int v);
void eliminar(NodoProducto*& lista, int v);
NodoProducto* insertarOrdenado(NodoProducto*& lista, InfoProducto info);
NodoProducto* buscaEInsertaOrdenado(NodoProducto*& lista, int v, bool& enc, InfoProducto info);
NodoProducto* eliminarPrimerNodo(NodoProducto*& lista);

//-------------------PROVEEDORES------------------------

void agregarNodo(NodoProveedor*& lista, InfoProveedor info);
void mostrar(NodoProveedor* lista);
NodoProveedor* buscar(NodoProveedor* lista, int v);
void eliminar(NodoProveedor*& lista, int v);
NodoProveedor* insertarOrdenado(NodoProveedor*& lista, InfoProveedor info);
NodoProveedor* buscaEInsertaOrdenado(NodoProveedor*& lista, int v, bool& enc, InfoProveedor info);
NodoProveedor* eliminarPrimerNodoP(NodoProveedor*& lista);

//--------------------CLIENTES--------------------------

void agregarNodo(NodoCliente*& lista, InfoCliente info);
void mostrar(NodoCliente* lista);
NodoCliente* buscar(NodoCliente* lista, int v);
void eliminar(NodoCliente*& lista, int v);
NodoCliente* insertarOrdenado(NodoCliente*& lista, InfoCliente info);
NodoCliente* buscaEInsertaOrdenado(NodoCliente*& lista, int v, bool& enc, InfoCliente info);
NodoCliente* eliminarPrimerNodoC(NodoCliente*& lista);

//-------------------------------------------PEDIDOS-----------------------------------------

void agregarNodo(NodoItem*& lista, InfoItem info);
void encolar(NodoPedido*& colafte, NodoPedido*& colafin, InfoPedido info);
InfoPedido desencolar(NodoPedido*& colafte, NodoPedido*& colafin);
void push(NodoPedido*& pila, InfoPedido info);
InfoPedido pop(NodoPedido*& pila);

//--------------------------------------ARCHIVOS----------------------------------------------
bool archivoExiste(const char* arch);
FILE* archExiste (const char* arch);
void guardarPedido(NodoPedido* nodo, FILE* archivo);
	

void guardarProveedores(NodoProveedor* proveedores, FILE* arch);
void cargarProveedores(NodoProveedor*& proveedores, FILE* file);

void imprimirPedidos(NodoPedido* pedidos);

#endif
