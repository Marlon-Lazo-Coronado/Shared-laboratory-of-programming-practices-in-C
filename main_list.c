// Main file for list function
#define _CRTDBG_MAP_ALLOC
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
  node_t* testlist = NULL;
  
  int opcion;
  int elemento;
  char desicion;
  char enter;
  int es_lista_valida;
  int elementoEliminado;
  int posicion;

  printf("*********************Bienvenido al programa para crear listas enlazadas**********************\n");

  printf("\n\nEstas son las opciones del menu:\n\n");

  while (1)
  {
    printf("**********************************************************\n");
    printf("**********************************************************\n");
    printf("1.  Crear Lista\n");
    printf("2.  Mostrar lista\n");
    printf("3.  Agregar un elemento al final de la lista\n");
    printf("4.  Agregar un elemento al principio de la lista\n");
    printf("5.  Eliminar un elemento del final de la lista\n");
    printf("6.  Eliminar un elemento del principio de la lista\n");
    printf("7.  Agregar un elemento en cualquier posicion de la lista\n");
    printf("8.  Eliminar un elemento de cualquier posicion de la lista\n");
    printf("9.  Librar nodos\n");
    printf("10  Averiguar el elemento deseado de la lista\n");
    printf("11  Averiguar el elemento deseado de la lista (printf no return)\n");
    printf("12. Ordenar la lista\n");
    printf("13. Salir\n");
    printf("**********************************************************\n");
    printf("**********************************************************\n");

    printf("\n\nElija una opcion del menu anterior:  ");
    scanf("%d", &opcion);
    
    if (testlist == NULL)
    {
      while (opcion != 1)
      {
        printf("\nLa lista aun no ha sido creada. Primero debe elegir la opcion 1: ");
        scanf("%d", &opcion);
      }
    }

    switch (opcion)
    {
      case 1:
        printf("\n\nDigite el valor del primer elemento de la lista: ");

        scanf("%d", &elemento);
        testlist = createList(elemento);
        printf("\n\n");
        printf("Desea continuar modificando la lista?. Digite 'y' si desea continuar, o 'n' en caso contrario\n\n");
        scanf(" %c", &desicion);
        printf("\n");

        if (desicion == 'n') {
          printf("\nRegrese pronto!\n\n");
        } else {
        }
        system("clear");
        break;

      /////////////////////////////////////////////
      /////////////////////////////////////////////

      /*
      case 2:
        printf("Presione 'Enter' para desplegar los valores de la lista: \n\n");
        getchar();
        getchar();


        printList(testlist);

        printf("Desea continuar modificando la lista?. Digite 'y' si desea continuar, o 'n' en caso contrario\n\n");
        scanf(" %c", &desicion);
        printf("\n");

        if (desicion == 'n') {
          printf("\nRegrese pronto!\n\n");
          //return 0;
        } else {
        }
        system("clear");
        break;
    

        /////////////////////////////////////////////
        /////////////////////////////////////////////

    
      case 3:
        printf("Digite el valor del elemento que desea agregar al final de la lista: ");
        scanf("%d", &elemento);
  
        es_lista_valida = pushBack(testlist, elemento);
        if(es_lista_valida == 0)
        {
          printf("La lista no fue creada correctamente");
        }
        else
        {
          printf("\n");
          printf("Se ha agregado el valor %d al final de la lista!\n\n", elemento);
        }

        printf("Desea continuar modificando la lista?. Digite 'y' si desea continuar, o 'n' en caso contrario\n\n");
        scanf(" %c", &desicion);
        printf("\n");

        if (desicion == 'n') {
          printf("\nRegrese pronto!\n\n");
          //return 0;
        } else {
        }
        system("clear");
        break;
    

        /////////////////////////////////////////////
        /////////////////////////////////////////////

    
      case 4:
        printf("Digite el valor del elemento que desea agregar al principio de la lista: ");
        scanf("%d", &elemento);

        es_lista_valida = pushFront(&testlist, elemento);

        if(es_lista_valida == 0)
        {
          printf("El elemento no fue agregado correctamente.");
        }
        else
        {
          printf("\n");
          printf("Se ha agregado el valor %d al principio de la lista!\n\n", elemento);
        }

        printf("Desea continuar modificando la lista?. Digite 'y' si desea continuar, o 'n' en caso contrario\n\n");
        scanf(" %c", &desicion);
        printf("\n");

        if (desicion == 'n')
        {
          printf("\nRegrese pronto!\n\n");
          //return 0;
        } else
        {
        
        }
        system("clear");
        break;


        /////////////////////////////////////////////
        /////////////////////////////////////////////

      case 5:
        printf("Presione 'Enter' para eliminar el ultimo elemento de la lista: \n\n");
        getchar();
        getchar();

        elementoEliminado = popBack(testlist);

        if(testlist == NULL)
        {
          printf("La lista ahora esta vacia\n");
        }

        printf("El ultimo elemento de la lista cuyo valor es '%d' ha sido eliminado satisfactoriamente.\n\n", elementoEliminado);

        printf("Desea continuar modificando la lista?. Digite 'y' si desea continuar, o 'n' en caso contrario.\n\n");
        scanf(" %c", &desicion);
        printf("\n");

        if (desicion == 'n') {
          printf("\nRegrese pronto!\n\n");
          //return 0;
        } else {
        }
        system("clear");
        break;
    

        /////////////////////////////////////////////
        /////////////////////////////////////////////

    
      case 6:
        printf("Presione 'Enter' para eliminar el primer elemento de la lista: \n\n");
        getchar();
        getchar();

        elementoEliminado = popFront(&testlist);

        printf("El primer elemento de la lista cuyo valor es '%d' ha sido eliminado satisfactoriamente.\n\n", elementoEliminado);

        printf("Desea continuar modificando la lista?. Digite 'y' si desea continuar, o 'n' en caso contrario.\n\n");
        scanf(" %c", &desicion);
        printf("\n");

        if (desicion == 'n') {
          printf("\nRegrese pronto!\n\n");
          //return 0;
        } else {
        }
        system("clear");
        break;

        /////////////////////////////////////////////
        /////////////////////////////////////////////

      case 7:
        printf("\n\nSi desea agregar el elemento al inicio de la lista presione 0; o si desea agregarlo despues, digite la posicion en la que desea agregar el elemento: ");
        scanf("%d", &posicion);
        printf("\n\n");
        printf("Ahora inserte el valor del elemento: ");
        scanf("%d", &elemento);

        es_lista_valida = insertNode(&testlist, posicion, elemento);


        if (es_lista_valida == 1 && posicion == 0)
        {
          printf("El elemento fue agregado correctamente al inicio de la lista. El valor del elemento agregado fue %d", elemento);
        }
        else if (es_lista_valida == 1 && posicion != 0)
        {
          printf("El elemento %d fue agregado correctamente en la posicion %d de la lista.", elemento, posicion);
        }
        else
        {
          printf("El elemento no se pudo agregar correctamente.");
        }

        printf("\n\n");
        printf("Desea continuar modificando la lista?. Digite 'y' si desea continuar, o 'n' en caso contrario.\n\n");
        scanf(" %c", &desicion);
        printf("\n");

        if (desicion == 'n') {
          printf("\nRegrese pronto!\n\n");
          //return 0;
        } else {
        }
        system("clear");
        break;


        /////////////////////////////////////////////
        /////////////////////////////////////////////


      case 8:
        printf("Este es el menu para remover elementos de la lista. Digite 1 si desea eliminar el primer elemento de la lista, o digite la posicion del elemento que desea eliminar: ");
        scanf("%d", &posicion);
        printf("\n\n");

        es_lista_valida = removeNode(&testlist, posicion);

        if (es_lista_valida == 0)
        {
          printf("No se ha podido eliminar el elemento.");
        }

        if(es_lista_valida == 1 && posicion == 1)
        {
          printf("Se ha podido eliminar satisfactoriamente el primer elemento de la lista!");
        }

        if(es_lista_valida == 1 && posicion > 1)
        {
          printf("Se ha podido eliminar satisfactoriamente el elemento seleccionado.");
        }

        printf("\n\n");
        printf("Desea continuar modificando la lista?. Digite 'y' si desea continuar, o 'n' en caso contrario.\n\n");
        scanf(" %c", &desicion);
        printf("\n");

        if (desicion == 'n') {
          printf("\nRegrese pronto!\n\n");
          //return 0;
        } else {
        }
        system("clear");
        break;


        /////////////////////////////////////////////
        /////////////////////////////////////////////


      case 9:
        printf("Este es el menu para liberar todos los nodos (elementos) de la lista. Presione 'Enter' para vaciar la lista.");
        getchar();
        getchar();

        es_lista_valida = freelist(&testlist);

        if (es_lista_valida == 1)
        {
          printf("La lista se pudo vaciar correctamente!. Ahora la lista se encuentra vacia.");
        }
        else
        {
          printf("No se pudo vaciar la lista correctamente.");
        }

        printf("\n\n");
        printf("Desea continuar modificando la lista?. Digite 'y' si desea continuar, o 'n' en caso contrario.\n\n");
        scanf(" %c", &desicion);
        printf("\n");

        if (desicion == 'n') {
          printf("\nRegrese pronto!\n\n");
          //return 0;
        } else {

        system("clear");
        break;
        }


        /////////////////////////////////////////////
        /////////////////////////////////////////////


      case 10:
        printf("Este es el menu para averiguar el valor del elemento en cualquier posicion de la lista. A continuacion digite la posicion de la lista para la cual desea obtener su valor: ");
        scanf("%d", &posicion);
        printf("\n\n");

        elemento = getElement(testlist, posicion, &es_lista_valida);

        if (es_lista_valida == 1)
        {
          printf("El elemento de la posicion %d, es: %d.", posicion, elemento);
        }
        else if(es_lista_valida == 0 && posicion == 0)
        {
          printf("No ha sido posible obtener el elemento solicitado.");
        }
        else
        {
          printf("La lista no tiene esa cantidad de posiciones");
        }

        printf("\n\n");
        printf("Desea continuar modificando la lista?. Digite 'y' si desea continuar, o 'n' en caso contrario.\n\n");
        scanf(" %c", &desicion);
        printf("\n");

        if (desicion == 'n') {
          printf("\nRegrese pronto!\n\n");
          //return 0;
        } else {

        system("clear");
        break;
        }


        /////////////////////////////////////////////
        /////////////////////////////////////////////


      case 11:
        printf("Este es el menu para averiguar el valor del elemento en cualquier posicion de la lista(mediante printlist y no return). A continuacion digite la posicion de la lista para la cual desea obtener su valor: ");
        scanf("%d", &posicion);
        printf("\n\n");

        printElement(testlist, posicion);

        printf("\n\n");
        printf("Desea continuar modificando la lista?. Digite 'y' si desea continuar, o 'n' en caso contrario.\n\n");
        scanf(" %c", &desicion);
        printf("\n");

        if (desicion == 'n') {
          printf("\nRegrese pronto!\n\n");
          //return 0;
        } else {

        system("clear");
        break;
        }


        /////////////////////////////////////////////
        /////////////////////////////////////////////


      //case 12:
        //  printf("Este es el menu para ordenar la lista.\n");
        //  printf("Si desea ordenar la lista en orden ascendente, oprima 'a'; si la quiere de manera descendente, oprima 'd': ");
        //  scanf(" %c", &desicion);
        //  printf("\n");

        //  if (desicion == 'a')
        //  {
        //    sortList(testlist);
        //  }

        /////////////////////////////////////////////
        /////////////////////////////////////////////

      */
    
      default:
      {
        printf("\nLa opcion ingresada no se encuentra en el conjunto de valores permitidos. Intentelo nuevamente. \n\n");
        printf("\n\n");
        system("clear");
      break;
      }
    }  
  }
  return 0;
}
