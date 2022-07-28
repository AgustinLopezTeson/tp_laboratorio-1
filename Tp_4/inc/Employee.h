#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
Employee* employee_newParametrosN(int id,char* nombre,int horasTrabajadas,float sueldo);

void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,float sueldo);
int employee_getSueldo(Employee* this,float* sueldo);

void list_Employee(Employee* this);
int new_employeeManual(LinkedList* pArrayListEmployee);
int editEmployee(Employee* this, LinkedList* lista);
int searchEmployeeId(LinkedList* pArrayListEmployee, int id);
int compEmployeeSueldo(void* pEmployee, void* sEmployee);
int compEmployeeHorasTrabajadas(void* pEmployee, void* sEmployee);
int buscarMayorId(LinkedList* pArrayListEmployee);

#endif // employee_H_INCLUDED
