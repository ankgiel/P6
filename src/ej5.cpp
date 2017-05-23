//EJ_5.cpp
#include "ej5.h"
#include "Matriz2D-2.h"

int buscaMax(int * vec, int num){
	int max = vec[0] ;
	for(int i=1 ; i<num ; i++)
		if (vec[i]>max)
			max = vec[i] ; 
	return max ; 
}

int numElementos(TipoValor * valores){
	int num=0; 
	int i=0;
	while(valores[i] != '0')
		num++; 
	return num ; 
}


MatrizDispersa::MatrizDispersa(){
	nfilas=0; 
	ncolumnas=0; 
	valores=0;
	numeroValores=0;
}

MatrizDispersa::MatrizDispersa(int* filas, int* columnas, TipoValor* numeros){
	numeroValores = numElementos(numeros);
	nfilas = buscaMax(filas,numeroValores);
	ncolumnas = buscaMax(columnas,numeroValores);

	int f,c ; 
	TipoValor n ;

	valores = new Valor [numeroValores] ; 

	for(int i=0 ; i<numeroValores ; i++){
		f=filas[i]; 
		c=columnas[i];
		n=numeros[i];
		valores[i](f,c,n);
	}
}

void MatrizDispersa::MuestraValores(){
	for(int i=0 ; i<numeroValores ; i++)
		valores[i].mostrar() ; 
}


Matriz2D_2 MatrizDispersa::CreaMatrizDispersa (){
	Matriz2D_2 matriz = CreaMatriz2D_2(nfilas,ncolumnas);

	for( int f=0 ; f<nfilas ; f++ ) 
		for (int c=0 ; c<ncolumnas ; c++ ) 
			matriz[f][c] = 0 ;

	for(int k=0 ; k<numeroValores ; k++)
		matriz [valores[k].getfila()] [valores[k].getcolumna()] = valores[k].getvalor(); 

	return matriz ; 
}


	
 