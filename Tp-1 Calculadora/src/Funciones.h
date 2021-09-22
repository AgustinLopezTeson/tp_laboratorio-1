#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED





int fFactorial(int primerNumero, int segundoNumero,unsigned long  int* a , unsigned long  int* b);

void muestraOperaciones(int primerNumero, int segundoNumero);

/** \brief Despliega un menu y escribe los numeros en las variables
 *
 * \param a int* Se pide el puntero para escribirle un valor que se ingresa
 * \param b int* Se pide otro puntero para tambien escribirle el valor que se ingresa
 * \return int  Retorna la opcion elegida
 *
 */
int menu(int* a, int* b,int* flag1,int* flag2, int* flagCal );

/** \brief  Suma dos numeros que se recibe
 *
 * \param a int Primer Numero que recibe
 * \param b int Segundo numero que recibe
 * \param suma int* Puntero que escribe la suma de los dos numeros
 * \return int Retorna 1 o 0 para corroborar que todo salio bien
 *
 */
int fsuma(int a , int b, int* suma);


/** \brief Divide dos numeros que recibe
 *
 * \param a int Primer numero que recibe
 * \param b int Segundo numero que recibe
 * \param division float* Puntero que escribe la division de los dos numeros
 * \return int  Retorna 1 o 0 para corroborar que todo salio bien
 *
 */
int fDivision(int a, int b,float* division);


/** \brief Multiplica dos numeros que recibe
 *
 * \param a int Primer numero que recibe
 * \param b int Segundo numero que recibe
 * \param multiplicacion int* Puntero que escribe la multiplicacion de los numeros
 * \return int  Retorna 1 o 0 para corroborar que todo salio bien
 *
 */
int fMultiplicacion(int a, int b, int* multiplicacion);


/** \brief Resta dos numeros que recibe
 *
 * \param a int Primer numero que recibe
 * \param b int Segundo numero que recibe
 * \param resta int* Puntero que escribe la resta de los numeros
 * \return int Retorna 1 o 0 para corroborar que todo salio bien
 *
 */
int fResta(int a, int b, int* resta );
