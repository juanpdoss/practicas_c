#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ok = 0;
    int leido;
    int i=0;
    Employee* unEmpleado[1000];

    char bufferEntrada[4][200];

    if (pFile==NULL||pArrayListEmployee==NULL)
    {

        return ok;
    }



    //fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",bufferEntrada[0], bufferEntrada[1], bufferEntrada[2], bufferEntrada[3]);

    while(!feof(pFile)&&i<1000)
    {


        leido=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]",bufferEntrada[0], bufferEntrada[1], bufferEntrada[2], bufferEntrada[3]);
        unEmpleado[i]=employee_new();


       if (leido==4)
        {

            if (unEmpleado!=NULL)
            {


                unEmpleado[i]=employee_newParametros(bufferEntrada[0], bufferEntrada[1], bufferEntrada[2], bufferEntrada[3]);

                ll_add(pArrayListEmployee,unEmpleado[i]);
                ok=1;
                i++;


            }
        }

    }


   return ok;

}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ok=0;
    int leido;
    Employee* unEmpleado;

    //no pude realizar este punto


    if (pFile==NULL||pArrayListEmployee==NULL)
    {

        return ok;
    }
    unEmpleado=employee_new();

    while (!feof(pFile))
    {


        if (unEmpleado!=NULL)
        {
            leido=fread(unEmpleado,sizeof(Employee),1, pFile);

            if (leido == 1)
            {

                ll_add(pArrayListEmployee,unEmpleado);
                ok = 1;

            }

        }

    }

    return ok;

}
