#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define TAM 5

int main()
{
    char seguir= 's';
    Employee list [TAM];
    int nextId = 20000;
    int id;

    initEmployees(list,TAM);

    do
    {
        switch (menu())
        {
        case 1:
            if(!addEmployee(list,TAM,&nextId,name,lastName,salary,sector))
            {
                printf("No se pudo hacer el alta ");
            }
            else
            {
                printf("Alta Exitosa");
            }
            break;
        case 2:
            if(!modificarNotebook(lista,TAM,  tipoNote, TAM_TIPO, marcas,TAM_MAR,clientes, TAM_CLI))
            {
                printf("No se pudo realizar la modificacion");
            }
            else
            {
                printf("Modificacion exitosa");
            }
            break;
        case 3:
            if( bajaNotebook(lista,TAM,tipoNote,TAM_TIPO,marcas,TAM_MAR,clientes,TAM_CLI))
            {
                printf("No se pudo realizar la baja");
            }
            else
            {
                printf("Baja exitosa");
            }
            break;
        case 4:
            mostrarNotebooks(lista,TAM,marcas,tipoNote,TAM_TIPO,TAM_MAR,clientes,TAM_CLI);
            system("pause");
            break;
    }
    while(seguir == 's');*/

    return 0;
}
