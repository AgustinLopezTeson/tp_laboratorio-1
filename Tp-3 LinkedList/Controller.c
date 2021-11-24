#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* f= fopen("data.csv","r");

    if(f==NULL && pArrayListEmployee==NULL)
    {
        printf("No se pudo cargar el archivo");
    }
    else
    {
        if(parser_EmployeeFromText(f,pArrayListEmployee))
        {
            printf("Hubo un error en cargar los empleados");
        }
        else
        {
            printf("Carga exitosa!!!!\n\n");
            system("pause");
            fclose(f);
        }

    }
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

    FILE* f= fopen("data.bin","rb");

    if(f==NULL && pArrayListEmployee==NULL)
    {
        printf("No se pudo cargar el archivo");
    }
    else
    {
        if(parser_EmployeeFromBinary(f,pArrayListEmployee))
        {
            printf("Hubo un error en cargar los empleados");
        }
        else
        {
            printf("Carga exitosa!!!!\n\n");
            system("pause");
            fclose(f);
        }

    }
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* id)
{

    if(pArrayListEmployee!=NULL)
    {
        system("cls");
        if(new_employeeManual(pArrayListEmployee,&id))
        {
            printf("Alta Exitosa\n\n");
            system("pause");
        }
    }
    else
    {
        printf("No se pudo dar el alta");
    }


    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{





    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int todoOk=0;
    Employee* auxEmp=NULL;
    if(pArrayListEmployee!=NULL)
    {
        printf("ID        NOMBRE      HorasTrabajadas      SUELDO\n\n");
        for(int i = 0 ; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmp=(Employee* )ll_get(pArrayListEmployee,i);
            list_Employee(auxEmp);

        }
        system("pause");
    }

    return todoOk;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    return 1;
}

