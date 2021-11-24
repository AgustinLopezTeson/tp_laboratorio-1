#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int id=1001;
    char seguir='s';
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            if ( !controller_loadFromText("data.csv", listaEmpleados) )
            {
                printf("Error al cargar desde texto\n");
            }
            break;
        case 2:
            if ( !controller_loadFromBinary("data.bin", listaEmpleados) )
            {
                printf("Error al cargar desde binario\n");
            }
            break;
        case 3:
            if ( !controller_addEmployee(listaEmpleados,&id) )
            {
                printf("Error en el alta de empleado\n");
            }
            break;
        case 4:
            if ( !controller_editEmployee(listaEmpleados) )
            {
                printf("Error al editar al empleado\n");
            }
            break;
        case 5:
            if ( !controller_removeEmployee(listaEmpleados) )
            {
                printf("Error en la baja de empleado\n");
            }
            break;
        case 6:
            if ( !controller_ListEmployee(listaEmpleados) )
            {
                printf("Error en listar los empleados\n");
            }
            system("pause");
            break;
        case 7:
            if ( !controller_sortEmployee(listaEmpleados) )
            {
                printf("Error al  ordenar los empleados\n");
            }
            break;
        case 8:
            if ( !controller_saveAsText("data1.csv", listaEmpleados) )
            {
                printf("Error al guardar en texto\n");
            }
            break;
        case 9:
            if ( !controller_saveAsBinary("data.bin", listaEmpleados) )
            {
                printf("Error al guardar en binario\n");
            }
            break;
        case 10:
            seguir='n';
            break;
        default:
            printf("\nOpcion Incorrecta \n\n");
            break;
        }
    }
    while(seguir=='s');
    return 0;
}
