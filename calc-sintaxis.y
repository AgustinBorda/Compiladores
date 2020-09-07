%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Lista.c"
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
                    

declaration :  VAR  ID '=' expr {  $$ = loadVar($2,$4) ;  }
             
             | VAR ID { $$ = loadVar($2,0);};             
                                  
                              
line: declaration {printf("declaration\n");}
    | expr {printf("expression\n");};

                                   
  
expr: INT               { $$ = $1; 
                           printf("%s%d\n","Constante entera:",$1);
                        }                    
    | expr '+' expr     { $$ = $1 + $3; 
                          // printf("%s,%d,%d,%d\n","Operador Suma\n",$1,$3,$1+$3);
                        }
    | expr '-' expr     { $$ = $1 - $3; 
                          // printf("%s,%d,%d,%d\n","Operador Resta\n",$1,$3,$1-$3);  
                        }
    | expr '*' expr     { $$ = $1 * $3; 
                          // printf("%s,%d,%d,%d\n","Operador Producto\n",$1,$3,$1*$3);  
                        }                    
    | expr '/' expr     { $$ = $1 / $3; 
                          // printf("%s,%d,%d,%d\n","Operador Division\n",$1,$3,$1/$3);  
                        }                                                                                                        
    | '(' expr ')'      { $$ =  $2; }

    | ID		{ printf("variable usada");}
    ;
 
%%


