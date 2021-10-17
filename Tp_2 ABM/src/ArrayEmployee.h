/*
 * ArrayEmployee.h
 *
 *  Created on: 16 oct. 2021
 *      Author: agust
 */

#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED
#include "Function.h"

struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}typedef Employee;


int initEmployees(Employee* list, int len);

int newEmployee(Employee* list , int len, int* nextId);

int addEmployee(Employee* list, int len, int* id, char name[],char
lastName[],float salary,int sector);

int findEmployeeById(Employee* list, int len,int id);

int removeEmployee(Employee*  list, int len, int id);

int sortEmployees(Employee* list, int len, int order);

int printEmployees(Employee* list, int length);

int printEmployee(Employee* list );

int modificarEmpleado(Employee*  list, int len, int id);

int menuModificar();
#endif // ARRAYEMPLOYEE_H_INCLUDED
