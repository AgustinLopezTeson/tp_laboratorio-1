#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int menu(int* kilometros,float* preAerolineas, float* preLatam)
{
   int opcion;
   int km;
   float aerolineas;
   float latam;

   km=*kilometros;
   aerolineas=*preAerolineas;
   latam=*preLatam;

	printf(" ****Menu de Opciones****\n\n");

    printf("1-Ingresar Kilometros  (Km=%d Km)\n",km);
	printf("2-Ingresa  precio de Vuelos(Aerolineas=$%.2f , Latam=$%.2f)\n",aerolineas,latam);
	printf("3-Calcular todos los costos\n");
	printf("4-Informar  Resultados\n");
	printf("5-Carga forzada de datos\n");
	printf("6-Salir\n\n");

	printf("Ingrese la opcion que le interesa:");
	scanf("%d",&opcion);

	return opcion;
}

int precioVuelos(float* aerolineas,float* latam)
{

	int todoOk=0;
	float aerolineasP;
	float latamP;


	printf("\nIngrese el precio del vuelo Aerolineas: ");
	scanf("%f",&aerolineasP);

	printf("\nIngrese el precio del vuelo Latam: ");
	scanf("%f",&latamP);

	*aerolineas=aerolineasP;
	*latam=latamP;


return todoOk=1;
}

int calcularTodosLosCostos(int kilometros,float pAerolineas, float pLatam,float* tarjetaLatam,float* creditoLatam, float* btcLatam, float* unitarioLatam,float* tarjetaAerolineas,float* creditoAerolineas,float* btcAerolineas,float* unitarioAerolineas,float* diferencia)
{
	int todoOk=0;

	float debitoLatam;
	float credLatam;
	float LatamBtc;
	float unitarioKmLatam;
	float debitoAero;
	float credAero;
	float AeroBtc;
	float unitarioKmAero;
	float diferenciaLyA;

	printf("1- Tarjeta  de Debito (10%% de descuento)\n");
	printf("2- Tarjeta  de Credito (25%% de Interes)\n");
	printf("3- Bitcoin( 1BTC -> 4606954.55 Pesos Argentinos)\n");
	printf("4- Mostrar precio por kilometro(Precio Unitario)\n");
	printf("5- Mostrar diferencia de precio ingresada (Latam-Aerolineas)\n\n");

	debitoLatam=pLatam/1.1000;
	*tarjetaLatam=debitoLatam ;

	credLatam=pLatam*1.2500;
	*creditoLatam=credLatam;

	LatamBtc=pLatam/4606954.55;
	*btcLatam=LatamBtc;

	unitarioKmLatam=pLatam/kilometros;
	*unitarioLatam=unitarioKmLatam;

	 debitoAero=pAerolineas/1.1000;
	 *tarjetaAerolineas=debitoAero;

	 credAero=pAerolineas*1.2500;
	 *creditoAerolineas=credAero;

	 AeroBtc=pAerolineas/4606954.55;
	 *btcAerolineas=AeroBtc;

	 unitarioKmAero=pAerolineas/kilometros;
	 *unitarioAerolineas=unitarioKmAero;

	 diferenciaLyA=pLatam-pAerolineas;

	 if(diferenciaLyA<0){
		 diferenciaLyA=diferenciaLyA*-1;
	 }
	 *diferencia=diferenciaLyA;


	printf("SE CALCULARON TODAS LOS COSTOS\n\n");
	return todoOk;
}

void informarResultado(float tarjetaLatam,float creditoLatam,float btcLatam,float unitarioLatam,float tarjetaAerolineas,float creditoAerolineas,float btcAerolineas,float unitarioAerolineas,float diferencia)
{

	printf("\n\nLatam:\n\n");
	printf("a) Precio con tarjeta de debito: $%.2f\n",tarjetaLatam);
	printf("b) Precio con tarjeta de credito: $%.2f\n",creditoLatam);
	printf("c) Precio pagando con bitcoin: %.6f BTC\n",btcLatam);
	if(unitarioLatam>0)
	{
		printf("d) Precio Unitario: $%.2f\n",unitarioLatam);
	}else
	{printf("d)ERROR");}


	printf("\nAerolineas:\n\n");
	printf("a) Precio con tarjeta de debito: $%.2f\n",tarjetaAerolineas);
	printf("b) Precio con tarjeta de credito: $%.2f\n",creditoAerolineas);
	printf("c) Precio pagando con bitcoin: %.6f BTC\n",btcAerolineas);
	if(unitarioAerolineas>0)
		{
			printf("d) Precio Unitario: $%.2f\n",unitarioAerolineas);
		}else
		{printf("d)ERROR");}

	printf("\nLa diferencia de precio es: $%f\n\n",diferencia);

}




void cargaForzada()
{
	float precioLatam=159339;
	float precioAerolineas=162965;

	int km=7090;


	printf("Kms Ingresados: %d Km\n\n",km);


	printf("\nPrecio Aerolineas:$%.2f\n",precioAerolineas);
	printf("a) Precio con tarjeta de debito: $%.2f\n",precioAerolineas/1.100);
	printf("b) Precio con tarjeta de credito: $%.2f\n",precioAerolineas*1.100);
	printf("c) Precio pagando con bitcoin: %.6f BTC\n",precioAerolineas/4606954.55);
	printf("d) Precio Unitario: $%.2f\n",precioAerolineas/km);

	printf("\n\nPrecio Latam: $%.2f\n",precioLatam);
	printf("a) Precio con tarjeta de debito: $%.2f\n",precioLatam/1.100);
	printf("b) Precio con tarjeta de credito: $%.2f\n",precioLatam*1.100);
	printf("c) Precio pagando con bitcoin: %.6f BTC\n",precioLatam/4606954.55);
	printf("d) Precio Unitario: $%.2f\n",precioLatam/km);

	printf("\nLa diferencia de precio es: $%f\n\n",precioAerolineas-precioLatam);
}

/*int tarjetaCredito(int precio , float*total)
{
	float  resultado;
	resultado=precio*1.25;
	*total=resultado;
}*/
