#include <stdio.h>
#include <stdlib.h>
#include "libreriacalculadora.h"
/* no me quedo otra que usar Codeblock ya que es el ide con el que explica Baus y con el cual me siento
* mas comodo, aun asi quise instalar eclipse siguiendo todos los pasos del video que nos dan y nunca
* pude lograr que compile, siempre me tira el error "build not configured correctly"
*/
int main()
{
    int a;
    int b;
    int flagPrimerOperando=0;
    int flagSegundoOperando=0;
    int flagRealizoOperaciones=0;
    float c;
    int resultado1,resultado2,resultado4,resultado5;
    float resultado3;
    char respuesta='s';
    do
    {
        switch(menuOpciones(a,b,flagPrimerOperando,flagSegundoOperando))
        {
        case 1:
            ingresarPrimerOperando(&a);
            flagPrimerOperando=1;
            system("cls");
            break;
        case 2:

            if(flagPrimerOperando)
            {
                ingresarSegundoOperando(&b);
                flagSegundoOperando=1;
            }
            else
            {
                puts("por favor, ingrese el primer numero");
                system("pause");

            }
            system("cls");
            break;
        case 3:
            if(flagSegundoOperando)
            {
                system("cls");
                resultado1=sumar(a,b);
                resultado2=restar(a,b);
                resultado3=dividir(a,b,&c);
                resultado4=multiplicar(a,b);
                resultado5=factorear(a);
                puts("operaciones realizadas");

                flagRealizoOperaciones=1;
            }
            else
            {
                puts("por favor,ingrese ambos operandos");
                system("pause");
                system("cls");
            }
            break;
        case 4:
            if(flagRealizoOperaciones)
            {
                system("cls");
                printf("el resultado de la suma es %d\n",resultado1);
                printf("el resultado de la resta es %d\n",resultado2);
                if(resultado3==-1)
                {
                    printf("error, no se puede dividir por cero\n");
                }
                else
                {
                    printf("el resultado de la division es %.2f\n",c);
                }

                printf("el resultado de la multiplicacion es %d\n",resultado4);
                if(resultado5>=1)
                {
                    printf("el resultado del factorial de A! es %d\n",resultado5);
                }
                else
                {
                    puts("error, no existe factorial para numeros negativos o para cero");
                }
            }
            else
            {
                puts("primero hay que realizar las operaciones");
                system("pause");
                system("cls");
            }
            break;
        case 5:
            respuesta='n';
            break;
        default:
            printf("utilice una opcion valida!\n");
            system("pause");
            system("cls");

        }


    }
    while(respuesta=='s');
    return 0;
}

