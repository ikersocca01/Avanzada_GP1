#include <stdio.h>  //entrada , salida
#include <stdlib.h> //utileria  
#include <malloc.h> //
#include "listas.h"   //Busca en la misma carpeta 



int main()
        {

      /*        CREACION DE APODOS

            int javierHernandez;
            int *chicharito;

            chicharito = &javierHernandez;  //Creamos un alias (apodo)
            
            // & Significa direccion de
            // * Significa lo que hay en la direccion de

        */   
    char dato;
    nodo *nombre = NULL, *apellido = NULL;  //LISTA LIGADA

    imprimeLista(nombre);

    nombre = insert(nombre, 'I');
    nombre = insert(nombre, 'k');
    nombre = insert(nombre, 'e');
    nombre = insert(nombre, 'r');

    nombre = insert(apellido, 'S');
    nombre = insert(apellido, 'o');
    nombre = insert(apellido, 't');
    nombre = insert(apellido, 'o');
    

    imprimeLista(nombre);
    imprimeLista(apellido);


    apellido = remueve(apellido, &dato);
    printf("El dato que salió fue; %c\n", dato);

    nombre = remueve(apellido, &dato);
    printf("El dato que salió fue; %c\n", dato);
    
    pausa;
    return 0;

}