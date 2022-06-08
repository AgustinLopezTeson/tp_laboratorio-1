#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"


int menu()
{
	int opcion;
	printf("*** MENU PASAJEROS *** \n\n");
	printf("1-ALTAS\n");
	printf("2-MODIFICAR\n");
	printf("3-BAJA\n");
	printf("4-INFORMAR\n");
	printf("5-SALIR\n");
	fflush(stdin);
	printf("Ingrese su opcion : ");
	scanf("%d",&opcion);
return opcion;
}

int buscarLibre(Passenger list[],int tam,int* id)
{

int todoOk=0;

	if(list!=NULL)
	{
		*id=-1;
		for(int i=0;i<tam;i++)
	   {
		   if(list[i].isEmpty)
		   {
			   *id=list[i].id;
			   break;
		   }
	   }
		todoOk=1;
	}
return todoOk;
}


int initPassengers(Passenger list[],int len)
{
	int todoOk=0;

		if(list!=NULL && len > 0)
		{
			for(int i=0;i<len;i++)
		   {
			   list[i].isEmpty=1;
		   }
			todoOk=1;
		}
	return todoOk;
}

int addPassenger(Passenger* list,int len, int id, char name[],char lastName[],float price,int typePassenger,char flycode[])
{
	int todoOk=0;
	int indice;
	Passenger newPassenger;

	if (list!= NULL && len > 0)
	{
		buscarLibre(list,len,&indice);

		if(indice==-1)
		{
		printf("No hay lugar en el sistema");
		}
		else
		{
			newPassenger.id=id;
			strcpy(newPassenger.name,name);
			strcpy(newPassenger.lastName,lastName);
			newPassenger.price=price;
			newPassenger.typePassenger=typePassenger;
			strcpy(newPassenger.flyCode,name);
			newPassenger.isEmpty=0;

			list[indice]=newPassenger;

		}

	}

	return todoOk;
}

int cargarPasajeros(Passenger list[],int tam,int*pNextId)
{
int todoOk=0;
int id;
char name[51];
char lastName[51];
float price;
int typePassenger;
char flycode[10];

	if(list!=NULL && tam > 0 && pNextId != NULL)
	{
			printf("     *** Alta Empleado ***\n\n");


				id=*pNextId;
				printf("Ingrese el nombre: \n\n");
				fflush(stdin);
				gets(name);

				printf("Ingrese el apellido: \n\n");
				fflush(stdin);
				gets(lastName);

				printf("Ingrese el precio: \n\n");
				scanf("%f",&price);

				printf("Ingrese el codigo del vuelo: \n\n");
				fflush(stdin);
				gets(flycode);

				printf("Ingresar el tipo de pasajero: \n\n");
				scanf("%d",&typePassenger);


				addPassenger(list,tam,id,name,lastName,price,typePassenger,flycode);


				(*pNextId)++;
	}

	return todoOk;
}


int findPassengerById(Passenger* list, int len, int id)
{
int index;
	if(list != NULL && len > 0)
	{
		        for(int i=0; i < len; i++)
		        {
		            if( !list[i].isEmpty  && list[i].id == id)
		            {
		                index = i;
		                break;
		            }
		        }
	}
return index;
}

int removePassenger(Passenger* list,int len, int id)
{





return 0;
}


int sortPassengers(Passenger* list, int len, int order)
{return 0;}



int printPassengers(Passenger list[],int length)
{
	int todoOk = 0;
	    int flag = 1;
	    if( list!= NULL && length > 0)
	    {
	        system("cls");
	        printf("       *** Listado de Pasajeros ***\n");
	        printf("   Id       nombre  Apellido   precio    Tipo   Fly Code\n");
	        printf("-----------------------------------------------------------------------\n");
	        for(int i=0; i < length; i++)
	        {
	            if( !list[i].isEmpty)
	            {
	                mostrarPasajero(list[i],length);
	                flag = 0;
	            }
	        }
	        if(flag)
	        {
	            printf("     No hay pasajeros en el sistema\n");
	        }

	        todoOk = 1;
	    }
	    return todoOk;
 }

void mostrarPasajero(Passenger list[],int tam)
{

    printf("    %4d    %10s      %10s    %2f    %d   %10s\n",
           list->id,
		   list->name,
		   list->lastName,
		   list->price,
		   list->typePassenger,
		   list->flyCode
            );
}

int sortPassengersByCode(Passenger* list,int len,int order)
{return 0;}
