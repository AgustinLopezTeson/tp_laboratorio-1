#include <stdio.h>
#include <ctype.h>
#include "Funciones.h"

int fsuma(int a, int b, int* suma)
{
    int todoOk=0;
    if ( suma != NULL)
    {
        *suma = a + b;
        todoOk=1;
    }

    return todoOk;
}

 int fDivision(int a, int b, float* division)
{
    int todoOk =0;
    if(division!=NULL && b !=0)
    {
        *division = a / b;
        todoOk=1;
    }

    return todoOk;
}

 int fMultiplicacion(int a, int b, int* multiplicacion)
{
    int todoOk=0;
    if(multiplicacion!=NULL)
    {
        *multiplicacion = a * b;
        todoOk=1;
    }

    return todoOk;

}

 int fResta(int a, int b,int* resta)
{
    int todoOk= 0;
    if(resta!=NULL)
    {
        *resta = a - b;
        todoOk=1;
    }
    return todoOk;


}

int menu(int* a, int* b)
{

    int opcionElegida;
    int primerNumero;
    int segundoNumero;
    int flagPriNumero=0;
    int flagSegunNumero=0;
    int flagCalcular=0;

    primerNumero= *a;
    segundoNumero= *b;

    printf("\n Menu de Opciones : \n\n");
    printf("1. Ingresar el primer Numero (A=%d)\n\n",primerNumero);
    printf("2. Ingresar el segundo Numero (B=%d)\n\n",segundoNumero);
    printf("3. Calcular Operaciones\n\n");
    printf("4. Informar resultados\n\n");
    printf("5. Salir de la Calculadora\n");
    printf( "\nIngrese la opcion correspondiente: \n");


  /*  switch (opcionElegida)
    {

    case 1 :
        flagPriNumero=1;
        break;
    case 2:
        if(flagPriNumero==1)
        {
            opcionElegida=2;

        }
        else
        {
            printf("Necesita ingresar el primer numero primero\n");
            opcionElegida=1;

        }
        break;
    case 3:
        if(flagSegunNumero==1 && flagPriNumero==1)
        {
            opcionElegida=3;
            flagCalcular=1;

        }
        else
        {
            printf("Tiene que ingresar los dos numeros primero\n");
        }
        break;
    case 4:
        if(flagCalcular==1)
        {
            opcionElegida=4;
        }
        else
        {
            printf("Tiene que pedir calcular antes de mostrar resultados\n");
        }
        break;
    }*/

    scanf("%d", &opcionElegida);


    return opcionElegida;
}

