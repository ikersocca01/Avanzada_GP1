#include "pila.h"
#include <stdio.h>
#include <malloc.h>
#define NL putchar('\n')
#define pause system("pause")

int main()
{
    Pila *nombre = crearPila();

    NL;
    printf("Prueba 1:");
    NL;
    push(nombre, 'I');
    push(nombre, 'k');
    push(nombre, 'e');
    push(nombre, 'r');

    NL;

    printf(nombre);
    
    pause;    
    return 0;
}