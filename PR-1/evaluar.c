/**
 * Programa Principal.
 * @author Pablo Lencina, Federico Esteche
 */
#include "pila.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXITO EXIT_SUCCESS
#define EXP_MALF 2
#define OPND_DEMAS 5
#define OPND_INSUF 6
#define OPND_INV 7
#define OPRD_INV 8
#define PIL_VACIA 10

/**
 * Realiza la suma de los operandos de la lista pasada por parámetro.
 *@param operandos Lista de operandos a sumar.
 * @return Devuelve el resultado de la suma.
 */
int suma(lista_t operandos)
{
  int s=0;
  //Verifico si tiene la cantidad de operando para operar.
  if (lista_cantidad(operandos)<2)
     {
       printf("La cantidad de operandos es insuficiente para aplicar el operador.");
       exit(OPND_INSUF);
     }
  else { //Realizo la operación vacando los operandos de la lista.
         while (lista_cantidad(operandos)>0)
         {
           int op=lista_eliminar(operandos,0);
           s=s+op;
         }
       }
  return s;
}

/**
 * Realiza la resta de los operandos de la lista pasada por parámetro.
 *@param operandos Lista de operandos a restar.
 * @return Devuelve el resultado de la resta.
 */
int resta(lista_t operandos)
{
  int r=0;
  //Verifico si tiene la cantidad de operando para operar.
  if (lista_cantidad(operandos)<2)
     {
       printf("La cantidad de operandos es insuficiente para aplicar el operador.");
       exit(OPND_INSUF);
     }
  else if (lista_cantidad(operandos)>2)
          {
            printf("La cantidad de operadores es mayor a 2.");
            exit(OPND_DEMAS);
          }
       else { //Realizo la operación vaciando la lista de operandos.
              int op1=lista_eliminar(operandos,0);
              int op2=lista_eliminar(operandos,0);
              r=op1-op2;
            }
  return r;
}

/**
 * Realiza el producto de los operandos de la lista pasada por parámetro.
 *@param operandos Lista de operandos a multiplicar.
  * @return Devuelve el resultado del producto.
 */
int producto(lista_t operandos)
{
  int p=1;
  //Verifico si tiene la cantidad de operando para operar.
  if (lista_cantidad(operandos)<2)
     {
       printf("La cantidad de operandos es insuficiente para aplicar el operador.");
       exit(OPND_INSUF);
     }
  else { //Realizo la operación vacando los operandos de la lista.
         while (lista_cantidad(operandos)>0)
         {
           int op=lista_eliminar(operandos,0);
           p=p*op;
         }
       }
  return p;
}

/**
 * Realiza la división de los operandos de la lista pasada por parámetro.
 *@param operandos Lista de operandos a dividir.
 * @return Devuelve el resultado de la división.
 */
int division(lista_t operandos)
{
  int d=0;
  //Verifico si tiene la cantidad de operando para operar.
  if (lista_cantidad(operandos)<2)
     {
       printf("La cantidad de operandos es insuficiente para aplicar el operador.");
       exit(OPND_INSUF);
     }
  else if (lista_cantidad(operandos)>2)
          {
            printf("La cantidad de operadores es mayor a 2.");
            exit(OPND_DEMAS);
          }
       else { //Realizo la operación vaciando la lista de operandos.
              int op1=lista_eliminar(operandos,0);
              int op2=lista_eliminar(operandos,0);
              d=op1/op2;
            }
  return d;
}

/**
 * Verifica si el string pasado por parametro es un número.
 * @param c Puntero al caracter que quiero conocer si es un entero.
  * @return Devuelve 1 si es verdadero, 0 si es falso.
 */
int esNumero(char* c)
{
  int value=0;
  if ((strcmp(c,"0")==0) || (strcmp(c,"1")==0) || (strcmp(c,"2")==0) || (strcmp(c,"3")==0) || (strcmp(c,"4")==0) || (strcmp(c,"5")==0) || (strcmp(c,"6")==0) || (strcmp(c,"7")==0) || (strcmp(c,"8")==0) || (strcmp(c,"9")==0))
     value=1;
  return value;
}
/**
 * Ve si es un operador el caracter pasada por parametro.
 * @param c Puntero al caracter que quiero conocer si es un operador.
 * @return Devuelve 1 si es verdadero, 0 si es falso.
 */
