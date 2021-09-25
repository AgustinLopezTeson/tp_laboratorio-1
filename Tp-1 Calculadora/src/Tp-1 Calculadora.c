/*
 ============================================================================
 Name        : Tp-1.c
 Author      : Agustin Lopez Teson
 Version     :
 Copyright   : Your copyright notice
 Description : TP-1 Calculadora
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Funciones.h"

int main() {
	setbuf(stdout, NULL);

	int primerNumero = 0;
	int segundoNumero = 0;
	int opcionElegida;
	int respuesta = 1;
	int resta;
	int multiplicacion;
	int suma;
	int divCero;
	int flagPrNum = 0;
	int flagSegNum = 0;
	int flagCalc = 0;
	long int factorialA;
	long int factorialB;
	int factorialNegativo1;
	int factorialNegativo2;
	float division;

	do {


			opcionElegida = menu(&primerNumero, &segundoNumero, &flagPrNum,
			&flagSegNum, &flagCalc);

		switch (opcionElegida) {

		case 1:
			printf("\n1er Numero :  ");
			scanf("%d", &primerNumero);
			break;
		case 2:
			printf("\n2do Numero:  ");
			scanf("%d", &segundoNumero);
			break;
		case 3:

			fsuma(primerNumero, segundoNumero, &suma);
			fResta(primerNumero, segundoNumero, &resta);
			divCero = fDivision(primerNumero, segundoNumero, &division);
			fMultiplicacion(primerNumero, segundoNumero, &multiplicacion);
			factorialNegativo1=fFactorial(primerNumero, &factorialA);
			factorialNegativo2=fFactorial(segundoNumero,&factorialB);
			muestraOperaciones(primerNumero, segundoNumero);

			break;
		case 4:

			system("cls");
			printf("\n\nEl resultado de %d + %d es : %d\n\n", primerNumero,
					segundoNumero, suma);
			printf("El resultado de %d - %d es : %d \n\n", primerNumero,
					segundoNumero, resta);

			if (divCero == 1) {
				printf("El resultado de %d / %d es : %.2f \n\n", primerNumero,
						segundoNumero, division);
			} else {
				printf("No se puede dividir por cero\n\n");
			}


			printf("El resultado de %d * %d es : %d \n\n", primerNumero,
					segundoNumero, multiplicacion);

			if(factorialNegativo1==1){
			printf("El resultado del factorial de A:%d es %li\n\n",primerNumero,factorialA);
			}else{
			printf("No se puede calcular el factorial de A:%d, ya que es  negativo\n\n",primerNumero);
			}

			if(factorialNegativo2==1){
			printf("El resultado del factorial de B:%d es %li\n\n",segundoNumero,factorialB);
			}else{
				printf("No se puede calcular el factorial de B:%d, ya es que es negativo\n\n",segundoNumero);
			}
			system("pause");

			break;
		case 5:
			respuesta = 0;
			printf("Saliendo de la calculadora ...");
			break;
		default:

			printf("Ingrese una opcion valida (1-5)");
			break;
		}
		system("cls");

	} while (respuesta == 1);

	return 0;
}

