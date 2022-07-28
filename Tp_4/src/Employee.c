#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Employee.h"
#include "../inc/input.h"
#include "../inc/parser.h"


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


void employee_delete(Employee* emp)
{

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


int  new_employeeManual(LinkedList* pArrayListEmployee)
{

    int todoOk=0;
    char nombre [30];
    int horasTrabajadas;
    int sueldo;
    int id;
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
        ll_add(pArrayListEmployee,aux);
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



int searchEmployeeId(LinkedList* pArrayListEmployee, int id)
{
    int indice = -1;
    int idAux;
    Employee* auxEmp;

    for (int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        auxEmp = ll_get(pArrayListEmployee, i);
        if( employee_getId(auxEmp, &idAux) && idAux == id)
        {
            indice = i;
        }
    }
    return indice;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;

}

int employee_getNombre(Employee* this,char* nombre)
{

    int todoOk = 0;
    if (this != NULL && nombre != NULL )
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;

}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;
    if (this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;

}

int employee_getSueldo(Employee* this,float* sueldo)
{

    int todoOk = 0;
    if (this != NULL && sueldo > 0)
    {
        *sueldo=this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int compEmployeeHorasTrabajadas(void* pEmployee, void* sEmployee)
{
    int todoOk= 0;

    if( ((Employee*)pEmployee)->horasTrabajadas > ((Employee*)sEmployee)->horasTrabajadas )
    {
        todoOk++;
    }
    if( ((Employee*)pEmployee)->horasTrabajadas < ((Employee*)sEmployee)->horasTrabajadas )
    {
        todoOk--;
    }
    return todoOk;
}

int compEmployeeSueldo(void* pEmployee, void* sEmployee)
{
    int todoOk= 0;

    if(((Employee*)pEmployee)->sueldo > ((Employee*)sEmployee)->sueldo)
    {
        todoOk++;
    }
    if(((Employee*)pEmployee)->sueldo < ((Employee*)sEmployee)->sueldo)
    {
        todoOk --;
    }
    return todoOk;

}


int buscarMayorId(LinkedList* pArrayListEmployee)
{
    Employee* auxEmpleado = NULL;
    int mayor = 0;
    int id;
    if(pArrayListEmployee != NULL)
    {
        for( int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
            employee_getId(auxEmpleado, &id);
            if( i==0 || id > mayor)
            {
                mayor = id;
            }
        }
    }
    return mayor;
}
