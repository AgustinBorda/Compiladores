#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

#include <string.h>

/*struct dato* loadVar(char* cadena, int valor) {
	struct dato* d = malloc(sizeof(dato));
	d -> name = cadena;
	d -> value = valor;
	return d; 
 }*/

 

int buscar_valor(lista head, char* var) {
	lista aux = head;
	while (aux != NULL ) {
		if (strcmp(aux -> info.name, var)==0) {		
		   return aux -> info.value; 
		}   
	}
}

/* Retorna 1 si la variable existe en la TS, 0 en otro caso */
int existe(lista* head, char* var){
	lista aux = *head;
	while(aux != NULL) { 
		if (strcmp(aux -> info.name, var)==0) {		
		   return 1; 
		}   
	} 
	return 0;	
}

/* Inserta la variable con su valor en la TS */
/* Retorna 1 si pudo insertar correctamente, 0 si ya existe, -1 si la TS esta llena*/
int insertar(lista *head, char * var, int valor) {
	
	if (existe(head, var) != 1) {
		lista aux = malloc(sizeof(nodoL)); //Crear un nuevo nodo.
		aux -> info.name = var; 
		aux -> info.value = valor; 
		cant_var++;
		aux -> sig = *head; //Apuntar el nodo al nodo que apuntaba la lista.
		*head = aux; //Hacer que la lista apunte al nodo nuevo.

	    return 1; // se inserto correctamente 
	} else  {  
	    return 0; // ya existe, no se inserta
	}
	
}

int mostrar(lista head){
	//Crea y asigna 0 a la variable a devolver
	int i=0;
	//Preguntar si la lista no es vacia
	if (head != NULL){
		//Asigna 1 a la variable i.
		i=1;
		//Muestra el valor actual en pantalla
		printf(" |%s =",head->info.name);
		printf(" %d|->",head->info.value);
		//Llama la función con el próximo valor.
		mostrar(head->sig);
	}
	//La función devulelve el resultado.
	return i;
}

int main(int argc, char const *argv[]) {
		printf("%s\n","hola mundo" );
		lista l = NULL;
		insertar(&l, "x", 22);
		//insertar(&l, "y", 8);
		mostrar(l);
		return 0;
}



