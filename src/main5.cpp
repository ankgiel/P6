//EJ_5.cpp
#include <iostream>
#include "ej5.h"
#include "Matriz2D-2" 

using namespace std; 

int main (){
	int x;

	cout << "Nº de elementos que va a introducir: " << endl; 
	cin >> x; 

	int arrayfilas[x]; 
	int arraycolumnas[x]; 
	TipoValor arrayvalores[x]; 

	for(int i=0 ; i<x ; i++){
		cout << endl << "Introduzca los valores del elemento : " << i << endl; 
		cout << "Filas: " << endl; 
		cin >> arrayfilas[i];
		cout << "Columnas: " << endl;
		cin >> arraycolumnas[i]; 
		cout << "Valor: " << endl;
		cin >> arrayvalores[i];
	}

	cout << "Fin de insercción de valores" << endl;

	cout << "Array de filas: "
	for(int j=0 ; j<x ; j++)
		cout << arrayfilas[j] << " , " ;

	cout << "Array de columnas: "
	for(int k=0 ; k<x ; k++)
		cout << arraycolumnas[k] << " , " ;

	cout << "Array de valores: "
	for(int l=0 ; l<x ; l++)
		cout << arrayvalores[l] << " , " ;

	MatrizDispersa md1(arrayfilas,arraycolumnas,arrayvalores); 

	md1.MuestraValores() ; 


} 