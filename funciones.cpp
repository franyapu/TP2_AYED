#include <iostream>
#include <string>
#include "funciones.hpp"
using namespace std;

void agregar(int arr[], int n, int& len, int v){
	
	if(len == n){
		cout << "El vector esta lleno" << endl;
	} else{
		arr[len] = v;
		len++;
	}
	
	return;
}

void mostrar(int arr[], int len){
	
	for(int i=0; i < len; i++){
		cout << arr[i] << endl;
	}
	
}

int buscar(int arr[], int len, int v){
	int pos;
	int i = 0;
	
	while(i < len && arr[i] != v ){
		i++;
	}
	
	if(i==len){
		pos = -1;
	} else{
		pos = i;
	}
	
	return pos;
}


void eliminar(int arr[], int& len, int pos){
	
	for(int i=pos; i < len-1 ;i++){
		arr[i] = arr[i+1];
	}
	len--;
	
	return;
}

void insertar(int arr[], int& len, int v, int pos){
	
	for(int i=len-1 ; i >= pos ; i--){
		arr[i+1] = arr[i];
	}
	arr[pos] = v;
	len++;
	
	return;
}


int insertarOrdenado(int arr[], int& len, int v){
	int pos = 0;
	
	while(pos < len && arr[pos] <= v ){
		pos++;
	}
	
	insertar(arr,len,v,pos);
	return pos;
}

int buscaEInserta(int arr[], int& len, int v, bool& enc){
	int pos = buscar(arr,len,v);
	
	if(pos == -1){
		enc = false;
		pos = insertarOrdenado(arr,len,v);
	} else {
		enc = true;
	}
	
	return pos;
}

void inicializar(int arr[],int n){
	
	for(int i=0; i < n; i++){
		arr[i] = 0;
	}
	
	return;
}

int busquedaBinaria(int vec[],int len, int valor){
	int inicio = 0;
	int fin = len-1;
	int medio = (inicio + fin) / 2;
	int pos = -1;
	
	while(inicio <= fin){
		if(vec[medio] == valor){
			pos = medio;
			break;
		} else if(valor > vec[medio]){
			inicio = medio + 1;
		} else{
			fin = medio - 1;
		}
		
		medio = (inicio + fin) / 2;
	}
	
	return pos;
}

void burbuja(int vec[],int len){
	int temp;
	
	for(int i=0; i < len-1; i++){
		for(int j=0; j < len-1-i; j++){
			if(vec[j] > vec[j+1]){
				temp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = temp; 
			}	
		}
	}
	
}

//listas
/*
void agregarNodo(Nodo*& lista, int x){
	
	Nodo* nuevo = new Nodo();
	nuevo->info = x;
	nuevo->sig = NULL;
	
	if(lista == NULL){
		lista = nuevo;
	} else{
		Nodo* aux = lista;
		while(aux->sig != NULL){
			aux = aux->sig;	
		}
		aux->sig = nuevo;	
	}
}
*/
void mostrar(Nodo* lista){
	 Nodo* aux = lista;
	 
	 while(aux != NULL) {
	   cout << aux->info << endl;
	   aux = aux->sig;
	 }
}


void liberar(Nodo*& lista){
	Nodo* aux;
	while(lista != NULL){
		aux = lista;
		lista = lista->sig;
		delete aux;
	}
}

Nodo* buscar(Nodo* lista, int v){
	Nodo* aux = lista;
	
	while(aux != NULL && aux->info != v){
		aux = aux->sig;		
	}
	
	return aux;
}

void eliminar(Nodo*& lista, int v){
	Nodo* aux = lista;
	Nodo* ant = NULL;
	while(aux != NULL && aux->info != v){
		ant = aux;
		aux = aux->sig;		
	}
	if(ant != NULL){
		ant->sig = aux->sig;
	} else {
		lista = aux->sig;
	}
	
	delete aux;
}

int eliminarPrimerNodo(Nodo*& lista){
	int retorno = lista->info;
	Nodo* aux = lista;
	lista = lista->sig;
	delete aux;
	return retorno;
};

Nodo* insertarOrdenado(Nodo*& lista, int v){
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;
	Nodo* aux = lista;
	Nodo* ant = NULL;
	while(aux != NULL && aux->info <= v){
		ant = aux;
		aux = aux->sig;
	}
	if(ant != NULL){
		ant->sig = nuevo;
	} else {
		lista = nuevo;
	}
	nuevo->sig = aux;
	
	return nuevo;
}

void ordenar(Nodo*& lista){
	Nodo* aux = NULL;
	int x;
	while(lista != NULL){
		x = eliminarPrimerNodo(lista);
		insertarOrdenado(aux,x);
	}
	lista = aux;
}

