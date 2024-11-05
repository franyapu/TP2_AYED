#include <iostream>
#include <string>
#include <cstdlib>
#include "funciones.hpp"

using namespace std;

void menuPrincipal(NodoProducto*& productos, NodoProveedor*& proveedores, NodoCliente*& clientes, NodoPedido*& pedidosFte, NodoPedido*& pedidosFin, NodoPedido*& pedidosTerminados){
	
	int opt;
		
	do{
		system("cls");
		//system("clear");
		msgl("--------------- INICIO ---------------");
		msgl("Seleccione una opcion");
		msgl("1 - Ir al modulo de PRODUCTOS");
		msgl("2 - Ir al modulo de PROVEEDORES");
		msgl("3 - Ir al modulo de CLIENTES");
		msgl("4 - Ir al modulo de PEDIDOS");
		msgl("5 - Ir al modulo de STOCK");
		msgl("0 - FINALIZAR");
		cin>>opt;
		switch(opt){
			case 0:
				break;
			case 1: menuProductos(productos, proveedores);
				break;
			case 2: menuProveedores(proveedores);
				break;
			case 3: menuClientes(clientes);
				break;
			case 4: menuPedidos(pedidosFte, pedidosFin, pedidosTerminados, clientes, productos);
				break;
			case 5: menuStock();
				break;
			default:msgl("! ! ! Opcion invalida! ! !");
			system("pause"); 	
		}
				
	}while(opt!=0);
}