#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn_biblioteca.h"


Employee* employee_new()
{


    return  (Employee*) malloc(sizeof(Employee));

}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{

    Employee* thiss=employee_new();


    if(thiss!=NULL)

    {


        if(employee_setId(thiss,atoi(idStr))&&employee_setHorasTrabajadas(thiss,atoi(horasTrabajadasStr))&&employee_setNombre(thiss,nombreStr)&&employee_setSueldo(thiss,atoi(sueldoStr)))
        {


            return thiss;

        }

    }

    return NULL;
    employee_delete(thiss);



}
void employee_delete(Employee* thiss)
{

    free(thiss);


}

int employee_setId(Employee* thiss,int id)
{
    int ok=0;


        if(thiss!=NULL&&id>=0)
        {

            thiss->id=id;
            ok=1;

        }


    return ok;
}
int employee_getId(Employee* thiss,int* id)
{
    int ok=0;

    if(thiss!=NULL&&id!=NULL)
    {
        *id=thiss->id;
        ok=1;


    }


    return ok;


}

int employee_setNombre(Employee* thiss,char* nombre)
{
    int ok=0;

    if(thiss!=NULL&&nombre!=NULL&&strlen(nombre)<128)
    {

        strcpy(thiss->nombre,nombre);
        ok=1;
    }


    return ok;


}
int employee_getNombre(Employee* thiss,char* nombre)
{
    int ok=0;

    if(thiss!=NULL&&nombre!=NULL)
    {

        strcpy(nombre,thiss->nombre);
        ok=1;


    }



    return ok;

}

int employee_setHorasTrabajadas(Employee* thiss,int horasTrabajadas)
{
    int ok=0;


        if(thiss!=NULL)
        {
            thiss->horasTrabajadas=horasTrabajadas;
            ok=1;

        }

    return ok;


}
int employee_getHorasTrabajadas(Employee* thiss,int* horasTrabajadas)
{
    int ok=0;

    if(thiss!=NULL&&horasTrabajadas!=NULL)
    {
        *horasTrabajadas=thiss->horasTrabajadas;
        ok=1;

    }


    return ok;


}

int employee_setSueldo(Employee* thiss,int sueldo)
{
    int ok=0;

        if(thiss!=NULL)
        {

            thiss->sueldo=sueldo;
            ok=1;

        }


    return ok;


}
int employee_getSueldo(Employee* thiss,int* sueldo)
{
    int ok=0;



    if(thiss!=NULL&&sueldo!=NULL)
    {
        *sueldo=thiss->sueldo;
        ok=1;


    }


    return ok;




}
