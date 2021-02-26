#include<stdio.h>
#include<conio.h>
#include<iostream>

using namespace std;

struct Nodo
{
	char ascii[1];
	int numAscii;
	int cantidad;
	Nodo *siguiente = NULL;
	Nodo *anterior = NULL;
	
};

struct listaSimple
{
	Nodo *primerNodo;
	Nodo *ultimoNodo;
	
	listaSimple()
	{
		//constructor del struct
		primerNodo = NULL;
		ultimoNodo = NULL;
	}
	
	add(Nodo *qNodo)
	{
		if (primerNodo == NULL)
     	{
        	primerNodo = qNodo;
         	ultimoNodo = primerNodo; // ambos apuntan al nuevo               
     	}
     	else
     	{	
         	ultimoNodo->siguiente = qNodo;
         	ultimoNodo = qNodo;	
     	}
	}
	
	
};

int main()
{
	listaSimple *lista = new listaSimple();
	

	cout << "programa finalizado con éxito";	
return 0;}

