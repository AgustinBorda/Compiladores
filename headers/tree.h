#ifndef _TREE_H
#define _TREE_H

#include "structures.h"

int cant_nod = 0; // cantidad de variables insertada en la tabla de simbolos

typedef node* tree;

node* load_node( tree nd, tree ni, int f, dato inf);

node* load_nodeOP(  tree nd, tree ni, int f, char op);

node* newNodeInt (int a); 

int size();

#endif