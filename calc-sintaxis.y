%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "src/table.c"
#include "src/tree.c"
#include "interprete/interprete.c"
#include "src/assembly.c"
tree t = NULL;
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
%type<s> declaration

%left '=' 
%left '+' '-' 
%left '*' '/'
 
%%
 
prog: line ';' prog  {}
    | line {}
    | {}
    ;
                    

declaration :  VAR  ID '=' INT {	
             
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
                                  
                              
line: declaration {}
    | expr        {
                    printf("resultado: %d\n",eval($1, symbol_table));
                    if(assemble($1, symbol_table) == 0) {
                     printf("Ensamblado\n");
                    }
                      
                  };

                                   
  
expr:
    INT                { 
                          struct type t;
                           t.value = $1;
                      $$ = load_node(NULL,NULL,1,t);
                           
                        }
    | ID                { 
                                              struct dato d;
                                              d.name = $1;
                                              d.value = buscar_valor(symbol_table, $1);
                                              struct type t;
                                              t.var = d;
                                              $$ =  load_node(NULL, NULL, 0, t);
                                              

                        }                   
    | expr '+' expr     {   struct type t;
                            t.op = '+';
                          $$ = load_node( $3, $1, 2,t);
                              
                        }
    | expr '-' expr     {
                        struct type t;
                        t.op = '-'; 
                        $$ =  load_node( $3, $1, 2, t);
                         
                        }
    | expr '*' expr     {
                        struct type t;
                        t.op = '*'; 
                        $$ =  load_node( $3, $1, 2, t);
                         
                        }                    
    | expr '/' expr     {
                        struct type t;
                        t.op = '/'; 
                        $$ =  load_node( $3, $1, 2, t);
                          
                        }
    | '(' expr ')'      { $$ =  $2; }
    ;
 
%%


