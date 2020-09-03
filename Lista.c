#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int info;
	struct nodo *sig;

}nodoL;

typedef struct date {
	int value;
	char* name;
}date;

typedef nodoL* lista;

struct date* loadVar(char* cadena, int valor) {
	struct date* d = malloc(sizeof(date));
	d -> name = cadena;
	d -> value = valor;
	return d; 
 } 
/*Insercion a la cabeza*/
void add (lista *L, int n) {
	lista aux = malloc(sizeof(nodoL)); //Crear un nuevo nodo.
	aux -> info = n; //Asignar el valor al nodo.
	aux -> sig = *L; //Apuntar el nodo al nodo que apuntaba la lista.
	*L=aux; //Hacer que la lista apunte al nodo nuevo.
	printf("Se agrego el %d a la lista\n",n); //Escribir en pantalla que se agregó el valor a la lista.
}
/*remove a la cabeza*/
void rm(lista *L, int n) {
	lista aux = *L; //puntero auxiliar al primer nodo
	(*L) = (*L) -> sig; //hago apuntar l al siguiente nodo
	free(aux);   //elimino el primer nodo de la memoria
	
}


/* mostrar lista*/
void toShow(nodoL* L) {
	if (L!=NULL) {
		printf(" |%d|->",L->info);
		toShow(L->sig);
	}	
}

int length(nodoL* L) {
	if (L!=NULL) {
		return 1 + length(L->sig);
	}
	return 0;	
}

int getr(nodoL* L, int n, int i) {
	if (L!=NULL && i != n) {
		i++;
		return  getr(L->sig, n, i);
	}
	if (i == n) {
		return L -> info;
	}
	return -1;
}