int esOperador(char* c)
{
  int value=0;
  if ((strcmp(c,"+")==0) || (strcmp(c,"-")==0) || (strcmp(c,"*"))==0 || (strcmp(c,"/")==0))
     value=1;
  return value;
}

/**
 * Arma el número para operar.
 * @param pila Puntero a la pila donde esta la expresión.
 * @param n Digito inicial del número.
 * @return Retorna el número capturado.
 */
int capturarNumero(pila_t* pila,int n)
{
   int m;
   if (pila_vacia(*pila)==0)
      {char* s=desapilar(pila);
       while (esNumero(s)!=0)
       {
         m=atoi(s);
         if (m<0)
            {
              printf("El operando es invalido.");
              exit(OPND_INV);
            }
         else {
                n=n + m*10;
                s=desapilar(pila);
              }
       }
       apilar(pila,s);
      }
   else {
          printf("Pila vacia.");
          exit(PIL_VACIA);
        }
   return n;
}

/**
 * Consume los parentesis apilandolos en una pila.
 * @param pila Puntero a la pila a la que le quiero consumir los parentesis.
 * @param p Puntero a la pila donde apilo los parentesis que consumo.
 */
void consumirParentesis(pila_t* pila, pila_t* p)
{
  char* s;
  if (pila_vacia(*pila)==0)
     {
       s=desapilar(pila);
       while (strcmp(s,")")==0)
       {
         apilar(p,s);
         if (pila_vacia(*pila)==0)
            s=desapilar(pila);
         else {
                printf("Expresión mal formada, falta o exceso de “( )”.");
                exit(EXP_MALF);
              }
       }
      apilar(pila,s);
     }
  else {
         printf("Pila vacia.");
         exit(PIL_VACIA);
       }
}

void cerrarParentesis(pila_t* pila,pila_t* p)
{
  char* s;
  if (pila_vacia(*pila)==0)
     {
       s=desapilar(pila);
       while (strcmp(s,"(")==0)
       {
         if (pila_vacia(*p)==0)
            {
              desapilar(p);
              if (pila_vacia(*pila)==0)
                 s=desapilar(pila);
              else if (pila_vacia(*p)==0)
                      {
                       printf("Expresión mal formada, falta o exceso de “( )”.");
                       exit(EXP_MALF);
                      }
            }
         else {
                printf("Expresión mal formada, falta o exceso de “( )”.");
                exit(EXP_MALF);
              }
       }
       apilar(pila,s);
     }
  else {
         printf("Pila vacia.");
         exit(PIL_VACIA);
        }
}

/**
 * Realiza una operación apilada en una pila en preorden sin parentesis.
 * @param Puntero a la pila que contienen los operandos y operadores de la operación.
 */
int operacion (pila_t* pila)
{
   lista_t operandos =lista_crear();
   int n=0;
   int m;
   char* s;
   if (pila_vacia(*pila)==0)
      {
        s=desapilar(pila);
        while (esNumero(s)!=0 || strcmp(s," ")==0)
        {
          while (strcmp(s," ")==0)
          {
             if (pila_vacia(*pila)==0)
                desapilar(pila);
             else {
                   printf("Expresión mal formada");
                   exit(EXP_MALF);
                  }
          }
          if (esNumero(s)!=0)
             {
               m=atoi(s);
               if (m<0)
                  {
                    printf("El operando es invalido.");
                    exit(OPND_INV);
                  }
               else {
                      n=capturarNumero(pila,m);
                      lista_adjuntar(operandos,n);
                    }
             }
        }
        if (pila_vacia(*pila)==0)
           {
            s=desapilar(pila);
            if (strcmp(s,"+")==0)
               n=suma(operandos);
            else if (strcmp(s,"-")==0)
                    n=resta(operandos);
                 else if (strcmp(s,"*")==0)
                         n=producto(operandos);
                      else if (strcmp(s,"/")==0)
                              n=division(operandos);
            apilar(pila,s);
           }
        else {
              printf("Expresión mal formada");
              exit(EXP_MALF);
             }
      }
   else {
         printf("Pila vacia.");
         exit(PIL_VACIA);
        }
  return n;
}

