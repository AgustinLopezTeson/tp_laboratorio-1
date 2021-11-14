/*
 ============================================================================
 Name        : Tp_2.c
 Author      : Agustin Ezequiel Lopez Teson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Function.h"
#include "ArrayEmployee.h"

#define TAM 1000



 int main(void) {

		setbuf(stdout,NULL);

	 	char seguir= 's';

        Employee list [TAM];

	    int nextId = 20000;
	    int idBorrado;
	    int idModificar;


	    initEmployees(list,TAM);

	    buscarLibre(list,TAM);


	    do
	    {

	        switch(menu())
	        {

	        case 1 :
	            if(!newEmployee(list,TAM, &nextId))
	            {
	                printf("No se pudo realizar el alta");
	            }
	            else
	            {
	                printf("Alta exitosa !!!\n");

	            }
	            break;
	        case 2:
	            system("cls");
	                printf("           *** Modificar Empleado ***       \n\n");
	                printf("Ingrese el ID: ");

	                scanf("%d",&idModificar );
	            if(!modificarEmpleado(list,TAM,idModificar))
	            {
	                printf("No se pudo realizar la modificacion");
	            }
	            else
	            {
	                printf("Modificacion exitosa !!!\n");

	            }

	            break;
	        case 3:
	                system("cls");
	                printf("           *** Modificar Empleado ***       \n\n");
	                printf("Ingrese el ID: ");

	                scanf("%d",&idBorrado);
	             if(!removeEmployee(list,TAM,idBorrado))
	            {
	                printf("No se pudo realizar la baja");
	            }
	            else
	            {
	                printf("Baja exitosa !!!\n");


	            }
	            break;
	        case 4:
	            if(!printEmployees(list,TAM)){
                       printf("No hay personas que mostrar");
	            }
	            break;
	        case 5:
	            printf("Eligio salir");
	            seguir='n';
	            break;
	        default:
	            printf("Opcion Invalida \n");
	            break;
	        }

            system("pause");
	    }
	    while(seguir=='s');














	return 0;
}
