#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct dato {	
	int value;
	char* name;
}dato;

//typedef struct dato info_var;

int insertar(nodoL* head, char* var, int valor);

int existe(nodoL* head, char* var);

int buscar_valor(nodoL* head, char* var);

struct date* loadVar(char* cadena, int valor);

#endif
