
/*typedef struct dato {	
	int value;
	char* name;
}dato;*/



typedef struct node {
	struct node* hi;
	struct node* hd;
	int flag; // 0 variable , 1 constante , 2 op
	struct dato data; //var
	int valor; //constante
	char op ;
}node;

int cant_nod = 0; // cantidad de variables insertada en la tabla de simbolos

typedef node* tree;

node* load_node( tree nd, tree ni, int f, dato inf);
node* load_nodeOP(  tree nd, tree ni, int f, char op);
node* newNodeInt (int a); 
int size();