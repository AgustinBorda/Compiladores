
typedef struct dato {	
	int value;
	char* name;
}dato;

typedef struct nodo {
	dato info;
	struct nodo *sig;

}nodoL;

int cant_var = 0; // cantidad de variables insertada en la tabla de simbolos

typedef nodoL* lista;
//typedef struct dato info_var;

int insertar( char* var, int valor);

int existe( char* var);

int buscar_valor( char* var);

void mostrar();

int loadValue(char * var, int valor);

void borrar(int pos);


