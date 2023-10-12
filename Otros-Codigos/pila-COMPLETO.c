/*
Este código convierte una expresión a notación de postfijo.
El código comienza definiendo una función que devuelve un int y toma un puntero char como parámetro.
Luego, el código define una función que devuelve un int y toma 2 parámetros de caracteres.
Luego, el código define una función que devuelve un puntero de caracteres y toma un puntero de caracteres como parámetro.
Luego, el código define una función que devuelve un valor flotante y toma un carácter como parámetro.
Luego, el código define una función que devuelve un valor flotante y toma un valor flotante, un carácter y un valor flotante como parámetros.
Luego, el código define una función que devuelve un flotante y toma un puntero de carácter como parámetro.
Luego, el código define un entero constante llamado "maxLen" y lo establece en 80.
A continuación, el código define un puntero de caracteres denominado "expresión".
El código luego define una función principal.
Luego, el código establece el puntero de caracteres de "expresión" igual a una función calloc.
Luego, el código ingresa a un ciclo while que se ejecutará para siempre.
Luego, el código le pedirá al usuario que ingrese una expresión y la almacene en el puntero de caracteres "expresión".
Luego, el código llamará a la función "profundidad" y verificará si la expresión es válida.
Si la expresión es válida, el código imprimirá el resultado de la expresión.
*/
#include "pila.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int profundidad(char *);
int prec(char, char);
char *postfijo(char *);
float convierte(char);
float evalua(float, char, float);
float evaluarPostfijo(char *);

const int maxLen = 80;
char *expresion;

int main()
{
    expresion = (char *)calloc(maxLen, sizeof(char));

    while (1)
    {
        printf("Ingrese una expresión Matemática: ");
        scanf("%99[^\n]%*c", expresion);

        if (profundidad(expresion))
        {
        	printf("Profundidad: %d\n",profundidad(expresion));
            printf("Resultado: %f\n", evaluarPostfijo(postfijo(expresion)));
        }
        system("pause");
    }
    return 0;
}

nodo *pila;
int profundidad(char *expresion)
{
    int i = 0;
    data symb, temp;
    bool equal = true;
    nodo *pila = NULL; // agregamos la declaración de la pila
    while (expresion[i] != '\0')
    {
        symb.x = expresion[i];
        if (symb.x == '(' || symb.x == '{' || symb.x == '[')
        {
            pila = push(pila, symb, 0); // usamos la función push para agregar el símbolo de apertura a la pila
        }
        if (symb.x == ')' || symb.x == '}' || symb.x == ']')
        {
            if (isEmpty(pila))
            {
                equal = false;
            }
            else
            {
                pila = pop(pila, &temp); // usamos la función pop para obtener el último símbolo de apertura de la pila
                if (symb.x == ')')
                    symb.x = '(';
                else if (symb.x == '}')
                    symb.x = '{';
                else
                    symb.x = '[';
                if (temp.x != symb.x) // comparamos los símbolos de apertura y cierre
                {
                    equal = false;
                }
                else
                {
                    equal = true;
                }
            }
        }
        i++;
    }
    if (!isEmpty(pila)) // si la pila no está vacía, entonces hay símbolos de apertura sin su respectivo cierre
    {
        equal = false;
    }
    return equal; // retornamos el valor de igualdad
}

int prec(char op1, char op2)
{
    int jer1, jer2;
    switch (op1)
    {
    case '(':
    case '[':
    case '{':
        jer1 = -2;
        break;
    case '^':
        jer1 = 3;
        break;
    case '*':
    case '/':
        jer1 = 2;
        break;
    case '+':
    case '-':
        jer1 = 1;
        break;

    default:
        jer1 = 0;
        break;
    }
    switch (op2)
    {
    case ')':
    case ']':
    case '}':
        jer2 = -1;
        break;
    case '^':
        jer2 = 3;
        break;
    case '*':
    case '/':
        jer2 = 2;
        break;
    case '+':
    case '-':
        jer2 = 1;
        break;

    default:
        jer2 = 0;
        break;
    }

    if (jer1 >= jer2)
    {
        return 1;
    }
    else
        return 0;
}
char *postfijo(char *expresion)
{
    pila = NULL;
    data symb, topSymb;
    char *postfijo;
    postfijo = (char *)calloc(strlen(expresion), sizeof(char));
    int i, j;
    i = 0;
    j = 0;

    while (expresion[i] != '\0')
    {
        symb.x = expresion[i];
        if (isalnum(symb.x))
        {
            postfijo[j++] = symb.x;
        }
        else if (symb.x == '(' || symb.x == '{' || symb.x == '[')
        {
            pila = push(pila, symb, 0);
        }
        else if (symb.x == ')' || symb.x == '}' || symb.x == ']')
        {
            char opnSymb;
            if (symb.x == ')')
                opnSymb = '(';
            if (symb.x == ']')
                opnSymb = '[';
            if (symb.x == '}')
                opnSymb = '{';
            while (!isEmpty(pila) && peek(pila).x != opnSymb)
            {
                pila = pop(pila, &topSymb);
                postfijo[j++] = topSymb.x;
            }
            if (!isEmpty(pila) && peek(pila).x == opnSymb)
            {
                pila = pop(pila, &topSymb);
            }
        }
        else
        {
            while (!isEmpty(pila) && prec(peek(pila).x, symb.x))
            {
                pila = pop(pila, &topSymb);
                postfijo[j++] = topSymb.x;
            }
            pila = push(pila, symb, 0);
        }
        i++;
    }
    while (!isEmpty(pila))
    {
        pila = pop(pila, &topSymb);
        postfijo[j++] = topSymb.x;
    }
    postfijo[j] = '\0';
    printf("La expresión en postfijo es: %s\n", postfijo);
    return postfijo;
}
float convierte(char car)
{
    double i;
    i = atof(&car);
    return i;
}

float evalua(float opnd1, char sign, float opnd2)
{
    switch (sign)
    {
    case '^':
        return pow(opnd1, opnd2);
        break;
    case '+':
        return opnd1 + opnd2;
        break;
    case '-':
        return opnd1 - opnd2;
        break;
    case '/':
        return opnd1 / opnd2;
        break;
    case '*':
        return opnd1 * opnd2;
        break;
    }
}

float evaluarPostfijo(char *expresion)
{
    pila = NULL;
    data symb;
    data number, opnd1, opnd2, value;
    int i = 0;
    while (expresion[i] != '\0')
    {
        symb.x = expresion[i];
        if (symb.x >= '0' && symb.x <= '9')
        {
            number.y = convierte(symb.x);
            pila = push(pila, number, 1);
        }
        else
        {
            pila = pop(pila, &opnd2);
            pila = pop(pila, &opnd1);
            value.y = evalua(opnd1.y, symb.x, opnd2.y);
            pila = push(pila, value, 1);
        }
        i++;
    }
    pila = pop(pila, &value);
    return value.y;
    PAUSA;
}