int main(int argc, char* argv[])
{
  char* s;
  int n=0;
  pila_t pila=pila_crear();
  pila_t p=pila_crear();
  lista_t operandos=lista_crear();
  //Me fijo si la llamada a la función tiene el parametro que solicita la ayuda.
  if (argc>1 && (strcmp(argv[1],"-h")==0))
     {
       //Me fijo que no tenga parametros erroneos.
       if (argc>2)
          printf("La cantidad de parametrops es erronea.");
       printf("El programa opera las operaciones aritméticas suma, resta, división y multiplicación (+, −, /, ∗):\n *Los operandos son números enteros sin signo, de uno o más dígitos.\n *Los operadores + y * pueden recibir dos o más operandos.\n *Las expresiones se interpretan en preorden.\n \n");
     }
  else { //Me fijo que no tenga parametros erroneos.
         if (argc>1)
            {printf("Los parametros son erroneos");
             printf("El programa opera las operaciones aritméticas suma, resta, división y multiplicación (+, −, /, ∗):\n *Los operandos son números enteros sin signo, de uno o más dígitos.\n *Los operadores + y * pueden recibir dos o más operandos.\n *Las expresiones se interpretan en preorden.\n \n");
            }
       }
  printf("Ingrese la operación que quiere realizar: ");
  scanf("%[^\n]",&s);
  //Apilo la expresión.
  while (strcmp((s+n),"\0")!=0)
    {
      apilar(&pila,s+n);
      n++;
    }
  if (pila_vacia(pila)==0)
    {
      s=desapilar(&pila);
      if (strcmp(s,")")!=0)
         {
          printf("Expresión mal formada, falta o exceso de “( )”.");
          exit(EXP_MALF);
         }
      else {
            //Apilo los paretesis para luego controlar que tengan su contraparte.
            apilar(&p,s);
            consumirParentesis(&pila,&p);
            //Verifico que el operando sea valido.
            if (esNumero(s)==0 && strcmp(s," ")!=0)
               {
                 printf("El operando es invalido.");
                 exit(OPND_INV);
               }
            else {
                   while (pila_vacia(p)==0)
                     {
                      apilar(&pila,s);
                      n=operacion(&pila);
                      lista_adjuntar(operandos,n);
                      if (pila_vacia(pila)==0)
                         {
                           s=desapilar(&pila);
                           if (strcmp(s,")")==0)
                              {
                                consumirParentesis(&pila,&p);
                                n=operacion(&pila);
                                lista_adjuntar(operandos,n);
                                cerrarParentesis(&pila,&p);
                                if (pila_vacia(pila)==0)
                                   {
                                     s=desapilar(&pila);
                                     if (strcmp(s,"+")==0)
                                        n=suma(operandos);
                                     else if (strcmp(s,"-")==0)
                                             n=resta(operandos);
                                          else if (strcmp(s,"*")==0)
                                                  n=producto(operandos);
                                               else if (strcmp(s,"/")==0)
                                                       n=division(operandos);
                                                    else {
                                                           printf("El operador es invalido.");
                                                           exit(OPRD_INV);
                                                         }
                                   }
                                else {
                                       printf("Expresión mal formada");
                                       exit(EXP_MALF);
                                     }

                              }
                           else {
                                  printf("El operador es invalido.");
                                  exit(OPRD_INV);
                                }
                         }
                      else {
                             printf("Expresión mal formada");
                             exit(EXP_MALF);
                           }
                     }
                   printf("El resultado de la operación es %i: ",n);
                   exit(EXITO);
                 }
           }
    }
  else {
         printf("Expresión mal formada");
         exit(EXP_MALF);
       }
  return 0;
}
