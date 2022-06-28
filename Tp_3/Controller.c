#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "input.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE* f= fopen("data.csv","r");

	    if(f==NULL && pArrayListPassenger==NULL)
	    {
	        printf("No se pudo cargar el archivo");
	    }
	    else
	    {
	        if(parser_PassengerFromText(f,pArrayListPassenger))
	        {
	              printf("Hubo un error en cargar los empleados");
	        }
	        else
	        {
	            printf("Carga exitosa!!!!\n\n");
	            system("pause");
	            fclose(f);
	        }

	    }
	    return 1;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{

    FILE* f= fopen(path,"rb");

    if(f==NULL && pArrayListPassenger==NULL)
    {
        printf("No se pudo cargar el archivo");
    }
    else
    {
        if(parser_PassengerFromBinary(f,pArrayListPassenger))
        {
            printf("Hubo un error en cargar los empleados");
        }
        else
        {
            printf("Carga exitosa!!!!\n\n");
            system("pause");
            fclose(f);
        }

    }
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	if(pArrayListPassenger!=NULL)
	    {
	        system("cls");
	        if(new_PassengerManual(pArrayListPassenger))
	        {
	            printf("Alta Exitosa\n\n");
	            system("pause");
	        }
	    }
	    else
	    {
	        printf("No se pudo dar el alta");
	    }


	    return 1;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	    Passenger* auxPassenger;

	    char seguir = 's';
	    char salir;
	    int id;
	    int opcion;
	    int indice;
	    int precio;
	    int estadoDelVuelo;

	    char confirma;

	    controller_ListPassenger(pArrayListPassenger);

	    if ( pArrayListPassenger != NULL )
	    {
	        //system("cls");
	        printf("Modificar datos del pasajero\n");

	        printf("Ingrese id: ");
	        scanf("%d", &id);
	        indice = searchPassengerId( pArrayListPassenger, id );
	        if ( indice == -1 )
	        {
	            printf("No se encontro el Pasajero\n");
	        }
	        else
	        {
	            auxPassenger = ll_get(pArrayListPassenger, indice);

	            do
	            {
	                system("cls");
	                printf("\n");
	                printf("Id  Nombre Apellido Precio  CodigoVuelo    EstadoVuelo    \n");
	                list_Passenger(auxPassenger);
	                opcion = menuDeModificaciones();

	                switch (opcion)
	                {
	                case 1:
	                    system("cls");
	                    printf("  Editar Precio\n");
	                    printf("Ingrese el precio del vuelo : ");
	                    scanf("%d", &precio);
	                    printf("Confirma cambio del precio? (S/N)\n");
	                    fflush(stdin);
	                    scanf("%c", &confirma);
	                    confirma = toupper(confirma);
	                    if (confirma == 'S')
	                    {
	                        Passenger_setPrecio(auxPassenger, precio);
	                    }
	                    else
	                    {
	                        printf("Edición cancelada\n");
	                    }

	                    break;
	                case 2:
	                    system("cls");
	                    printf("  Editar estado\n");
	                    printf("Ingrese el sueldo: ");
	                    scanf("%d", &estadoDelVuelo);

	                    printf("Confirma cambio estado? (S/N)\n");
	                    fflush(stdin);
	                    scanf("%c", &confirma);
	                    confirma = toupper(confirma);
	                    if (confirma == 'S')
	                    {
	                        Passenger_setTipoPasajero(auxPassenger, estadoDelVuelo);
	                    }
	                    else
	                    {
	                        printf("Edición cancelada\n");
	                    }

	                    break;
	                case 3:
	                    printf("Esta seguro que quiere salir? (S/N)\n");
	                    fflush(stdin);
	                    scanf("%c", &salir);
	                    salir = toupper(salir);
	                    if (salir == 'S')
	                    {
	                        seguir = 'n';
	                    }
	                    else
	                    {
	                        break;
	                    }
	                    break;
	                default:
	                    printf("Opcion invalida\n");
	                    break;
	                }
	                system("pause");
	            }
	            while(seguir == 's');
	            todoOk=1;
	        }
	    }
	    return todoOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	    int id;
	    int indice;
	    char confirma;

	    Passenger* auxPass;

	    controller_ListPassenger(pArrayListPassenger);

	    if ( pArrayListPassenger != NULL )
	    {

	        printf("Baja de Pasajero\n");

	        printf("Ingrese id: ");
	        scanf("%d", &id);
	        indice = searchPassengerId( pArrayListPassenger, id );
	        system("cls");
	        if ( indice == -1 )
	        {
	            printf("No se encontro el empleado\n");
	        }
	        else
	        {
	            auxPass = ll_get(pArrayListPassenger, indice);
	            printf("Empleado seleccionado: \n\n");
	            printf("Id  Nombre Apellido Precio  CodigoVuelo    EstadoVuelo    \n");
	            list_Passenger(auxPass);
	            printf("\n");
	            printf("Confirma la baja? (S/N)\n");
	            fflush(stdin);
	            scanf("%c", &confirma);
	            if ( tolower(confirma) == 's' )
	            {
	                ll_remove(pArrayListPassenger, indice);
	                printf("Baja exitosa\n");
	                todoOk = 1;
	            }
	        }

	    }
	    return todoOk;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	    Passenger* auxEmp;
	    if(pArrayListPassenger!=NULL)
	    {
	    	printf("Id  Nombre Apellido Precio  CodigoVuelo    EstadoVuelo    \n");
	        for(int i = 0 ; i<ll_len(pArrayListPassenger); i++)
	        {
	            auxEmp=(Passenger* )ll_get(pArrayListPassenger,i);
	            list_Passenger(auxEmp);

	        }
	        todoOk=1;
	    }

	    return todoOk;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
		char seguir = 's';
	    char salir;

	    int todoOk = 1;
	    int opcion;
	    if ( pArrayListPassenger != NULL )
	    {
	        system("cls");
	        printf("***Menu Ordenar Pasajeros***\n");

	       /* do
	        {
	            opcion = subMenuComp();

	            switch (opcion)
	            {
	            case 1:
	                system("cls");
	                printf("  Ordenar Horas trabajadas de menor a mayor  \n");
	               // ll_sort( pArrayListPassenger, compPassengerHorasTrabajadas, 1 );
	                controller_ListPassenger(pArrayListPassenger);
	                break;
	            case 2:
	                system("cls");
	                printf("  Ordenar  Horas trabajadas de mayor a menor\n");
	             //   ll_sort( pArrayListPassenger, compPassengerHorasTrabajadas, 0 );
	                controller_ListPassenger(pArrayListPassenger);
	                break;
	            case 3:
	                system("cls");
	                printf("  Ordenar  Sueldo de menor a mayor\n");
	             //   ll_sort( pArrayListPassenger, compPassengerSueldo, 1 );
	                controller_ListPassenger(pArrayListPassenger);
	                break;
	            case 4:
	                system("cls");
	                printf("  Ordenar  Sueldo de mayor a menor\n");
	               // ll_sort( pArrayListPassenger, compPassengerSueldo, 0 );
	                controller_ListPassenger(pArrayListPassenger);
	                break;
	            case 5:
	                printf("Esta seguro que quiere salir? (S/N)\n");
	                fflush(stdin);
	                scanf("%c", &salir);
	                salir = toupper(salir);
	                if (salir == 'S')
	                {
	                    seguir = 'n';
	                }
	                else
	                {
	                    break;
	                }
	                break;
	            default:
	                printf("Opcion invalida\n");
	                break;
	            }
	            system("pause");
	        }
	        while(seguir == 's');
	    }*/
	    return todoOk;

}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	    FILE* f;
	    int id;
	    char nombre[50];
	    char apellido[50];
	    float precio;
	    int estadoVuelo;
	    char codigoVuelo[5];
	    Passenger* auxPassanger;

	    if ( path != NULL && pArrayListPassenger != NULL )
	    {

	        f = fopen(path, "w"); // abro el archivo
	        if ( f == NULL )
	        {
	            printf("No se pudo abrir el archivo\n");

	        }

	        fprintf( f, "Id  Nombre Apellido Precio  CodigoVuelo    EstadoVuelo    \n" );

	        for (int i = 0; i < ll_len(pArrayListPassenger); i++)
	        {
	            auxPassanger = ll_get(pArrayListPassenger, i);
	            if ( Passenger_getId( auxPassanger, &id ) &&
	                    Passenger_getNombre( auxPassanger, nombre ) &&
	    				Passenger_getApellido(auxPassanger,apellido)&&
	                    Passenger_getPrecio( auxPassanger, &precio) &&
	                    Passenger_getCodigoVuelo(auxPassanger, codigoVuelo)&&
	    				Passenger_getTipoPasajero(auxPassanger,&estadoVuelo)
	               )
	            {
	                fprintf(f, "%d,%s,%s,%f,%s,%d\n", id, nombre,apellido,precio,codigoVuelo,estadoVuelo);
	                todoOk = 1;
	            }
	        }
	        system("cls");
	        printf("\nGuardado correctamente en DATA1.CSV.\n");
	        system("pause");
	    }
	    fclose(f);
	    return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk = 0;
	    FILE* f;

	    Passenger* auxPassanger;

	    if ( path != NULL && pArrayListPassenger != NULL )
	    {
	        f = fopen(path, "wb");
	        if ( f == NULL )
	        {
	            printf("No se pudo abrir el archivo\n");

	        }

	        for (int i = 0; i < ll_len(pArrayListPassenger); i++)
	        {
	            auxPassanger = ll_get(pArrayListPassenger, i);
	            if ( (auxPassanger + i) != NULL )

	                if ( (auxPassanger) != NULL )
	                {
	                    fwrite( auxPassanger, sizeof(Passenger),1, f);
	                    todoOk = 1;
	                }
	        }
	        system("cls");
	        printf("\nGuardado correctamente en DATA.BIN.\n");
	        system("pause");


	    }
	    fclose(f);
	    return todoOk;

}
}
