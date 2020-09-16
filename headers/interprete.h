#ifndef _INTERPRETER_H
#define _INTERPRETER_H
#include "structures.h"

void semError();

int eval(node* root, nodoL* sym_table);

int getValueConstant(node* root);

int getValueId(node* root, nodoL* sym_table);

int getValueOp(node* root, nodoL* sym_table);

#endif
