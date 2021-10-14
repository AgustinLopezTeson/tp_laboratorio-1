#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED



/** \brief Calcula el Factorial del numero pasado y escribe el resultado
 *
 * \param Numero int Numero que se pasa
 * \param a long int* Se le pasa un puntero a int donde escribe el resultado
 * \return int Retorna si se pudo hacer la operacion
 *
 */
int fFactorial(int Numero,long int* a);

/** \brief Muestra las operaciones a realizar
 *
 * \param primerNumero int Se le pasa el valor del primer numero
 * \param segundoNumero int Se le pasa el valor del segundo numero
 * \return void
 *
 */
void muestraOperaciones(int primerNumero, int segundoNumero);


/** \brief Muestra el menu , verifica la opcion ingresada y retorna la opcion
 *
 * \param a int* Se le pasa el puntero a int del primer numero
 * \param b int* Se le pasa el puntero a int del segundo numero
 * \param flag1 int* Puntero de flag para verificaciones (Primer numero)
 * \param flag2 int* Puntero de flag para verificaciones (Segundo numero)
 * \param flagCal int* Puntero de flag para verificaciones (calcular)
 * \return int Retorna la opcion verificada
 *
 */
int menu(int* a, int* b,int* flag1,int* flag2, int* flagCal );


/** \brief Suma dos numeros y escribe el resultado
 *
 * \param a int Valor del primer numero
 * \param b int Valor del segundo numero
 * \param suma int* Puntero Int del resultado parara escribir resultado
 * \return int Retorna si se pudo hacer la operacion
 *
 */
int fsuma(int a , int b, int* suma);



/** \brief Divide dos numeros y escribe el resultado (Verifica la division por 0)
 *
 * \param a int Valor del primer numero
 * \param b int Valor del segundo numero
 * \param division float* Puntero Float del resultado parara escribir resultado
 * \return int Retorna si se pudo hacer la operacion
 *
 */
int fDivision(int a, int b,float* division);



/** \brief Multiplica dos numeros y escribe el resultado
 *
 * \param a int Valor del primer numero
 * \param b int Valor del segundo numero
 * \param multiplicacion int* Puntero Int del resultado parara escribir resultado
 * \return int Retorna si se pudo hacer la operacion
 *
 */
int fMultiplicacion(int a, int b, int* multiplicacion);



/** \brief Resta dos numeros y escribe el resultado
 *
 * \param a int Valor del primer numero
 * \param b int Valor del segundo numero
 * \param resta int* Puntero Int del resultado parara escribir resultado
 * \return int Retorna si se pudo hacer la operacion
 *
 */
int fResta(int a, int b, int* resta );
