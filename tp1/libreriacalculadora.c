#include <stdio.h>
#include <stdlib.h>

void ingresarPrimerOperando(int *a)
{

    printf("ingrese el primer operando:");
    scanf("%d",a);

}
void ingresarSegundoOperando(int *a)
{
    printf("ingrese el segundo operando:");
    scanf("%d",a);

}

int menuOpciones(int a,int b,int c,int d)
{
    int opcion;
    puts("\tcalculadora\n\n");
    if(c)
    {
        printf("1)ingresar primer operando (A=%d)\n",a);
    }
    else
    {
        printf("1)ingresar primer operando (A=X)\n");
    }

    if(d)
    {
        printf("2)ingresar segundo operando (B=%d)\n",b);
    }
    else
    {
        printf("2)ingresar segundo operando (B=Y)\n");
    }

    puts("3)Calcular todas las operaciones\n\ta)Calcular la suma(A+B)\n\tb)Calcular la resta(A-B)\n\tc)Calcular la division(A/B)\n\tc)Calcular la multiplicacion(A*B)\n\td)calcular el factorial(A!)");
    puts("4)Mostrar resultados:");
    puts("5)Salir");
    scanf("%d",&opcion);

    return opcion;

}

int sumar(int a,int b)
{
    int resultado=a+b;
    return resultado;
}
int restar (int a,int b)
{
    int resultado=a-b;
    return resultado;
}
float dividir(int a,int b,float *c)
{
    int valorRetorno;
    if(b==0)
    {
        valorRetorno=-1;
    }
    else
    {
        *c=(float)a/b;
        valorRetorno=0;
    }

    return valorRetorno;


}
int multiplicar(int a,int b)
{
    int resultado=a*b;
    return resultado;
}

long long int factorear(int a)
{
    int valorRetorno=1;
    if(a>0)
    {
        for (int i=1; i<=a; i++)
        {
            valorRetorno=valorRetorno*i;
        }


    }
    else
    {
        valorRetorno=-1;
    }
    return valorRetorno;

}





