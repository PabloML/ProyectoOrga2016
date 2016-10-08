/**
 * TDA Pila.
 * @author Pablo Lencina, Federico Esteche
 */
#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

#define EXITO EXIT_SUCCESS
#define PIL_NO_INI 9
#define PIL_VACIA 10

/**
 * Crea y devuelve una pila nueva vacía.
 * @return Puntero al espacio de memoria donde se ubicara la pila.
 */
pila_t pila_crear(void)
{
  return (pila_t)malloc(sizeof(pila_t));
}

/**
 * Examina el elemento que se encuentra en el tope de la pila.
 * El comportamiento de esta operación no está definido si la pila está vacía.
 * @param pila Puntero a la pila a examinar.
 * @return Elemento que se encuentra en el tope de la pila.
 */
char* tope (pila_t pila)
{
  return pila->elemento;
}

/**
 * Elimina y devuelve el elemento que se encuentra en el tope de la pila.
 * Debe notarse que, para permitir la actualización de la referencia al primer
 * elemento de la pila, se debe utilizar un puntero indirecto (tPila**).
 * @param pila Puntero indirecto a la pila a examinar.
 * @return Elemento removido del tope de la pila.
 */
char* desapilar (pila_t* pila)
{
  char* element;
  /*Verifico si la pila fue inicializada*/
  if (pila==NULL)
     exit(PIL_NO_INI);
  else {
         /* Realizar una copia de pila, para luego liberarlo*/
         pila_t backup = (*pila);
         /*Verifico si la pila esta vacia*/
         if (backup == NULL)
            exit(PIL_VACIA);
         else {
               /*Paso 1. Solicitar el elemento residente en P.elem
                 Notar que es un doble puntero, así que hay que desreferenciar x2 */
               element = backup->elemento;
               pila_t next = backup->proximo_elemento;
               /*Actualizamos el puntero referenciado por pila al nuevo elemento */
               (*pila) = next;
               /* Eliminamos P (está guardado en backup)*/
               free(backup);
              }
       }
  return element;
}

/**
 * Inserta el entero a en el tope de la pila.
 * Devuelve 0 si la inserción fue exitosa, 1 en caso contrario.
 * @param pila Puntero indirecto a la pila a examinar.
 * @param a Entero a insertar.
 * @return Código entero de error:
 *            0 (operación exitosa)
 *            1 (error desconocido)
 */
int apilar (pila_t* pila,char* str)
{
  /*Verifico si la pila fue inicializada*/
  if (pila==NULL)
     exit(PIL_NO_INI);
  else {
         pila_t element = (pila_t)malloc(sizeof(pila_t));
         if (element != NULL)
            {
             element->elemento = str;
             element->proximo_elemento = (*pila);
             (*pila) = element;
         return EXITO;
    }
    else  /* Nuestro espacio de almacenamiento se agotó */
         {
           return EXIT_FAILURE;
         }
       }
}

/**
 * Consulta si la pila está vacía.
 * @param pila Puntero a la pila a examinar.
 * @return Verdadero si la pila está vacía, falso en caso contrario.
 */
int pila_vacia(pila_t pila)
{
  return pila==NULL;
}