Nodo* buscaEInsertaOrdenado(Nodo*& lista, int v, bool& enc){
	Nodo* nodoBuscado = buscar(lista, v);
	if(nodoBuscado != NULL){
		enc = true;
	} else{
		nodoBuscado = insertarOrdenado(lista,v);
	}
	return nodoBuscado;
}

//pilas
void push(Nodo*& pila, int valor){
	Nodo* nuevo = new Nodo();
	nuevo->info = valor;
	nuevo->sig = pila;
	pila = nuevo;
}

int pop(Nodo*& pila){
	int retorno = pila->info;
	Nodo* aux = pila;
	pila = pila->sig;
	delete aux;
	return retorno;
}

//colas
void encolar(Nodo*& colafte, Nodo*& colafin, int v){
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sig = NULL;
	if(colafte == NULL){
		colafte = nuevo;
	} else{
		colafin->sig = nuevo;
	}
	colafin = nuevo;
};


int desencolar(Nodo*& colafte, Nodo*& colafin){
	int retorno = colafte->info;
	Nodo* aux = colafte;
	colafte = colafte->sig;
	if(colafte == NULL){
		colafin = NULL;
	}
	delete aux;
	return retorno;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------------------------------TP2----------------------------------------------------//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void msgl(string mensaje){
	cout<<mensaje<<endl;
};

void msg(string mensaje){
	cout<<mensaje;
};

//-------------------------------------------PRODUCTOS---------------------------------------------------
void agregarNodo(NodoProducto*& lista, InfoProducto info){
	
	NodoProducto* nuevo = new NodoProducto();
	nuevo->info = info;
	nuevo->sig = NULL;
	
	if(lista == NULL){
		lista = nuevo;
	} else{
		NodoProducto* aux = lista;
		while(aux->sig != NULL){
			aux = aux->sig;	
		}
		aux->sig = nuevo;	
	}
}

void mostrar(NodoProducto* lista){	
	NodoProducto* aux = lista;	 
	while(aux != NULL) {
	  cout <<"ID: "<< aux->info.id <<"   Descripcion: "<< aux->info.nombre <<"   Precio: $"<<aux->info.precio<<"   Umbral: "<< aux->info.umbral <<"   Disponibles: "<< aux->info.disponibles<<endl;
	  aux = aux->sig;
	}
}

NodoProducto* buscar(NodoProducto* lista, int v){
	NodoProducto* aux = lista;
	
	while(aux != NULL && aux->info.id != v){
		aux = aux->sig;		
	}	
	return aux;
}

void eliminar(NodoProducto*& lista, int v){
	NodoProducto* aux = lista;
	NodoProducto* ant = NULL;
	while(aux != NULL && aux->info.id != v){
		ant = aux;
		aux = aux->sig;		
	}
	if(ant != NULL){
		ant->sig = aux->sig;
	} else {
		lista = aux->sig;
	}	
	delete aux;
}

NodoProducto* insertarOrdenado(NodoProducto*& lista, InfoProducto info){
	NodoProducto* nuevo = new NodoProducto();
	nuevo->info = info;
	nuevo->sig = NULL;
	NodoProducto* aux = lista;
	NodoProducto* ant = NULL;
	while(aux != NULL && aux->info.id <= info.id){
		ant = aux;
		aux = aux->sig;
	}
	if(ant != NULL){
		ant->sig = nuevo;
	} else {
		lista = nuevo;
	}
	nuevo->sig = aux;
	
	return nuevo;
}

NodoProducto* buscaEInsertaOrdenado(NodoProducto*& lista, int v, bool& enc, InfoProducto info){
	NodoProducto* nodoBuscado = buscar(lista, v);
	if(nodoBuscado != NULL){
		enc = true;
	} else{
		nodoBuscado = insertarOrdenado(lista, info);
	}
	return nodoBuscado;
}

NodoProducto* eliminarPrimerNodo(NodoProducto*& lista){
	NodoProducto* retorno = lista;
	NodoProducto* aux = lista;
	lista = lista->sig;
	delete aux;
	return retorno;
};


NodoProducto* recorrer(NodoProducto* lista, int v){
	NodoProducto* aux = lista;
	
	while(aux != NULL && aux->info.id != v){
		aux = aux->sig;		
	}	
	return aux;
}

//----------------------------------------PROVEEDORES---------------------------------------------------


void agregarNodo(NodoProveedor*& lista, InfoProveedor info){
	
	NodoProveedor* nuevo = new NodoProveedor();
	nuevo->info = info;
	nuevo->sig = NULL;
	
	if(lista == NULL){
		lista = nuevo;
	} else{
		NodoProveedor* aux = lista;
		while(aux->sig != NULL){
			aux = aux->sig;	
		}
		aux->sig = nuevo;	
	}
}

