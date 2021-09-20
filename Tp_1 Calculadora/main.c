#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones.h"

int main()
{

    int primerNumero=0;
    int segundoNumero=0;
    int opcionElegida;
    int respuesta = 1 ;
    int resta;
    int multiplicacion;
    int suma;
    int divCero;
    int flagPrNum=0;
    int flagSegNum=0;
    int flagCalc=0;
    unsigned long  int factorialA;
    unsigned long  int factorialB;
    float division;


    do
    {
        opcionElegida  = menu(&primerNumero, &segundoNumero, &flagPrNum, &flagSegNum, &flagCalc);

        switch(opcionElegida)
        {

        case 1 :
            printf("\n1er Numero :  ");
            scanf("%d", &primerNumero);
            break;
        case 2 :
            printf("\n2do Numero:  ");
            scanf("%d", &segundoNumero);
            break;
        case 3 :

            fsuma(primerNumero,segundoNumero,&suma);
            fResta(primerNumero,segundoNumero,&resta);
            divCero=fDivision(primerNumero,segundoNumero,&division);
            fMultiplicacion(primerNumero,segundoNumero,&multiplicacion);
            fFactorial(primerNumero,segundoNumero,&factorialA,&factorialB);
            muestraOperaciones(primerNumero,segundoNumero);

            break;
        case 4 :

           system("cls");
            printf("\n\nEl resultado de %d + %d es : %d\n\n", primerNumero,segundoNumero,suma);
            printf("El resultado de %d - %d es : %d \n\n", primerNumero,segundoNumero,resta);

            if(divCero==1)
            {
                printf("El resultado de %d / %d es : %.2f \n\n",primerNumero,segundoNumero,division);
            }
            else
            {
                printf("No se puede dividir por cero\n\n");
            }

            printf("El resultado de %d * %d es : %d \n\n",primerNumero,segundoNumero,multiplicacion);
            printf("El resultado del factorial de A:%d es %d y de B:%d es %d\n\n",primerNumero,segundoNumero,factorialA,factorialB);
            system("pause");
            break;
        case 5 :
            respuesta=0;
            break;
        }
        system("cls");
    }
    while(respuesta==1);

    return 0;
}

