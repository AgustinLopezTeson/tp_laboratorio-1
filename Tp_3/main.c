#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "input.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	//int id=1001;
    char seguir='s';
    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
        switch(menu())
        {
        case 1:
            if ( !controller_loadFromText("data.csv", listaPasajeros) )
            {
                printf("Error al cargar desde texto\n");
            }
            break;
        case 2:
            if ( !controller_loadFromBinary("data.bin", listaPasajeros) )
            {
                printf("Error al cargar desde binario\n");
            }
            break;
        case 3:
            if ( !controller_addPassenger(listaPasajeros) )
            {
                printf("Error en el alta de empleado\n");
            }
            break;
        case 4:
            if ( !controller_editPassenger(listaPasajeros) )
            {
                printf("Error al editar al empleado\n");
            }
            break;
        case 5:
            if ( !controller_removePassenger(listaPasajeros) )
            {
                printf("Error en la baja de empleado\n");
            }
            break;
        case 6:
            if ( !controller_ListPassenger(listaPasajeros) )
            {
                printf("Error en listar los empleados\n");
            }
            system("pause");
            break;
        case 7:
            if ( !controller_sortPassenger(listaPasajeros) )
            {
                printf("Error al  ordenar los empleados\n");
            }
            break;
       /* case 8:
            if ( !controller_saveAsText("data1.csv", listaPasajeros) )
            {
                printf("Error al guardar en texto\n");
            }
            break;
        case 9:
            if ( !controller_saveAsBinary("data.bin", listaPasajeros) )
            {
                printf("Error al guardar en binario\n");
            }
            break;
        case 10:
            seguir='n';
            break;*/
        default:
            printf("\nOpcion Incorrecta \n\n");
            break;
        }
    }
    while(seguir=='s');
    return 0;
}

