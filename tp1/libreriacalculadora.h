#ifndef LIBRERIACALCULADORA_H_INCLUDED
#define LIBRERIACALCULADORA_H_INCLUDED
/*
* brief recibe dos numeros A y B , retorna la suma.
* param el primero numero para realizar la suma.
* param el segundo numero utilizado para la suma.
* return retorna el valor de la suma.
*/
int sumar(int a,int b);
/*
* brief recibe un numero y le realiza su factorial.
* param el numero a realizarle el factorial.
* return retorna el resultado del factorial.
*/
long long int factorear(int a);
/*
* brief permite al usuario ingresar un numero.
* param recibe el puntero a la direccion de memoria donde se va a guardar el numero.
*
*/
void ingresarPrimerOperando(int *a);
/*
* brief permite al usuario ingresar un numero.
* param recibe el puntero a la direccion de memoria donde se va a guardar el numero.
*
*/
void ingresarSegundoOperando(int *a);
/*
* brief recibe un numero A y le resta un numero B.
* param el numero minuendo.
* param el numero sustraendo.
* return retorna el resultado de la resta.
*/
int restar(int a,int b);
/*
* brief recibe dos numeros A y B, realiza la division.
* param el numero dividiendo.
* param el numero divisor.
* return retorna el cociente.
*/
float dividir(int a,int b,float *c);
/*
* brief realiza la multiplicacion entre dos numeros A y B.
* param el primer factor A.
* param el segundo factor B.
* return retorna el producto de A*B.
*/
int multiplicar(int a,int b);
/*
* brief el menu de opciones de la calculadora.
* param recibe el numero A para mostrarlo en pantalla.
* param recibe el numero B para mostrarlo en pantalla.
* return retorna la opcion que ingrese el usuario
*/
int menuOpciones(int a,int b,int c,int d);


#endif // LIBRERIACALCULADORA_H_INCLUDED
