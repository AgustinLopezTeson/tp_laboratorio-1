#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "input.h"

Passenger* Passenger_new()
{

    Passenger* new_Passenger;


    new_Passenger = (Passenger*) malloc ( sizeof(Passenger));

    if(new_Passenger!=NULL)
    {
        new_Passenger->id= 0;
        strcpy(new_Passenger->nombre," ");
        strcpy(new_Passenger->lastname," ");
        new_Passenger->precio= 0;
        strcpy(new_Passenger->codigoVuelo," ");
        strcpy(new_Passenger->typePassenger," ");
        strcpy(new_Passenger->statusFlight," ");
        new_Passenger->isEmpty=1;

    }else{

        printf("Hubo un problema");
     }

    return new_Passenger;
}

void Passenger_delete(Passenger* emp)
{

    free(emp);
}

int Passenger_setId(Passenger* this,int id)
{
    int todoOk=0;

    if(this !=NULL && id>=0 && id<= 50000)
    {
        this->id=id;
        todoOk =1;
    }
    else
    {
        printf("Problema con el Id");
    }


    return todoOk;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
    int todoOk=0;

    if(this != NULL && nombre!=NULL && strlen(nombre)<20)
    {
        strcpy(this->nombre,nombre);
        todoOk=1;
    }
    else
    {
        printf("Problema con el Nombre");
    }


    return todoOk;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOk=0;
    if(this != NULL && apellido!=NULL && strlen(apellido)<20)
    {
        strcpy(this->lastname,apellido);
        todoOk =1;
    }
    else
    {
        printf("Problema con el apellido");
    }


    return todoOk;

   }

int Passenger_setPrecio(Passenger* this,float precio)
{

    int todoOk=0;

    if(this !=NULL)
    {
        this->precio=precio;
        todoOk = 1;
    }
    else
    {
        printf("Problema con el precio");
    }


    return todoOk;


}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
    int todoOk=0;

    if(this !=NULL)
    {
    	strcpy(this->codigoVuelo,codigoVuelo);
        todoOk =1;
    }
    else
    {
        printf("Problema con el codigo de vuelo ");
    }


    return todoOk;


}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
    int todoOk=0;

    if(this !=NULL)
    {
    	strcpy(this->typePassenger,tipoPasajero);
        todoOk =1;
    }
    else
    {
        printf("Problema con el tipo de pasajero");
    }
    return todoOk;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
    int todoOk=0;

    if(this !=NULL)
    {
    	strcpy(this->statusFlight,estadoVuelo);
        todoOk =1;
    }
    else
    {
        printf("Problema con el estado del vuelo ");
    }


    return todoOk;
}


int Passenger_getId(Passenger* this,int* id)
{
    int todoOk = 0;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;

}

