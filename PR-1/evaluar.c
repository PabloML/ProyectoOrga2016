/**
 * Programa Principal.
 * @author Pablo Lencina, Federico Esteche
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pila.h"
#include "lista.h"

#define EXITO EXIT_SUCCESS
#define EXP_MALF 2
#define OPND_DEMAS 5
#define OPND_INSUF 6
#define OPND_INV 7
#define OPRD_INV 8
#define PIL_VACIA 10

int validar_expresion(char* str);
void calcular(pila_t* pOperandos,lista_t operandos,char* operador);
int esOperador(char c);
int esNumero(char c);




const char* help = "\nEvaluar 1.0\n"
             "Es un evaluador de las expresiones aritméticas suma, resta, división y multiplicación (+, −, /, ∗),Las expresiones aritméticas utilizan la siguiente sintaxis:\n"
             " (< operador > < operando 1 > < operando 2 > . . . < operando n >)\n"
             " Donde:\n"
             "      1)Los operadores, paréntesis y operandos están separados por cualquier número de espacios en blanco.\n"
             "      2)Los operandos son números enteros sin signo, de uno o más dígitos.\n"
             "      3)Los operadores + y * pueden recibir dos o más operandos.\n"
             "      4)Las expresiones se interpretan en preorden. \n"
             "Algunos ejemplos de expresiones válidas son:\n"
             "La expresión ( + ( / 51 37 ) 6 ) se interpreta como 51 / 37 + 6.\n"
             "La expresión (∗ (+ 9 12 3) 4 5 (− 3 2)) se interpreta como (9 + 12 + 3) ∗ 4 ∗ 5 ∗ (3 − 2)\n"
             "Algunos ejemplos de expresiones inválidas son:\n"
             "La expresión + ( / 51 37 ) 6 ) -> No respeta la sintaxis, debe comenzar con un (\n"
             "La expresión ( ++ ( / 51 31 37 ) 6 ) -> No respeta el inciso 2.\n"
             "ERRORES: \n"
             "            a) Si alguno de los operadores no corresponde a un operador válido, muestra un\n"
             "               error y finaliza la ejecución con exit status OPRD_INV.\n"
             "            b) Si la cantidad de operandos es insuficiente para aplicar el operador, muestra\n"
             "               un error y abortar con exit status OPND_INSUF.\n"
             "            c) Si el operador es / o -, y la cantidad de operadores es > 2, muesta un error,\n"
             "               y aborta con exit status OPND_DEMAS.\n"
             "            d) Si alguno de los operandos no corresponde a un número entero válido, muestra\n"
             "               nun error, y termina con exit status OPND_INV.\n"
             "            e) Si al evaluar la expresión no se encuentra un símbolo (, muestra un error y\n"
             "               termina con exit status EXP_MALF.\n"
             "            f) Si al evaluar la expresión, se encuentra que un ( o ) no cuenta con su correspondiente\n"
             "               ) o (, muestra un error y termina con exit status EXP_MALF.\n"
             "            g) Si hay un único elemento en la expresión, y es un entero, muestra el resultado\n"
             "               y terminar con exit status EXITO. Si el elemento no es un entero, termina con\n"
             "               exit status OPND_INV.;\n";



 void evaluar_expresion(){
  char* s;
  s=(char*)malloc(sizeof(char)*256);
  pila_t pOperadores=pila_crear();
  pila_t pOperandos=pila_crear();
  lista_t operandos=lista_crear();

  printf("Ingrese la operacion que quiere realizar: ");
  scanf("%[^\n]*",s);
  int i=0;
  int sigue=validar_expresion(s);//sigue el algoritmo si la expresion es válida
   if(sigue!=1){
    while(s[i]!='\0'){
       char* c=(char*)malloc(sizeof(char)*32);
       sprintf(c,"%c",s[i]);
        if(esOperador(s[i])){
            apilar(&pOperadores,c);
        }
        else{
            if(s[i]=='('){
               apilar(&pOperandos,c);
            }
            else{
                if(s[i]==')'){
                   //Primero controla que la pila de operadores no este vacía.
                      if(pila_vacia(pOperadores)!=1){
                            calcular(&pOperandos,operandos,desapilar(&pOperadores));
                            }
                      else{
                            printf("%s","ERROR: La cantidad de parentesis totales dividido 2 debe coincidir con la cantidad de operadores");
                            exit(EXP_MALF);
                            }
                }
                else{
                    if(esNumero(s[i])){
                        int j=0;
                        char* numero=(char*)malloc(sizeof(char)*10);
                        while(esNumero(s[i])){
                            numero[j]=s[i];
                            j++;
                            i++;
                        }
                        i--;
                    apilar(&pOperandos,numero);
                    }
                }
            }
        }
        i++;

    }//Fin while

    if(pila_vacia(pOperadores)){//si la pila de operadores está vacia
        char* resul=desapilar(&pOperandos);
           if(pila_vacia(pOperandos))//Resultado Correcto
                printf(" El resultado es: %s",resul);
    }
  }//Fin del primer if.
  else
      printf("El resultado es: %s",s);
}

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
           int op=lista_obtener(operandos,0);
           lista_eliminar(operandos,0);
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
int resta(lista_t operandos){
  int r=0;
  //Verifico si tiene la cantidad de operando para operar.
  if (lista_cantidad(operandos)<2){
       printf("La cantidad de operandos es insuficiente para aplicar el operador.");
       exit(OPND_INSUF);
     }
  else if (lista_cantidad(operandos)>2){
            printf("La cantidad de operadores es mayor a 2.");
            exit(OPND_DEMAS);
          }
       else { //Realizo la operación vaciando la lista de operandos.
              int op1=lista_obtener(operandos,0);
              lista_eliminar(operandos,0);
              int op2=lista_obtener(operandos,0);
              lista_eliminar(operandos,0);
              r=op2-op1;
            }
  return r;
}

/**
 * Realiza el producto de los operandos de la lista pasada por parámetro.
 * @param operandos Lista de operandos a multiplicar.
 * @return Devuelve el resultado del producto.
 */
