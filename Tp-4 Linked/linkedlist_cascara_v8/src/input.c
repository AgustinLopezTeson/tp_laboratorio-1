#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Employee.h"
#include "../inc/input.h"
#include "../inc/parser.h"


int menu(){

    int opcionElegida;

    printf("\n                ****  Menu de Opciones  **** \n\n");
    printf("1.Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n\n");
    printf("3. Alta de empleado\n\n");
    printf("4. Modificar datos de empleado\n\n");
    printf("5. Baja de empleado\n\n");
    printf("6. Listar empleados \n\n");
    printf("7. Ordenar empleados\n\n");
    printf("8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n\n");
    printf("10. Salir\n\n");
    printf( "\nIngrese la opcion correspondiente: \n");

    scanf("%d",&opcionElegida);

    return opcionElegida;
}

int menuDeModificaciones()
{
    int opcion;

    printf("\n\n        *** Modificar Empleado ***          \n");
    printf("------------------------------------------------\n");
    printf("    1- Horas Trabajadas\n\n");
    printf("    2- Sueldo\n\n");
    printf("    3- Salir\n\n");

    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}


int subMenuComp()
{
    int opcion = 0;
    system("cls");
    printf("     *** Menu de ordenamiento ***\n");
    printf("  1- Ordenar por Horas trabajadas de menor a mayor\n");
    printf("  2- Ordenar por Horas trabajadas de mayor a menor\n");
    printf("  3- Ordenar por Sueldo de menor a mayor\n");
    printf("  4- Ordenar por Sueldo de mayor a menor\n");
    printf("  5- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}
