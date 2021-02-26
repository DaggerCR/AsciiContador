#include<stdio.h>
#include<conio.h>
#include<iostream>
#include <fstream>

using namespace std;

struct Nodo
{
	char ascii;
	int numAscii;
	int cantidad;
	Nodo *siguiente = NULL;
	
	Nodo()
	{
		//constructor vacío
		//usado para los nodos temporales	
	}
	
	Nodo(char qAscii, int qNumAscii)
	{
		//constructor completo para los nodos de la lista simple
		ascii = qAscii;
		numAscii = qNumAscii;
		cantidad = 0;
	}
	
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
	
	bool buscarAscii(int x)
	{
		//busca en todos los nodos por el numero de ascii
		//entrada: x = el int del ascii
		//salida: True si lo encuentra, False en caso contrario
		
		if(primerNodo == NULL)
			return false;
						
		Nodo *tmp = new Nodo();
		tmp = primerNodo;
		
		while(tmp != NULL)
		{
			if(tmp->numAscii == x)
			{
				tmp->cantidad++;
				return true;
			}	
			tmp = tmp->siguiente;
		}
		return false;
		
	}
	
	void add(char qAscii, int qNumAscii)
	{
		//Añade el caracter a la lista simple 
		//entrada: el char plano del archivo de texto, su número de ascii
		//salida: ninguna
		
		Nodo *nuevo = new Nodo(qAscii, qNumAscii);
		nuevo->cantidad++;
		
		if (primerNodo == NULL)
     	{
        	primerNodo = nuevo;
         	ultimoNodo = primerNodo; // ambos apuntan al nuevo               
     	}
     	else
     	{	
         	ultimoNodo->siguiente = nuevo;
         	ultimoNodo = nuevo;	
     	}
	}
	
	void imprimir()
	{
		//imprime la lista completa
		//entrada: ninguna
		//salida: ninguna
		
		if(primerNodo == NULL)
			cout << "La lista esta vacia";
		else
		{
			Nodo *tmp = new Nodo();
			tmp = primerNodo;
			
			while(tmp != NULL)
			{
				printf("Char: %c    Ascii:%d    cantidad: %d\n",tmp->ascii,tmp->numAscii,tmp->cantidad);
				tmp = tmp->siguiente;
			}
			
		}
	}
	
};

int main()
{
	listaSimple *lista = new listaSimple();	
	
	fstream archivo;
	char letra;
	
	archivo.open ("frase2.txt", ios::in);
	if (archivo.is_open())
	{
		while (!archivo.eof() )
		{
			archivo >> letra;
			if(!lista->buscarAscii(letra))
				lista->add(letra,letra);
		}
		archivo.close();
		lista->imprimir();
	}
	else 
		cout << "No se encontró el archivo" << endl;
	
	cout << "programa finalizado con éxito";	
return 0;}

