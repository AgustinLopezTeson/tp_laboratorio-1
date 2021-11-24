#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


Employee* employee_new()
{

    Employee* new_employee;


    new_employee = (Employee*) malloc ( sizeof(Employee));

    if(new_employee!=NULL)
    {
        new_employee->id= 0;
        strcpy(new_employee->nombre," ");
        new_employee->horasTrabajadas=000;
        new_employee->sueldo= 0000;
    }

    return new_employee;
}





void employee_delete(Employee* emp){

    free(emp);
}

int employee_setId(Employee* this,int id)
{
    int todoOk=0;

    if(this !=NULL && id>=0 && id<= 50000)
    {
        this->id=id;
        todoOk =1;
    }
    else
    {
        printf("Problema con el Id");
    }


    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk=0;

    if(this != NULL && nombre!=NULL && strlen(nombre)<20)
    {
        strcpy(this->nombre,nombre);
        todoOk =1;
    }
    else
    {
        printf("Problema con el Nombre");
    }


    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{

     int todoOk=0;

    if(this !=NULL && horasTrabajadas>0 )
    {
        this->horasTrabajadas=horasTrabajadas;
        todoOk = 1;
    }
    else
    {
        printf("Problema con las horas trabajadas");
    }


    return todoOk;


}

int employee_setSueldo(Employee* this,float sueldo)
{
    int todoOk=0;

    if(this !=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        todoOk =1;
    }
    else
    {
        printf("Problema con el sueldo ");
    }


    return todoOk;


}

void list_Employee(Employee* this)
{

    printf("%3d   %10s           %4d          %7.2f\n\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);

}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{


   Employee* new_Emp;


    new_Emp= employee_new();

    if(new_Emp!=NULL)
    {
        if(!(    employee_setId(new_Emp,atoi(idStr))&&
                 employee_setNombre(new_Emp,nombreStr)&&
                 employee_setHorasTrabajadas(new_Emp,atoi(horasTrabajadasStr))&&
                 employee_setSueldo(new_Emp,atof(sueldoStr))))
        {
            printf("Hubo un problema");
            employee_delete(new_Emp);
            new_Emp=NULL;
        }

    }
    else
    {
        printf("No se pudo conseguir memoria");
    }

    return new_Emp;
}


int  new_employeeManual(Employee* this , int* id)
{

    int todoOk=0;
    char nombre [30];
    int horasTrabajadas;
    float sueldo;
    Employee* aux=NULL;
    printf("*** Alta de Empleado***\n\n");
    printf("\n\nIngrese la id: ");
    scanf("%d", &id);

    printf("\n\nIngrese el nombre: ");
    fflush(stdin);
    gets(nombre);

    printf("\n\nIngrese horas trabajadas:");
    scanf("%d",&horasTrabajadas);

    printf("\n\n Ingrese el sueldo: ");
    scanf("%f", &sueldo);


    aux=employee_newParametrosN(id,nombre,horasTrabajadas,sueldo);

    if(aux!=NULL)
    {
        ll_add(this,aux);
        todoOk=1;
    }

return todoOk;
}


Employee* employee_newParametrosN(int id,char* nombre,int horasTrabajadas,float sueldo)
{

    Employee* new_Emp;

    new_Emp= employee_new();

    if(new_Emp!=NULL)
    {
        if(!(    employee_setId(new_Emp,id)&&
                 employee_setNombre(new_Emp,nombre)&&
                 employee_setHorasTrabajadas(new_Emp,horasTrabajadas)&&
                 employee_setSueldo(new_Emp,sueldo)))
        {
            printf("Hubo un problema");
            employee_delete(new_Emp);
            new_Emp=NULL;
        }

    }
    else
    {
        printf("No se pudo conseguir memoria");
    }

    return new_Emp;
}


/*int editEmployee(Employee* this,LinkedList* lista)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;
    char seguir = 's';
    char salir;
    Employee* aux=NULL;

    if (pArrayEmployees != NULL && pArrayEmployees!=NULL)
    {
        system("cls");
        printf("   *** Modificar Empleado *** \n\n");
        controller_ListEmployee(lista);
        printf("Ingrese id del empleado : ");
        scanf("%d", &id);


        if (indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n", id);
        }
        else
        {
            do
            {
                switch ( menuDeModificaciones() )
                {
                case 1:

                    printf("Modificar Horas: ");
                    scanf("%d",aux->horasTrabajadas);
                    printf("Confirma cambio de tipo? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        ll_index)
                        employee_setHorasTrabajadas(this,aux->horasTrabajadas);
                    }
                    else
                    {
                        printf("Edición cancelada\n");
                    }
                    break;
                case 2:
                    printf("Modificar sueldo: ");
                    scanf("%.2f", aux->sueldo);
                    printf("Confirma cambio de precio? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    confirma = toupper(confirma);
                    if (confirma == 'S')
                    {
                        employee_setSueldo(this,aux->sueldo);
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
                }
                system("pause");
            }
            while(seguir == 's');

            todoOk = 1;

        }
    }
    return todoOk;
}
*/

int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        int  tam=ll_len(this);
        for(int i = 0 ; i<tam; i++)
        {
            if(pElement==ll_get(this,i))
            {
                returnAux=0;
                break;
            }
        }
    }
    return returnAux;
}
