#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn_biblioteca.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char sigue='s';
    int flagCargo=0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados==NULL)
    {
        printf("Error.No se consiguio memoria");
        exit(EXIT_FAILURE);

    }


    do
    {
        switch(menu())
        {
        case 1:
            controller_loadFromText("data.csv",listaEmpleados);
            printf("%d empleados agregados con exito\n",ll_len(listaEmpleados));
            flagCargo=1;

            break;
        case 2:
            controller_loadFromBinary("data.bin",listaEmpleados);
            printf("no pude realizar este punto\n");
            break;
        case 3:
            if(controller_addEmployee(listaEmpleados))
            {
                printf("alta exitosa\n");
                flagCargo=1;

            }
            else
            {
                printf("no se pudo realizar el alta, el id ya esta ocupado.\n");

            }


            break;
        case 4:
            if(flagCargo)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("sistema vacio\n");

            }
            break;
        case 5:
            if(flagCargo)
            {
                controller_removeEmployee(listaEmpleados);

            }
            else
            {
                printf("sistema vacio\n");
            }
            break;
        case 6:
            if(flagCargo)
            {

                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("sistema vacio\n");

            }
            break;
        case 7:
            if(flagCargo)
            {

                controller_sortEmployee(listaEmpleados);

            }
            else
            {
                printf("sistema vacio\n");

            }

            break;
        case 8:
            if(flagCargo&&(ll_len(listaEmpleados)>0))
            {
                if(controller_saveAsText("cargadatos.csv",listaEmpleados))
                {
                    printf("archivos guardados\n");

                }
                else
                {
                    printf("no se pudo guardar el archivo\n");
                }

            }
            else
            {
                printf("sistema vacio\n");

            }

            break;
        case 9:
            if(flagCargo&&(ll_len(listaEmpleados)>0))
            {

                if( controller_saveAsBinary("cargadatos.bin",listaEmpleados))
                {
                    printf("archivos guardados\n");
                }
                else
                {
                    printf("no se pudo guardar el archivo\n");

                }

            }
            else
            {
                printf("sistema vacio\n");

            }

            break;
        case 10:
            sigue='n';
            ll_deleteLinkedList(listaEmpleados);
            break;

        }
        system("pause");
        system("cls");
    }
    while(sigue=='s');
    return 0;
}
