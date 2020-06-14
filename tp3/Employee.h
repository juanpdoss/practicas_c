#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;
#include "LinkedList.h"

//recibo todo los parametros enteros como chars para poder aplicarles validacion con mi biblioteca utn dentro de los setters.

/** \brief para reservar espacio en memoria dinamica para un empleado
 *
 * \param vacio
 * \param vacio
 * \return retorna un puntero del tipo employee en donde empiece el archivo en memoria dinamica
 *
 */

Employee* employee_new();
/** \brief para reservar espacio en memoria dinamica para un empleado y escribir en sus campos
 *
 * \param cadena de id
 * \param cadena de nombre
 * \param cadena de horas
 * \param cadena de sueldo
 * \return retorna un puntero del tipo employee con sus campos ya setteados
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
/** \brief para eliminar un empleado de memoria dinamica
 *
 * \param el empleado a ser borrado
 * \return vacio
 *
 */

void employee_delete(Employee* thiss);
/** \brief para establecer un id en el campo id de un empleado
 *
 * \param un empleado
 * \param el id a establecer
 * \return int
 *
 */


int employee_setId(Employee* thiss,int id);
/** \brief para conseguir el id del empleado pasado como parametro
 * \param el empleado
 * \param el puntero de la variable donde se guardara el id
 * \return int
 *
 */

int employee_getId(Employee* thiss,int* id);
/** \brief para establecer un nombre en el campo nombre del empleado
 *
 * \param un empleado
 * \param el nombre que se copiara en el campo nombre del empleado
 * \return int
 *
 */


int employee_setNombre(Employee* thiss,char* nombre);
/** \brief para conseguir el nombre del empleado pasado como parametro
 *
 * \param el empleado
 * \param array donde se guardara el nombre del empleado
 * \return int
 *
 */


int employee_getNombre(Employee* thiss,char* nombre);
/** \brief para establecer un nombre en el campo nombre del empleado
 *
 * \param
 * \param
 * \return
 *
 */


int employee_setHorasTrabajadas(Employee* thiss,int horasTrabajadas);
/** \brief para conseguir las horas trabajadas del empleado pasado como parametro
 *
 * \param el empleado
 * \param puntero a la variable donde se guardaran las horas trabajadas
 * \return
 *
 */

int employee_getHorasTrabajadas(Employee* thiss,int* horasTrabajadas);
/** \brief para establecer el sueldo en el campo sueldo de un empleado
 * \param el empleado
 * \param el sueldo a establecer
 * \return int
 *
 */


int employee_setSueldo(Employee* thiss,int sueldo);
/** \brief para conseguir el sueldo del empleado pasado como parametro
 *
 * \param el empleado
 * \param el puntero a la variable donde se guardara el sueldo
 * \return
 *
 */

int employee_getSueldo(Employee* thiss,int* sueldo);





#endif // employee_H_INCLUDED
