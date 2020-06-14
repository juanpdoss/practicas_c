/** \brief para cargar los empleados desde el archivo data.csv
 *
 * \param la ruta al archivo
 * \param el linked list
 * \return int
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief  para cargar los empleados desde el archivo data.bin
 *
 *
 * \param la ruta al archivo
 * \param el linked list
 * \return int
 *
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief para agregar un empleado en el linked list
 *
 * \param el linked list
 * \return int
 *
 */

int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief para editar un empleado en el linked list
 *
 * \param el linkedlist
 * \return int
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief para quitar un empleado del linked list
 *
 * \param el linkedlist
 * \return
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief para listar los empleados en el linkedlist
 *
 * \param el linkedlist
 * \return int
 *
 */

int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief para ordenar los empleados en el linkedlist
 *
 * \param el linkedlist
 * \return int
 *
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief para guardar los datos en el linkedlist como un archivo.csv
 *
 * \param la ruta y el nombre del archivo
 * \param el linkedlist
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief para guardar los datos en el linkedlist como un archivo.bin
 *
 * \param la ruta y el nombre del archivo
 * \param el likedlist
 * \return int
 *
 */

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief para mostrar al usuario el menu de modificaciones
 *
 * \param vacio
 * \param vacio
 * \return retorna la opcion elegida por el usuario
 *
 */

int opcionModifica(void);
/** \brief para buscar un id ingresado por el usuario en el linkedlist
 *
 * \param el linkedlist
 * \param el id a buscar
 * \return retorna 1 si el id es encontrado, 0 si no
 *
 */

int buscoPorId(LinkedList* pArrayListEmployee,int id);
/** \brief para mostrar el menu al usuario
 *
 * \param vacio
 * \param vacio
 * \return la opcion elegida por el usuario
 *
 */

int menu(void);
/** \brief para comprar dos empleados por sus ids
 *
 * \param puntero vacio proveniente del linked list
 * \param puntero vacio proveniente del linked list
 * \return
 *
 */

int cmpId(void* a,void* b);
/** \brief para comparar dos empleados por su sueldo
 *
 * \param puntero vacio proveniente del linked list
 * \param puntero vacio proveniente del linked list
 * \return
 *
 */

int cmpSueldo(void* a,void*b);
/** \brief para comprar dos empleados por sus nombres
 *
 * \param puntero vacio proveniente del linked list
 * \param puntero vacio proveniente del linked list
 * \return
 *
 */

int cmpNombre(void* a,void*b);
/** \brief para comparar dos empleados por sus horas trabajadas
 *
 * \param puntero vacio proveniente del linked list
 * \param puntero vacio proveniente del linked list
 * \return
 *
 */

int cmpHoras(void* a,void* b);
/** \brief para mostrar al usuario el menu de ordenamiento
 *
 * \param vacio
 * \param vacio
 * \return la opcion ingresada por el usuario
 *
 */

int menuOrdenaPor(void);

