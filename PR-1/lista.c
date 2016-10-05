#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/**
 * TDA Lista.
 * @author Pablo Lencina, Federico Esteche
 */

/**Crea una lista vacía y la retorna.
  */
  lista_t lista_crear(void){
    lista_t* lista =(lista_t*)malloc(sizeof(lista_t));
    if (lista != NULL)
    {
        lista->cantidad_elementos = 0;
        lista->head = NULL;
    }
    return *lista;
}

/**Inserta el elemento elem en la posición pos de la lista. Sobrescribe el valor existente en la posición
   indicada, o agrega un nuevo elemento si la posición coincide con la cantidad de elementos.
   Si procede exitosamente retorna verdadero. En otro caso retorna falso.
 */
 int lista_insertar(lista_t lista, unsigned int pos, int elem) {

            }

/**Elimina el elemento en la posición pos. Reacomoda la lista adecuadamente al eliminar en posiciones
       intermedias. Retorna verdadero si procede con éxito, falso en caso contrario. Si la posición no
       es válida,aborta con exit status LST_POS_INV.
 */
 int lista_eliminar(lista_t lista, unsigned int pos) {
    #ifdef DEBUG
    if (lista == NULL)  {printf("\nERROR lista_eliminar PUNTERO A LISTA nulo\n");return;}
    if ((lista->header) == NULL)  {printf("\nERROR lista_eliminar PUNTERO A LISTA vacia\n");return;}
    if (pos < 1 || pos > lista_cantidad())  {printf("\nERROR lista_eliminar posicion fuera de rango\n");return;}
    #endif
    celda_t* celda_eliminar=lista_obtener(lista, pos);  //mal.
    if (((lista != NULL) && ((lista->head)!= NULL) && pos>=1) && (celda_eliminar!=NULL)){
        if ((lista->head) == celda_eliminar){//Eliminar el primero elemento de la Lista.
            if ((lista->size) == 1)//Si es una Lista de un unico elemento.
                lista->head = NULL;
            lista->head = celda_eliminar->proxima_celda;
        }
        else { //busco la celda anterior a la celda a eliminar en la lista
             celda_t* anterior = lista->head;
                while (((anterior->next) != NULL) && ((anterior->proxima_celda) != celda_eliminar))
                        anterior = anterior->proxima_celda;

                 #ifdef DEBUG
                    if (((anterior->proxima_celda) == NULL) || ((anterior->proxima_celda) != pos)){
                        printf("\nERROR en lista_eliminar la posicion NO PERTENECIENTE A LA LISTA\n");return;}
                 #endif

            anterior->next = pos->next;
        }

        free(celda_eliminar); //Liberamos el espacio de memoria usado por la celda pos_eliminar
        (lista->cantidad_elementos)--; //reducimos el tamaño en uno
    }
    return true;
}


/**Retorna la cantidad de elementos de la lista. Si la lista no está inicializada, el programa aborta
   con exit status LST_NO_INI.
 */
int lista_cantidad(lista_t lista){
    #ifdef DEBUG
    if (lista == NULL)  {printf("\nERROR lista_cantidad PUNTERO A LISTA nulo\n");return;}
    #endif
    celda_t* actual;
    int cont=0;
        if((lista != NULL) && ((lista->header) != NULL){
            actual=lista->head;
            cont++;
                while (actual!=null){
                    actual=actual->next_nodo;
                    cont++;
                    }
        }
    return cont;
    }

/**Retorna el elemento en la posición pos de la lista. Si la posición no es válida, aborta con exit
   status LST_POS_INV.
 */
int lista_obtener(lista_t lista, unsigned int pos){
    #ifdef DEBUG
    if (lista == NULL)  {printf("\nERROR lista_obtener PUNTERO A LISTA nulo\n");return;}
    if (pos <1 || pos>lista_cantidad())  {printf("\nERROR lista_obtener Posicion inválida\n");return;}
    #endif
    celda_t* pos_return;
    int encontre=0; //cero si no se encontro la posicion, 1 en caso contrario.
    itn num_pos=0;
        if (lista->cantidad_elementos > 0){
                pos_return=lista->head;
                num_pos=1;
                    while(pos_return!=null && encontre=0){
                        if(num_pos==pos)
                                encontre=1;
                        else
                            if (pos_return->proxima_celda!=NULL){
                                    num_pos++;
                                    pos_return=pos_return->proxima_celda;
                                }
                            else
                                exit-----**
                    }
        }
        else
            exit_status-----***
    return pos_return;
    }

/**Inserta el elemento elem en la última posición de la lista.
   Si la lista no está inicializada, aborta con exit status LST_NO_INI.
 */
int lista_adjuntar(lista_t lista, int elem){
    #ifdef DEBUG
    if (lista == NULL)  {printf("\nERROR lista_adjuntar PUNTERO A LISTA ES NULL\n");return;}
    #endif // DEBUG

    if ((lista != NULL) {
            celda_t* nueva_celda = (celda_t*) malloc (sizeof (nueva_celda));
            nueva_celda-> /**INSERTAR EN ELEMENTO EN LA CELDA*/
            #ifdef DEBUG
                if (nueva_celda == NULL)  {printf("\nERROR en lista_adjuntar IMPOSIBLE RESERVAR MEMORIA PARA LA CELDA DEL NUEVO ELEMENTO\n");return;}
            #endif
    //busco la ultima celda
        if (lista->cantidad_elementos==0){
                lista->head=nueva_celda;
                (lista->cantidad_elementos)++;
                }
        else{
                celda_t* ultima_celda=lista_obtener(lista, lista_cantidad(lista)); //¿BIEN?
                ultima_celda->proxima_celda=nueva_celda;
                lista->cantidad_elementos++;
            }
    }
    else
            ACA HAY QUE RETORNAR EL status.

  return 1;
  }

/**Libera la memoria ocupada por la lista y le asigna NULL. Retorna verdadero en caso de éxito.
   Si la lista no está inicializada, aborta con exit status LST_NO_INI.
 */
int lista_destruir(lista_t* lista){
    #ifdef DEBUG
        if (lista == NULL)  {printf("\nERROR en lista_destruir lista no inicializada\n");return;}
    #endif
    free(lista);
    lista=NULL;
    return 1;
}






