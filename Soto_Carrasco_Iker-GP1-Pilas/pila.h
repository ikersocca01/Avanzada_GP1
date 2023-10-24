#ifndef HEADER_PILA
#define HEADER_PILA

#include <stdio.h>
#include <stdlib.h>

#define PAUSA system("pause")
#define CLS system("cls")

/* Generamos un UNION para poder recibir tanto los valores char de los operadores
    como también los float de los valores de la expresión
    Puede verse como una cubeta donde puedes meter distintos liquidos; agua, aceite, etc
    
    Ejemplo: 
    Agua = Char
    Aceite = Float

    Union permite que llenemos la cubeta con alguno de los dos, por ende no pueden entrar ambos
    Al ingrear uno se toma ese tipo de dato y no puede usarse otro hasta que vaciemos la cubeta

*/
union Data
{
    char x;
    float y;
};

typedef union Data data;
struct Nodo
{
    data info;
    int flag; // → 0 para char 1 para float
    struct Nodo *sig;
};

typedef struct Nodo nodo;

// Prototipo de funciones
nodo *push(nodo *, data, int);
nodo *pop(nodo *, data *);
int isEmpty(nodo *);
data peek(nodo *);
void imprimeStack(nodo *raiz);

nodo *push(nodo *pila, data dato, int tipo)
{
    nodo *nuevo = NULL;
    nuevo = (nodo *)malloc(sizeof(nodo));
    if (nuevo == NULL)
    {
        printf("Error: no hay memoria disponible \n");
        exit(1);
    }
    nuevo->info = dato;
    nuevo->flag = tipo;
    nuevo->sig = pila;

    pila = nuevo;
    return pila;
}

nodo *pop(nodo *pila, data *dato)
{
    nodo *recorre = NULL;
    nodo *first = NULL;
    // si la lista está vacía
    if (pila == NULL)
    {
        printf("La pila esta vacia, no se puede hacer pop.\n");
        return NULL;
    } 
    recorre = pila;
    first = recorre->sig;
    // recorre->sig = pila;
    pila = first;
    *dato = recorre->info;
    pila = first;
    free(recorre);
    return pila;
}

int isEmpty(nodo *pila)
{
    if (pila == NULL)
        return 1;
    else
        return 0;
}

data peek(nodo *pila)
{
    data valor;

    if (pila == NULL)
    {
        printf("La pila esta vacia, no se puede hacer pop\n");
        return valor;
    }

    if (pila->flag == 0)
    {
        // printf("%c\n", pila->info.x);
        valor.x = pila->info.x;
    }
    else if (pila->flag == 1)
    {
        // printf("%f\n", pila->info.y);
        valor.y = pila->info.y;
    }

    return valor;
}

void imprimeStack(nodo *pila)
{
    nodo *recorre = pila;
    int primer_dato = 1;
    while (recorre != NULL)
    {
        if (!primer_dato)
        {
            printf("|");
        }
        primer_dato = 0;
        if (recorre->flag == 0)
        {
            printf(" %c ", recorre->info.x);
        }
        else if (recorre->flag == 1)
        {
            printf(" %f ", recorre->info.y);
        }
        recorre = recorre->sig;
    }
    putchar('\n');
}

#endif // HEADER_PILA