int producto(lista_t operandos){
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
           int op=lista_obtener(operandos,0);
           lista_eliminar(operandos,0);
           p=p*op;
         }
       }
  return p;
}

/**
 * Realiza la división de los operandos de la lista pasada por parámetro.
 * @param operandos Lista de operandos a dividir.
 * @return Devuelve el resultado de la división.
 */
int division(lista_t operandos){
  int d=0;
  //Verifico si tiene la cantidad de operando para operar.
  if (lista_cantidad(operandos)<2){
       printf("La cantidad de operandos es insuficiente para aplicar el operador.");
       exit(OPND_INSUF);
     }
  else if (lista_cantidad(operandos)>2){
            printf("La cantidad de operadores es mayor a 2.");
            exit(OPND_DEMAS);
          }
       else { //Realizo la operación vaciando la lista de operandos.
              int op1=lista_obtener(operandos,0);
              lista_eliminar(operandos,0);
              int op2=lista_obtener(operandos,0);
              lista_eliminar(operandos,0);
              d=op2/op1;
            }
  return d;
}

/**
 * Verifica si el string pasado por parametro es un número entero.
 * @param c Puntero al caracter a evaluar.
 * @return retorna 1 si el caracter es un entero, 0 si en caso contrario.
 */
int esNumero(char c){
  int value=0;
  if ((c=='0') || (c=='1') || (c=='2') || (c=='3') || (c=='4') || (c=='5')
               || (c=='6') || (c=='7') || (c=='8') || (c=='9'))
     value=1;
  return value;
}
/**
 * Evalua si el caracter c es un operador.
 * @param c Puntero al caracter a evaluar.
 * @return Devuelve 1 si es el caractec c es un operador, 0 en caso contrario.
 */
int esOperador(char c){
  int value=0;
  if ((c=='+') || (c=='-') || (c=='*') || (c=='/'))
     value=1;
  return value;
}

