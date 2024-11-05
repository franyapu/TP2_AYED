#include <iostream>
#include <string>
#include "funciones.hpp"

using namespace std;

void menuStock(){
	
	int opt;
		
	do{
		system("cls");
		//system("clear");
		msgl("* * * STOCK * * * ");
		msgl("Seleccione una opcion");
		msgl("0 - VOLVER");
		
		cin>>opt;
		
		switch(opt){
			case 0:
				break;
			case 1:;
				break;
			default:msgl("Opcion invalida");
			system("pause"); 	
		}		
	}while(opt!=0);
}