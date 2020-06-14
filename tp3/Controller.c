#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn_biblioteca.h"
#include "parser.h"
#include "controller.h"
#include "Employee.h"
int menu(void)
{
    int opcion;
    printf("        linkedlist         \n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
    utn_getEntero(&opcion,100,"Opcion:","\nError.Opcion invalida",1,10);




    return opcion;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ok=0;

    FILE* archivo;


    if(path!=NULL&&pArrayListEmployee!=NULL)
    {

        archivo=fopen(path,"r");
        if(parser_EmployeeFromText(archivo,pArrayListEmployee))
        {
            ok=1;



        }

    }

    fclose(archivo);



    return ok;
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

    int ok=0;
    FILE* archivo;

    if(path!=NULL&&pArrayListEmployee!=NULL)
    {
        archivo=fopen(path,"rb");
        if(parser_EmployeeFromBinary(archivo,pArrayListEmployee))
        {
            ok=1;

        }

    }

    fclose(archivo);

    return ok;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* unEmpleado=employee_new();
    int ok=0;
 //   int tam=ll_len(pArrayListEmployee);
    int auxId;
//    int flagEncontre=0;
    system("cls");

    printf("        menu alta empleado\n\n");
    utn_getEntero(&auxId,100,"ingrese id (ids comienzan en el uno):","Error.Utilice numeros\n",1,1000000);
    /*
        for(int i=0; i<tam; i++)
        {
            unEmpleado=ll_get(pArrayListEmployee,i);
            if(unEmpleado->id==auxId)
            {
                flagEncontre=1;
                break;
            }

        }

        if(flagEncontre)
        {
            printf("el id ingresado ya esta ocupado\n");
            employee_delete(unEmpleado);
            return ok;

        }
    */

    if(buscoPorId(pArrayListEmployee,auxId)==0)
    {
        unEmpleado->id=auxId;
        utn_getCadena(unEmpleado->nombre,128,100,"ingrese nombre:","Error.Utilice letras.\n");
        utn_getEntero(&unEmpleado->sueldo,100,"Ingrese sueldo:","Error. Utilice numeros.\n",0,99999);
        utn_getEntero(&unEmpleado->horasTrabajadas,100,"Ingrese horas trabajadas:","Error.Utilice numeros.\n",0,99999);


        if(unEmpleado!=NULL)
        {
            ll_add(pArrayListEmployee,unEmpleado);
            ok=1;

        }

    }



    return ok;
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
    Employee* unEmpleado=employee_new();
    int tam=ll_len(pArrayListEmployee);
    int auxId;
    int flagEncontre=0;
    char auxnombre[50];
    int auxsueldo;
    int auxhoras;

    char sigue='s';
    int posicion;

    system("cls");
    printf("        modificacones\n");
    utn_getEntero(&auxId,100,"Ingrese id del empleado a modificar:","Error.Utilice caracteres numericos",0,999999);


    for(int i=0; i<tam; i++)
    {
        unEmpleado=ll_get(pArrayListEmployee,i);
        if(unEmpleado->id==auxId)
        {
            flagEncontre=1;
            posicion=i;
            break;


        }

    }

    if(!flagEncontre)
    {
        printf("no hay empleados con el id ingresado\n");
        return 0;


    }

    unEmpleado=ll_get(pArrayListEmployee,posicion);
    printf("datos del empleado ingresado:\n");
    printf("     Id     Nombre     Horas trabajadas  Sueldo\n  ");
    printf("%5d  %10s   %10d   %10d\n",unEmpleado->id,unEmpleado->nombre,unEmpleado->horasTrabajadas,unEmpleado->sueldo);


    do
    {
        switch(opcionModifica())
        {
        case 1:
            utn_getEntero(&auxId,100,"ingrese nuevo id:","Error.Utilice numeros\n",1,99999);
            if(buscoPorId(pArrayListEmployee,auxId)==0)
            {
               employee_setId(unEmpleado,auxId);
                printf("modificacion exitosa\n");

            }
            else
            {
                printf("id en uso\n");

            }

            break;
        case 2:
            utn_getCadena(auxnombre,50,100,"Ingrese nuevo nombre:","Error. Nombre demasiado largo o caracteres numericos ingresados\n");
            employee_setNombre(unEmpleado,auxnombre);
            printf("modificacion exitosa\n");
            break;
        case 3:
            utn_getEntero(&auxhoras,100,"Ingrese nueva cantidad de horas:","Error. Utilice caracteres numericos",1,99999);
            employee_setHorasTrabajadas(unEmpleado,auxhoras);
            printf("modificacion exitosa\n");
            break;
        case 4:
            utn_getEntero(&auxsueldo,100,"Ingrese nuevo sueldo:","Error.Utilice caracteres numericos",1,99999);
            employee_setSueldo(unEmpleado,auxsueldo);
            printf("modificacion exitosa\n");
            break;
        case 5:
            sigue='n';
            break;

        }



    }
    while(sigue=='s');




    return 0;
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
    int flagEncontre=0;
    int posicion;
    int auxId;
    int tam=ll_len(pArrayListEmployee);

    system("cls");
    printf("        bajas\n");
    utn_getEntero(&auxId,100,"Ingrese id del empleado a eliminar:","Error.Utilice caracteres numericos",0,999999);


    Employee* unEmpleado=employee_new();


    for(int i=0; i<tam; i++)
    {
        unEmpleado=ll_get(pArrayListEmployee,i);
        if(unEmpleado->id==auxId)
        {
            flagEncontre=1;
            posicion=i;
            break;
        }

    }
    if(flagEncontre==0)
    {

        printf("el id ingresado no esta en el sistema\n");
        return 0;

    }

    ll_remove(pArrayListEmployee,posicion);
    printf("baja exitosa\n");

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
    system("cls");
    int ok=0;
    int flagmostro=0;

    Employee* unEmpleado;

    if(pArrayListEmployee!=NULL)
    {

        int tam=ll_len(pArrayListEmployee);

        printf(" Id     Nombre      Horas trabajadas     Sueldo\n  ");

        for(int i=0; i<tam; i++)
        {
            unEmpleado=(Employee*)ll_get(pArrayListEmployee,i);

            printf("%4d  %10s   %5d                %6d\n",unEmpleado->id,unEmpleado->nombre,unEmpleado->horasTrabajadas,unEmpleado->sueldo);
            flagmostro=1;
        }

    }

    if(flagmostro==0)
    {

        printf("no hay empleados que listar\n");

    }


    return ok;
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
    system("cls");
    printf("   menu de ordenamiento\n\n");
    int criterio;
    utn_getEntero(&criterio,100,"ingrese 1 para ordenamiento ascendente o 0 para ordenamiento descendente:","Error,Opcion invalida\n",0,1);

    switch(menuOrdenaPor())
    {

    case 1:
        ll_sort(pArrayListEmployee,cmpId,criterio);
        printf("ordenamiento realizado\n");
        break;
    case 2:
        ll_sort(pArrayListEmployee,cmpNombre,criterio);
        printf("ordenamiento realizado\n");
        break;
    case 3:
        ll_sort(pArrayListEmployee,cmpHoras,criterio);
        printf("ordenamiento realizado\n");
        break;
    case 4:
        ll_sort(pArrayListEmployee,cmpSueldo,criterio);
        printf("ordenamiento realizado\n");
        break;

    }

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

    int ok=0;
    int tam=ll_len(pArrayListEmployee);
    FILE* archivo=fopen(path,"w");
    Employee* unEmpleado=(Employee*) employee_new();

    if (path!=NULL&&pArrayListEmployee!=NULL&&archivo!=NULL)
    {
        fprintf(archivo, "id,nombre,horasTrabajadas,sueldo\n");
        for (int i=0; i<tam;i++)
        {
            unEmpleado=ll_get(pArrayListEmployee,i);
            fprintf(archivo,"%d,%s,%d,%d\n",unEmpleado->id,unEmpleado->nombre,unEmpleado->horasTrabajadas,unEmpleado->sueldo);
        }
        ok = 1;
    }

    return ok;

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
    int ok=0;
    int escrito;
    int tam=ll_len(pArrayListEmployee);
    Employee* unEmpleado=(Employee*) employee_new();
    FILE* archivo=fopen(path,"wb");

    if (path!=NULL&&pArrayListEmployee!=NULL&&archivo!=NULL&&unEmpleado!=NULL)
    {
        for (int i=0;i<tam;i++)
        {
            unEmpleado = ll_get(pArrayListEmployee,i);
            escrito=fwrite(unEmpleado,sizeof(Employee),1,archivo);

            if (escrito<1)
            {
                return ok;
            }

        }

        ok = 1;
    }

    return ok;


}

int opcionModifica(void)
{
    int modifica;

    printf("1 modifica id:\n");
    printf("2 modifica nombre:\n");
    printf("3 modifica horas trabajadas:\n");
    printf("4 modifica sueldo:\n");
    printf("5 salir\n");
    utn_getEntero(&modifica,100,"opcion:","Error.Opcion invalida\n",1,5);



    return modifica;



}
int buscoPorId(LinkedList* pArrayListEmployee,int id)
{
    int esta=0;
    int tam=ll_len(pArrayListEmployee);
    Employee* empleado;

    for(int i=0; i<tam; i++)
    {
        empleado=ll_get(pArrayListEmployee,i);

        if(empleado->id==id)
        {
            esta=1;
            break;
        }


    }

    return esta;

}
int cmpId(void* a,void* b)
{
    int retorno=0;
    Employee* empleadoA;
    Employee* empleadoB;

    if(a!=NULL&&b!=NULL)
    {
        empleadoA=(Employee*)a;
        empleadoB=(Employee*)b;

        if(empleadoA->id>empleadoB->id)
        {
            retorno=1;

        }
        else if(empleadoA->id<empleadoB->id)
        {
            retorno=-1;

        }


    }

    return retorno;

}
int cmpSueldo(void* a ,void*b)
{

    int retorno=0;
    Employee* empleadoA;
    Employee* empleadoB;

    if(a!=NULL&&b!=NULL)
    {
        empleadoA=(Employee*)a;
        empleadoB=(Employee*)b;

        if(empleadoA->sueldo>empleadoB->sueldo)
        {
            retorno=1;

        }
        else if(empleadoA->sueldo<empleadoB->sueldo)
        {
            retorno=-1;

        }


    }

    return retorno;


}
int cmpNombre(void* a,void*b)
{
    int retorno=0;
    Employee* empleadoA;
    Employee* empleadoB;

    if(a!=NULL&&b!=NULL)
    {
        empleadoA=(Employee*)a;
        empleadoB=(Employee*)b;


        retorno=strcmp(empleadoA->nombre,empleadoB->nombre);

    }


    return retorno;


}
int cmpHoras(void* a,void* b)
{

    int retorno=0;
    Employee* empleadoA;
    Employee* empleadoB;

    if(a!=NULL&&b!=NULL)
    {
        empleadoA=(Employee*)a;
        empleadoB=(Employee*)b;

        if(empleadoA->horasTrabajadas>empleadoB->horasTrabajadas)
        {
            retorno=1;

        }
        else if(empleadoA->horasTrabajadas<empleadoB->horasTrabajadas)
        {
            retorno=-1;

        }


    }

    return retorno;

}
int menuOrdenaPor(void)
{
    int retorno;
    printf("1 ordenar por id\n");
    printf("2 ordenar por nombre\n");
    printf("3 ordenar por horas trabajadas\n");
    printf("4 ordenar por sueldo\n");
    utn_getEntero(&retorno,100,"opcion:","Error.Opcion invalida\n",1,4);
    return retorno;

}

