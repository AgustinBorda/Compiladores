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

typedef nodoL* lista;
//typedef struct dato info_var;

int insertar(lista *head, char* var, int valor);

int existe(lista head, char* var);

int buscar_valor(lista head, char* var);

int mostrar(lista head);

void borrar(lista *head, int pos);
//struct date* loadVar(char* cadena, int valor);

#endif
