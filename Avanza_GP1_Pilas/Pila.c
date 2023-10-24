#include "pila.h"
#include <stdlib.h>
#define NL putchar('\n')
#define pause system("pause")

Pila* crearPila() {
    Pila* pila = (Pila*)malloc(sizeof(Pila));
    pila->tope = NULL;
    return pila;
}

int estaVacia(Pila* pila) {
    return (pila->tope == NULL);
}

void push(Pila* pila, void* dato) {
    Elemento* nuevoElemento = (Elemento*)malloc(sizeof(Elemento));
    nuevoElemento->dato = dato;
    nuevoElemento->siguiente = pila->tope;
    pila->tope = nuevoElemento;
}

void* pop(Pila* pila) {
    if (estaVacia(pila)) {
        // Manejar el caso de pila vacía, por ejemplo, devolver NULL.
        return NULL;
    }
    Elemento* elemento = pila->tope;
    void* dato = elemento->dato;
    pila->tope = elemento->siguiente;
    free(elemento);
    return dato;
}

void liberarPila(Pila* pila) {
    while (!estaVacia(pila)) {
        pop(pila);
    }
    free(pila);
}
