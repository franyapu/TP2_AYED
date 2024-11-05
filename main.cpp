#include <iostream>
#include <string>
#include <string.h>
#include "funciones.hpp"
using namespace std;


int main(int argc, char** argv) {
	
	NodoProducto* productos=NULL;
	NodoProveedor* proveedores=NULL;
	NodoCliente* clientes=NULL;
	NodoPedido* pedidosFte=NULL;
	NodoPedido* pedidosFin=NULL;
	NodoPedido* pedidosTerminados=NULL;
	

	
	FILE* productosFile = archExiste("persistencia/productos.dat");
	FILE* clientesFile = archExiste("persistencia/clientes.dat");
	FILE* proveedoresFile = archExiste("persistencia/proveedores.dat");
	FILE* pedidosFile = archExiste("persistencia/pedidos.dat");
	
	
	rewind(productosFile);
    rewind(clientesFile);
    rewind(proveedoresFile);
    rewind(pedidosFile);
	
	InfoProducto regProducto;
	InfoCliente regCliente;
	InfoProveedor regProveedores;
	InfoPedido regPedido;
		
	fread(&regProducto, sizeof(InfoProducto),1, productosFile);
	
	while(!feof(productosFile)){
	
	insertarOrdenado (productos, regProducto);
	
	fread(&regProducto, sizeof(InfoProducto),1, productosFile);
	}
	
	
	
	
	fread(&regCliente, sizeof(InfoCliente),1, clientesFile);
	
	while(!feof(clientesFile)){
	
	insertarOrdenado (clientes, regCliente);
	
	fread(&regCliente, sizeof(InfoCliente),1, clientesFile);
	}
	




//	cargarProveedores(proveedores, proveedoresFile);
	
	
	fread(&regProveedores, sizeof(InfoProveedor),1, proveedoresFile);
	
	while(!feof(proveedoresFile)){
	
	insertarOrdenado (proveedores, regProveedores);
	
	fread(&regProveedores, sizeof(InfoProveedor),1, proveedoresFile);
	}
	
	
	


	fread(&regPedido, sizeof(InfoPedido),1, pedidosFile);
	
	while(!feof(pedidosFile)){
	
	encolar(pedidosFte, pedidosFin, regPedido);
	
	fread(&regPedido, sizeof(InfoPedido),1, pedidosFile);
	}
	
	
	
	
	
	/*NodoProducto reg;
	fread(&reg, sizeof(NodoProducto),1,productosFile)
	while(!feof(productosFile)){	
	}*/
	

	NodoProducto* mio;
	menuPrincipal(productos, proveedores, clientes, pedidosFte, pedidosFin, pedidosTerminados);
	
	rewind(productosFile);
	
	while(productos != NULL){		
		
		regProducto=productos->info;
	
		cout<<regProducto.nombre<<" "<<endl;
	
		fwrite(&regProducto, sizeof(InfoProducto), 1, productosFile);
		
		eliminarPrimerNodo(productos);	
		
	
	}
	
	

	
	
	rewind(clientesFile);
	
	while(clientes != NULL){		
		
		regCliente=clientes->info;
	
		cout<<regCliente.nombre<<" "<<endl;
	
		fwrite(&regCliente, sizeof(InfoCliente), 1, clientesFile);
		
		eliminarPrimerNodoC(clientes);	
	}
	
	
//	guardarProveedores(proveedores, proveedoresFile);

	rewind(proveedoresFile);
	
	while(proveedores != NULL){		
		
		regProveedores=proveedores->info;
	
		cout<<regProveedores.nombre<<" "<<endl;
	
		fwrite(&regProveedores, sizeof(InfoProveedor), 1, proveedoresFile);
		
		eliminarPrimerNodoP(proveedores);	
	}
	

	


    rewind(pedidosFile);
	
	
	//guardarPedido (pedidosTerminados, pedidosFile);
	guardarPedido (pedidosFte, pedidosFile);
	
	fclose(productosFile);
    fclose(clientesFile);
    fclose(proveedoresFile);
    fclose(pedidosFile);
		
	return 0;
}


