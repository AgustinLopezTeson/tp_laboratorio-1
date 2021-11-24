#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "myLibrary.h"

int pedirCadena(char cadena[], char mensaje[], int limite)
{
    int todoOk = 0;
    char cadenaAuxiliar[50];
    if (cadena != NULL && mensaje != NULL)
    {
        todoOk = 1;
        printf("%s", mensaje);
        fflush(stdin);
        gets(cadenaAuxiliar);

        while (miStrlen(cadenaAuxiliar)>limite|| valCadena(cadenaAuxiliar) == 1 )
        {
            printf("Solo se aceptan letras Reingrese (maximo %d): ", limite);
            fflush(stdin);
            gets(cadenaAuxiliar);
        }

        UpperPrimerCaracter(cadenaAuxiliar);

        strcpy(cadena, cadenaAuxiliar);
    }
    return todoOk;
}

int EnteroLimitado(int min, int max)
{
    int entero;
    printf("Ingrese un numero entero: ");
    scanf("%d", &entero);
    while (entero < min || entero > max)
    {
        printf("Numero Fuera de maximos y minimos Reingrese: ");
        scanf("%d", &entero);
    }
    return entero;
}

int numeroPar(int numero)
{
    int todoOk = 0;
    if (numero % 2 == 0)
    {
        todoOk = 1;
    }
    return todoOk;
}

int getEntero()
{
    int entero;
    printf("Ingrese un numero entero: ");
    scanf("%d", &entero);
    return entero;
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


int difCero(int numero)
{
    int todoOk = 0;
    if (numero != 0)
    {
        todoOk = 1;
    }
    return todoOk;
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

int parserInt(int *pResultado)
{
    int retorno = -1;
    char buffer[4096];
    if (((gets(buffer)) && valCadenaNumerica(buffer)))
    {
        retorno = 0;
        *pResultado = atoi(buffer);
    }
    return retorno;
}


int validarEntero(int *pResultado, char *mensaje, char *mensajeError,
                  int minimo, int maximo, int reintentos)
{
    int todoOk = 0;
    int buffer;
    if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
            && minimo <= maximo && reintentos>0)
    {
        do
        {
            printf("%s", mensaje);

            if (parserInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo)
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

int valCadenaNumerica(char *cadena)
{
    int todoOk = 1;
    for (int i = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[0] == '-')
        {
            i = 1;
        }
        if (cadena[i] > '9' || cadena[i] < '0')
        {
            todoOk = 0;
            break;
        }
    }
    return todoOk;
}

int UpperPrimerCaracter(char cadena[])
{
    int todoOk = 0;
    if (cadena != NULL)
    {
        todoOk = 1;
        strlwr(cadena);
        cadena[0] = toupper(cadena[0]);
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
