#include <stdio.h>
#include <stdlib.h>


#define TAM 3

typedef struct
{

    int id;
    char nombre[20];
    char sexo ;
    int edad;
    float altura;
    int isEmpty;

} ePersona;



int menu();
int inicializarPersonas(ePersona lista [], int tam);
int buscarLibre(ePersona lista[],int tam);
int altaPersona(ePersona lista [], int tam, int* pId);
void mostrarPersona(ePersona p);
int mostrarPersonas(ePersona lista[], int tam);

int main()
{
    char seguir= 's';
    ePersona lista [TAM];
    int nextId= 20000;

    inicializarPersonas(lista,TAM);
    buscarLibre(lista,TAM);


    do
    {

        switch(menu())
        {

        case 1 :
            if(!altaPersona(lista,TAM,&nextId))
            {
                printf("No se pudo realizar el alta");
            }
            else
            {
                printf("Alta exitosa !!!\n");

            }
            break;
        case 2:
            printf("Baja Persona");
            break;
        case 3:
            printf("Modificar Persona");
            break;
        case 4:
            printf("Ordenar Persona");
            break;
        case 5:
            printf("Listar Personas");
            break;
        case 6:
            printf("Eligio salir");
            seguir='n';
            break;
        default:
            printf("Opcion Invalida \n");
        }


        system("pause");
    }
    while(seguir=='s');






    return 0;
}


int menu()
{

    int opcion;

    system("cls");
    printf(" **** ABM PERSONAS ***** \n\n");
    printf("1-Alta Persona\n");
    printf("2-Baja Persona\n");
    printf("3-Modificar Persona\n");
    printf("4-Ordenar Persona\n");
    printf("5-Listar Persona\n");
    printf("6-Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
}

int inicializarPersonas(ePersona lista [], int tam)
{

    int todoOk=0;
    if( lista!= NULL && tam>0)
    {
        for(int i = 0; i<tam; i++)
        {

            lista[i].isEmpty = 1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibre(ePersona lista[], int tam)
{

    int libre=0;

    if( lista!= NULL && tam>0)
    {
        for(int i = 0; i<tam; i++)
        {
            if(lista[i].isEmpty)
            {
                libre=i;
                break;
            }
        }
    }

    return libre;
}

int altaPersona(ePersona lista [], int tam, int* pId)
{

    int todoOk=0;
    int indice;
    ePersona auxPersona;


    if( lista!= NULL && tam>0)
    {
        system("cls");
        printf("***Alta Persona*** \n\n");
        indice = buscarLibre(lista,tam);

        if(indice == -1)
        {
            printf("No hay lugar \n");

        }
        else
        {

            auxPersona.id=*pId;

            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(auxPersona.nombre);

            printf("\nIngrese sexo: ");
            scanf("%s", &auxPersona.sexo);

            printf("\nIngrese edad: ");
            scanf("%d", &auxPersona.edad);

            printf("\nIngrese altura: ");
            scanf("%.2f", &auxPersona.altura);

            (*pId)++;
        }

        auxPersona.isEmpty=0;

        lista[indice]=auxPersona;
        todoOk=1;
    }
    return todoOk;


}

void mostrarPersona(ePersona p)
{

    int todoOk=0;





    return todoOk;
}







int mostrarPersonas(ePersona lista[], int tam)
{

    int todoOk=0;

    printf("%d     %s       %");



    return todoOk;

}

