// Lista enlazada

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Case1
node_t *createList(int first_value) {
  node_t *head = NULL;
  head = malloc(sizeof(node_t));

  if (head == NULL) {
    printf("La lista no ha sido creada todavia.");
    return NULL;
  }

  head->data = first_value;
  head->next = NULL;

  printf("\n\nLa lista ha sido creada con el valor de %d!\n", head->data);
  return head;
}

/////////////////////////////////////////////
/////////////////////////////////////////////

// Case2
/* Esta funcion tiene que recibir la direccion del head y tiene que imprimir la
 * lista, es de tipo void.
 */
void printList(node_t* head) {

  if (head == NULL)
  {
    printf("La lista se encuentra vacia.\n");
  }

  printf("La lista contiene actualmente los siguientes valores: \n\n");

  node_t* currentNode = head;
  while (currentNode != NULL)
  {
    printf("%d \n", currentNode->data);
    currentNode = currentNode->next;
  }

  printf("\n\n\n");
}

/////////////////////////////////////////////
/////////////////////////////////////////////

// Case3
/*Esta funcion crea un nuevo nodo y agrega un elemento al final de la lista.
 * Recibe el puntero de head y el valor que se desea agregar. Regresa un 1 en
 * caso de que el elemento haya sido agregado exitosamente o 0 en caso
 * contrario*/
int pushBack(node_t *head, int value) {
  int result = 0;
  node_t *newNode = malloc(sizeof(node_t));
  newNode->data = value;
  newNode->next = NULL;

  node_t *currentNode = head;

  while (currentNode->next != NULL) {
    currentNode = currentNode->next;
  }

    /*Despues de que sale del bucle, cuando currentNode->next s� es NULL
    asignele la direccion de memoria de newNode ya con eso se le agrega el ultimo nodo a la lista.*/
  currentNode->next = newNode;

  result = 1;
  return result;
}

/////////////////////////////////////////////
/////////////////////////////////////////////

//Case4
/*Esta funcion crea un nuevo nodo y lo agrega al inicio de la lista.
Recibe el puntero a head y el valor del elemento a ingresar.
Devuelve un 1 en el caso de que el nodo se haya agregado correctamente y un cero en caso contrario*/
int pushFront(node_t **head, int value)
{
  int result = 1;
  node_t *newNode = malloc(sizeof(node_t));
  newNode->data = value;
  newNode->next = *head;

  *head = newNode;
  return result;
}

/////////////////////////////////////////////
/////////////////////////////////////////////

//Case5
/*Se elimina el ultimo nodo de la lista. Recibe el puntero a head y muestra el valor reliminado. Despliega un mensaje afirmativo en caso de que se haya podido eliminar el ultimo nodo satisfactoriamente, o un mensaje negativo en caso contrario*/
int popBack(node_t* head)
{

  if(head == NULL)
  {
    printf("Todos los elementos de la lista han sido eliminados");
    return -1;
  }

  int valueErased;

  if(head->next == NULL)
  {
    valueErased = head->data;
    free(head);
    head = NULL;
    return valueErased;
  }

  node_t *currentNode = head;
  while(currentNode->next->next != NULL)
    {
      currentNode = currentNode->next;
    }

  valueErased = currentNode->next->data;
  free(currentNode->next);
  currentNode->next = NULL;

  return valueErased;
}

/////////////////////////////////////////////
/////////////////////////////////////////////

// Case6
/*Esta funcion recibe el puntero al puntero al primer elemento de la lista y elimina el primer nodo de la lista. Devuelve el valor eliminado*/
int popFront(node_t **head)
{
  if (head == NULL)
  {
    printf("La lista se encuentra vacia.");
    return -1;
  }

  node_t* currentNode = *head;
  int value_erased = currentNode->data;
  *head = currentNode->next;
  free(currentNode);
  return value_erased;
}

/////////////////////////////////////////////
/////////////////////////////////////////////

// Case7
/*Agrega un elemento en cualquier parte de la lista.
Recibe como parametro el puntero al puntero que apunta al primer elemento de la lista;
la posicion en la cual desea agregar el nuevo elemento y el valor del elemento que desea agregar.
Regresa 1 en caso de haber agregado correctamente el elemento o 0 en caso contrario.*/

int insertNode(node_t **head, int pos, int value)
{
  int result;
  int count = 0;

  if(head == NULL|| *head == NULL)
  {
    printf("La lista se encuentra vacia");
    result = 0;
    return result;
  }

  if(pos == 0)
  {
    result = 1;
    node_t* newNode = malloc(sizeof(node_t));
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
    return result;
  }

    node_t* newNode = malloc(sizeof(node_t));
    newNode->data = value;
    newNode->next = NULL;
    node_t* currentNode = *head;

   while (currentNode->next != NULL && count<(pos-1))
   {
     currentNode = currentNode->next;
     count ++;
   }

   if(currentNode->next != NULL && count==(pos-1))
   {
      newNode->next = currentNode->next;
      currentNode->next = newNode;
      result = 1;
      return result;
   }

   if(currentNode->next == NULL && count==(pos-1))
   {
      newNode->next = currentNode->next;
      currentNode->next = newNode;
      result = 1;
      return result;
   }

   if (currentNode->next == NULL && count<(pos-1))
   {
     printf("La lista no tiene la cantidad de elementos indicada. ");
     result = 0;
     return result;
   }
  return result;
}
/////////////////////////////////////////////
/////////////////////////////////////////////


