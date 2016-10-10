#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
/**
 * TDA Pila.
 * @author Pablo Lencina, Federico Esteche
 */

typedef struct pila
{
    char* elemento;
    struct pila* proximo_elemento;
} *pila_t;

/**
 * Crea y devuelve una pila nueva vac�a.
 * @return Puntero a pila vac�a.
 */
pila_t pila_crear(void);

/**
 * Examina el elemento que se encuentra en el tope de la pila.
 * El comportamiento de esta operaci�n no est� definido si la pila est� vac�a.
 * @param pila Puntero a la pila a examinar.
 * @return Elemento que se encuentra en el tope de la pila.
 */
char* tope (pila_t pila);

/**
 * Elimina y devuelve el elemento que se encuentra en el tope de la pila.
 * Debe notarse que, para permitir la actualizaci�n de la referencia al primer
 * elemento de la pila, se debe utilizar un puntero indirecto (tPila**).
 * @param pila Puntero indirecto a la pila a examinar.
 * @return Elemento removido del tope de la pila.
 */
char* desapilar (pila_t* pila);

/**
 * Inserta el entero a en el tope de la pila.
 * Devuelve 0 si la inserci�n fue exitosa, 1 en caso contrario.
 * @param pila Puntero indirecto a la pila a examinar.
 * @param a Entero a insertar.
 * @return C�digo entero de error:
 *            0 (operaci�n exitosa)
 *            1 (error desconocido)
 */
int apilar (pila_t* pila,char* str);

/**
 * Consulta si la pila est� vac�a.
 * @param pila Puntero indirecto a la pila a examinar.
 * @return Verdadero si la pila est� vac�a, falso en caso contrario.
 */
int pila_vacia(pila_t pila);
#endif // PILA_H_INCLUDED
