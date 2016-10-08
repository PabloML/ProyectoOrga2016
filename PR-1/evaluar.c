#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    pila_t pila;//=pila_crear();
    int n=apilar(&pila,"Pablo");
    printf("El tope de la pila es: %s\n",tope(pila));
    apilar(&pila,"Sofia");
    printf("El tope de la pila es: %s\n",desapilar(&pila));
    printf("El tope de la pila es: %s\n",desapilar(&pila));
    return 0;
}
