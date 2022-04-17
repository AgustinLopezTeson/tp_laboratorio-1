/*
 ============================================================================
 Name        : Tp_1.c
 Author      : Agustin Lopez
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo Practico N°1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main() {

	setbuf(stdout, NULL);

	int respuesta;
	int kilometros=0;
	float preAerolineas=0;
	float preLatam=0;
	float tarjetaLatam;
	float creditoLatam;
	float btcLatam;
	float unitarioLatam;
	float tarjetaAerolineas;
	float creditoAerolineas;
	float btcAerolineas;
	float unitarioAerolineas;
	float diferencia;
	int seguir =1;


	do
	{

	respuesta=menu(&kilometros,&preAerolineas,&preLatam);


	switch(respuesta){

	case 1:
		printf("Ingrese los kilometros");
		scanf("%d",&kilometros);
		break;
	case 2:
		precioVuelos(&preAerolineas,&preLatam);
		break;
	case 3:
		calcularTodosLosCostos(kilometros,preAerolineas,preLatam,&tarjetaLatam,&creditoLatam,&btcLatam,&unitarioLatam,&tarjetaAerolineas,&creditoAerolineas,&btcAerolineas,&unitarioAerolineas,&diferencia);
		break;
	case 4:
		informarResultado(tarjetaLatam,creditoLatam,btcLatam,unitarioLatam,tarjetaAerolineas,creditoAerolineas,btcAerolineas,unitarioAerolineas,diferencia);
		break;
	case 5:
		cargaForzada();
		break;
	case 6:
		printf("Saliendo....\n\n");
		seguir=0;
		break;
	default:
		printf("Ingrese una  opcion correcta\n\n");
		break;C
	}
	}while(seguir==1);

	return EXIT_SUCCESS;
}
