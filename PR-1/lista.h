#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
/**
 * TDA Pila.
 * @author Pablo Lencina, Federico Esteche
 */

typedef struct celda
{
  int elementos[4];
  struct celda* proxima_celda;
} celda_t;

typedef struct lista_eficiente
{
  unsigned int cantidad_elementos;
  celda_t* primera_celda;
} *lista_t;

 //Funciones
 /**Crea una lista vacía y la retorna.*/
 lista_t lista_crear();

/**Inserta el elemento elem en la posición pos de la lista. Sobrescribe el valor existente en la posición
   indicada, o agrega un nuevo elemento si la posición coincide con la cantidad de elementos.
   Si procede exitosamente retorna verdadero. En otro caso retorna falso.
 */
int lista_insertar(lista_t lista, unsigned int pos, int elem) ;

 /**Elimina el elemento en la posición pos. Reacomoda la lista adecuadamente al eliminar en posiciones
    intermedias. Retorna verdadero si procede con éxito, falso en caso contrario. Si la posición no es válida,
    aborta con exit status LST_POS_INV.
  */
 int lista_eliminar(lista_t lista, unsigned int pos) ;

 /**Retorna la cantidad de elementos de la lista. Si la lista no está inicializada, el programa aborta
    con exit status LST_NO_INI.
  */
 int lista_cantidad(lista_t lista);

 /**Retorna el elemento en la posición pos de la lista. Si la posición no es válida, aborta con exit
    status LST_POS_INV.
  */
 int lista_obtener(lista_t lista, unsigned int pos);

/**Inserta el elemento elem en la última posición de la lista.
   Si la lista no está inicializada, aborta con exit status LST_NO_INI.
 */
int lista_adjuntar(lista_t lista, int elem);

/**Libera la memoria ocupada por la lista y le asigna NULL. Retorna verdadero en caso de éxito.
   Si la lista no está inicializada, aborta con exit status LST_NO_INI.
 */
int lista_destruir(lista_t* lista);
#endif // LISTA_H_INCLUDED
