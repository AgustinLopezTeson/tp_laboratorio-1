#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Function.h"
#include "ArrayEmployee.h"

#define TAM 1000


int initEmployees(Employee* lista, int len)
{

    int todoOk=0;

    if( lista!= NULL && len>0)
    {
        for(int i = 0; i<len; i++)
        {

            lista[i].isEmpty = 1;
        }
        todoOk=1;
    }
    return todoOk;
}

int newEmployee(Employee* list , int len, int* nextId){

        int todoOk=0;
        int indice;
        int id;
        char name[51];
        char lastName[51];
        float salary;
        int sector;

        indice = buscarLibre(list,len);

        if(indice == -1)
        {
            printf("No hay lugar \n");

        }
        else
        {

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

            addEmployee(list, len , &nextId,name,lastName,salary,sector);
            todoOk=1;
            }


return todoOk;
}

int addEmployee(Employee* list, int len, int* id, char name[],char
lastName[],float salary,int sector)
{

    int todoOk=0;
    int indice;
    Employee auxEmployee;
    if( list!= NULL && len>0)
    {
                auxEmployee.id = *id;
                strcpy(auxEmployee.name,name);
                strcpy(auxEmployee.name,name);
                auxEmployee.salary = salary;
                auxEmployee.sector = sector;

        }
            list[indice]=auxEmployee;
            todoOk=1;

        return todoOk;
    }

int printEmployee(Employee* list)
{
	strcat(list->name,"");
	strcat(list->name,list->lastName);

	printf("%d      %s     %f      %d\n",list->id,list->name, list->salary,list->sector);
}

int printEmployees(Employee* list, int tam)
{

    int todoOk=0;
    if( list !=  NULL && tam>0)
    {

        system("cls");
         printf("                     **Lista de Empleados  **\n");
         printf("--------------------------------------------------------------------------\n");
         printf("   ID  Nombre                  Apellido              Sueldo       Sector  \n");
         printf("--------------------------------------------------------------------------\n");


        for(int i = 0 ; i>tam ; i++)
        {
            if(list[i].isEmpty==0)
            {

            }
        }
    }




    return todoOk;

}

int removeEmployee(Employee list[], int len, int id)
{
    int todoOk=0;
    int indice;
    char confirma;

    if(list!=NULL && len > 0 )
    {


        indice = findEmployeeById(list,len,id);
        printEmployee(list);

        if(indice == -1)
        {
            printf("No existe una persona con esa ID : %d", id);
        }
        else
        {


            printf("Confirma la baja S/N");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma=='s')
            {

                list[indice].isEmpty=1;

            }
            else
            {

                printf("Baja cancelada");

            }


        }

    }
return todoOk;
}


int findEmployeeById(Employee list[], int len,int id){

	int indice = -1;


		if(list != NULL && len> 0)
		{

			for(int i = 0 ; i<len; i++)
			{

				if(list[i].id==id && list[i].isEmpty ==0)
				{
					indice=id;
					break;
				}


			}



		}
		return indice;
}

int modificarEmpleado(Employee*  list, int len, int id){

    int todoOk=0;
    int indice;
    char confirma;

    if(list!=NULL && len > 0 )
    {


        indice = findEmployeeById(list,len,id);
        printEmployee(list);

        if(indice == -1)
        {
            printf("No existe una persona con esa ID : %d", id);
        }
        else
        {


            printf("Confirma la modificacion S/N");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma=='s')
            {

                list[indice].isEmpty=1;

            }
            else
            {

                printf("Baja cancelada");

            }


        }

    }
return todoOk;


}

