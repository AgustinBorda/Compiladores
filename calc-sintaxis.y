%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "src/table.c"
#include "src/tree.c"

nodoL* symbol_table = NULL;

void notifyError(char* msg, char* var) {
	printf("%s: %s\n", msg, var);
	exit(1);
}
%}	
 
%union { int i; char *s; struct node *n}  
 
%token<i> INT
%token<s> ID
%token<s> VAR

%type<n> expr
%type<n> declaration

%left '=' 
%left '+' '-' 
%left '*' '/'
 
%%
 
prog: line {printf("line alone\n");}
    | line ';' prog  { printf( "\n");  }
    | {}
    ;
                    

declaration :  VAR  ID '=' expr {	
              struct dato d; 
              d.name = $2 ;
              d.value = $4;
              $$ = load_node(NULL, NULL, 0, d);
              int ins = insertar(&symbol_table, $2, $4);	    
	    				if(ins == 0) {
	    					notifyError("Duplicate variable", $2);
   					}	    
	   			//	printf("assigned value: %d\n",$4);  
			}
             
             | VAR ID { 
			if(insertar(&symbol_table,$2,0) == 0) {
				notifyError("Duplicate variable", $2);
			}
			//printf("assigned variable without value\n");
	     };             
                                  
                              
line: declaration {/*printf("declaration\n")*/;}
    | expr        {inorden($1); };

                                   
  
expr:
    INT                { $$ = newNodeInt($1);
                           //show_node(newNodeInt($1));
                        }
    | expr '+' expr     { $$ = load_nodeOP( $3, $1, 2, '+');
                           //show_node(load_nodeOP( $3, $1, 2, '+'));      
                        }
    | expr '-' expr     { $$ =  load_nodeOP( $3, $1, 2, '-');
                           //show_node(load_nodeOP( $3, $1, 2, '-'));
                        }
    | expr '*' expr     { $$ =  load_nodeOP( $3, $1, 2, '*');
                           //show_node(load_nodeOP( $3, $1, 2, '*'));
                        }                    
    | expr '/' expr     { $$ =  load_nodeOP( $3, $1, 2, '/');
                           //show_node(load_nodeOP( $3, $1, 2, '/'));
                        }
    | '(' expr ')'      { $$ =  $2; }
    ;
 
%%


