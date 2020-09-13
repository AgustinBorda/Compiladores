#include <stdio.h>
#include <stdlib.h>
#include "../headers/structures.h"

int open_file(tree head) {
	FILE* f;

	f = fopen("assembly.txt", "w+");
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
		fprintf(f,"%s%d\n" ,"MOV EAX, ", root -> data.var.value);
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
				}
			}
			if(root -> hd -> flag == 0){
				fprintf(f,"%s%d%s\n" ,"ADD ", root -> hd -> data.var.value, ", EAX");
			}else{
				fprintf(f,"%s%d%s\n" ,"ADD ", root -> hd -> data.value, ", EAX");
			}
		}
		if(root -> data.op == '*') {
			if(root -> hi -> flag == 0){
				fprintf(f,"%s\n", "MOV EAX, 1");
				fprintf(f,"%s%d%s\n" ,"MUL ", root -> hi -> data.var.value, ", EAX");
			}else{
				if(root -> hi -> flag == 1){
					fprintf(f,"%s\n", "MOV EAX, 1");
					fprintf(f,"%s%d%s\n" ,"MUL ", root -> hi -> data.value, ", EAX");
				}
			}
			if(root -> hd -> flag == 0){
				fprintf(f,"%s%d%s\n" ,"MUL ", root -> hd -> data.var.value, ", EAX");
			}else{
				fprintf(f,"%s%d%s\n" ,"MUL ", root -> hd -> data.value, ", EAX");
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


