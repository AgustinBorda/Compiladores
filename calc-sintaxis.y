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
%type<i> expresion
%type<d> declaration

%left '=' 
%left '+' '-' 
%left '*' '/'
 
%%
 
prog: expresion ;
    | declaration ';' prog  { printf( "Variable: %s\n", $1 -> name );
                          printf( "Valor: %d\n", $1 -> value );  };
    | {};
                    

declaration :  VAR  ID '=' expr {  $$ = loadVar($2,$4) ;  };
             
             | VAR ID { $$ = loadVar($2,0);};             
                                  
                              

expresion :expresion expr  ';'     { printf("%s%d\n", "Resultado: ",$2);  };
                                   
          | {};
  
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
    ;
 
%%


