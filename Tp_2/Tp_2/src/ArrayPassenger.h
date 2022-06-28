
#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_


typedef struct
{
int id;
char name[51];
char lastName[51];
float price;
char flyCode[10];
int typePassenger;
int statusFlight;
int isEmpty;
}Passenger;


int initPassengers(Passenger* list,int len);
int addPassenger(Passenger* list,int len, int id, char name[],char lastName[],float price,int typePassenger,char flycode[]);
int findPassengerById(Passenger* list, int len, int id);
int removePassenger(Passenger* list,int len);
int sortPassengers(Passenger* list, int len, int order);
int printPassengers(Passenger* list,int length);
int sortPassengers(Passenger* list,int len,int order);
void mostrarPasajero(Passenger list);

int buscarLibre(Passenger list[] ,int tam);
int menu();
int cargarPasajeros(Passenger list[],int tam,int*pNextId);

#endif /* ARRAYPASSENGER_H_ */
