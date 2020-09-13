#ifndef _TREE_H
#define _TREE_H

#include "structures.h"

int cant_nod = 0; // cantidad de variables insertada en la tabla de simbolos

typedef node* tree;

node* load_node( tree nd, tree ni, int f, type inf);

int size();

void preorden(node* n);
void inorden(node* n);

#endif