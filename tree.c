#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#include <string.h>

 node* load_node( tree n, tree nd, tree ni, int f, dato inf) {
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

 int main(int argc, char const *argv[])
 {
 	
 	return 0;
 }