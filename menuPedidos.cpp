#include <iostream>
#include <string>
#include <cstring>
#include "funciones.hpp"

using namespace std;

void checkStock(NodoProducto*& productos, int idProducto){
	NodoProducto* aux = buscar(productos, idProducto);
	if(aux->info.umbral>aux->info.disponibles){
		msgl("* * * Se solicito reposicion del producto * * *");
	}
}

void mostrarPendientes(NodoPedido*& pedidosFte, NodoPedido*& pedidosFin){	
	
	if(pedidosFte!=NULL){
		
		NodoPedido* auxFte=NULL;
		NodoPedido* auxFin=NULL;
		InfoPedido aux;
		
		msgl("-------------------- Pedidos Pendientes --------------------");		

		while(pedidosFte!=NULL){			
			aux=desencolar(pedidosFte, pedidosFin);
			cout<<"   ID_PEDIDO: "<<aux.id<<"   ID_Cliente: "<<aux.idCliente<<"   Total: $"<<aux.totalPedido<<endl;
			encolar(auxFte, auxFin, aux);
		};
		pedidosFte=auxFte;
		pedidosFin=auxFin;	
	}else{
		msgl("-------------------- NO HAY Pedidos Pendientes --------------------");
	}
	
	system("pause");

}

void mostrarTerminados(NodoPedido*& pedidosTerminados){
	NodoPedido* auxPila = new NodoPedido();
	auxPila=NULL;
	InfoPedido aux;	
	
	if(pedidosTerminados!=NULL){
		msgl("-------------------- Pedidos Terminados --------------------");
		while(pedidosTerminados!=NULL){
			aux=pop(pedidosTerminados);
			cout<<"ID_Pedido: "<<aux.id<<"   ID_Cliente"<<aux.idCliente<<"   Total: $"<<aux.totalPedido<<endl;
			push(auxPila, aux);
		};		
		while(auxPila!=NULL){
			aux=pop(auxPila);
			push(pedidosTerminados, aux);
		}		
	}else{
		msgl("-------------------- NO HAY Pedidos Terminados --------------------");
	}
	system("pause");
}

void enviarPedido(NodoPedido*& pedidosFte, NodoPedido*& pedidosFin, NodoPedido*& pedidosTerminados){
	if(pedidosFte!=NULL){
		InfoPedido aux=desencolar(pedidosFte, pedidosFin);
		aux.estado=false;
		push(pedidosTerminados, aux);	
		msgl("* * * Pedido enviado y archivado * * *");
		cout<<"ID PEDIDO: "<<aux.id<<endl;
		
	}else{
		msgl("-------------------- NO HAY Pedidos Pendientes --------------------");
	}	
	system("pause");
	
}

void asociarCliente(NodoCliente*& clientes, int clienteId, InfoPedido pedido){
	NodoCliente* clienteBuscado;
	clienteBuscado=buscar(clientes, clienteId);
	if(clienteBuscado!=NULL){
		push(clienteBuscado->info.historialCompras, pedido);
		msgl("* * * Cliente asociado * * *");
		cout<<"ID_Cliente: "<<clienteBuscado->info.id<<"   Nombre: "<<clienteBuscado->info.nombre<<endl;		
	}else{
		msgl("! ! ! Cliente NO existe ! ! !");
	}
	
}

void crearPedido(NodoPedido*& pedidosFte, NodoPedido*& pedidosFin, NodoPedido* pedidosTerminados, NodoCliente*& clientes, NodoProducto*& productos){
	NodoPedido* pedido = new NodoPedido(); /////////////////////////////////////////VER DESDE ACA
		
	NodoItem* item = new NodoItem();
	NodoProducto* producto;
	char opt;
	msg("Ingrese el ID del pedido: ");
	cin>>pedido->info.id;
	cout<<endl;	
	msg("Ingrese el ID del cliente: ");
	cin>>pedido->info.idCliente;
	pedido->info.estado=true;
	
	msgl("--------------- Agregando items al pedido ---------------");
	
	do{
		msg("Ingrese el ID del producto: ");
		cin>>item->info.idProducto;
		cout<<endl;	
			
		producto=buscar(productos, item->info.idProducto);
		
		if(producto!=NULL){
			strcpy(item->info.nombreProducto, producto->info.nombre);
			item->info.precio=producto->info.precio;
			
			msg("Ingrese la cantidad: ");
			cin>>item->info.cantidad;
			cout<<endl;
			
			item->info.totalItem=item->info.precio*item->info.cantidad;
			agregarNodo(pedido->info.productos, item->info);
			producto->info.disponibles=producto->info.disponibles-item->info.cantidad;					
		}else{
			msgl("! ! ! El producto NO existe ! ! !");			
		}
		
		pedido->info.totalPedido+=item->info.totalItem;
		
		
		msg("Desea agregar otro item? S/N: ");		
		cin>>opt;
		cout<<endl;
		
	}while(opt!='n' && opt!='N');
	
	asociarCliente(clientes, pedido->info.idCliente, pedido->info);	
	
	encolar(pedidosFte, pedidosFin, pedido->info);
	
	checkStock(productos, producto->info.id);
	
	msgl("* * * Pedido creado exitosamente * * *");
	
	system("pause");
	
	
}

void menuPedidos(NodoPedido*& pedidosFte, NodoPedido*& pedidosFin, NodoPedido* pedidosTerminados, NodoCliente*& clientes, NodoProducto*& productos){
	
	int opt;
		
	do{
		system("cls");
		//system("clear");
		msgl("--------------- GESTION DE PEDIDOS ---------------");
		msgl("Seleccione una opcion");	
		msgl("1 - Crear Pedido");
		msgl("2 - Enviar Proximo Pedido");
		msgl("3 - Mostrar Pedidos Pendientes");
		msgl("4 - Mostrar Pedidos Finalizados");		
		msgl("0 - VOLVER");
		
		cin>>opt;
		
		switch(opt){
			case 0:
				break;
			case 1:
				crearPedido(pedidosFte, pedidosFin, pedidosTerminados, clientes, productos);
				break;
			case 2:
				enviarPedido(pedidosFte, pedidosFin, pedidosTerminados);
				break;
			case 3:
				mostrarPendientes(pedidosFte, pedidosFin);
				break;
			case 4:
				mostrarTerminados(pedidosTerminados);
				break;								
			default:msgl("! ! ! Opcion invalida ! ! !");
			system("pause"); 	
		}		
	}while(opt!=0);
}
