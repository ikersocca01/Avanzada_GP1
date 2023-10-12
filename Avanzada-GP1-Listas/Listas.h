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

typedef struct Nodo nodo;

// Prototipos
nodo *insert( nodo *raiz, char dato );
nodo *insert1( nodo *raiz, char dato );
nodo *insertn( nodo *raiz, char dato, int pos );
nodo *remueve(nodo *raiz, char *dato);
nodo *remueve1(nodo *raiz, char *dato);
nodo *remueven(nodo *raiz, char *dato, int pos);
void imprimeLista();

/*generlizar 4 pasos:
 - Recibir como argunmento el nodo raiz
 - El tipo de retorno es direccion de memoria donde es un nodo, cambiar el tipo de retorno de apuntador a nodo
 - Regresar raiz
*/

nodo *raiz = NULL;	


//  Primitivas
nodo *insert( nodo *raiz, char dato )
{
	nodo *nuevo = NULL;
	nuevo = ( nodo *) malloc( sizeof( nodo ) );
	if( nuevo == NULL)     ///  _No hay memoria
	{
		printf( "No hay memoria disponible\n");
		pausa;
		exit(1);
	}
	nuevo -> info = dato;
	nuevo -> sig = NULL;
	if( raiz == NULL )
	{
		raiz = nuevo;
	}
	else 
	{
		nodo *recorre = raiz;
		while( recorre->sig != NULL )
			recorre = recorre -> sig;
		recorre -> sig = nuevo;

	}
	return raiz;
}

nodo *insert1( nodo *raiz, char dato )
{
	nodo *nuevo = NULL;
	nuevo = ( nodo *) malloc( sizeof( nodo ) );
	if( nuevo == NULL)     ///  _No hay memoria
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



nodo *insertn( nodo *raiz, char dato, int pos )
{
	int cont;
	nodo *nuevo = NULL;
	nuevo = ( nodo *) malloc( sizeof( nodo ) );
	if( nuevo == NULL)     ///  _No hay memoria
	{
		printf( "No hay memoria disponible\n");
		pausa;
		exit(1);
	}
	nuevo -> info = dato;
	nuevo -> sig = NULL;
	if( raiz == NULL )
	{
		raiz = nuevo;
	}
	if( pos == 1)
	{
		nuevo ->sig = raiz;
		raiz = nuevo;
	}
	else 
	{
		nodo *recorre = raiz;
		cont = 1;
		while( recorre->sig != NULL && cont < pos - 1)
		{
			recorre = recorre -> sig;
			cont++;
		}
		nuevo ->sig = recorre ->sig;
		recorre -> sig = nuevo;

	}
	return raiz;
}
nodo *remueve(nodo *raiz, char *dato)
{

	nodo *anterior = NULL, *siguiente = NULL;
	if( raiz == NULL)
	{
		printf("Lista vacia, no hay nada que elimniar.\n");
		pausa;
		return '\0';
	}
	anterior = raiz;
	if( anterior->sig == NULL)
	{
		raiz = NULL;
		*dato = anterior->info;
		free(anterior);
		return raiz;
	}
	else
	{
		siguiente = anterior ->sig;
		while(siguiente -> sig != NULL)
		{
			anterior = anterior->sig;			// anterior = siguiente;
			siguiente = siguiente->sig;
		}
		*dato = siguiente ->info;
		anterior ->sig = NULL;
		free(siguiente);
		return raiz;
	}
}

nodo *remueve1(nodo *raiz, char *dato)
{
	
	nodo *anterior = NULL;
	if( raiz == NULL)
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


nodo *remueven(nodo *raiz, char *dato, int pos)
{
	
	nodo *anterior = NULL, *siguiente = NULL;
	 
	anterior = raiz;
	if( pos == 1)
	{
		raiz = raiz ->sig;
		*dato = anterior->info;
		free(anterior);
		return raiz;
	}
	else
	{
		int cont = 1;
		siguiente = anterior ->sig;
		while(siguiente -> sig != NULL && cont < pos -1)
		{
			anterior = anterior->sig;			// anterior = siguiente;
			siguiente = siguiente->sig;
			cont++;
		}
		*dato = siguiente ->info;
		anterior ->sig = siguiente ->sig;
		free(siguiente);
		return raiz;
	}
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