#ifndef MYLIBRARY_H_INCLUDED
#define MYLIBRARY_H_INCLUDED


/** \brief determina si un numero es par / devuelve 1 si lo es / 0 en caso que no lo sea
 *
 * \param numero int
 * \return int
 *
 */
int numeroPar(int numero);

/** \brief  ingreso de un numero entero y lo retorna validado
 *
 * \return int
 *
 */
int pedirEntero();

/** \brief ingreso de un numero entero dentro de un rango determinado  min y max
 *
 * \param min int
 * \param max int
 * \return int
 *
 */
int EnteroLimitado(int min, int max);

/** \brief valida diferente de 0
*
* \param numero int
* \return int retorna 1 si / 0 no
*
*
*/int difCero(int numero);

/** brief valida si el float 1 en caso que no haya decimales despues de la coma  devuelve 0 en caso contrario
*
* \numero float
* \return int
*
*/
int validarDecimales(float numero);

/** \brief recibe una cadena y devuelve el tamaño sin incluir \0
 *
 * \param vect[] char
 * \return int
 *
 */
int miStrlen(char vect[]);

/** \brief recibe una cadena y verifica que tenga letras u otros carcateres
 *
 * \param vect[] char
 * \return int devuelve 0 si son todas letras, devuelve 1 si encuentra alguna diferencia
 *
 */
int validarCadena(char vect[]);

/** \brief recibe una cadena y pone el primer Caracter en Mayusculas ademas de guardarla
 *
 * \param cadena[] char
 * \param mensaje[] char
 * \param limite int
 * \return int
 *
 */
int pedirCadena(char cadena[], char mensaje[], int limite);

/** \brief convierte a mayuscula el primer caracter de una cadena
 *
 * \param cadena[] char
 * \return int
 *
 */
int UpperPrimerCaracter(char cadena[]);

/** \brief parsea a entero una cadena
 *
 * \param
 * \param
 * \return
 *
 */
int parserInt(int *pResultado);


/** \brief valida si la cadena que recibe es un entero
 * \param pResultado int*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo int
 * \param maximo int
 * \param reintentos int
 * \return int
 *
 */
int validarEntero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos);

/** \brief valida si una cadena recibida esta compupuesta solo por enteros
 *
 * \param cadena char*
 * \return int
 *
 */
int valCadenaNumerica(char *cadena);

/** \brief parsea a float
 *
 * \param
 * \param
 * \return
 *
 */
int parseFloat(float *pResultado);

/** \brief valida si la cadena que recibe es float,
 * \param pResultado float*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo float
 * \param maximo float
 * \param reintentos int
 * \return int
 *
 */
int validarFloat(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos);

/** \brief valida si una cadena recibida esta compupuesta solo por floats
 *
 * \param str[] char
 * \return int
 *
 */
int valFlotante(char cadena[]);



#endif // MYLIBRARY_H_INCLUDED
