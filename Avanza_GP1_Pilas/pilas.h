#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define pausa system("pause")
#define cls system("cls")
#define NL putchar('\n')
//  Definicion del nodo
struct Nodo 
{ 
	char info;
	struct Nodo *sig;
};

typedef struct Nodo nodo;  //Especificacion de tipo de nodo

// Prototipos
nodo *push( nodo *raiz, char dato );
nodo *pop(nodo *raiz, char *dato);
int isEmpty(nodo *raiz);
nodo *StackTop(nodo *raiz, char *dato);
void imprimeLista(nodo *raiz);

/*generlizar 4 pasos:
 - Recibir como argunmento el nodo raiz
 - El tipo de retorno es direccion de memoria donde es un nodo, cambiar el tipo de retorno de apuntador a nodo
 - Regresar raiz
*/

nodo *StackTop(nodo *raiz, char *dato)
{
	
	if( raiz == NULL)
	{
		printf("Lista vacia, no hay nada que elimniar.\n");
		pausa;
		return '\0';
	}
	raiz = raiz ->sig;
	*dato = raiz->info;
	return raiz;
}

nodo *push( nodo *raiz, char dato )
{
	nodo *nuevo = NULL;
	nuevo = ( nodo *) malloc( sizeof( nodo ) );
	if( nuevo == NULL)     ///  Prevenir el Overflow
	{
		printf( "No hay memoria disponible\n");
		pausa;
		exit(1);
	}
	nuevo -> info = dato;
	nuevo -> sig = raiz;
	raiz = nuevo;
	return raiz;
}

nodo *pop(nodo *raiz, char *dato)
{
	
	nodo *anterior = NULL;
	if( raiz == NULL)           //Prevenir el underflow
	{
		printf("Lista vacia, no hay nada que elimniar.\n");
		pausa;
		return '\0';
	}
	anterior = raiz;
	raiz = raiz ->sig;
	*dato = anterior->info;
	free(anterior);
	return raiz;
}

int isEmpty(nodo *raiz){

    if(raiz == NULL) return 1; //Verdadero
    else return 0;              //Falso
}

void imprimeLista(nodo *raiz)
{
	nodo *recorre = raiz;
	while( recorre != NULL )
	{
		printf("%c, ", recorre->info);
		recorre = recorre -> sig;
	}
	NL;
}