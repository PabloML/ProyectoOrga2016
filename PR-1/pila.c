/**
 * TDA Pila.
 * @author Pablo Lencina, Marcelo Rodríguez, Leonardo E. Segovia
 * @version 1.2012.10.02
 */

#include "pila.h"
#include <stdlib.h>

#define OPERACION_EXITOSA 0
#define OPERACION_FALLIDA 1

/**
 * Crea y devuelve una pila nueva vacía.
 * @return Puntero a pila vacía, NULL si no se pudo crearla.
 */
pila_t* pila_crear(void)
{
    pila_t* pila =(pila_t*)malloc(sizeof(pila_t));
    if (pila != NULL)
    {
        pila->elemento = NULL;
        pila->proximo_elemento = NULL;
    }
    return pila;
}

/**
 * Examina el elemento que se encuentra en el tope de la pila.
 * El comportamiento de esta operación no está definido si la pila está vacía.
 * @param pila Puntero a la pila a examinar.
 * @return Elemento que se encuentra en el tope de la pila.
 */
char* tope (pila_t* pila)
{

    return pila->elemento;
}

/**
 * Elimina y devuelve el elemento que se encuentra en el tope de la pila.
 * Debe notarse que, para permitir la actualización de la referencia al primer
 * elemento de la pila, se debe utilizar un puntero (tPila*).
 * @param pila Puntero a la pila a examinar.
 * @return Elemento removido del tope de la pila.
 */
char* desapilar (pila_t* pila)
{
    /* Realizar una copia de pila, para luego liberarlo*/
    pila_t* backup = pila;
    /*Paso 1. Solicitar el elemento residente en pila.elemento*/
    char* elemento = backup->elemento;
    pila_t* siguiente = backup->proximo_elemento;
    /*Actualizamos el puntero referenciado por pila al nuevo elemento */
    pila -> proximo_elemento = siguiente;
    /* Eliminamos pila (está guardado en backup)*/
    free(backup);
    return elemento;
}

/**
 * Inserta el entero a en el tope de la pila.
 * Devuelve 0 si la inserción fue exitosa, 1 en caso contrario.
 * @param pila Puntero a la pila a examinar.
 * @param a Entero a insertar.
 * @return Código entero de error:
 *            0 (operación exitosa)
 *            1 (error desconocido)
 */
int apilar (pila_t* pila,char* str)
{
    pila_t* nuevoElemento = (pila_t*)malloc(sizeof(pila_t));
    if (nuevoElemento != NULL)
    {
        nuevoElemento->elemento = str;
        nuevoElemento->proximo_elemento;
        pila ->proximo_elemento = nuevoElemento;
        return OPERACION_EXITOSA;
    }
    else  /* Nuestro espacio de almacenamiento se agotó */
    {
        return OPERACION_FALLIDA;
    }
}

/**
 * Consulta si la pila está vacía.
 * @param pila Puntero a la pila a examinar.
 * @return Verdadero si la pila está vacía, falso en caso contrario.
 */
int pila_vacia(pila_t* pila)
{
    return pila -> elemento == NULL;
}
