#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#include <string.h>

 node* load_node( tree nd, tree ni, int f, dato inf) {
 	node* n = malloc(sizeof(node));
 	n->hi = ni;
	n->hd = nd;
	n->data = inf;
	n->flag = f;
	cant_nod++;
	return n;
 }
  node* load_nodeOP( tree nd, tree ni, int f, char op) {
 	node* n  =  malloc(sizeof(node));
 	n->hi = ni;
	n->hd = nd;
	n-> op = op;
	n->flag = f;
	cant_nod++;
	return n;
 }

 node* newNodeInt (int a) {
 	node* n = malloc(sizeof(node));  
 	n -> hd = NULL;
 	n -> hi = NULL;
 	n -> flag = 1; 
 	n -> valor = a; 
 	cant_nod++;
 	return n ;
 }

 int size() {
 	return cant_nod;
 }

void inorden(node* n){
	
	if(n == NULL ) {
		printf("%s\n", "NULL" );
	} else {
	

	if (n->hi != NULL) {
	 	inorden(n->hi);
	}

	if(n -> flag == 0 ) {
		printf(" |%s =",n->data.name);
		printf(" %d|->",n->data.value);
	}
	if(n -> flag == 1 ) {
		printf(" %d|->",n->valor);
	}
	if(n -> flag == 2 ) {
		printf(" %c|->",n->op);
	}
	if (n->hd != NULL) {
	 	inorden(n->hd);
	}
	
}

}
void show_node(tree n) {
	if(n -> flag == 0 ) {
		printf(" |%s =",n->data.name);
		printf(" %d|->",n->data.value);
	}
	if(n -> flag == 1 ) {
		printf(" %d|->",n->valor);
	}
	if(n -> flag == 2 ) {
		printf(" %c|->",n->op);
	}

}
