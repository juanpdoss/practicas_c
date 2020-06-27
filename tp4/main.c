#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "pokemon.h"

int main()
{
    int flagCargo=0;
    char sigue='s';
    char acepta;
    LinkedList* pokemones=ll_newLinkedList();
    if(pokemones==NULL)
    {
        printf("no se consiguio memoria\n");
        exit(EXIT_FAILURE);

    }
    /*
     ("1 cargar pokemones desde archivo csv\n");
     ("2 cargar pokemones desde archivo bin\n");
     ("3 alta pokemon\n");
     ("4 modificar pokemon\n");
     ("5 baja pokemon\n");
     ("6 listar pokemones\n");
     ("7 guardar pokemones en archivo csv\n");
     ("8 guardar pokemones en archivo bin\n");
     ("9 salir\n");

    */

    do
    {
        switch(menu())
        {
        case 1:

            if(cargarDesdeTexto(pokemones))
            {
                printf("%d pokemones cargados con exito\n",ll_len(pokemones));
                flagCargo=1;
            }
            else
            {
                printf("error al cargar el archivo data.csv\n");

            }
            break;
        case 2:
            if(cargarDesdeBinario(pokemones))
            {
                printf("%d pokemones cargados con exito\n",ll_len(pokemones));
                flagCargo=1;

            }
            else
            {
                printf("error al cargar el archivo data.bin\n");

            }
            break;
        case 3:
            if(add_pokemon(pokemones))
            {
                printf("pokemon agregado con exito\n");
                flagCargo=1;
            }
            else
            {
                printf("no se pudo agregar el pokemon,revise datos ingresados.\n");
            }

            break;
        case 4:
            if(flagCargo&&!ll_isEmpty(pokemones))
            {
                if( modificaPokemon(pokemones))
                {
                    printf("pokemon modificado\n");
                }
                else
                {
                    printf("no se pudo realizar una modificacion\n");

                }

            }
            else
            {
                printf("sistema vacio");
            }
            break;
        case 5:
            if(flagCargo&&!ll_isEmpty(pokemones))
            {
                if( bajaPokemon(pokemones))
                {
                    printf("baja exitosa\n");

                }
                else
                {
                    printf("no se realizo la baja\n");
                }


            }
            else
            {
                printf("sistema vacio");

            }
            break;
        case 6:
            if(flagCargo&&!ll_isEmpty(pokemones))
            {
                list_pokemons(pokemones);

            }
            else
            {
                printf("sistema vacio");

            }

            break;
        case 7:
            if(flagCargo&&!ll_isEmpty(pokemones))
            {
                if(ordenaPokemons(pokemones))
                {
                    printf("ordenamiento exitoso\n");

                }
                else
                {
                    printf("no se pudo realizar el ordenamiento\n");

                }

            }
            else
            {
                printf("sistema vacio");

            }


            break;
        case 8:
            if(flagCargo&&!ll_isEmpty(pokemones))
            {
                if(guardarPokemonesCsv(pokemones))
                {
                    printf("pokemones guardados\n");

                }
                else
                {
                    printf("no se pudieron guardar los pokemones\n");

                }

            }
            else
            {

                printf("sistema vacio");

            }
            break;
        case 9:
            if(flagCargo&&!ll_isEmpty(pokemones))
            {
                if(guardarPokemonesBin(pokemones))
                {
                    printf("pokemones guardados\n");

                }
                else
                {
                    printf("no se pudieron guardar los pokemones\n");

                }


            }
            else
            {
                printf("sistema vacio");

            }
            break;
        case 10:

            if(!ll_isEmpty(pokemones))
            {
                system("cls");
                printf("\n\n");
                printf("ingrese s para clonar la lista de pokemones\ny guardarlos en un archivo binario de seguridad antes de salir:");
                scanf("%c",&acepta);

                if(acepta=='s')
                {

                    if(crearCopiaBinaria(pokemones))
                    {

                        printf("copia creada y guardara\n");
                        printf("presione cualquier tecla para salir\n");




                    }



                }
                else
                {
                    printf("no se creo una copia de seguridad.\ningrese cualquier tecla para salir\n");

                }



            }



            ll_clear(pokemones);

            ll_deleteLinkedList(pokemones);

            sigue='n';

            break;

        }
        printf("\n\n");
        system("pause");
        system("cls");

    }
    while(sigue=='s');




    return 0;
}
