#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "../mibiblioteca/utn_biblioteca.h"
int initEmployees(Employee* list, int len)
{
    int retorno=-1;

    if(list!=NULL&&len>=0)
    {
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty=1;
            retorno=0;
        }

    }

    return retorno;
}
int addEmployee(Employee* list, int id, char name[],char lastName[],float salary,int sector,int freePlace)
{
    int retorno =-1;


    if(list!=NULL&&id>=1000&&name!=NULL&&lastName!=NULL&&salary>=0&&sector>=0&&freePlace>=0)
    {



        strcpy(list[freePlace].name,name);
        strcpy(list[freePlace].lastName,lastName);
        list[freePlace].id=id;
        list[freePlace].salary=salary;
        list[freePlace].sector=sector;
        list[freePlace].isEmpty=0;
        retorno=0;

    }

    return retorno;



}
int showMenu(void)
{
    int option;

    printf("            ABM employees           \n\n");
    printf("1 ALTA\n");
    printf("2 MODIFICAR\n");
    printf("3 BAJA\n");
    printf("4 INFORMAR\n");
    printf("5 SALIR\n");
    printf("ingrese opcion: ");
    scanf("%d",&option);


    return option;




}
int searchFreePlace(Employee* array,int len)
{
    int retorno =-1;


    if(array!=NULL&&len>=0)
    {
        for(int i=0; i<len; i++)
        {
            if((array[i].isEmpty==1))
            {
                retorno =i;
                break;
            }



        }


    }

    return retorno;


}
int findEmployeeById(Employee* list, int len,int id)
{
    int retorno=-1;

    if(list!=NULL&&len>=0&&id>=0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id==id&&list[i].isEmpty==0)
            {
                retorno =i;
                break;

            }


        }


    }


    return retorno;
}
int menuModifica(void)
{
    int opcion;

    printf("       menu modificaciones         \n\n");
    printf("1 modificar nombre\n");
    printf("2 modificar apellido\n");
    printf("3 modificar salario\n");
    printf("4 modificar sector\n");
    scanf("%d",&opcion);


    return opcion;
}
void showEmployee(Employee array)
{



    printf("%d      %10s          %10s          %5d              %5.2f\n",array.id, array.name, array.lastName,array.sector,array.salary);





}
int printEmployees(Employee* list, int length)
{
    int flagMostro=0;
    printf("        lista de empleados          \n\n");
    printf("id           nombre             apellido           sector             salario\n\n");



    for(int i=0; i<length; i++)
    {
        if(!list[i].isEmpty)
        {
            showEmployee(list[i]);
            flagMostro=1;


        }

    }
    if(flagMostro==0)
    {
        puts("no hay empleados en el sistema\n");


    }



    return 0;

}

int menuOption4(void)
{

    int opcion;

    printf("        pantalla informes       \n\n");
    printf("1 listar empleados alfabeticamente\nordenados por apellido y sector.\n");
    printf("2 mostrar el total y promedio de los salarios\nmostrar tambien, cuantos empleados superan el promedio de salarios.\n");
    printf("3 salir\n");
    scanf("%d",&opcion);//no valido esto ya que el default del switch en main descartaria cualquier cosa que no sean las opciones.



    return opcion;

}
int sortEmployees(Employee* list, int len, int order)
{
    Employee aux;

    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(order)
            {
                if(list[i].sector<list[j].sector)
                {
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;


                }
                else if( list[i].sector==list[j].sector&&(strcmp(list[i].lastName,list[j].lastName)<0))
                {


                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;

                }


            }


        }

    }

    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(order==2)
            {
                if(list[i].sector>list[j].sector)
                {
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;


                }
                else if( list[i].sector==list[j].sector&&(strcmp(list[i].lastName,list[j].lastName)>0))
                {


                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;

                }


            }


        }

    }



    return 0;

}


void hardcodearEmpleados(Employee array[],int len)
{

    char nombres[1000][100]= {"maria","raul","antonela","zahira","robert","pepe","mario","jackichan","ogro","gandalf"};
    char apellidos[1000][100]= {"rey","arturo","astor","rosa","rojas","santos","keiko","watson","nose","ponteprino"};
    int ids[20]= {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009};
    float salarios[30]= {40009,50000,60000,70000,24566,34567,43567,34540,34674,46676};
    int sectores[]= {1,1,1,2,2,2,3,3,4,4};


    for(int i=0; i<len; i++)
    {
        array[i].salary=salarios[i];
        strcpy(array[i].name,nombres[i]);
        strcpy(array[i].lastName,apellidos[i]);
        array[i].id=ids[i];
        array[i].isEmpty=0;
        array[i].sector=sectores[i];



    }


}
void informeMayorSueldo(Employee array[],int len)
{

    int acumuladorSueldos=0;
    int contadorSueldos=0;
    float promedioSueldos;


    for(int i=0;i<len;i++)
    {
        if(array[i].isEmpty==0)
        {
            acumuladorSueldos+=array[i].salary;
            contadorSueldos++;

        }


    }

    if(contadorSueldos==0)
    {
        promedioSueldos=0;
    }
    else
    {
        promedioSueldos=(float)acumuladorSueldos/contadorSueldos;

    }

    printf("el total de sueldos suma:%d.\nEl promedio de sueldos en base a los empleados dados de alta es de:%.2f\n\n\n",acumuladorSueldos,promedioSueldos);

    printf("lista de empleados que tienen un sueldo mayor al promedio\n\n\n");


    for(int i=0;i<len;i++)
    {
        if(!array[i].isEmpty&&array[i].salary>promedioSueldos)
        {

            showEmployee(array[i]);

        }

    }

    system("pause");






}

