
#ifndef _STRUCTURES_H
#define _STRUCTURES_H


//ESTRUCTURA VARIABLE
typedef struct dato {	
	int value;
	char* name;
}dato;

//ESTRUCTURA ARBOL
typedef struct node {
	struct node* hi;
	struct node* hd;
	int flag; // 0 variable , 1 constante , 2 op
	struct dato data; //var
	int valor; //constante
	char op ;
}node;

//ESTRUCTURA LISTA
typedef struct nodo {
	dato info;
	struct nodo *sig;

}nodoL;


#endif
