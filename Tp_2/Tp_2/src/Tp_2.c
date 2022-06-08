/*
 ============================================================================
 Name        : Tp_2.c
 Author      : Agustin Ezequie Lopez Teson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#define TAM 200


int main(void) {
	setbuf(stdout,NULL);

	char salir='n';
	int pId=100;
	Passenger list[TAM];

	initPassengers(list,TAM);



do{

switch(menu())
{

	case 1:
		cargarPasajeros(list,TAM,&pId);
		break;
	case 2:
		printf("Funciona");
		break;
	case 3:
		printf("Funciona");
		break;
	case 4:
		printPassengers(list,TAM);
		break;
	case  5:
		printf("Funciona");
		salir="s";
		break;
	default:
		break;

}

}while(salir != "s");



	return EXIT_SUCCESS;
}
