#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones.h"


int main()
{

    int primerNumero;
    int segundoNumero;
    int opcionElegida;
    char opcionOperacion;
    int respuesta = 1 ;
    int resta;
    int multiplicacion;
    unsigned long long int factorialA;
    unsigned long long int factorialB;
    int suma;
    float division;
    int divCero;

    do
    {
        opcionElegida= menu(&primerNumero, &segundoNumero);

        switch(opcionElegida)
        {

        case 1 :
            printf("1er Numero : \n");
            scanf("%d", &primerNumero);
            break;
        case 2 :
            printf("2do Numero: \n");
            scanf("%d", &segundoNumero);
            break;
        case 3 :
            system("cls");
            printf("\na) Calcular la Suma (%d + %d)\n\n",primerNumero,segundoNumero);
            printf("b) Calcular la Resta (%d - %d)\n\n",primerNumero,segundoNumero);
            printf("c) Calcular la Division (%d / %d)\n\n",primerNumero,segundoNumero);
            printf("d) Calcular la multiplicacion (%d * %d)\n\n",primerNumero,segundoNumero);
            printf("e) Calcular el factorial (!%d)\n\n",primerNumero);
            fsuma(primerNumero,segundoNumero,&suma);
            fResta(primerNumero,segundoNumero,&resta);
            divCero=fDivision(primerNumero,segundoNumero,&division);
            fMultiplicacion(primerNumero,segundoNumero,&multiplicacion);

            printf("SE CALCULARON TODAS LAS OPERACIONES\n\n");
            system("pause");
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

