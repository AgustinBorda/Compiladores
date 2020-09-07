#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

#include <string.h>

/*struct date* loadVar(char* cadena, int valor) {
	struct date* d = malloc(sizeof(date));
	d -> name = cadena;
	d -> value = valor;
	return d; 
 }*/

 

int buscar_valor(nodoL* head, char* var) {
	nodoL* aux = head;
	while (aux != NULL ) {
		if (strcmp(aux -> info.name, var)==0) {		
		   return aux -> info.value; 
		}   
	}
}

/* Retorna 1 si la variable existe en la TS, 0 en otro caso */
int existe(nodoL* head, char* var){
	nodoL* aux = head;
	while(aux != NULL) { 
		if (strcmp(aux -> info.name, var)==0) {		
		   return 1; 
		}   
	} 
	return 0;	
}

/* Inserta la variable con su valor en la TS */
/* Retorna 1 si pudo insertar correctamente, 0 si ya existe, -1 si la TS esta llena*/
int insertar(nodoL* head, char * var, int valor) {
	
	if (existe(head, var) != 1) {
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


	int main(int argc, char const *argv[]) {
		printf("%s\n","hola mundo" );
		return 0;
	}
}




