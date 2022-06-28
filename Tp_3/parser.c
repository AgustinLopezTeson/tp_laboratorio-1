#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "input.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int todoOk=1;
	    int cant;
	    char buffer[4][40];
	    Passenger * aux=NULL;

	            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]%[^,],%s\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
	            while(!feof(pFile)){
	                    aux=Passenger_new();

	                    if(aux!=NULL)
	                    {
	                        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]%[^,],%s\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5]);
	                        Passenger_setId(aux,atoi(buffer[0]));
	                        Passenger_setNombre(aux,buffer[1]);
	                        Passenger_setApellido(aux,buffer[2]);
	                        Passenger_setPrecio(aux,atof(buffer[3]));
	                        Passenger_setCodigoVuelo(aux,buffer[4]);
	                        Passenger_setTipoPasajero(aux,atoi(buffer[5]));

	                        ll_add(pArrayListPassenger,aux);

	                        todoOk=0;
	                    }
	                        if(cant<3){
	                            break;
	                        }
	                }

	    return todoOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

	int todoOk=1;
	    int cant;
	   Passenger* aux;
	            while(!feof(pFile)){

	                    aux=Passenger_new();
	                   if(aux!=NULL)
	                   {
	                        cant=fread(aux,sizeof(Passenger),1,pFile);

	                        if(cant!=1)
	                        {
	                            ll_add(pArrayListPassenger,aux);
	                            todoOk = 0;
	                            aux=NULL;
	                        }

	                   }
	                }
	    return todoOk;
}