int Passenger_getNombre(Passenger* this,char* nombre)
{
    int todoOk = 0;
    if (this != NULL && nombre != NULL )
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{

    int todoOk = 0;
    if (this != NULL && apellido != NULL )
    {
        strcpy(apellido, this->lastname);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
    int todoOk = 0;
    if (this != NULL && precio > 0)
    {
        *precio = this->precio;
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
    int todoOk = 0;
    if (this != NULL && codigoVuelo!=NULL)
    {
    	strcpy(codigoVuelo, this->codigoVuelo);
        todoOk = 1;
    }
    return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
    int todoOk = 0;
    if (this != NULL && tipoPasajero != NULL)
    {
    	strcpy(tipoPasajero, this->typePassenger);
        todoOk = 1;
    }

    return todoOk;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
    int todoOk = 0;
    if (this != NULL && estadoVuelo != NULL)
    {
    	strcpy(estadoVuelo, this->statusFlight);
        todoOk = 1;
    }

    return todoOk;
}

void list_Passenger(Passenger* this)
{
    int id;
    char nombre[50];
    char apellido[50];
    float precio;
    char codigoVuelo[4];
    char typePassenger[21];
    char statusFlight[21];

    if (this != NULL)
    {

        if ( 	Passenger_getId(this,&id) &&
                Passenger_getNombre(this, nombre ) &&
				Passenger_getApellido(this,apellido)&&
                Passenger_getPrecio( this,&precio) &&
                Passenger_getCodigoVuelo(this,codigoVuelo)&&
				Passenger_getTipoPasajero(this,typePassenger)&&
				Passenger_getEstadoVuelo(this,statusFlight)
           )
        {
            printf ("%-4d %-10s %-10s     %-10.2f    %-10s   %-15s%-5s\n", id, nombre,apellido, precio, codigoVuelo,typePassenger,statusFlight);

        }
    }
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* typePassengerSTR,char* statusFlightStr)
{


    Passenger* new_Emp;


    new_Emp= Passenger_new();

    if(new_Emp!=NULL)
    {
        if(!(    Passenger_setId(new_Emp,atoi(idStr))&&
                 Passenger_setNombre(new_Emp,nombreStr)&&
				 Passenger_setApellido(new_Emp,apellidoStr)&&
                 Passenger_setPrecio(new_Emp,atof(precioStr))&&
				 Passenger_setCodigoVuelo(new_Emp,codigoVueloStr)&&
                 Passenger_setTipoPasajero(new_Emp,typePassengerSTR)&&
				 Passenger_setEstadoVuelo(new_Emp,statusFlightStr)))
        {
            printf("Hubo un problema");
            Passenger_delete(new_Emp);
            new_Emp=NULL;
        }

    }
    else
    {
        printf("No se pudo conseguir memoria");
    }

    return new_Emp;
}


int  new_PassengerManual(LinkedList* pArrayListPassenger)
{

    int todoOk= 0;
    char nombre [50];
    char apellido[50];
    float precio;
    char codigoVuelo[8];
    char typePassenger[21];
    char statusFlight[21];
    int id;

    Passenger* aux=NULL;
    printf("*** Alta de Pasajero***\n\n");
    controller_ListPassenger(pArrayListPassenger);
    printf("\n\nIngrese la id: ");
    scanf("%d", &id);
printf("%d",id);
    printf("\n\nIngrese el nombre: ");
    fflush(stdin);
    gets(nombre);
printf("%s",nombre);
    printf("\n\nIngrese el Apellido: ");
    fflush(stdin);
    gets(apellido);
printf("%s",apellido);
    printf("\n\nIngrese precio:");
    scanf("%f",&precio);
printf("%.2f",precio);
    printf("\n\nIngrese el codigo de Vuelo(4 Caracteres): ");
    fflush(stdin);
    gets(codigoVuelo);
printf("%s",codigoVuelo);
    printf("\n\n Ingrese el tipo de pasajero(First Class/Executive Class/Economy Class): ");
    fflush(stdin);
    gets(typePassenger);
printf("%s",typePassenger);
    printf("\n\n Ingrese el estado del vuelo(Aterrizado/En horario): ");
    fflush(stdin);
    gets(statusFlight);
printf("%s",statusFlight);


    aux=Passenger_newParametrosN(id,nombre,apellido,precio,codigoVuelo,typePassenger,statusFlight);

    if(aux!=NULL)
    {
        ll_add(pArrayListPassenger,aux);
        todoOk=1;
    }

    return todoOk;
}


Passenger* Passenger_newParametrosN(int id,char* nombre,char* apellido,float precio,char* codigoVuelo,char* typePassenger,char* statusFlight)
{

    Passenger* new_Emp;

    new_Emp= Passenger_new();

    if(new_Emp!=NULL)
    {
        if(!(    Passenger_setId(new_Emp,id)&&
                 Passenger_setNombre(new_Emp,nombre)&&
				 Passenger_setApellido(new_Emp,apellido)&&
                 Passenger_setPrecio(new_Emp,precio)&&
                 Passenger_setCodigoVuelo(new_Emp,codigoVuelo)&&
				 Passenger_setTipoPasajero(new_Emp,typePassenger)&&
				 Passenger_setEstadoVuelo(new_Emp,statusFlight)))
        {
            printf("Hubo un problema");
            Passenger_delete(new_Emp);
            new_Emp=NULL;
        }

    }
    else
    {
        printf("No se pudo conseguir memoria");
    }

    printf("%d\n",new_Emp->id);
    printf("%s\n",new_Emp->nombre);
    printf("%s\n",new_Emp->lastname);
    printf("%.2f\n",new_Emp->precio);
    printf("%s\n",new_Emp->codigoVuelo);
    printf("%s\n",new_Emp->typePassenger);
    printf("%s\n",new_Emp->statusFlight);
    system("pause");
    return new_Emp;
}



int searchPassengerId(LinkedList* pArrayListPassenger, int id)
{
    int indice = -1;
    int idAux;
    Passenger* auxEmp;

    for (int i = 0; i < ll_len(pArrayListPassenger); i++)
    {
        auxEmp = ll_get(pArrayListPassenger, i);
        if( Passenger_getId(auxEmp, &idAux) && idAux == id)
        {
            indice = i;
        }
    }
    return indice;
}
/*
int compPassengerprecio(void* pPassenger, void* sPassenger)
{
    int todoOk= 0;

    if( ((Passenger*)pPassenger)->precio > ((Passenger*)sPassenger)->precio )
    {
        todoOk++;
    }
    if( ((Passenger*)pPassenger)->precio < ((Passenger*)sPassenger)->precio )
    {
        todoOk--;
    }
    return todoOk;
}

int compPassengerEstadoVuelo(void* pPassenger, void* sPassenger)
{
    int todoOk= 0;

    if(((Passenger*)pPassenger)->statusFlight > ((Passenger*)sPassenger)->statusFlight)
    {
        todoOk++;
    }
    if(((Passenger*)pPassenger)->statusFlight < ((Passenger*)sPassenger)->statusFlight)
    {
        todoOk --;
    }
    return todoOk;

}


int buscarMayorId(LinkedList* pArrayListPassenger)
{
    Passenger* auxEmpleado = NULL;
    int mayor = 0;
    int id;
    if(pArrayListPassenger != NULL)
    {
        for( int i = 0; i < ll_len(pArrayListPassenger); i++)
        {
            auxEmpleado = (Passenger*) ll_get(pArrayListPassenger, i);
            Passenger_getId(auxEmpleado, &id);
            if( i==0 || id > mayor)
            {
                mayor = id;
            }
        }
    }
    return mayor;
}
}
*/