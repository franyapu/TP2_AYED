#include <iostream>
#include <string>
#include "funciones.hpp"

using namespace std;

void crearCliente(NodoCliente*& lista){
	
	bool enc= false;
	
	NodoCliente* cliente;
	
	msgl("-------------------- Ingresando Cliente --------------------");
	
	InfoCliente info;
	
	msg("Ingrese el ID: ");
	cin>>info.id;
	cout<<endl;
	msg("Ingrese el nombre: ");
	cin>>info.nombre;
	cout<<endl;
	msg("Ingrese el domicilio: ");
	cin>>info.domicilio;
	cout<<endl;
	msg("Ingrese el telefono: ");
	cin>>info.telefono;
	cout<<endl;
	
	info.historialCompras = NULL;	
	
	cliente=buscaEInsertaOrdenado(lista, info.id, enc, info);
	
	if(enc){
		msgl("! ! ! El cliente ya existe ! ! !");
		cout<<"ID_Cliente: "<<cliente->info.id<<"   Nombre: "<<cliente->info.nombre<<"   Domicilio: "<<
		cliente->info.domicilio <<"   Telefono: "<<cliente->info.telefono<<endl;		
	}else{
		msgl("* * * Cliente creado exitosamente * * *");
		cout<<" ID_Cliente: "<<cliente->info.id<<"    Nombre: "<<cliente->info.nombre<<"    Domicilio: "<<
		cliente->info.domicilio <<"   Telefono: "<<cliente->info.telefono<<endl;
	}	
	system("pause");
}

void mostrarClientes(NodoCliente*& lista){
	msgl("-------------------- Listado de Clientes --------------------");
	mostrar(lista);
	system("pause");
}

void editarCliente(NodoCliente*& lista){
	int idBuscado, opt;
	msgl("Ingrese el ID del cliente a modificar");
	cin>>idBuscado;
	NodoCliente* clienteBuscado= buscar(lista, idBuscado);
	cout<<"ID_Cliente: "<<clienteBuscado->info.id<<"   Nombre: "<<clienteBuscado->info.nombre<<
	"   Domicilio: "<<clienteBuscado->info.domicilio<<"   Telefono: "<<clienteBuscado->info.telefono<<endl;
	msgl("1 - Modificar domicilio");
	msgl("2 - Modificar telefono");
	cin>>opt;
	switch(opt){
		case 1:
			msg("Ingrese el nuevo domicilio: ");
			cin.getline(clienteBuscado->info.domicilio, sizeof(clienteBuscado->info.domicilio));
			cout<<endl;
			break;
		case 2:
			msg("Ingrese el nuevo telefono: ");
			cin>>clienteBuscado->info.telefono;
			cout<<endl;
			break;
		default: msgl("! ! ! Opcion invalida ! ! !");					
	}
	system("pause");
}

void eliminarCliente(NodoCliente*& lista){
	int idBuscado;
	msg("Ingrese el ID del cliente a eliminar: ");
	cin>>idBuscado;
	cout<<endl;
	eliminar(lista, idBuscado);		
}

void verCliente(NodoCliente*& lista){
	int id;
	msgl("Ingrese el ID del cliente que desea ver");
	cin>>id;
	NodoCliente* clienteBuscado = buscar(lista, id);
	if(clienteBuscado!=NULL){
		cout<<"Nombre: "<<clienteBuscado->info.nombre<<"   Domicilio: "<<clienteBuscado->info.domicilio<<"   Telefono: "<<clienteBuscado->info.telefono<<endl;		
		NodoPedido* auxPila = new NodoPedido();
		auxPila=NULL;
		InfoPedido aux;	
	
		if(clienteBuscado->info.historialCompras!=NULL){
			msgl("-------------------- Pedidos asociados --------------------");
			while(clienteBuscado->info.historialCompras!=NULL){
				aux=pop(clienteBuscado->info.historialCompras);
				cout<<"ID_Pedido: "<<aux.id<<"   Total: $"<<aux.totalPedido<<endl;
				push(auxPila, aux);
			};		
			while(auxPila!=NULL){
				aux=pop(auxPila);
				push(clienteBuscado->info.historialCompras, aux);
			};	
		};			
	}else{
		msgl("! ! ! ID de cliente no existe ! ! !");
	}
	system("pause");
}

void menuClientes(NodoCliente*& lista){
	
	int opt;
		
	do{
		system("cls");
		//system("clear");
		msgl("* * * CLIENTES * * * ");
		msgl("Seleccione una opcion");	
		msgl("1 - Crear Cliente");
		msgl("2 - Modificar Cliente");
		msgl("3 - Eliminar Cliente");
		msgl("4 - Mostrar Clientes");
		msgl("5 - Ver un cliente");
		msgl("0 - VOLVER");
		
		cin>>opt;
		
		switch(opt){
			case 0:
				break;
			case 1:
				crearCliente(lista);
				break;
			case 2:
				editarCliente(lista);
				break;
			case 3:
				eliminarCliente(lista);
				break;
			case 4:
				mostrarClientes(lista);
				break;
			case 5:
				verCliente(lista);
				break;	
			default:msgl("! ! ! Opcion invalida ! ! !");
			system("pause"); 	
		}		
	}while(opt!=0);
}