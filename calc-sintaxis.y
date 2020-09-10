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
 
%union {struct date* d ; int i; char *s; struct node *n}  
 
%token<i> INT
%token<s> ID
%token<s> VAR

%type<n> expr
%type<d> declaration

%left '=' 
%left '+' '-' 
%left '*' '/'
 
%%
 
prog: line {printf("line alone\n");}
    | line ';' prog  { printf( "prog after line\n");  }
    | {}
    ;
                    

declaration :  VAR  ID '=' expr {	int ins = insertar(&symbol_table,$2,$4->info.name);	    
	    				if(ins == 0){
	    					notifyError("Duplicate variable", $2);
   					}	    
	   				printf("assigned value: %d\n",$4);  
			}
             
             | VAR ID { 
			if(insertar(&symbol_table,$2,0) == 0) {
				notifyError("Duplicate variable", $2);
			}
			printf("assigned variable without value\n");
	     };             
                                  
                              
line: declaration {printf("declaration\n");}
    | expr        {inorden($1->info.name); };

                                   
  
expr:ID                 { if (existe($1)==1) $$ = load_node( NULL, NULL, 0, ret_valor($1));
                          else{
                            printf("%s%s\n", "Variable no declarada :",$1);
                            $$ = NULL;
                          }
                        }  
    |INT                { $$ = newNodeInt($1);
                           //show_node(newNodeInt($1));
                        }
    | expr '+' expr     { $$ = load_nodeOP( $1, $3, 2, '+');
                           //show_node(load_nodeOP( $1, $3, 2, '+'));      
                        }
    | expr '-' expr     { $$ =  load_nodeOP( $1, $3, 2, '-');
                           //show_node(load_nodeOP( $1, $3, 2, '-'));
                        }
    | expr '*' expr     { $$ =  load_nodeOP( $1, $3, 2, '*');
                           //show_node(load_nodeOP( $1, $3, 2, '*'));
                        }                    
    | expr '/' expr     { $$ =  load_nodeOP( $1, $3, 2, '/');
                           //show_node(load_nodeOP( $1, $3, 2, '/'));
                        }
    | '(' expr ')'      { $$ =  $2; }

    | ID		{
			if(existe(symbol_table,$1) != 0) { 
				$$ = buscar_valor(symbol_table,$1);
			}
			else {
				notifyError("Undeclared variable", $1);
			}		
		 }

    | ID '=' expr    	{
			if(existe(symbol_table,$1) != 0){
				mostrar(symbol_table);
				borrar(&symbol_table,$1);
				insertar(&symbol_table,$1,$3);
				mostrar(symbol_table);
			}
			else {
				notifyError("undeclared variable",$1);  
			}
		}
    ;
 
%%


