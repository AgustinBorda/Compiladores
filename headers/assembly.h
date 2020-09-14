#include "structures.h"

int assemble(node* head, nodoL* sym_table);

void writeConst(node* root, char* resLoc, FILE* f);

void writeId(node* root, char* resLoc, FILE* f, nodoL* sym_table);

void writeOp(node* root, char* resLoc, FILE* f, nodoL* sym_table);

void write(node* root, char* resLoc, FILE* f, nodoL* sym_table);
