/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "../inc/Controller.h"
#include "../inc/Employee.h"
#include "../inc/input.h"
#include "../inc/parser.h"


int main(void)
{
        startTesting(1);  // ll_newLinkedList
        startTesting(2);  // ll_len
        startTesting(3);  // getNode - test_getNode*
        startTesting(4);  // addNode - test_addNode
        startTesting(5);  // ll_add
        startTesting(6);  // ll_get
        startTesting(7);  // ll_set //
        startTesting(8);  // ll_remove
        startTesting(9);  // ll_clear
        startTesting(10); // ll_deleteLinkedList
        startTesting(11); // ll_indexOf
        startTesting(12); // ll_isEmpty
        startTesting(13); // ll_push
        startTesting(14); // ll_pop
        startTesting(15); // ll_contains
        startTesting(16); // ll_containsAll
        startTesting(17); // ll_subList
        startTesting(18); // ll_clone
        startTesting(19); // ll_sort


 char seguir = 's';
    char salir;
    int id=1001;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        switch (menu())
        {
        case 1:
            if ( !controller_loadFromText("data.csv", listaEmpleados) )
            {
                printf("Error al cargar desde texto\n");
            }
            break;
        case 2:
            if ( !controller_loadFromBinary("data.bin", listaEmpleados) )
            {
                printf("Error al cargar desde binario\n");
            }
            break;
        case 3:
            if ( !controller_addEmployee(listaEmpleados,&id) )
            {
                printf("Error en alta de empleado\n");
            }
            break;
        case 4:
            if ( !controller_editEmployee(listaEmpleados) )
            {
                printf("Error en edicion de empleado\n");
            }
            break;
        case 5:
            if ( !controller_removeEmployee(listaEmpleados) )
            {
                printf("Error en baja de empleado\n");
            }
            break;
        case 6:
            if ( !controller_ListEmployee(listaEmpleados) )
            {
                printf("Error al listar empleados\n");
            }
            break;
        case 7:
            if ( !controller_sortEmployee(listaEmpleados) )
            {
                printf("Error en ordenamiento de empleados\n");
            }
            break;
        case 8:
            if ( !controller_saveAsText("data.csv", listaEmpleados) )
            {
                printf("Error al guardar en modo texto\n");
            }

            break;
        case 9:
            if ( !controller_saveAsBinary("data.bin", listaEmpleados) )
            {
                printf("Error al guardar en modo binario\n");
            }
            break;
      /*case 10:
            if ( !controller_replaceEmployee(listaEmpleados) )
            {
                printf("Error al reemplazar empleado\n");
            }
            break;
        case 11:
            if ( !controller_clearList(listaEmpleados) )
            {
                printf("Error al borrar los empleados\n");
            }
            break;
        case 12:
            if ( !controller_deleteList(listaEmpleados) )
            {
                printf("Error al vaciar la lista\n");
            }*/
            listaEmpleados = NULL;
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");
        }while(seguir == 's');
return 0;
    }

































