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
	setbuf(stdout,NULL);
    char seguir='s';
    int flagEntrada=0;
    int flagGuardado=0;
    int pNextId=1001;
    int*pId=&pNextId;
	LinkedList* listaPasajeros = ll_newLinkedList();
    do{
        switch(menu())
        {
        case 1:
            if ( !controller_loadFromText("data.csv", listaPasajeros) )
            {
                printf("Error al cargar desde texto\n");
            }
            flagEntrada=1;
            break;
        case 2:
            if ( !controller_loadFromBinary("data.bin", listaPasajeros) )
            {
                printf("Error al cargar desde binario\n");
            }
            flagEntrada=1;
            break;
        case 3:
            if ( !controller_addPassenger(listaPasajeros))
            {
                printf("Error en el alta de empleado\n");
            }
            flagEntrada=1;
            break;
        case 4:
        	if(flagEntrada==0)
        	   {
        		printf("Tiene que cargar algo antes de editar");
        	   }else
        	   {
        		   if ( !controller_editPassenger(listaPasajeros) )
        		               {
        		                   printf("Error al editar al empleado\n");
        		               }
        	   }

            break;
        case 5:

        	if(flagEntrada==0)
        	{
				printf("Tiene que cargar algo antes de remover");
        	}else
        	{
            	if ( !controller_removePassenger(listaPasajeros) )
                {
                    printf("Error en la baja de empleado\n");
                }
        	}

            break;
        case 6:
        	if(flagEntrada==0)
        	{
				printf("Tiene que cargar algo antes de listar");
        	}else
        	{
            	if ( !controller_ListPassenger(listaPasajeros) )
                {
                    printf("Error en listar los empleados\n");
                }
                system("pause");
        	}

            break;
       case 7:
			if(flagEntrada==0)
			{
				printf("Tiene que cargar algo antes de ordenar");
			}else
			{
		    	   if ( !controller_sortPassenger(listaPasajeros) )
		            {
		                printf("Error al  ordenar los empleados\n");
		            }
			}

            break;
        case 8:
            if ( !controller_saveAsText("data1.csv", listaPasajeros) )
            {
                printf("Error al guardar en texto\n");
            }else
            {
            	flagGuardado=1;
            }

            break;
        case 9:
            if ( !controller_saveAsBinary("data.bin", listaPasajeros) )
            {
                printf("Error al guardar en binario\n");
            }
            break;
        case 10:
        	if(flagGuardado==0)
        	{
        		printf("Tiene que guardar el archivo antes de poder salir");
        	}else
        	{
        		 seguir='n';
        	}

            break;
        default:
            printf("\nOpcion Incorrecta \n\n");
            break;
        }
    }
    while(seguir=='s');
    return 0;
}

