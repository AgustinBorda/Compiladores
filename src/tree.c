#include <stdio.h>
#include <stdlib.h>
#include "../headers/tree.h"

#include <string.h>

int cant_nod = 0; // cantidad de variables insertada en la tabla de simbolos

 node* load_node( tree nd, tree ni, int f, type inf) {
 	node* n = malloc(sizeof(node));
 	n->hi = ni;
	n->hd = nd;
	n->data = inf;
	n->flag = f;
	cant_nod++;
	return n;
 }
 

 int size() {
 	return cant_nod;
 }

void preorden(node* n) {
	
	if(n == NULL ) {
		printf("%s\n", "NULL" );
	} else {
	
	if(n -> flag == 0 ) {
		printf(" |%s = ", n->data.var.name);
		printf(" %d|-> ", n->data.var.value);
	}
	if(n -> flag == 1 ) {
		printf(" |%d|-> ",n->data.value);
	}
	if(n -> flag == 2 ) {
		printf(" |%c|-> ",n->data.op);
	}
	if (n->hi != NULL) {
	 	preorden(n->hi);
	}

	
	if (n->hd != NULL) {
	 	preorden(n->hd);
	}
	//sdlkjls
}
}

void inorden(node* n) {
	
	if(n == NULL ) {
		printf("%s\n", "NULL" );
	} else {
	
	if (n->hi != NULL) {
	 	inorden(n->hi);
	}
	if(n -> flag == 0 ) {
		printf(" |%s = ", n->data.var.name);
		printf(" %d|-> ", n->data.var.value);
	}
	if(n -> flag == 1 ) {
		printf(" |%d|-> ",n->data.value);
	}
	if(n -> flag == 2 ) {
		printf(" |%c|-> ",n->data.op);
	}

	if (n->hd != NULL) {
	 	inorden(n->hd);
	}
	
}
}


