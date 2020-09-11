#ifndef _TABLE_H
#define _TABLE_H


#include "structures.h"

int cant_var = 0; // cantidad de variables insertada en la tabla de simbolos


//typedef struct dato info_var;

int insertar(nodoL** head, char* var, int valor);

int existe(nodoL* head, char* var);

int buscar_valor(nodoL* head, char* var);

int mostrar(nodoL* head);

void borrar(nodoL** head, char* var);

#endif