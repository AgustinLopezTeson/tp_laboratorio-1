#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "input.h"

int menu(){

    int opcionElegida;

    printf("\n                ****  Menu de Opciones  **** \n\n");
    printf("1.Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n\n");
    printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n\n");
    printf("3. Alta de pasajero\n\n");
    printf("4. Modificar datos de pasajero\n\n");
    printf("5. Baja de pasajero\n\n");
    printf("6. Listar pasajeros \n\n");
    printf("7. Ordenar pasajeros\n\n");
    printf("8.Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n\n");
    printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n\n");
    printf("10. Salir\n\n");
    printf( "\nIngrese la opcion correspondiente: \n");

    scanf("%d",&opcionElegida);

    return opcionElegida;
}

int menuDeModificaciones()
{
    int opcion;

    printf("\n\n        *** Modificar Pasajero ***          \n");
    printf("------------------------------------------------\n");
    printf("    1- Nombre\n\n");
    printf("    2- Precio\n\n");
    printf("    3- Salir\n\n");

    printf("Ingrese opcion: \n");
    scanf("%d", &opcion);

    return opcion;
}

int valCadena(char vect[])
{
    int todoOk = 0;
    for (int i = 0; i < miStrlen(vect); i++)
    {
    	if (!(isalpha(vect[i])))
        {
            todoOk = 1;
            break;
        }

    }
    return todoOk;
}

int validarFloat(float *pResultado, char *mensaje, char *mensajeError,
                 float minimo, float maximo, int reintentos)
{
    int todoOk = 0;
    float buffer;
    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
            && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);

            if (parseFloat(&buffer) == 0 && buffer >= minimo
                    && buffer <= maximo)
            {
                *pResultado = buffer;
                todoOk = 1;
                break;
            }
            reintentos--;
            printf("%s", mensajeError);
        }
        while (reintentos >= 0);
    }
    return todoOk;
}

int parseFloat(float *pResultado)
{
    int todoOk = -1;
    char buffer[4096];
    if ((gets(buffer)) && valFlotante(buffer))
    {
        todoOk = 0;
        *pResultado = atof(buffer);
    }
    return todoOk;
}

int miStrlen(char vect[])
{
    int cantidad = 0;
    int i = 0;
    if (vect != NULL)
    {
        while (vect[i] != '\0')
        {
            cantidad++;
            i++;
        }
    }
    return cantidad;
}

int valFlotante(char cadena[])
{
    int i = 0;
    int cantidadPuntos = 0;
    while (cadena[i] != '\0')
    {
        if (i == 0 && cadena[i] == '-')
        {
            i++;
            continue;
        }
        if (cadena[i] == '.' && cantidadPuntos == 0)
        {
            cantidadPuntos++;
            i++;
            continue;
        }
        if (cadena[i] < '0' || cadena[i] > '9')
            return 0;
        i++;
    }
    return 1;
}
