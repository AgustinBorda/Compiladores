#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct dato {	
	int value;
	char* name;
}dato;

typedef struct nodo {
	dato info;
	struct nodo *sig;

}nodoL;

int cant_var = 0; // cantidad de variables insertada en la tabla de simbolos


//typedef struct dato info_var;

int insertar(nodoL** head, char* var, int valor);

int existe(nodoL* head, char* var);

int buscar_valor(nodoL* head, char* var);

int mostrar(nodoL* head);

void borrar(nodoL* head, char* var);
//struct date* loadVar(char* cadena, int valor);

#endif
