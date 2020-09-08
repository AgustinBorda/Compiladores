#include <stdio.h>
#include <stdlib.h>
#include "table.h"

#include <string.h>

lista head;

int buscar_valor( char* var) {
	lista aux = head;
	while (aux != NULL ) {
		if (strcmp(aux -> info.name, var)==0) {		
		   return aux -> info.value; 
		}  
		aux = aux -> sig; 
	}
}

/* Retorna 1 si la variable existe en la TS, 0 en otro caso */
int existe( char* var) {
	lista aux = head;
	while(aux != NULL) { 
		if (strcmp(aux -> info.name, var)==0) {		
		   return 1; 
		}  
		aux = aux -> sig; 
	} 
	return 0;	
}

/* Inserta la variable con su valor en la TS */
/* Retorna 1 si pudo insertar correctamente, 0 si ya existe, -1 si la TS esta llena*/
int insertar(char * var, int valor) {

	if (existe(var) != 1) {
		lista aux = malloc(sizeof(nodoL)); //Crear un nuevo nodo.
		aux -> info.name = var; 
		aux -> info.value = valor; 
		cant_var++;
		aux -> sig = head; //Apuntar el nodo al nodo que apuntaba la lista.
		head = aux; //Hacer que la lista apunte al nodo nuevo.

	    return 1; // se inserto correctamente 
	} else  {  
	    return 0; // ya existe, no se inserta
	}
	
}

int loadValue(char * var, int valor) {
	lista aux = head;
	while(aux != NULL) { 
		if (strcmp(aux -> info.name, var)==0) {		
		   aux->info.value = valor;
		   return 1;
		}  
		aux = aux -> sig; 
	} 
	return 0;
}

void borrar( int pos){
    lista aux = head; //puntero auxiliar al primer nodo
    int i = 1; 
    while (aux != NULL && i<pos){
    	aux = aux -> sig;	
    	i++;
    }	 
    free(aux);   //elimino el primer nodo de la memoria
}


void mostrar() {
	lista aux = head;
	while(aux != NULL) {
		//Muestra el valor actual en pantalla
		printf(" |%s =",aux->info.name);
		printf(" %d|->",aux->info.value);
		aux = aux -> sig;
	}
	
}
int main(int argc, char const *argv[])
{
	
	return 0;
}



