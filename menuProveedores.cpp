#include <iostream>
#include <string>
#include "funciones.hpp"

using namespace std;

void crearProveedor(NodoProveedor*& lista){
	
	bool enc= false;
	
	NodoProveedor* proveedor;
	
	msgl("-------------------- Ingresando Proveedor --------------------");
	
	InfoProveedor info;
	
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
	info.productosProveedor = NULL;	
	
	proveedor=buscaEInsertaOrdenado(lista, info.id, enc, info);
	
	if(enc){
		msgl("! ! ! El proveedor ya existe ! ! !");
		cout<<" "<<proveedor->info.id<<" "<<proveedor->info.nombre<<" "<<
		proveedor->info.domicilio <<" "<<proveedor->info.telefono<<endl;		
	}else{
		msgl("* * * Proveedor creado exitosamente * * *");
		cout<<"ID: "<<proveedor->info.id<<"   Nombre: "<<proveedor->info.nombre<<"   Domicilio: "<<
		proveedor->info.domicilio <<"   Telefono: "<<proveedor->info.telefono<<endl;
	}	
	system("pause");
}

void listarProveedores(NodoProveedor*& lista){
	msgl("------------------- Listado de Proveedores -----------------");
	mostrar(lista);
	system("pause");
}

void editarProveedor(NodoProveedor*& lista){
	int idBuscado, opt;
	msg("Ingrese el ID del proveedor a modificar: ");
	cin>>idBuscado;
	cout<<endl;
	NodoProveedor* proveedorBuscado= buscar(lista, idBuscado);
	cout<<"ID: "<<proveedorBuscado->info.id<<"   Nombre: "<<proveedorBuscado->info.nombre<<
	"   Domicilio: "<<proveedorBuscado->info.domicilio<<"   Telefono: "<<proveedorBuscado->info.telefono<<endl;
	msgl("1 - Modificar domicilio");
	msgl("2 - Modificar telefono");
	cin>>opt;
	switch(opt){
		case 1:
			msg("Ingrese el nuevo domicilio: ");
			cin>>proveedorBuscado->info.domicilio;
			cout<<endl;
			break;
		case 2:
			msg("Ingrese el nuevo telefono: ");
			cin>>proveedorBuscado->info.telefono;
			cout<<endl;
			break;
		default: msgl("! ! ! Opcion invalida ! ! !");					
	}
	system("pause");
}

void eliminarProveedor(NodoProveedor*& lista){
	int idBuscado;
	msgl("Ingrese el ID del proveedor a eliminar");
	cin>>idBuscado;
	eliminar(lista, idBuscado);		
}

void verProveedor(NodoProveedor*& lista){
	int id;
	msgl("Ingrese el ID del proveedor que desea ver");
	cin>>id;
	NodoProveedor* aux = buscar(lista, id);
	if(aux!=NULL){
		cout<<"Nombre: "<<aux->info.nombre<<"   Domicilio: "<<aux->info.domicilio<<"   Telefono: "<<aux->info.telefono<<endl;
		msgl("-------------------- Productos asociados --------------------");
		mostrar(aux->info.productosProveedor);
	}else{
		msgl("! ! ! ID de proveedor no existe ! ! !");
	}
	system("pause");
}

void menuProveedores(NodoProveedor*& lista){
	
	int opt;
		
	do{
		system("cls");
		//system("clear");
		msgl("--------------- GESTION PROVEEDORES ---------------");
		msgl("Seleccione una opcion");	
		msgl("1 - Crear Proveedor");
		msgl("2 - Modificar Proveedor");
		msgl("3 - Eliminar Proveedor");
		msgl("4 - Listar Proveedores");
		msgl("5 - Ver un Proveedor");
		msgl("0 - VOLVER");
		
		cin>>opt;
		
		switch(opt){
			case 0:
				break;
			case 1:
				crearProveedor(lista);	
				break;
			case 2:
				editarProveedor(lista);
				break;
			case 3:
				eliminarProveedor(lista);
				break;
			case 4:
				listarProveedores(lista);
				break;
			case 5:
				verProveedor(lista);
				break;
			default:msgl("! ! ! Opcion invalida! ! !");
			system("pause"); 	
		}		
	}while(opt!=0);
}