void mostrar(NodoProveedor* lista){	
	NodoProveedor* aux = lista;	 
	while(aux != NULL) {
	  cout << aux->info.id <<" "<< aux->info.nombre <<" "<<aux->info.domicilio<<" "<<aux->info.telefono <<endl;
	  aux = aux->sig;
	}
}

NodoProveedor* buscar(NodoProveedor* lista, int v){
	NodoProveedor* aux = lista;
	
	while(aux != NULL && aux->info.id != v){
		aux = aux->sig;		
	}	
	return aux;
}

void eliminar(NodoProveedor*& lista, int v){
	NodoProveedor* aux = lista;
	NodoProveedor* ant = NULL;
	while(aux != NULL && aux->info.id != v){
		ant = aux;
		aux = aux->sig;		
	}
	if(ant != NULL){
		ant->sig = aux->sig;
	} else {
		lista = aux->sig;
	}	
	delete aux;
}

NodoProveedor* insertarOrdenado(NodoProveedor*& lista, InfoProveedor info){
	NodoProveedor* nuevo = new NodoProveedor();
	nuevo->info = info;
	nuevo->sig = NULL;
	NodoProveedor* aux = lista;
	NodoProveedor* ant = NULL;
	while(aux != NULL && aux->info.id <= info.id){
		ant = aux;
		aux = aux->sig;
	}
	if(ant != NULL){
		ant->sig = nuevo;
	} else {
		lista = nuevo;
	}
	nuevo->sig = aux;
	
	return nuevo;
}

NodoProveedor* buscaEInsertaOrdenado(NodoProveedor*& lista, int v, bool& enc, InfoProveedor info){
	NodoProveedor* nodoBuscado = buscar(lista, v);
	if(nodoBuscado != NULL){
		enc = true;
	} else{
		nodoBuscado = insertarOrdenado(lista, info);
	}
	return nodoBuscado;
}

NodoProveedor* eliminarPrimerNodoP(NodoProveedor*& lista){
	NodoProveedor* retorno = lista;
	NodoProveedor* aux = lista;
	lista = lista->sig;
	delete aux;
	return retorno;
};



//-----------------------------------------CLIENTES------------------------------------------------------

void agregarNodo(NodoCliente*& lista, InfoCliente info){
	
	NodoCliente* nuevo = new NodoCliente();
	nuevo->info = info;
	nuevo->sig = NULL;
	
	if(lista == NULL){
		lista = nuevo;
	} else{
		NodoCliente* aux = lista;
		while(aux->sig != NULL){
			aux = aux->sig;	
		}
		aux->sig = nuevo;	
	}
}

void mostrar(NodoCliente* lista){	
	NodoCliente* aux = lista;	 
	while(aux != NULL) {
	  cout << aux->info.id <<" "<< aux->info.nombre <<" "<<aux->info.domicilio<<" "<<aux->info.telefono <<endl;
	  aux = aux->sig;
	}
}

NodoCliente* buscar(NodoCliente* lista, int v){
	NodoCliente* aux = lista;
	
	while(aux != NULL && aux->info.id != v){
		aux = aux->sig;		
	}	
	return aux;
}

void eliminar(NodoCliente*& lista, int v){
	NodoCliente* aux = lista;
	NodoCliente* ant = NULL;
	while(aux != NULL && aux->info.id != v){
		ant = aux;
		aux = aux->sig;		
	}
	if(ant != NULL){
		ant->sig = aux->sig;
	} else {
		lista = aux->sig;
	}	
	delete aux;
}

NodoCliente* insertarOrdenado(NodoCliente*& lista, InfoCliente info){
	NodoCliente* nuevo = new NodoCliente();
	nuevo->info = info;
	nuevo->sig = NULL;
	NodoCliente* aux = lista;
	NodoCliente* ant = NULL;
	while(aux != NULL && aux->info.id <= info.id){
		ant = aux;
		aux = aux->sig;
	}
	if(ant != NULL){
		ant->sig = nuevo;
	} else {
		lista = nuevo;
	}
	nuevo->sig = aux;
	
	return nuevo;
}

NodoCliente* buscaEInsertaOrdenado(NodoCliente*& lista, int v, bool& enc, InfoCliente info){
	NodoCliente* nodoBuscado = buscar(lista, v);
	if(nodoBuscado != NULL){
		enc = true;
	} else{
		nodoBuscado = insertarOrdenado(lista, info);
	}
	return nodoBuscado;
}
NodoCliente* eliminarPrimerNodoC(NodoCliente*& lista){
	NodoCliente* retorno = lista;
	NodoCliente* aux = lista;
	lista = lista->sig;
	delete aux;
	return retorno;
};