/**
 * Recibe una lista de operandos, una pila de operadores y una pila de operandos.
 * Aplica la operación aritmetica de acuerdo al operador que se encuentra en el
 * tope de la pila, a los operandos que contiene la lista.
 * @param pOperandos: Puntero a la pila que contiene los operandos.
 * @param operandos: Puntero a la lista que contiene los operandos a utilizar.
 * @param operador: Puntero a la pila que contiene operadores.
 */
void calcular(pila_t* pila_operandos,lista_t lista_operandos,char* operador){
    int p_vacia=pila_vacia(*pila_operandos);
    if(p_vacia!=1){
        while(strcmp(tope(*pila_operandos),"(")!=0){
            lista_adjuntar(lista_operandos,atoi(desapilar(pila_operandos)));
        }

     desapilar(pila_operandos);
     if(strcmp(operador,"+")==0){
        char* aux2=(char*)malloc(sizeof(char));
        int res=suma(lista_operandos);
        sprintf(aux2,"%d",res);
        apilar(pila_operandos,aux2);
       // free(aux2);
    }
    else{
         if(strcmp(operador,"-")==0){
            char* aux2=(char*)malloc(sizeof(char));
            int res=resta(lista_operandos);
            sprintf(aux2,"%d",res);
            apilar(pila_operandos,aux2);
            //free(aux2);
         }
         else{
             if(strcmp(operador,"*")==0){
                char* aux2=(char*)malloc(sizeof(char));
                int res=producto(lista_operandos);
                sprintf(aux2,"%d",res);
                apilar(pila_operandos, aux2);
               // free(aux2);
             }

             else{
                 if(strcmp(operador,"/")==0){
                    char* aux2=(char*)malloc(sizeof(char));
                    int res=division(lista_operandos);
                    sprintf(aux2,"%d",res);
                    apilar(pila_operandos, aux2);
                   // free(aux2);
                 }//fin if

              }//Fin else
         }
    }

    }
}
/** Retorna VERDADERO (1) si la expresion pasada por parámetro corresponde a un solo numero entero natural,
  * retorna FALSO (0) en caso contrario.
  */

int es_solo_numero(char* expresion){
 int i=0;
 int es_num=1;
   while((expresion[i]!='\0')&&(es_num)){
        es_num=(esNumero(expresion[i]));
        i++;
    }
    return es_num;
}

/**
 * Evalua si la expresion str es correcta.Una expresion se considera falsa si:
 * a) tiene parentesis mal balanceados, esto es, si la cantidad de "(" no coincide
 * con la cantidad de ")".
 * b) contiene algun caracter distinto de "(,),+,*,/,-,0,1,2,3,4,5,6,7,8,9"
 * @param str: expresión a evaluar.
 * @return OPRD_INV: Si contiene algun operador inválido.
 * @return EXP_MALF: Si los paréntesis están mal balanceados o si la expresion no comienza con "(".
 * @return 0: Si la expresión es válida.
 */
int validar_expresion(char* str){
    int cantParentesis=0;
    int i=0;
    if(es_solo_numero(str)){
                return 1;
                }
    else
        if(str[0]=='('){
           while(str[i]!='\0'){
            if((!esNumero(str[i])) && (!esOperador(str[i])) && (str[i]!='(') && (str[i]!=')') && (str[i]!=' ')){
                printf("%s","ERROR: Operador Inválido");
                exit(OPRD_INV);
                }
            else
                if(str[i]=='(')
                        cantParentesis++;
                else
                    if(str[i]==')')
                        cantParentesis--;
        i++;

        }

      if(cantParentesis!=0){
            printf("%s","Error: Parentesis mal balanceados");
            exit(EXP_MALF);
            }
      }
      else{//Si la expresion no comienza con "(".
           printf("%s","Error: La expresión debe comenzar con un paréntesis abierto '('");
           exit(EXP_MALF);
           }
    return (0);
}

/** Main **/

int main( const int argc, const char* argv[] ) {

    evaluar_expresion();
    return ( 0 );

}
