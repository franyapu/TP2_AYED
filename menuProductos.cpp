

#include <iostream>
#include <string>
#include "funciones.hpp"

using namespace std;

void asociarProveedor(NodoProveedor*& listaProv, int proveedorId, InfoProducto producto){
	NodoProveedor* proveedorBuscado;
	proveedorBuscado=buscar(listaProv, proveedorId);
	if(proveedorBuscado!=NULL){
		insertarOrdenado(proveedorBuscado->info.productosProveedor, producto);
		msgl("* * * Proveedor asociado * * *");
		cout<<"ID_Proveedor: "<<proveedorBuscado->info.id<<"   Nombre: "<<proveedorBuscado->info.nombre<<endl;		
	}else{
		msgl("! ! ! Proveedor NO existe ! ! !");
	}
	
}

void crearProducto(NodoProducto*& lista, NodoProveedor*& listaProv){
	
	bool enc= false;
	
	NodoProducto* producto;
	
	msgl("-------------------- Ingresando Producto --------------------");
	
	InfoProducto info;
	int proveedorId;
	
	msg("Ingrese el ID: ");
	cin>>info.id;
	cout<<endl;
	msg("Ingrese el nombre: ");
	cin>>info.nombre;
	cout<<endl;
	msg("Ingrese el precio: $");
	cin>>info.precio;
	cout<<endl;
	msg("Ingrese el umbral: ");
	cin>>info.umbral;
	cout<<endl;
	msg("Ingese la cantidad disponible: ");
	cin>>info.disponibles;
	cout<<endl;
	msg("Ingrese el ID del proveedor: ");
	cin>>proveedorId;
	
	//insertarOrdenado(lista, info);
	producto=buscaEInsertaOrdenado(lista, info.id, enc, info);
	
	if(enc){
		msgl("! ! ! El producto ya existe ! ! !");
		cout<<"ID_Producto: "<<producto->info.id<<" Descripcion: "<<producto->info.nombre<<"   Precio: "<<producto->info.precio<<"   Umbral: "<<
		producto->info.umbral<<"   Disponibles: "<<producto->info.disponibles<<endl;		
	}else{
		asociarProveedor(listaProv, proveedorId, info);
		msgl("* * * Producto creado exitosamente * * *");
		cout<<"ID: "<<producto->info.id<<"   Descripcion: "<<producto->info.nombre<<"   Precio: $"<<producto->info.precio<<"   Umbral: "<<
		producto->info.umbral<<"    Disponibles: "<<producto->info.disponibles<<endl;
	}	
	system("pause");
}

void listarProductos(NodoProducto*& lista){
	msgl("-------------------- Listado de Productos --------------------");
	mostrar(lista);
	system("pause");
}

void editarProducto(NodoProducto*& lista, NodoProveedor*& listaProv){
	int idBuscado, opt;
	msgl("Ingrese el ID del producto a modificar");
	cin>>idBuscado;
	NodoProducto* productoBuscado= buscar(lista, idBuscado);
	cout<<"ID: "<<productoBuscado->info.id<<"   Descripcion: "<<productoBuscado->info.nombre<<"   Precio: $"<<productoBuscado->info.precio<<"   Umbral: "<<
	productoBuscado->info.umbral<<" Disponibles: "<<productoBuscado->info.disponibles<<endl;
	msgl("1 - Modificar precio");
	msgl("2 - Modificar umbral");
	msgl("3 - Modificar disponibles");
	msgl("4 - Asociar Proveedor");
	cin>>opt;
	switch(opt){
		case 1:
			msg("Ingrese el nuevo precio: ");
			cin>>productoBuscado->info.precio;
			cout<<endl;			
			break;
		case 2:
			msg("Ingrese el nuevo umbral: ");
			cin>>productoBuscado->info.umbral;
			cout<<endl;			
			break;
		case 3:
			msg("Ingrese los disponibles: ");
			cin>>productoBuscado->info.disponibles;	
			cout<<endl;
		case 4:
			int proveedorId;
			msg("Ingrese el ID del proveedor: ");
			cin>>proveedorId;
			cout<<endl;
			asociarProveedor(listaProv, proveedorId, productoBuscado->info);
			break;		
		default: msgl("! ! ! Opcion invalida ! ! !");					
	}
	system("pause");
}

void eliminarProducto(NodoProducto*& lista){
	int idBuscado;
	msg("Ingrese el ID del producto a eliminar: ");
	cin>>idBuscado;
	cout<<endl;
	eliminar(lista, idBuscado);		
}

void menuProductos(NodoProducto*& lista, NodoProveedor*& listaProv){
	
	int opt;
		
	do{
		system("cls");
		//system("clear");
		msgl("---------------- GESTION DE PRODUCTOS ----------------");
		msgl("Seleccione una opcion");	
		msgl("1 - Crear producto");
		msgl("2 - Modificar Producto");
		msgl("3 - Eliminar Producto");
		msgl("4 - Listar Productos");
		msgl("0 - VOLVER");
		
		cin>>opt;
		
		switch(opt){
			case 0:
				break;
			case 1:
				crearProducto(lista, listaProv);
				break;
			case 2:
				editarProducto(lista, listaProv);
				break;
			case 3:
				eliminarProducto(lista);
				break;				
			case 4:
				listarProductos(lista);
				break;	
			default:msgl("! ! ! Opcion invalida ! ! !");
			system("pause"); 	
		}		
	}while(opt!=0);
}