//-------------------------------------------PEDIDOS-----------------------------------------

void agregarNodo(NodoItem*& lista, InfoItem info){
	
	NodoItem* nuevo = new NodoItem();
	nuevo->info = info;
	nuevo->sig = NULL;
	
	if(lista == NULL){
		lista = nuevo;
	} else{
		NodoItem* aux = lista;
		while(aux->sig != NULL){
			aux = aux->sig;	
		}
		aux->sig = nuevo;	
	}
}

void encolar(NodoPedido*& colafte, NodoPedido*& colafin, InfoPedido info){
	NodoPedido* nuevo = new NodoPedido();
	nuevo->info = info;
	nuevo->sig = NULL;
	if(colafte == NULL){
		colafte = nuevo;
	} else{
		colafin->sig = nuevo;
	}
	colafin = nuevo;
};


InfoPedido desencolar(NodoPedido*& colafte, NodoPedido*& colafin){
	InfoPedido retorno = colafte->info;
	NodoPedido* aux = colafte;
	colafte = colafte->sig;
	if(colafte == NULL){
		colafin = NULL;
	}
	delete aux;
	return retorno;
};

void push(NodoPedido*& pila, InfoPedido info){
	NodoPedido* nuevo = new NodoPedido();
	nuevo->info = info;
	nuevo->sig = pila;
	pila = nuevo;
}

InfoPedido pop(NodoPedido*& pila){
	InfoPedido retorno = pila->info;
	NodoPedido* aux = pila;
	pila = pila->sig;
	delete aux;
	return retorno;
}

/*
			--------- ARCHIVOS ----------
*/
bool archivoExiste(const char* arch) {
    FILE* file = fopen(arch, "rb+");
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}


FILE* archExiste (const char* arch){
	FILE* file;
	if (archivoExiste(arch)){
		file = fopen(arch, "rb+");
	} else {
		file = fopen(arch, "wb+");
	}
	return file;
}

void guardarPedido(NodoPedido* nodo, FILE* archivo) {
    if (nodo == nullptr) {
        return;
    }
    fwrite(&nodo->info, sizeof(InfoPedido), 1, archivo); // Asegúrate de que esto esté correcto
    guardarPedido(nodo->sig, archivo); // Llamada recursiva para el siguiente nodo
}


/*
void guardarPedido (NodoPedido* nodo, FILE* archivo){
	if (nodo == nullptr){
		return;
	}
	fwrite (&nodo->info, sizeof(InfoPedido), 1, archivo);
	
	NodoItem* item = nodo->info.productos;
	
	while (item != nullptr) {
		fwrite(&item->info, sizeof(InfoItem),1, archivo);
		item = item->sig;
		}
	
	guardarPedido (nodo->sig, archivo);
}

*/

//------------------------------EXTRAS PROBANDO----------------------------------------------

void guardarProveedores(NodoProveedor* proveedores, FILE* arch) {
    rewind(arch);
    while (proveedores != NULL) {
        fwrite(&proveedores->info, sizeof(InfoProveedor), 1, arch);   // Guarda la información principal del proveedor

        NodoProducto* producto = proveedores->info.productosProveedor;    // Guarda los productos del proveedor
        while (producto != NULL) {
            fwrite(&producto->info, sizeof(InfoProducto), 1, arch);
            producto = producto->sig;
        }
        
        proveedores = proveedores->sig;
    }
}


void cargarProveedores(NodoProveedor*& proveedores, FILE* file) {
    InfoProveedor regProveedor;
    rewind(file);
    while (fread(&regProveedor, sizeof(InfoProveedor), 1, file)) {
        NodoProveedor* nuevoProveedor = new NodoProveedor{regProveedor, nullptr};
        
		NodoProducto* productosProveedor = nullptr;    // Cargar productos del proveedor
        InfoProducto regProducto;
        while (fread(&regProducto, sizeof(InfoProducto), 1, file) && regProducto.id != -1) {
            insertarOrdenado(productosProveedor, regProducto);
        }
        nuevoProveedor->info.productosProveedor = productosProveedor;
        
		nuevoProveedor->sig = proveedores;     // Insertar en la lista de proveedores
        proveedores = nuevoProveedor;
    }
}


void imprimirPedidos(NodoPedido* pedidos) {
    while (pedidos != nullptr) {
        cout << "Pedido ID: " << pedidos->info.id << ", Cliente ID: " << pedidos->info.idCliente << ", Total: " << pedidos->info.totalPedido << endl;
        pedidos = pedidos->sig;
    }
}
