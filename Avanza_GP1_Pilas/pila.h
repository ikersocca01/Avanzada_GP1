#ifndef PILA_H
#define PILA_H

// Definición de un elemento de la pila
typedef struct Elemento {
    void* dato;
    struct Elemento* siguiente;
} Elemento;

// Definición de la estructura de la pila
typedef struct Pila {
    Elemento* tope;
} Pila;

// Funciones para operar la pila
Pila* crearPila();
int estaVacia(Pila* pila);
void push(Pila* pila, void* dato);
void* pop(Pila* pila);
void liberarPila(Pila* pila);

#endif
