
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}typedef Employee;

int menu();
int inicializarPersonas(Employee lista [], int tam);
int buscarLibre(Employee lista[],int tam);
int altaPersona(Employee lista [], int tam, int* pId);
int bajaPersona(Employee lista [],int tam);

void mostrarPersona(Employee p);
int mostrarPersonas(Employee lista[], int tam);

#endif // FUNCIONES_H_INCLUDED
