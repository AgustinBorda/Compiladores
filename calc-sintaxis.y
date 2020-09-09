%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "src/table.c"
nodoL* symbol_table = NULL;

void notifyError(char* msg, char* var) {
	printf("%s: %s\n", msg, var);
	exit(1);
}
%}	
 
%union {struct date* d ; int i; char *s;}  
 
%token<i> INT
%token<s> ID
%token<s> VAR


%type<i> expr
%type<d> declaration

%left '=' 
%left '+' '-' 
%left '*' '/'
 
%%
 
prog: line {printf("line alone\n");}
    | line ';' prog  { printf( "prog after line\n");  }
    | {}
    ;
                    

declaration :  VAR  ID '=' expr {	int ins = insertar(&symbol_table,$2,$4);	    
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
    | expr {printf("expression\n");};

                                   
  
expr: INT               { $$ = $1; 
                           printf("%s%d\n","Constante entera:",$1);
                        }                    
    | expr '+' expr     { $$ = $1 + $3; 
                           printf("%s,%d,%d,%d\n","Operador Suma\n",$1,$3,$1+$3);
                        }
    | expr '-' expr     { $$ = $1 - $3; 
                           printf("%s,%d,%d,%d\n","Operador Resta\n",$1,$3,$1-$3);  
                        }
    | expr '*' expr     { $$ = $1 * $3; 
                           printf("%s,%d,%d,%d\n","Operador Producto\n",$1,$3,$1*$3);  
                        }                    
    | expr '/' expr     { $$ = $1 / $3; 
                           printf("%s,%d,%d,%d\n","Operador Division\n",$1,$3,$1/$3);  
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


