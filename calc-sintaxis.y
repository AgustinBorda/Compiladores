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
 
prog: line ';' prog  { printf( "\n");  }
    | {}
    ;
                    

declaration :  VAR  ID '=' INT {	
              struct dato d; 
              d.name = $2 ;
              d.value = $4;
              $$ = load_node(NULL, NULL, 0, d);
              int ins = insertar(&symbol_table, $2, $4);	    
	    				if(ins == 0) {
	    					notifyError("Duplicate variable", $2);
   					}	    
	   		  
			}
             
             | VAR ID { 
			if(insertar(&symbol_table,$2,0) == 0) {
				notifyError("Duplicate variable", $2);
			}
			
	     };             
                                  
                              
line: declaration {preorden($1);}
    | expr        {preorden($1);};

                                   
  
expr:
    INT                { $$ = newNodeInt($1);
                           
                        }
    | expr '+' expr     { $$ = load_nodeOP( $3, $1, 2, '+');
                              
                        }
    | expr '-' expr     { $$ =  load_nodeOP( $3, $1, 2, '-');
                         
                        }
    | expr '*' expr     { $$ =  load_nodeOP( $3, $1, 2, '*');
                         
                        }                    
    | expr '/' expr     { $$ =  load_nodeOP( $3, $1, 2, '/');
                          
                        }
    | '(' expr ')'      { $$ =  $2; }
    ;
 
%%


