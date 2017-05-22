//EJ_5.cpp
#include "ej5.h"
#include <iostream>
using namespace std;

/*
	Creo que tiene más sentido como dato miembro privado
	Ayuda a calcular un método de la clase
	
	Todo método público debe ser antecedido por un objeto de dicha clase
*/

int buscaMax(int *valores){
	int max = valores [0] ;
	
	for(int i = 1 ; i < getnumeroValores() ; i++)
		if (vec [i] > max)
			max = vec[i] ; 
	return max ;
}

int numElementos(TValor * valores){
	int num=0; 
	int i=0;
	
	while(valores[i] != '0')
// Es más eficiente ++num; num++, posdata: es un puto detalle pero dicen que se agradece
		++num; 
	return num ; 
}


MatrizDispersa::MatrizDispersa(){
	nfilas=0; 
	ncolumnas=0; 
	valores=0;
	numeroValores=0;
}

MatrizDispersa::MatrizDispersa(int* filas, int* columnas, double* numeros){
	numeroValores = numElementos(numeros);
	nfilas = buscaMax(filas);
	ncolumnas = buscaMax(columnas);

// Faltaba esta parte
// Reserva tantos objetos Valor como números válidos haya
	
	this -> valores = new Valor [numeroValores];

// Asigna todos sus valores
	
	for (int i = 0; i < numeroValores; i++){
		this -> valores [i].setValor (filas [i], columnas [i], numero [i]);
}

// Intercambia el contenido de 2 matrices dispersas
	
void MatrizDispersa::Swap (MatrizDispersa &aux){

	// Valores auxiliriares	

	int filas = this -> nfilas;
	int columnas = this -> ncolumnas;
	int numeroValores = this -> numeroValores;
	Valor *valores = this -> valores;
	
	// Introduce en el objeto implícito los datos miembros auxiliares
	
	this -> nfilas = aux.nfilas;
	this -> ncolumnas = aux.ncolumnas;
	this -> numeroValores = aux.numeroValores;
	this -> valores = aux.valores;
	
	// Introduce en el objeto enviado los valores de this
	
	aux.nfilas = filas;
	aux.ncolumnas = columnas;
	aux.numeroValores = numeroValores;
	aux.valores = valores;
}

MatrizDispersa& MatrizDispersa::operator= (const MatrizDispersa &matriz){
	if (this != &matriz){
		MatrizDispersa aux (matriz);
		
		Swap (aux);
	}
	
	return *this;
}

MatrizDispersa::MatrizDispersa (const MatrizDispersa &matriz){
	this -> nfilas = matriz.nfilas;
	this -> ncolumnas = matriz.ncolumnas;
	this -> numeroValores = matriz.numeroValores;
	this -> valores = new Valor [numeroValores];
	
	CopiaValores (matriz);
}

// Posible método erróneo
	
void MatrizDispersa::CopiaValores (const MatrizDispersa &matriz){
	for (int i = 0; i < numeroValores; i++)
	// Al no haber datos miembros que sean punteros, no importa asignar 2 objetos de una misma clase
	// la asignación se produce campo a campo
		this -> valores [i] = matriz.valores [i];
}
	
ostream& operator<< (ostream& out, const MatrizDispersa &matriz){
	for (int i = 0; i < matriz.getnumeroValores (); i++)
		out << "Valor " << i << ": " << valores;
}
