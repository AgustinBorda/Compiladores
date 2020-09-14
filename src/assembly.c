#include <stdio.h>
#include <stdlib.h>
#include "../headers/structures.h"
int variable = 0;

int open_file(tree head) {
	FILE* f;

	f = fopen("assembly.txt", "w+");
	fprintf(f,"%s\n", "MOV EAX, 0");
	fprintf(f,"%s\n", "MOV EBX, 0");
	fprintf(f,"%s\n", "MOV ECX, 0");
	fprintf(f,"%s\n", "MOV EDX, 0");
	dfs(head, f);
	fclose(f);
	return 0;
}


void dfs(struct node *head,FILE* f) {
    
    if (head != NULL) {
        if (head -> hi != NULL) {
            dfs(head->hi, f);
        }
        if (head->hd != NULL) {
            dfs(head->hd, f);
        }
       struct node * aux = head;
        write(aux, f);
    }
}

void write(struct node * root, FILE* f) {
	if (root ->flag == 0) {
		variable = variable + 1 ;
		fprintf(f,"%s%d%s%d\n" ,"MOV TEMP", variable, ", ", root -> data.var.value);
	}
	if (root ->flag == 1) {
		fprintf(f, "%s%d\n", "MOV ECX, ", root ->data.value);
	}
	if (root ->flag == 2) {
		if(root -> data.op == '+') {
			if(root -> hi -> flag == 0){
				fprintf(f,"%s\n", "MOV EAX, 0");
				fprintf(f,"%s%d%s\n" ,"ADD ", root -> hi -> data.var.value, ", EAX");
			}else{
				if(root -> hi -> flag == 1){
					fprintf(f,"%s\n", "MOV EAX, 0");
					fprintf(f,"%s%d%s\n" ,"ADD ", root -> hi -> data.value, ", EAX");
				}else{
					if((root -> hd -> data.op == '*') || (root -> hd -> data.op == '/')) {
						fprintf(f,"%s\n" ,"ADD EBX, EAX");
					}
				}
			}
			if(root -> hd -> flag == 0){
				fprintf(f,"%s%d%s\n" ,"ADD ", root -> hd -> data.var.value, ", EAX");
			}else{
				if(root -> hd -> flag == 1){
					fprintf(f,"%s%d%s\n" ,"ADD ", root -> hd -> data.value, ", EAX");
				}
			}
		}
		if(root -> data.op == '*') {
			if(root -> hi -> flag == 0){
				fprintf(f,"%s\n", "MOV EBX, 1");
				fprintf(f,"%s%d%s\n" ,"MUL ", root -> hi -> data.var.value, ", EBX");
			}else{
				if(root -> hi -> flag == 1){
					fprintf(f,"%s\n", "MOV EBX, 1");
					fprintf(f,"%s%d%s\n" ,"MUL ", root -> hi -> data.value, ", EBX");
				}
			}
			if(root -> hd -> flag == 0){
				fprintf(f,"%s%d%s\n" ,"MUL ", root -> hd -> data.var.value, ", EBX");
			}else{
				fprintf(f,"%s%d%s\n" ,"MUL ", root -> hd -> data.value, ", EBX");
			} 

		}
		if(root -> data.op == '-') {
			if(root -> hi -> flag == 0){
				fprintf(f,"%s\n", "MOV EAX, 0");
				fprintf(f,"%s%d%s\n" ,"DIF ", root -> hi -> data.var.value, ", EAX");
			}else{
				if(root -> hi -> flag == 1){
					fprintf(f,"%s\n", "MOV EAX, 0");
					fprintf(f,"%s%d%s\n" ,"DIF ", root -> hi -> data.value, ", EAX");
				}else{
					if((root -> hd -> data.op == '*') || (root -> hd -> data.op == '/')) {
						fprintf(f,"%s\n" ,"ADD EBX, EAX");
					}
				}
			}
			if(root -> hd -> flag == 0){
				fprintf(f,"%s%d%s\n" ,"DIF ", root -> hd -> data.var.value, ", EAX");
			}else{
				fprintf(f,"%s%d%s\n" ,"DIF ", root -> hd -> data.value, ", EAX");
			}
		}
		if(root -> data.op == '/') {
			if(root -> hi -> flag == 0){
				fprintf(f,"%s\n", "MOV EAX, 0");
				fprintf(f,"%s%d%s\n" ,"DIV ", root -> hi -> data.var.value, ", EAX");
			}else{
				if(root -> hi -> flag == 1){
					fprintf(f,"%s\n", "MOV EAX, 0");
					fprintf(f,"%s%d%s\n" ,"DIV ", root -> hi -> data.value, ", EAX");
				}
			}
			if(root -> hd -> flag == 0){
				fprintf(f,"%s%d%s\n" ,"DIV ", root -> hd -> data.var.value, ", EAX");
			}else{
				fprintf(f,"%s%d%s\n" ,"DIV ", root -> hd -> data.value, ", EAX");
			}
		}
		
	}
}


