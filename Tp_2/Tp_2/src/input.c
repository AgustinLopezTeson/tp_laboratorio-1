#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "ArrayPassenger.h"

int menu()
{
	int opcion;
	printf("*** MENU PASAJEROS *** \n\n");
	printf("1-ALTAS\n");
	printf("2-MODIFICAR\n");
	printf("3-BAJA\n");
	printf("4-INFORMAR\n");
	printf("5-CARGA FORZADA\n");
	printf("6-INFORMAR PROMEDIOS\n");
	printf("7-SALIR\n");
	fflush(stdin);
	printf("Ingrese su opcion : ");
	scanf("%d",&opcion);
return opcion;
}

int editMenu(Passenger list[], int len, int indice)
{
    int opcion = 0;
    system("cls");
    printf("     *** Modificar pasajero ***\n");
    printf("* Nombre: %s *----* Apellido: %s  *----* Precio: %.1f *----* Codigo Vuelo: %s Tipo Pasajero: %d *\n",
           list[indice].name, list[indice].lastName, list[indice].price,
           list[indice].flyCode,list[indice].typePassenger);
    printf("1- Editar Nombre\n");
    printf("2- Editar Apellido\n");
    printf("3- Editar Precio\n");
    printf("4- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    printf("\n");
    return opcion;
}

int menuSort()
{
    int retorno;
    printf("Filtar Ascendente o Descendente? (a/d): ");
    fflush(stdin);
    char opcion = getchar();
    opcion = tolower(opcion);
    while (opcion != 'a' && opcion != 'd')
    {
        printf("Invalido. Reingrese(a/d): ");
        fflush(stdin);
        opcion = getchar();
        opcion = tolower(opcion);
    }
    if (opcion == 'a')
    {
        retorno = 1;
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

char nombres [10][21] = {
            {"Mariela"},
            {"Juan Pablo"},
            {"Mauro"},
            {"Yolanda"},
            {"Fabio"},
            {"Simon"},
            {"Hugo"}

                                };
char apellidos[10][21] = {
            {"Gomez"},
            {"Martinez"},
            {"Gomez"},
            {"Alberdi"},
            {"Benitez"},
            {"Heredia"},
            {"Gomez"}

                                };
char codigoVuelo [10][10] = {
            {"AA20"},
            {"LA20"},
            {"AA20"},
            {"LA20"},
            {"AA22"},
            {"poy7"},
            {"aqpe"}

                                };

float precios[8] = {20000,30000,18000,32000,45000, 5400, 7840};
int tipoVuelo[8] = {1,2,2,1,2,0};


int hardcodearPasajeros(Passenger lista[], int tam, int cant, int* pId)
{

    int contador = -1;
    if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for(int i = 0; i < cant; i++)
        {
            lista[i].id = *pId;
            (*pId)++;
            strcpy(lista[i].name ,nombres[i]);
            strcpy(lista[i].lastName ,apellidos[i]);
            lista[i].price=precios[i];
            lista[i].typePassenger=tipoVuelo[i];
            strcpy(lista[i].flyCode ,codigoVuelo[i]);
            lista[i].isEmpty = 0;
            contador++;
        }
    }

    return contador;
}


