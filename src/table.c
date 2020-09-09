#include <stdio.h>
#include <stdlib.h>
#include "../headers/table.h"

#include <string.h>

/*struct dato* loadVar(char* cadena, int valor) {
	struct dato* d = malloc(sizeof(dato));
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
		aux = aux -> sig; 
	}
}

/* Retorna 1 si la variable existe en la TS, 0 en otro caso */
int existe(nodoL* head, char* var){
	nodoL* aux = head;
	while(aux != NULL) { 
		if (strcmp(aux->info.name, var)==0) {		
		   return 1; 
		}  
		aux = aux -> sig; 
	} 
	return 0;	
}

/* Inserta la variable con su valor en la TS */
/* Retorna 1 si pudo insertar correctamente, 0 si ya existe, -1 si la TS esta llena*/
int insertar(nodoL** head, char * var, int valor) {
		
	if (existe(*head, var) != 1) {
		nodoL* aux = malloc(sizeof(nodoL)); //Crear un nuevo nodo.
		aux -> info.name = var; 
		aux -> info.value = valor; 
		cant_var++;
		(*aux).sig = *head; //Apuntar el nodo al nodo que apuntaba la lista.
		*head = aux; //Hacer que la lista apunte al nodo nuevo.

	    return 1; // se inserto correctamente 
	} else  {  
	    return 0; // ya existe, no se inserta
	}
	
}


void borrar(nodoL* head, char* var){
    nodoL* aux = head; //puntero auxiliar al primer nodo
    int i = 1; 
    while (aux != NULL && strcmp(aux->info.name, var)){
    	aux = aux -> sig;	
    	i++;
    }	 
    if(strcmp(aux->info.name, var)) {
    	free(aux);   //elimino el primer nodo de la memoria
	}
}


int mostrar(nodoL* head) {
	//Crea y asigna 0 a la variable a devolver
	//Preguntar si la lista no es vacia
	if (head != NULL){
		//Asigna 1 a la variable i.
		//Muestra el valor actual en pantalla
		printf(" |%s =",head->info.name);
		printf(" %d|->",head->info.value);
		//Llama la función con el próximo valor.																																		
		mostrar(head -> sig);
	}
	else {
		printf(" NULL\n");
	}
	return 0;
}



int main() {
	nodoL* l = NULL;
	insertar(&l,"aaa",0);
	mostrar(l);
	insertar(&l,"bbb",1);
	mostrar(l);
	return 0;
}

