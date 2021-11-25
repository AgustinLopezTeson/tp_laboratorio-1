#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Employee.h"
#include "../inc/input.h"
#include "../inc/parser.h"


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
        if(new_employeeManual(pArrayListEmployee))
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
    int todoOk = 0;
    Employee* auxEmpleado;

    char seguir = 's';
    char salir;
    int id;
    int opcion;
    int indice;
    int sueldo;
    int horasTrabajadas;

    char confirma;

    controller_ListEmployee(pArrayListEmployee);

    if ( pArrayListEmployee != NULL )
    {
        //system("cls");
        printf("Modificar datos de empleado\n");

        printf("Ingrese id: ");
        scanf("%d", &id);
        indice = searchEmployeeId( pArrayListEmployee, id );
        if ( indice == -1 )
        {
            printf("No se encontro el empleado\n");
        }
        else
        {
            auxEmpleado = ll_get(pArrayListEmployee, indice);

            do
            {
                system("cls");
                printf("\n");
                printf("Legajo  Nombre          Horas Trabajadas    Sueldo\n");
                list_Employee(auxEmpleado);
                opcion = menuDeModificaciones();

                switch (opcion)
                {
                case 1:
                    system("cls");
                    printf("  Editar Horas Trabajadas\n");
                    printf("Ingrese las horas trabajadas: ");
                    scanf("%d", &horasTrabajadas);
                    printf("Confirma cambio horas trabajadas? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas);
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }

                    break;
                case 2:
                    system("cls");
                    printf("  Editar sueldo\n");
                    printf("Ingrese el sueldo: ");
                    scanf("%d", &sueldo);

                    printf("Confirma cambio sueldo? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        employee_setSueldo(auxEmpleado, sueldo);
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }

                    break;
                case 3:
                    printf("Esta seguro que quiere salir? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &salir);
                    salir = toupper(salir);
                    if (salir == 'S')
                    {
                        seguir = 'n';
                    }
                    else
                    {
                        break;
                    }
                    break;
                default:
                    printf("Opcion invalida\n");
                    break;
                }
                system("pause");
            }
            while(seguir == 's');
            todoOk=1;
        }
    }
    return todoOk;
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

    int todoOk = 0;
    int id;
    int indice;
    char confirma;

    Employee* auxEmp;

    controller_ListEmployee(pArrayListEmployee);

    if ( pArrayListEmployee != NULL )
    {

        printf("Baja de empleado\n");

        printf("Ingrese id: ");
        scanf("%d", &id);
        indice = searchEmployeeId( pArrayListEmployee, id );
        system("cls");
        if ( indice == -1 )
        {
            printf("No se encontro el empleado\n");
        }
        else
        {
            auxEmp = ll_get(pArrayListEmployee, indice);
            printf("Empleado seleccionado: \n\n");
            printf("ID        NOMBRE      HorasTrabajadas      SUELDO\n\n");
            list_Employee(auxEmp);
            printf("\n");
            printf("Confirma la baja? (S/N)\n");
            fflush(stdin);
            scanf("%c", &confirma);
            if ( tolower(confirma) == 's' )
            {
                ll_remove(pArrayListEmployee, indice);
                printf("Baja exitosa\n");
                todoOk = 1;
            }
        }

    }
    return todoOk;
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
        todoOk=1;
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

    char seguir = 's';
    char salir;

    int todoOk = 0;
    int opcion;
    if ( pArrayListEmployee != NULL )
    {
        system("cls");
        printf("***Menu Ordenar empleados***\n");

        do
        {
            opcion = subMenuComp();

            switch (opcion)
            {
            case 1:
                system("cls");
                printf("  Ordenar Horas trabajadas de menor a mayor  \n");
                ll_sort( pArrayListEmployee, compEmployeeHorasTrabajadas, 1 );
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 2:
                system("cls");
                printf("  Ordenar  Horas trabajadas de mayor a menor\n");
                ll_sort( pArrayListEmployee, compEmployeeHorasTrabajadas, 0 );
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 3:
                system("cls");
                printf("  Ordenar  Sueldo de menor a mayor\n");
                ll_sort( pArrayListEmployee, compEmployeeSueldo, 1 );
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 4:
                system("cls");
                printf("  Ordenar  Sueldo de mayor a menor\n");
                ll_sort( pArrayListEmployee, compEmployeeSueldo, 0 );
                controller_ListEmployee(pArrayListEmployee);
                break;
            case 5:
                printf("Esta seguro que quiere salir? (S/N)\n");
                fflush(stdin);
                scanf("%c", &salir);
                salir = toupper(salir);
                if (salir == 'S')
                {
                    seguir = 'n';
                }
                else
                {
                    break;
                }
                break;
            default:
                printf("Opcion invalida\n");
                break;
            }
            system("pause");
        }
        while(seguir == 's');
    }
    return todoOk;





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
    int todoOk = 0;
    FILE* f;
    int id;
    char nombre[50];
    int horasTrabajadas;
    int sueldo;
    Employee* auxEmpleado;

    if ( path != NULL && pArrayListEmployee != NULL )
    {

        f = fopen(path, "w"); // abro el archivo
        if ( f == NULL )
        {
            printf("No se pudo abrir el archivo\n");

        }

        fprintf( f, "Id,Nombre,Horas Trabajadas,Sueldo\n" );

        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);
            if ( employee_getId( auxEmpleado, &id ) &&
                    employee_getNombre( auxEmpleado, nombre ) &&
                    employee_getHorasTrabajadas( auxEmpleado, &horasTrabajadas) &&
                    employee_getSueldo(auxEmpleado, &sueldo)
               )
            {
                fprintf(f, "%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
                todoOk = 1;
            }
        }
        system("cls");
        printf("\nGuardado correctamente en DATA1.CSV.\n");
        system("pause");
    }
    fclose(f);
    return todoOk;
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
    int todoOk = 0;
    FILE* f;

    Employee* auxEmpleado;

    if ( path != NULL && pArrayListEmployee != NULL )
    {
        f = fopen(path, "wb");
        if ( f == NULL )
        {
            printf("No se pudo abrir el archivo\n");

        }

        for (int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = ll_get(pArrayListEmployee, i);
            if ( (auxEmpleado + i) != NULL )

                if ( (auxEmpleado) != NULL )
                {
                    fwrite( auxEmpleado, sizeof(Employee), 1, f );
                    todoOk = 1;
                }
        }
        system("cls");
        printf("\nGuardado correctamente en DATA.BIN.\n");
        system("pause");


    }
    fclose(f);
    return todoOk;

}

