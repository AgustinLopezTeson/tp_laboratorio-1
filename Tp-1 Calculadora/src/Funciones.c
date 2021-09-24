#include <stdio.h>
#include <stdlib.h>
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
        *division = (float)a / b;
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

int menu(int* a, int* b,int* flag1,int* flag2, int* flagCal)
{

    int opcionElegida;
    int primerNumero;
    int segundoNumero;
    int correcto=0;

    primerNumero= *a;
    segundoNumero= *b;


    do
    {

    	printf("\n Menu de Opciones : \n\n");
        printf("1. Ingresar el primer Numero (A=%d)\n\n",primerNumero);
        printf("2. Ingresar el segundo Numero (B=%d)\n\n",segundoNumero);
        printf("3. Calcular Operaciones\n\n");
        printf("4. Informar resultados\n\n");
        printf("5. Salir de la Calculadora\n");
        printf( "\nIngrese la opcion correspondiente: \n");

        	scanf("%d", &opcionElegida);


    switch (opcionElegida)
        {

        case 1 :
            *flag1=1;
            correcto=1;
            break;
        case 2:
            *flag2=1;
            correcto=1;
            break;
        case 3:
            if(*flag1!=1 && *flag2!=1)
            {

                printf("\nTiene que ingresar los dos numeros primero\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                *flagCal=1;
                correcto=1;
            }
            break;
        case 4:

            if(*flagCal!=1)
            {
                printf("\nTiene que calcular antes de mostrar resultados\n\n");
                system("pause");

            }
            else
            {
                correcto=1;
            }

            break;

        case 5:
        {

            correcto=1;
        }
        break;
        }
    }
    while(correcto==0);

    return opcionElegida;
}

void muestraOperaciones(int primerNumero,int segundoNumero)
{

    system("cls");
    printf("\na) Calcular la Suma (%d + %d)\n\n",primerNumero,segundoNumero);
    printf("b) Calcular la Resta (%d - %d)\n\n",primerNumero,segundoNumero);
    printf("c) Calcular la Division (%d / %d)\n\n",primerNumero,segundoNumero);
    printf("d) Calcular la multiplicacion (%d * %d)\n\n",primerNumero,segundoNumero);
    printf("e) Calcular el factorial (!%d) y (!%d)\n\n",primerNumero,segundoNumero);
    printf("SE CALCULARON TODAS LAS OPERACIONES\n\n");
    system("pause");

}


void fFactorial(int primerNumero, int segundoNumero,long int* a,long int* b)
{
    long int resultadoFactorialA=1;
    long int resultadoFactorialB=1;



    for(int i=1 ; i<primerNumero; i++)
    {
            resultadoFactorialA=resultadoFactorialA*i;

    }

    for(int i=1 ; i<=segundoNumero; i++)
    {
            resultadoFactorialB=resultadoFactorialB*i;

    }

    *a = resultadoFactorialA;
    *b = resultadoFactorialB;
}

