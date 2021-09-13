#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones.h"
#include <stdlib.h>


int main()
{

    int primerNumero;
    int segundoNumero;
    int opcionElegida;
    char opcionOperacion;
    char respuesta;
    int resta;
    int multiplicacion;
    int factorial;
    int suma;
    int division;

    do
    {
        printf("Menu de Operaracion : \n");

        printf("1. Ingresar el primer Numero (A=%d)\n\n",primerNumero);

        printf("2. Ingresar el segundo Numero (B=%d)\n\n",segundoNumero);

        printf("3. Calcular Operaciones\n\n");
        printf("4. Informar resultados\n\n");


        printf( "\nIngrese la opcion correspondiente: \n");
        scanf("%d", &opcionElegida);



        switch(opcionElegida)
        {

        case 1 :
        case 2 :
            printf("1er Numero : \n");
            scanf("%d", &primerNumero);
            printf("2do Numero: \n");
            scanf("%d", &segundoNumero);


            break;
        case 3 :
            printf("\na) Calcular la Suma (%d + %d)\n\n",primerNumero,segundoNumero);
            printf("b) Calcular la Resta (%d - %d)\n\n",primerNumero,segundoNumero);
            printf("c) Calcular la Division (%d / %d)\n\n",primerNumero,segundoNumero);
            printf("d) Calcular la multiplicacion (%d * %d)\n\n",primerNumero,segundoNumero);
            printf("e) Calcular el factorial (!%d)\n\n",primerNumero);

            printf("Ingrese la operacion que necesita \n");
            scanf("%c", &opcionOperacion);

            switch(opcionOperacion)
            {

            case 'a':
                suma = fsuma(primerNumero,segundoNumero);
                break;
            case 'b':

                resta=fResta(primerNumero,segundoNumero);
                break;
            case 'c':
                if(segundoNumero=!0)
                {
                    division=fDivision(primerNumero,segundoNumero);
                }
                else
                {
                    printf("No se puede dividir \n");
                }

                break;
            case 'd':
                multiplicacion = fMultiplicacion(primerNumero,segundoNumero);
                break;
            case 'e':
                break;
            }
            break;
        case 4 :
            printf("El resultado de %d + %d es : %d\n", primerNumero,segundoNumero,suma);
            break;
        }

        printf("Quiere continuar Y/N\n");
        scanf("%c", &respuesta);
    }
    while(tolower(respuesta)=='');



    return 0;
}

