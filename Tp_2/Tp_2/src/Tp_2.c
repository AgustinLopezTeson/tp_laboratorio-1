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
#include "input.h"
#define TAM 100


int main(void) {
	setbuf(stdout,NULL);
	float precioPromedio;
	float sumaPrecio;
	char salir='n';
	int pId=100;
	int cantPasajeros=5;
	Passenger list[TAM];
	int flag=0;

	initPassengers(list,TAM);

do{

switch(menu())
{

	case 1:
		cargarPasajeros(list,TAM,&pId);
		cantPasajeros++;
		flag=1;
		break;
	case 2:
		if(flag==0)
		{printf("Tiene que cargar pasajeros primero");}
		else
		{editEmployee(list,TAM);}
		break;
	case 3:
		if(flag==0)
		{printf("Tiene que cargar pasajeros primero");}
		else
		{removePassenger(list,TAM);}
		break;
	case 4:
		if(flag==0)
		{printf("Tiene que cargar pasajeros primero");}
		else{printPassengers(list,TAM);}
		break;
	case 5:
		hardcodearPasajeros(list,TAM,5,&pId);
		flag=1;
		break;
	case 6:
		if (flag==0)
		{
			printf("Ingrese pasajeros primero");
		}
		else{

			                if( pricePromedio(list, TAM, &precioPromedio, &sumaPrecio) )
			                {
			                    printf("No se pudo mostrar la informacion de los salarios\n");
			                }
			                else
			                {
			                    printf("  *** Informe Precio *** \n\n");
			                    printf("Total precios: $%.2f\n", sumaPrecio);
			                    printf("Precio promedio: %.2f\n", precioPromedio);
			        	        printf("       *** Listado de Pasajeros ***\n");
			        	        printf("   Id           nombre         Apellido      precio      Tipo      Fly Code\n");
			        	        printf("------------------------------------------------------------------------------------\n");

			                    masPromedioPrecio(list, TAM, precioPromedio, sumaPrecio);
			                }
		}
		break;
	case 7:
		printf("Saliendo...");
		salir='s';
		break;
	default:
		break;

}

}while(salir != 's');



	return EXIT_SUCCESS;
}
