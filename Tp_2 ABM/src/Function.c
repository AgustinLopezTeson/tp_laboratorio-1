#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Function.h"
#include "ArrayEmployee.h"

#define TAM 1000



int menu()
{

    int opcion;

    system("cls");
    printf(" **** ABM PERSONAS ***** \n\n");
    printf("1-Alta Persona\n");
    printf("2-Modificar Persona\n");
    printf("3-Baja Persona\n");
    printf("4-Listar Persona\n");
    printf("5-Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int buscarLibre(Employee* list, int tam)
{

    int libre=0;

    if( list!= NULL && tam>0)
    {
        for(int i = 0; i<tam; i++)
        {
            if(list[i].isEmpty)
            {
                libre=i;
                break;
            }
        }
    }

    return libre;
}
