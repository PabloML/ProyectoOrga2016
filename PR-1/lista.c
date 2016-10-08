/**
 * TDA Pila.
 * @author Pablo Lencina, Federico Esteche
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

lista_t lista_crear(){

    lista_t nueva_lista=malloc(sizeof(lista_t));
    nueva_lista->head=NULL;
    nueva_lista->cantidad_elementos=0;
    return nueva_lista;
}


celda_t* crearCelda(){
        celda_t* celda=(celda_t*) malloc(sizeof(celda_t));
        int i;
        for(i=0;i<4;i++){
            celda->elementos[i]=(int)NULL;
        }
        celda->proxima_celda=NULL;
        return celda;
}
   /**Inserta el elemento elem en la posici�n pos de la lista. Sobrescribe el valor existente en la posici�n
    indicada, o agrega un nuevo elemento si la posici�n coincide con la cantidad de elementos.
    Si procede exitosamente retorna verdadero. En otro caso retorna falso. **/
int lista_insertar(lista_t lista, unsigned int pos, int elem) {

    if(lista->cantidad_elementos>=pos){ //ERROR si la posicion de insersion es mayor que la cantidad de elementos,
        int numero_de_celda=pos/4;
        int pos_en_arreglo=pos%4;
        int i;
        celda_t *celda;
        if(lista->cantidad_elementos>0){
            celda=lista->head;
            for(i=0;i<numero_de_celda;i++){
                if(celda->proxima_celda!=NULL)
                    celda=celda->proxima_celda;
                else{
                    celda_t* nueva_celda=crearCelda();
                    celda->proxima_celda=nueva_celda;
                    celda=nueva_celda;
                }
            }
        }
        else{//la lista est� vac�a
            celda=(celda_t *)crearCelda();
            lista->head=celda;

        }
        //Agrego el elemento en la posicion.
        int* arreglo=celda->elementos;
        arreglo[pos_en_arreglo]=elem;
        lista->cantidad_elementos++;
        return 1;
    }
    else
        return 0;

}

 /**Elimina el elemento en la posici�n pos. Reacomoda la lista adecuadamente al eliminar en posiciones
    intermedias.
    Retorna verdadero si procede con �xito, falso en caso contrario.
    Si la posici�n no es v�lida,aborta con exit status LST_POS_INV.
int lista_eliminar(lista_t lista, unsigned int pos) {
    int numero_de_celda=pos/4; //El numero de celda que contiene la posicion a eliminar.
    int pos_eliminar=pos%4;

    int i;
    celda_t *celda=lista->head;
        for(i=0;i<numero_de_celda;i++){
            celda=celda->proxima_celda;
        }
     int* arreglo= celda->elementos;
        while(celda->proxima_celda!=NULL){



      }
    }*/

/**Retorna la cantidad de elementos de la lista. Si la lista no est� inicializada, el programa aborta
   con exit status LST_NO_INI.*/
int lista_cantidad(lista_t lista){
    if (lista==NULL)
            return 3;
    else
        return lista->cantidad_elementos;
    }

/**Retorna el elemento en la posici�n pos de la lista. Si la posici�n no es v�lida, aborta con exit
   status LST_POS_INV.*/
int lista_obtener(lista_t lista, unsigned int pos){
    int numero_de_celda=pos/4;
    int pos_en_arreglo=pos%4;
    int i;
    int to_return;
    celda_t *celda;
        if(lista->cantidad_elementos>0){
            celda=lista->head;
            for(i=0;i<numero_de_celda;i++){
                if(celda->proxima_celda!=NULL)
                    celda=celda->proxima_celda;
                    }
            int* arreglo=celda->elementos;
            to_return=arreglo[pos_en_arreglo];
        }
        else
            return 4;
    return to_return;
    }
/**Inserta el elemento elem en la �ltima posici�n de la lista.
   Si la lista no est� inicializada, aborta con exit status LST_NO_INI.*/
int lista_adjuntar(lista_t lista, int elem){
    int to_return=0;
    if (lista==NULL){
        to_return= 3;
        }
    else{
         int pos_de_insercion=lista->cantidad_elementos+1;
         to_return=lista_insertar(lista,pos_de_insercion,elem);
         }
    return to_return;
    }

/** Elimina el primer nodo de la lista recibida como par�metro
 */

void eliminar_celda(lista_t lista){
    celda_t *primera_celda= lista->head;
    lista->head= lista->head->proxima_celda; //asigno como head de la lista, al 2do nodo.
    free(primera_celda);
    lista->cantidad_elementos--;
}

/**Libera la memoria ocupada por la lista y le asigna NULL. Retorna verdadero en caso de �xito.
   Si la lista no est� inicializada, aborta con exit status LST_NO_INI.*/
int lista_destruir(lista_t* lista){
    int to_return=1;
    if (lista==NULL)
            to_return=3;
    else{
         while((*lista)->cantidad_elementos > 0)
            eliminar_celda(*lista);
         lista=NULL;
        to_return=1;
     }
     return to_return;
}
