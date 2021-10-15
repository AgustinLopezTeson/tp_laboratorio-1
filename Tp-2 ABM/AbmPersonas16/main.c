
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

#define TAM 3



int main()
{
    char seguir= 's';
    Employee lista [TAM];
    int nextId= 20000;

    inicializarPersonas(lista,TAM);
    buscarLibre(lista,TAM);


    do
    {

        switch(menu())
        {

        case 1 :
            if(!altaPersona(lista,TAM,&nextId))
            {
                printf("No se pudo realizar el alta");
            }
            else
            {
                printf("Alta exitosa !!!\n");


            }
            break;
        case 2:
            printf("Modificar Persona");
            break;
        case 3:

             if(!bajaPersona(lista,TAM))
            {
                printf("No se pudo realizar la baja");
            }
            else
            {
                printf("Baja exitosa !!!\n");


            }
            break;
        case 4:
            printf("Informar");
            break;
        case 5:
            printf("Eligio salir");
            seguir='n';
            break;
        default:
            printf("Opcion Invalida \n");
        }


        system("pause");
    }
    while(seguir=='s');


    return 0;
}

