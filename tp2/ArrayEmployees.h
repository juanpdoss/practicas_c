#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;


}Employee;
#endif // ARRAYEMPLOYEES_H_INCLUDED
/*
*  \brief para mostrar el total de salarios y su promedio, y listar los empleados que superen el promedio
*  \param el array de empleados
*  \param el tamaño del array
*
*/
void informeMayorSueldo(Employee array[],int len);
/*
*   \brief to load information in the employees array
*   \n param the list of employees
*   \the size of the array
*/


void hardcodearEmpleados(Employee array[],int len);
/*
*  \brief to show the menu from the option 4 in main
*
*  \return the option chosen by the user
*/
int menuOption4(void);

/*
* \brief show one employee from the array Employees in the screen
* \param the employee from the employees array
*
*/
void showEmployee(Employee array);
/*
* \brief to show the menu from the "modifica" section
*
*/
int menuModifica(void);

/*
*   \brief to search the first free place in the array
*   \param the employees array
*   \param the size of the employees array
*   \param return -1 if error[no more space in the array, invalid len or null pointer]
*          or the location of the first free place in the array
*/

int searchFreePlace(Employee* array,int len);



/* \brief to show the options menu to the user
*
*   \return the option chosen by the user
*/

int showMenu(void);

/** \brief  To indicate that all position in the array are empty
*           this function put the flag (isEmpty) in TRUE in all
*           position of the array
*   \param list Employee[] array of employees
*   \param len int Array length
*   \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if O ok
*
*/

int initEmployees(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
 *         in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space]- (0) if Ok
*/

int addEmployee(Employee* list, int id, char name[],char lastName[],float salary,int sector,int freePlace);
/** \brief find an Employee by Id en returns the index position in array.
 *  \param list Employee*
 *  \param len int
 *  \param id int
 *  \return Return employee index position or (-1) if [Invalid length or NULL
 *   pointer received or employee not found]
 *
*/

int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
  * \param list Employee
    \param len int
  * \param id int
  * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
    find a employee] - (0) if Ok
  *
  */

int removeEmployee(Employee* list, int len, int id);
/** \brief Sort the elements in the array of employees, the argument order
  *  indicate UP or DOWN order
  * \param list Employee
  * \param len int
  * \param order int  [1] indicate UP - [0] indicate DOWN
  * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
  *
  */
int sortEmployees(Employee* list, int len, int order);

/** \brief print the content of employees array
  * \param list Employee*
  * \param length int
  * \return int
  *
  */

int printEmployees(Employee* list, int length);




