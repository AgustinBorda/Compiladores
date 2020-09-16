#ifndef _INTERPRETER_H
#define _INTERPRETER_H
#include "structures.h"

/*
*Error semantico
*/

void semError();

/*
*Decide el tipo de contenido de root y llama al metodo correspondiente
*/

int eval(node* root, nodoL* sym_table);

/*
*Escribe el valor constante de root en resLoc y lo escribe en f
*/

int getValueConstant(node* root);

/*
*Escribe el valor de la variable de root en resLoc
*y lo escribe en f
*/

int getValueId(node* root, nodoL* sym_table);

/*
*Realiza la operacion de root guarda el resultado en resLoc
*y lo escribe en f
*/

int getValueOp(node* root, nodoL* sym_table);

#endif
