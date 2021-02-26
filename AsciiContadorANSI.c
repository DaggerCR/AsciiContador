#include<stdlib.h>
#include<stdio.h>




struct Nodo
{
	char ascii;
	int numAscii;
	int cantidad;
	struct Nodo *siguiente;
	
	
};

struct listaSimple
{
	struct Nodo *primerNodo;
	struct Nodo *ultimoNodo;

};struct listaSimple *lista;
	
	


int buscarAscii(int x)
	{
		//busca en todos los nodos por el numero de ascii
		//entrada: x = el int del ascii
		//salida: True1 si lo encuentra, False0 en caso contrario
		
		if(lista->primerNodo == NULL)
			return 0;
						
		struct Nodo *tmp;
		tmp = lista->primerNodo;
		
		while(tmp != NULL)
		{
			if(tmp->numAscii == x)
			{
				tmp->cantidad++;
				return 1;
			}	
			tmp = tmp->siguiente;
		}
		return 0;
		
	}

void add(char qAscii, int qNumAscii)
{
	//Añade el caracter a la lista simple 
	//entrada: el char plano del archivo de texto, su número de ascii
	//salida: ninguna
	
	struct Nodo *nuevo;
	nuevo=(struct Nodo*)malloc(sizeof(struct Nodo));
	
	nuevo->cantidad = 1;
	nuevo-> ascii = qAscii;
	nuevo-> numAscii = qNumAscii;
	
	if (lista->primerNodo == NULL)
    	{
       		lista->primerNodo = nuevo;
       	 	lista->ultimoNodo = lista->primerNodo; // ambos apuntan al nuevo               
     	}
     	else
     	{	
         	lista->ultimoNodo->siguiente = nuevo;
         	lista->ultimoNodo = nuevo;	
     	}
}
	

void imprimir()
{
	//imprime la lista completa
	//entrada: ninguna
	//salida: ninguna
		

	if(lista->primerNodo == NULL)
		printf("La lista esta vacia");
	else
	{
		struct Nodo *tmp;
		tmp = lista->primerNodo;
		while(tmp != NULL)
		{
			printf("Char: %c    Ascii:%d    cantidad: %d\n",tmp->ascii,tmp->numAscii,tmp->cantidad);
			tmp = tmp->siguiente;
		}
			
	}
}



int main ()
{


	lista = (struct listaSimple*)malloc(sizeof(struct listaSimple));	
	
	FILE *fp;
    	int c;
    	fp = fopen("frase2.txt","rt");
    	while(1)
 	{
     		c = fgetc(fp);
       		if( c == EOF)
          		break;
       		if(buscarAscii(c) == 0)
			add(c,c);
   	}
   	imprimir();
   	fclose(fp);
   	
   	printf("\nAdios");
   	return(0);
}