// Case8

/*Remueve un nodo en cualquier parte de la lista.
Recibe el puntero al puntero del head y la posicion que se quiere eliminar*/

int removeNode(node_t **head, int pos)
{
  int result = 0;
  int count = 1;
  node_t* currentNode;

  if (*head == NULL)
  {
    //result = 0;
    return result;
  }

  if(pos == 1)
  {
    currentNode = (*head)->next;
    free(*head);
    *head = currentNode;
    result = 1;
    return result;
  }

  currentNode = *head;
  while (currentNode->next!=NULL && count<(pos-1))
  {
    currentNode = currentNode->next;
    count++;
  }

  node_t* tempNode;
  if (currentNode->next!=NULL && count==(pos-1))
  {
    tempNode=currentNode->next;
    currentNode->next = tempNode->next;
    free(tempNode);
    result = 1;
    return result;
  }


  //printf("La lista tiene menor cantidad de elementos que la posicion elegida");

  return result;
}


/////////////////////////////////////////////
/////////////////////////////////////////////


// Case9

/*Libera toda la memoria que ha sido asignada a la lista.
Recibe el puntero al primer nodo de la lista*/

int freelist(node_t** head)
{
  if (*head == NULL)
  {
    printf("La lista esta vacia.");
    return 1;
  }

  while((*head)->next != NULL)
  {
    node_t *currentNode = (*head)->next;
    free(*head);
    *head = currentNode;
  }

  free(*head);
  *head = NULL;
  return 1;
}


/////////////////////////////////////////////
/////////////////////////////////////////////


// Case 10

/*Se obtiene el valor del elemento de la posicion que se solicite en la lista.
Recibe el puntero al primer nodo de la lista, la posicion para la cual se desea obtener el valor y
un puntero a int donde se almacenara unS 1 en caso de que se obtenga el valor correctamente o 0 en caso de que no*/

int getElement(node_t* head, int pos, int* valid)
{
  int count;
  *valid = 0;
  int retornar;

  if (head == NULL)
  {
    *valid = 0;
  }

  for(count = 0; count<pos;)
  {
    node_t *currentNode = head;
    while (currentNode->next != NULL)
    {
      if (count == (pos-1))
      {
        *valid = 1;
        retornar = currentNode->data;
        return retornar;
      }

      currentNode = currentNode->next;
      count++;
    }

    if (count == pos-1)
    {
      *valid = 1;
      retornar = currentNode->data;
      return retornar;
    }

    *valid = 0;
    return retornar;
  }

  return retornar;
}


/////////////////////////////////////////////
/////////////////////////////////////////////


// Case 11
/*Imprime en consola el valor del elemento que se solicite, seguido de un espacio, sin cambios de linea.
La lista en este caso es de tipo void. Recibe como parametro la posicion del elemento que se desea imprimir*/

void printElement(node_t* head, int pos)
{
  int count;

  if(head == NULL)
  {
    printf("La lista esta vacia");
  }

  for (count = 0; count<pos; count++)
  {
    node_t* currentNode = head;
    while (currentNode->next != NULL)
    {
      if (count == (pos-1))
      {
        printf("El valor del elemento es: %d ", currentNode->data);
      }
      currentNode = currentNode->next;
      count++;
    }

    if (count == pos-1)
    {
      printf("El valor del elemento: %d ", currentNode->data);
    }

    if (count<(pos-1))
    {
      printf("La lista no tiene esa cantidad de elementos.");
      break;
    }
  }
}


/////////////////////////////////////////////
/////////////////////////////////////////////


// Case 12
/*Esta funcion ordena la lista en forma ascendente si se selecciona la opcion 'a'
o en forma descendente si se selecciona la opcion 'd', para cualquier otra letra seleccionada la funcion no hace nada
Recibe como parametro el puntero al primer elementp de la lista*/

/*
void swap(int* valorA, int* valorB)
{
  int temp = *valorA;
  *valorA = *valorB;
  *valorB = temp;
}

void sortList(node_t* head)
{
  while (head == NULL)
  {
    printf("la lista esta vacia");
  }

  node_t* currentNode = head;

  while (currentNode->next != NULL)
  {
    if (currentNode->data > currentNode->next->data)
    {
      swap(&currentNode->data, &currentNode->next->data);
      printf("%d\n", currentNode->data);
    }
    else
    {
      //printf("%d\n", currentNode->data);
      currentNode = currentNode->next;
    }


  }
}
*/