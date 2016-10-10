/**
 * TDA Pila.
 * @author Pablo Lencina, Federico Esteche
 */

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define EXITO EXIT_SUCCESS
#define LST_NO_INI 3
#define LST_POS_INV 4
#define FALSO 0
#define VERDADERO 1

//Funciones Auxiliares
void eliminar_intermedio(celda_t* cel, unsigned int pos_eliminar, unsigned int cant_ele, lista_t l);
void eliminar_celda(lista_t lista);
celda_t* buscar_celda(int pos_buscar, lista_t l);
celda_t* crearCelda();




lista_t lista_crear(){

    lista_t nueva_lista=(lista_t)malloc(sizeof(lista_t));
    nueva_lista->primera_celda=NULL;
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
   /**Inserta el elemento elem en la posición pos de la lista. Sobrescribe el valor existente en la posición
    indicada, o agrega un nuevo elemento si la posición coincide con la cantidad de elementos.
    Si procede exitosamente retorna verdadero. En otro caso retorna falso. **/
int lista_insertar(lista_t lista, unsigned int pos, int elem) {

    if(lista->cantidad_elementos>=pos){
        int numero_de_celda=pos/4;
        int pos_en_arreglo=pos%4;
        int i;
        celda_t *celda;
        if(lista->cantidad_elementos>0){
            celda=lista->primera_celda;
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
        else{//la lista está vacía
            celda=(celda_t *)crearCelda();
            lista->primera_celda=celda;

        }
        //Agrego el elemento en la posicion.
        int* arreglo=celda->elementos;
        arreglo[pos_en_arreglo]=elem;
        lista->cantidad_elementos++;
        return VERDADERO;
    }
    else
        return FALSO;

}

 /**Elimina el elemento en la posición pos. Reacomoda la lista adecuadamente al eliminar en posiciones
    intermedias.
    Retorna verdadero si procede con éxito, falso en caso contrario.
    Si la posición no es válida,aborta con exit status LST_POS_INV.*/
int lista_eliminar(lista_t lista, unsigned int pos) {
    if (pos>=0 && pos<lista->cantidad_elementos) {
        int numero_de_celda=pos/4; //El numero de celda que contiene la posicion a eliminar.
        int pos_celda=pos%4; //posicion del arreglo.
        celda_t *celda=buscar_celda(pos,lista);
        celda->elementos[pos_celda]=(int)NULL;
        //Si es el ultimo elemento o el unico de la lista
        if (pos==lista->cantidad_elementos-1){//si es el ultimo elemento
             if ( pos_celda==0 && numero_de_celda!=0){//Si es el primer elemento de la celda, pero la celda no es la primera.
                      free(celda);
                    if (lista->cantidad_elementos==1)//si es el unico elemento
                            lista->primera_celda=NULL;
                    else {
                            celda_t* celda_ant=buscar_celda(pos-1,lista);
                            celda_ant->proxima_celda=NULL;
                            }
                }
        }
        else //Si no es el ultimo elemento.
             eliminar_intermedio(celda,pos,lista->cantidad_elementos-1,lista);

        lista->cantidad_elementos--;
        return (VERDADERO);
        }
    else{
         exit(LST_POS_INV);
         }

   return(FALSO);
}



void eliminar_intermedio(celda_t* cel, unsigned int pos_eliminar, unsigned int cant_ele,lista_t l){
        if (cant_ele==pos_eliminar){
            cel->elementos[pos_eliminar%4]=(int)NULL;
            int probar=pos_eliminar%4;
                    if(probar==0){//Elimino el nodo
                        celda_t* c_ante=buscar_celda(pos_eliminar-1,l);
                        c_ante->proxima_celda=NULL;
                        free(cel);
                       }
        }
        else{
              cel->elementos[pos_eliminar%4]=lista_obtener(l,pos_eliminar+1); //A la posicion pos le asigno el contenido de pos+1
                if (pos_eliminar%4==3){ //Si es el ultimo elemento de la celda, encuentro la celda siguiente.
                     if(cel->proxima_celda==NULL)
                        cel->elementos[pos_eliminar%4]=(int)NULL;
                     else{
                        pos_eliminar=pos_eliminar+1;
                        eliminar_intermedio(cel->proxima_celda ,pos_eliminar,cant_ele,l);
                    }
                }
                else{
                     pos_eliminar=pos_eliminar+1;
                     eliminar_intermedio(cel ,pos_eliminar,cant_ele,l);
                }
        }
}


celda_t* buscar_celda(int pos_buscar, lista_t l){
    //Se asume que la posicion pasada como parametro es valida.
    celda_t* celda_buscada=NULL;
    int numero_de_celda=pos_buscar/4;
     if (l->cantidad_elementos!=0){
          celda_buscada=l->primera_celda;
          int i;
          for(i=0;i<numero_de_celda;i++){
                celda_buscada=celda_buscada->proxima_celda;
        }
        return celda_buscada;
     }
     else{
        exit(LST_POS_INV);
        }
    }



/**Retorna la cantidad de elementos de la lista. Si la lista no está inicializada, el programa aborta
   con exit status LST_NO_INI.*/
int lista_cantidad(lista_t lista){
    if (lista==NULL)
            return 3;
    else
        return lista->cantidad_elementos;
    }

/**Retorna el elemento en la posición pos de la lista. Si la posición no es válida, aborta con exit
   status LST_POS_INV.*/
int lista_obtener(lista_t lista, unsigned int pos){
    int numero_de_celda=pos/4;
    int pos_en_arreglo=pos%4;
    int i;
    int to_return;
    celda_t *celda;
        if(lista->cantidad_elementos>0){
            celda=lista->primera_celda;
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
/**Inserta el elemento elem en la última posición de la lista.
   Si la lista no está inicializada, aborta con exit status LST_NO_INI.*/
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

/** Elimina el primer nodo de la lista recibida como parámetro
 */

void eliminar_celda(lista_t l){
    celda_t *celda= l->primera_celda;
        if (celda->proxima_celda==NULL){
                    l->primera_celda=NULL;
                    l->cantidad_elementos=0;
                    l=NULL;
                    }
        else
             l->primera_celda= celda->proxima_celda; //asigno como head de la lista, al 2do nodo.
    free(celda);
    }

/**Libera la memoria ocupada por la lista y le asigna NULL. Retorna verdadero en caso de éxito.
   Si la lista no está inicializada, aborta con exit status LST_NO_INI.*/
int lista_destruir(lista_t* lista){
    if (lista==NULL){
            exit(LST_NO_INI);
            }
    else{
         int cant_celdas=(*lista)->cantidad_elementos/4;
         while(cant_celdas>0){
            eliminar_celda(*lista);
            cant_celdas--;
            }
         lista=NULL;
         return (VERDADERO);
      }
}

