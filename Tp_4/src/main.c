#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

int main()
{
    setbuf(stdout, NULL);
    int option;
    LinkedList* listaPasajeros = ll_newLinkedList();
    int flagCargarTexto = 0;
    int flagCargarBin = 0;

    	startTesting(1);  // ll_newLinkedList
    	startTesting(2);  // ll_len
    	startTesting(3);  // getNode - test_getNode
    	startTesting(4);  // addNode - test_addNode
    	startTesting(5);  // ll_add
    	startTesting(6);  // ll_get
    	startTesting(7);  // ll_set
    	startTesting(8);  // ll_remove
    	startTesting(9);  // ll_clear
    	startTesting(10); // ll_deleteLinkedList
    	startTesting(11); // ll_indexOf
    	startTesting(12); // ll_isEmpty
    	startTesting(13); // ll_push
    	startTesting(14); // ll_pop
    	startTesting(15); // ll_contains
    	startTesting(16); // ll_containsAll
    	startTesting(17); // ll_subList
    	startTesting(18); // ll_clone
    	startTesting(19); // ll_sort

    do{
    	puts("\nMENU DE OPCIONES:\n"
    		"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto). \n"
    		"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario). \n"
    		"3. Alta de pasajero \n"
    		"4. Modificar datos de pasajero \n"
    		"5. Baja de pasajero \n"
    		"6. Listar pasajeros \n"
    		"7. Ordenar pasajeros \n"
    		"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto). \n"
    		"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario). \n"
    		"10. Salir \n");

    	utn_getNumero("INGRESE OPCION: ", "ERROR \n", 1, 10, 2, &option);

        switch(option)
        {
            case 1:
            	if(flagCargarTexto == 0)
            	{
            		controller_loadFromText("data.csv",listaPasajeros);
					flagCargarTexto = 1;
            	}
            	else
            	{
            		puts("\nError,con el binario.\n");
            	}
            break;

            case 2:
            	if(flagCargarBin == 0)
            	{
					controller_loadFromBinary("data.bin", listaPasajeros);
					flagCargarBin = 1;
            	}
            	else
            	{
            		puts("\nError , con el binario.\n");
            	}
            break;

            case 3:
            	if(flagCargarTexto == 1 || flagCargarBin == 1)
				{
					controller_addPassenger(listaPasajeros);
				}
				else
				{
					puts("\nCargar antes de dar de alta.\n");
				}
            break;

            case 4:
            	if(flagCargarTexto == 1 || flagCargarBin == 1)
            	{
					controller_editPassenger(listaPasajeros);
            	}
            	else
            	{
            		puts("\nCargue el archivo antes de editar un pasajero.\n");
            	}
			break;

            case 5:
            	if(flagCargarTexto == 1 || flagCargarBin == 1)
				{
    				controller_removePassenger(listaPasajeros);
				}
				else
				{
					puts("\nNo se puede eliminar si no se cargoe l .CSV.\n");
				}
			break;

            case 6:
            	if(flagCargarTexto == 1 || flagCargarBin == 1)
				{
					controller_ListPassenger(listaPasajeros);
				}
				else
				{
					puts("\n No se puede listar sin la carga del Archivo.\n");
				}
			break;

            case 7:
            	if(flagCargarTexto == 1 || flagCargarBin == 1)
				{
                	controller_sortPassenger(listaPasajeros);
				}
				else
				{
					puts("\nNo se puede ordenar sin el archivo cargado\n");
				}
            break;

            case 8:
            	if(flagCargarTexto == 1)
            	{
					controller_saveAsText("data.csv", listaPasajeros);
            	}
            	else
            	{
					puts("\nNo hay nada que guardar  .\n");
            	}
           	break;

            case 9:
            	if(flagCargarBin == 1)
				{
					controller_saveAsBinary("data.bin", listaPasajeros);
				}
				else
				{
					puts("\nNo hay nada que guardar .\n");
				}
            break;

            case 10:
            	puts("\nSaliendo....");
            break;
        }
    }while(option != 10);

    return EXIT_SUCCESS;
}
