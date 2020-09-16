#ifndef _TREE_H
#define _TREE_H

#include "structures.h"

typedef node* tree;

/*
*Construye un nodo del tipo tree y lo carga
*/

node* load_node( tree nd, tree ni, int f, type inf);

int size();

/*
*Escribe el arbol usando la estrategia preorder
*/

void preorden(node* n);

/*
*Escribe el arbol usando la estrategia inorder
*/

void inorden(node* n);

#endif
