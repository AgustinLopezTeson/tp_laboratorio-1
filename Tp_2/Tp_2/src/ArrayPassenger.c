#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "input.h"
#include "myLibrary.h"


int buscarLibre(Passenger list[],int tam)
{


int indice=-1;
	if(list!=NULL)
	{

		for(int i=0;i<tam;i++)
	   {
		   if(list[i].isEmpty==1)
		   {
			   indice=i;
			   break;
		   }
	   }

	}
return indice;
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
		indice=buscarLibre(list,len);


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
			strcpy(newPassenger.flyCode,flycode);
			newPassenger.isEmpty=0;

			list[indice]=newPassenger;

		}

	}
	printf("fUNCO00\n");
	printf("%d",indice);
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
			printf("     *** Alta Pasajero ***\n\n");


				id=*pNextId;

				do{
				printf("Ingrese el nombre: \n\n");
				fflush(stdin);
				gets(name);

				}while((valCadena(name))==1 || name[0]=='\0');

				do{
				printf("Ingrese el apellido: \n\n");
				fflush(stdin);
				gets(lastName);
				}while((valCadena(lastName))==1 || name[0]=='\0');

	            if (!validarFloat(&price, "Ingrese el precio: ",
	                              "Error, un precio valido: ", 1, 1000000, 3))
	            {
	                printf("Error al ingresar el precio\n");
	            }

				do
				{
						printf("Ingrese el codigo del vuelo(4 caracteres): \n\n");
						fflush(stdin);
						gets(flycode);

				}while(name[0]=='\0');


				printf("Ingresar el tipo de pasajero(1 o 0): \n\n");
				scanf("%d",&typePassenger);


				addPassenger(list,tam,id,name,lastName,price,typePassenger,flycode);


				(*pNextId)++;
	}

	return todoOk;
}


int removePassenger(Passenger* list,int len)
{
	int todoOk = 0;
	int id;
	int indice;
	    char confirma;
	    if (list != NULL && len > 0)
	    {
	        system("cls");
	        printf("   *** Baja Empleado *** \n\n");
	        printPassengers(list,len);
	        printf("Ingrese id: ");
	        scanf("%d", &id);


	        indice = findPassengerById(list, len, id);
	        mostrarPasajero(list[indice]);

	        if (indice == -1)
	        {
	            printf("El id: %d no esta registrado en el sistema\n", id);
	        }
	        else
	        {
	            printf("Confirma baja?: S/N");
	            fflush(stdin);
	            scanf("%c", &confirma);
	            if (confirma == 's')
	            {
	                list[indice].isEmpty = 1;
	                todoOk = 1;
	            }
	            else
	            {
	                printf("Baja cancelada por el usuario.\n");
	            }
	        }
	    }
	    return todoOk;
	}


//int sortPassengers(Passenger* list, int len, int order)
//{return 0;}



int printPassengers(Passenger list[],int length)
{
	int todoOk = 0;
	int flag = 1;
	int order;

	    if( list!= NULL && length > 0)
	    {


	    	order=menuSort();
	    	sortPassengersByCode(list,length,order);

	    	system("cls");
	        printf("       *** Listado de Pasajeros ***\n");
	        printf("   Id           nombre         Apellido      precio      Tipo      Fly Code\n");
	        printf("------------------------------------------------------------------------------------\n");
	        for(int i=0; i < length; i++)
	        {
	            if(list[i].isEmpty==0)
	            {
	                mostrarPasajero(list[i]);
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

void mostrarPasajero(Passenger list)
{

    printf("    %4d    %10s      %10s    %.2f       %d   %10s\n",
           list.id,
		   list.name,
		   list.lastName,
		   list.price,
		   list.typePassenger,
		   list.flyCode
            );
}

int sortPassengersByCode(Passenger* list,int len,int order)
{
	int todoOk = -1;
	    Passenger auxEmployee;
	    if (list != NULL && len > 0 && order >= 0 && order <= 1)
	    {
	        todoOk = 0;
	        switch (order)
	        {
	        case 1:
	            for (int i = 0; i < len - 1; i++)
	            {
	                for (int j = i + 1; j < len; j++)
	                {
	                    if (strcmp(list[i].lastName, list[j].lastName) > 0
	                            || (strcmp(list[i].lastName, list[j].lastName) == 0
	                                && list[i].price > list[j].price))
	                    {
	                        auxEmployee = list[i];
	                        list[i] = list[j];
	                        list[j] = auxEmployee;
	                    }
	                }
	            }
	            break;
	        case 0:
	            for (int i = 0; i < len - 1; i++)
	            {
	                for (int j = i + 1; j < len; j++)
	                {
	                    if (strcmp(list[i].lastName, list[j].lastName) < 0
	                            || (strcmp(list[i].lastName, list[j].lastName) == 0
	                                && list[i].price< list[j].price))
	                    {
	                        auxEmployee = list[i];
	                        list[i] = list[j];
	                        list[j] = auxEmployee;
	                    }
	                }
	            }
	            break;
	        }
	    }
	   return todoOk;
}

int editEmployee(Passenger list[], int len)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    char salir;
    Passenger auxEmployee;
    if (list != NULL && len > 0)
    {
        system("cls");
        printf("   *** Modificar pasajero *** \n\n");
        printPassengers(list,len);
        printf("Ingrese id: ");
        scanf("%d", &id);

        indice = findPassengerById(list, len, id);

        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            do
            {
                switch(editMenu(list, len, indice))
                {
                case 1:
                    printf("Modificar nombre: ");
                    fflush(stdin);
                    gets(auxEmployee.name);
                    printf("Confirma cambio de nombre? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        strcpy(list[indice].name, auxEmployee.name);
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 2:
                    printf("Modificar apellido: ");
                    fflush(stdin);
                    gets(auxEmployee.lastName);
                    printf("Confirma cambio de apellido? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        strcpy(list[indice].lastName, auxEmployee.lastName);
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 3:
                    printf("Modificar precio: ");
                    scanf("%f", &auxEmployee.price);
                    printf("Confirma cambio de precio? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        list[indice].price = auxEmployee.price;
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 4:
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
                }
            }
            while (seguir == 's');

            todoOk = 1;
        }
    }
    return todoOk;
}

int findPassengerById(Passenger list[], int len, int id)
{
    int indice = -1;
    for (int i = 0; i < len; i++)
    {
        if (list[i].id == id && list[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int pricePromedio(Passenger list[], int len, float *pPrecio, float *sumaPrecio)
{
    int todoOk = -1;
    float auxSalario = 0;
    int contadorSalarios = 0;

    if (list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 0 )
            {
                auxSalario += list[i].price;
                contadorSalarios++;
            }
        }
        todoOk = 0;

        *pPrecio = (float)auxSalario /contadorSalarios;
        *sumaPrecio = auxSalario;
    }
    return todoOk;
}

int masPromedioPrecio(Passenger list[], int len, float precioPromedio, float totalPrecio)
{
    int todoOk = -1;
    int contador = 0;

    pricePromedio(list,len, &precioPromedio, &totalPrecio);

    if (list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 0 )
            {
                if(list[i].price > precioPromedio)
                {
					mostrarPasajero(list[i]);
					contador++;
                }
            }
        }
        todoOk = 0;
    }

    printf("Hay %d persona/s que pagan mas del promedio de precios en total\n", contador);

    return todoOk;
}
