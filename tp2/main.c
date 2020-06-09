#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_biblioteca.h"
#define LEN 10
int main()
{
    Employee employees[LEN];
    char seguir='s';
    char seguir4='s';
    char auxName[51];
    char auxLastName[51];
    int id=1000;
    int flagCargoEmpleado=0;
    int auxId;
    int auxIndice;
    int ordenamiento;
    int auxSector;

    int Freeplace;
    float auxSalary;


    initEmployees(employees,LEN);



    do
    {

        switch(showMenu())
        {


        case 1: //si hay lugar en el vector,valido los datos y luego los capturo en variables auxiliares
            system("cls");
            printf("Alta empleado\n\n");

            Freeplace=searchFreePlace(employees,LEN);

            if(Freeplace>=0)
            {

                utn_getCadena(auxName,51,30,"\n\ningrese nombre del empleado:","\n\nerror. Utilice letras ");

                utn_getCadena(auxLastName,51,30,"\n\ningrese apellido del empleado:","\n\nerror. Utilice letras");

                utn_getEntero(&auxSector,30,"\n\ningrese sector del empleado:","\n\nerror. Utilice numeros",0,10000000);

                utn_getFlotante(&auxSalary,30,"\n\ningrese el salario del empleado:","\n\nerror. Utilice numeros",0,100000000);

                //copio los datos auxiliares en el indice del vector employees que me devuelva la funcion searchFreePlace con la funcion addEmployee

                addEmployee(employees,id,auxName,auxLastName,auxSalary,auxSector,Freeplace);
                id++;
                printf("empleado cargado con exito\n\n");
                flagCargoEmpleado=1;

            }
            else
            {
                printf("el sistema ya esta lleno");
            }
            printf("\n");



            break;

        case 2:
            if(flagCargoEmpleado)
            {
                system("cls");
                printf("        menu modificar empleado         \n\n");
                printf("empleados en el sistema:\n");
                printEmployees(employees,LEN);

                utn_getEntero(&auxId,100,"Ingrese el id del empleado a modificar:","error.Utilice numeros\nrecuerde que los id estan comprendidos en el campo del 1000 al 2000\n",1000,2000);
                auxIndice=findEmployeeById(employees,LEN,auxId);
                printf("\n\n");

                if(auxIndice>=0)
                {
                    switch(menuModifica())
                    {

                    case 1:
                        utn_getCadena(employees[auxIndice].name,51,100,"ingrese nuevo nombre del empleado:","error. Utilice letras.");
                        printf("modificacion exitosa\n");
                        break;
                    case 2:
                        utn_getCadena(employees[auxIndice].lastName,51,100,"ingrese nuevo nombre del empleado:","error.Utilice letras.");
                        printf("modificacion exitosa\n");
                        break;
                    case 3:
                        utn_getFlotante(&employees[auxIndice].salary,100,"ingrese nuevo sueldo:","error, utilice numeros. El sueldo no puede ser negativo.\n",0,1000000);
                        printf("modificacion exitosa\n");
                        break;
                    case 4:
                        utn_getEntero(&employees[auxIndice].sector,100,"ingrese nuevo sector:", "error, utilice numeros. El sector no puede ser negativo\n",0,1000000);
                        break;
                    default:
                        printf("opcion no valida");
                        break;

                    }
                }
                else
                {

                    printf("no hay registros del id ingresado\n");


                }
            }
            else
            {

                printf("no hay empleados en el sistema\n\n");


            }



            break;
        case 3:
            if(flagCargoEmpleado)
            {
                printf("        menu bajas      \n\n");

                printf("ingrese id del empleado a eliminar \n(nota: puede ver el id en la pantalla de informes)\n\n");
                utn_getEntero(&auxId,300,"\n\ningrese id del empleado a dar de baja:","\n\nerror. Utilice numeros\nlos ids estan comprendidos en el rando del 1000 al 2000.",1000,2000);
                auxIndice=findEmployeeById(employees,LEN,auxId);
                if(auxIndice>=0)
                {
                    employees[auxIndice].isEmpty=1;
                    printf("baja exitosa\n\n");

                }
                else
                {
                    printf("el id no corresponde a un empleado en el sistema\n\n");

                }

            }
            else
            {
                printf("no hay empleados en el sistema\n\n");
            }


            break;
        case 4:
            if(flagCargoEmpleado)
            {
                system("cls");
                do
                {
                    switch(menuOption4())
                    {

                    case 1:

                        utn_getEntero(&ordenamiento,100,"ingrese uno para ordenar los apellidos de mayor a menor, o 2 para ordenarlos de menor a mayor:","Error.Opcion invalida\n",1,2);
                        system("cls");
                        sortEmployees(employees,LEN,ordenamiento);
                        printEmployees(employees,LEN);
                        system("cls");
                        break;
                    case 2:
                        system("cls");
                        informeMayorSueldo(employees,LEN);
                        system("cls");
                        break;
                    case 3:
                        seguir4='n';
                        break;

                    }



                }
                while(seguir4=='s');


            }
            else
            {

                puts("primero hay que ingresar al menos un empleado\n\n");

            }

            break;
        case 5:
            seguir='n';
            break;
        default:
            printf("opcion no valida");

        }

    system("pause");
    system("cls");

    }
    while(seguir=='s');


}
