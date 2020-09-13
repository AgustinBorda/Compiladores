#include <stdio.h>
#include <stdlib.h>
#include "interprete.h"

void semError() {
	printf("Semantic error\n");
	exit(1);
}

int eval(node* root) {
	switch(root->flag) {
		case 0 : return getValueId(root);
			 break;
		case 1 : return getValueConstant(root);
			 break;
		case 2 : return getValueOp(root);
			 break;
		default : semError();
			  break;
	}
}



int getValueConstant(node* root) {
	return root->data.value;
}

int getValueId(node* root) {
	return root->data.var.value;
}

int getValueOp(node* root) {
	int valLeftSon;
	int valRightSon;
	if(root -> hi != NULL) {
		valLeftSon = eval(root->hi);
	}
	else {
		semError();
	}
       	if(root -> hd != NULL) {
	       	valRightSon = eval(root->hd);
	}
	else {
		semError();
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
		default : semError();
			  break;
	}
}

