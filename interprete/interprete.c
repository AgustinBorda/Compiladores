#include <stdio.h>
#include <stdlib.h>
#include "interprete.h"
#include "../src/table.c"
#include <string.h>

void semError(char* msg) {
	printf("Semantic error: %s\n",msg);
	exit(1);
}

int eval(node* root, nodoL* sym_table) {
	switch(root->flag) {
		case 0 : return getValueId(root,sym_table);
			 break;
		case 1 : return getValueConstant(root);
			 break;
		case 2 : return getValueOp(root,sym_table);
			 break;
		default : semError("Unknown token");
			  break;
	}
}



int getValueConstant(node* root) {
	return root->data.value;
}

int getValueId(node* root, nodoL* sym_table) {
	if(existe(sym_table, root->data.var.name)) {
		return buscar_valor(sym_table, root->data.var.name);
	}
	else {
		char err[20+strlen(root->data.var.name)] = "\0";
		strcat(err, "Undeclared variable: ");
	        strcat(err,root->data.var.name);	
		semError(err);
	}
}

int getValueOp(node* root, nodoL* sym_table) {
	int valLeftSon;
	int valRightSon;
	if(root -> hi != NULL) {
		valLeftSon = eval(root->hi,sym_table);
	}
	else {
		semError("NULL left son");
	}
       	if(root -> hd != NULL) {
	       	valRightSon = eval(root->hd,sym_table);
	}
	else {
		semError("NULL right son");
	}	
	switch (root->data.op) {
		case '+' : return valLeftSon + valRightSon;
			    break;
		case '-' : return valLeftSon - valRightSon;
			   break;
		case '*' : return valLeftSon * valRightSon;
			   break;
		case '/' : return valLeftSon / valRightSon;
			   break;
		default : semError("Unsupported Operator");
			  break;
	}
}

