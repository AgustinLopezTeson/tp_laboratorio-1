

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

#define TAM 3


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
    scanf("%d", &opcion);
}

int inicializarPersonas(Employee lista[] , int tam)
{

    int todoOk=0;
    if( lista!= NULL && tam>0)
    {
        for(int i = 0; i<tam; i++)
        {

            lista[i].isEmpty = 1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibre(Employee lista[], int tam)
{

    int libre=0;

    if( lista!= NULL && tam>0)
    {
        for(int i = 0; i<tam; i++)
        {
            if(lista[i].isEmpty)
            {
                libre=i;
                break;
            }
        }
    }

    return libre;
}

int altaPersona(Employee lista [], int tam, int* pId)
{

    int todoOk=0;
    int indice;
    Employee auxPersona;


    if( lista!= NULL && tam>0)
    {
        system("cls");
        printf("***Alta Persona*** \n\n");
        indice = buscarLibre(lista,tam);

        if(indice == -1)
        {
            printf("No hay lugar \n");

        }
        else
        {

            auxPersona.id=*pId;

            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(auxPersona.name);

            printf("\nIngrese su apellido: ");
            scanf("%s", &auxPersona.lastName);

            printf("\nIngrese el salario : ");
            scanf("%d", &auxPersona.salary);

            printf("\nIngrese sector: ");
            scanf("%.2f", &auxPersona.sector);

            (*pId)++;
        }

            auxPersona.isEmpty=0;

            lista[indice]=auxPersona;
            todoOk=1;
    }
    return todoOk;


}

void mostrarPersona(Employee p)
{

    int todoOk=0;





    return todoOk;
}







int mostrarPersonas(Employee lista[], int tam)
{

    int todoOk=0;

    printf("%d     %s       %");



    return todoOk;

}

int bajaPersona(Employee lista [], int tam)
{
    int todoOk=0;
    int id;
    int indice;
    char confirma;

    if(lista!=NULL && tam > 0 )
    {
        system("cls");
        printf("           *** Baja Persona ***       \n\n");
        printf("Ingrese el ID: ");

        scanf("%d", &id);

        indice= buscarLibre(lista,tam);


        if(indice == -1)
        {
            printf("No existe una persona con esa ID : %d", id);
        }else
        {
            mostrarPersona(lista[indice]);

            printf("Confirma la baja S/N");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma=='s'){

                lista[indice].isEmpty=1;

            }else{

                printf("Baja cancelada");

            }


        }

    }

}
