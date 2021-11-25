#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk=1;
    int cant;
    char buffer[4][40];
    Employee * aux=NULL;

            fscanf(pFile,"%[^,],%[^,],%[^,],%s\n",buffer[0],buffer[1],buffer[2],buffer[3]);
            while(!feof(pFile)){
                    aux=employee_new();

                    if(aux!=NULL)
                    {
                        cant = fscanf(pFile,"%[^,],%[^,],%[^,],%s\n",buffer[0],buffer[1],buffer[2],buffer[3]);
                        employee_setId(aux,atoi(buffer[0]));
                        employee_setNombre(aux,buffer[1]);
                        employee_setHorasTrabajadas(aux,atoi(buffer[2]));
                        employee_setSueldo(aux,atof(buffer[3]));

                        ll_add(pArrayListEmployee,aux);

                        todoOk=0;
                    }
                        if(cant<3){
                            break;
                        }
                }

    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

int todoOk=1;
    int cant;
    Employee * aux=NULL;
            while(!feof(pFile)){

                    aux=employee_new();
                   if(aux!=NULL)
                   {
                        aux=fread(aux,sizeof(Employee),1000,pFile);
                        ll_add(pArrayListEmployee,aux);
                        todoOk=0;
                   }
            }
    return todoOk;
}

