%{

#include <stdlib.h>
#include <stdio.h>

#include "table.c" 

%}
 
%union { int i; char *s; }
 
%token<i> INT
%token<s> ID
%token VAR

%type<i> expr
%type<i> expresion
 
%left '+' 
%left '*'
 
%%
 
prog: expresion ;
    | decl_var expr ';' prog           { printf("%s%d\n", "Resultado: ",$2); } 
    | {}
    ;
  
expresion :expresion expr  ';'     { printf("%s%d\n", "Resultado: ",$2);  };

          | {};


decl_var : VAR ID '=' INT ';' decl_var { if (existe($2)==0) insertar($2, $4);
                                         else  printf("%s%s\n", "Variable redeclarada :",$2);
                                       }
         |  
         ;  
  
expr: ID              { if (existe($1)==1) $$ = buscar_valor($1);
                        else{
                              printf("%s%s\n", "Variable no declarada :",$1);
                              $$ = 0;
                            }   
                       }  
    |INT               { $$ = $1; 
                           printf("%s%d\n","Constante entera:",$1);
                        }
    | expr '+' expr     { $$ = $1 + $3; 
                          // printf("%s,%d,%d,%d\n","Operador Suma\n",$1,$3,$1+$3);
                        }
    | expr '*' expr     { $$ = $1 * $3; 
                          // printf("%s,%d,%d,%d\n","Operador Producto\n",$1,$3,$1*$3);  
                        }
    | '(' expr ')'              { $$ =  $2; }
    ;
 
%%



                        




