#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "input.h"

int menu(){

    int opcionElegida;

    printf("\n                ****  Menu de Opciones  **** \n\n");
    printf("1.Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n\n");
    printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n\n");
    printf("3. Alta de pasajero\n\n");
    printf("4. Modificar datos de pasajero\n\n");
    printf("5. Baja de pasajero\n\n");
    printf("6. Listar pasajeros \n\n");
    printf("7. Ordenar pasajeros\n\n");
    printf("8.Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n\n");
    printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n\n");
    printf("10. Salir\n\n");
    printf( "\nIngrese la opcion correspondiente: \n");

    scanf("%d",&opcionElegida);

    return opcionElegida;
}

int menuDeModificaciones()
{
    int opcion;

    printf("\n\n        *** Modificar Pasajero ***          \n");
    printf("------------------------------------------------\n");
    printf("    1- Nombre\n\n");
    printf("    2- Precio\n\n");
    printf("    3- Salir\n\n");

    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

