#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

int initEmployees(Employee list[], int tam)
{
    int todoOk = 0;
    if (list != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            list[i].isEmpty = 1;
        }
    }
    return todoOk;
}

int buscarLibreEmpleado(Employee list[], int tam)
{
    int indice = -1;
    for (int i = 0; i < tam; i++)
    {
        if (list[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int addEmployee(Employee list[],int tam, int* id,char name[], char lastName[], float salary,int sector)
{
    int todoOk = 0;
    int indice;
    Employee aux;
    if (list != NULL && tam > 0)
    {
        system("cls");
        printf("  ***Alta Empleado*** \n\n");
        indice = buscarLibreEmpleado(list, tam);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
           aux.id=*id;

            system("cls");
            printf("***Alta Persona*** \n\n");
            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(name);

            printf("\nIngrese su apellido: ");
            gets(lastName);

            printf("\nIngrese el salario : ");
            scanf("%f", &salary);

            printf("\nIngrese sector: ");
            scanf("%.2f", &sector);

            addEmployee(list,tam,&id,name,lastName,salary,sector);
            todoOk=1;

        (*id)++;
        }
    }
    return todoOk;
}
