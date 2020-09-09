%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Lista.c"
lista list = NULL;

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
                    

declaration :  VAR  ID '=' expr {	int ins = insertar(&list,$2,$4);	    
	    				if(ins == 0){
	    					notifyError("Duplicate variable", $2);
   					}	    
	   				printf("assigned value: %d\n",$4);  
			}
             
             | VAR ID { 
			if(insertar(&list,$2,0) == 0) {
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
			if(existe(list,$1) != 0) { 
				$$ = buscar_valor(list,$1);
			}
			else {
				notifyError("Undeclared variable", $1);
			}		
		 }

    | ID '=' expr    	{
			if(existe(list,$1) != 0){
				borrar(&list,$1);
				insertar(&list,$1,$3);
			}
			else {
				notifyError("undeclared variable",$1);  
			}
		}
    ;
 
%%


