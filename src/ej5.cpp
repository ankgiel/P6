//EJ_5.cpp
#include "ej5.h"

int buscaMax(int * vec){
	int max = vec[0] ;
	for(int i=1 ; i<getnumeroValores() ; i++)
		if (vec[i]>max)
			max = vec[i] ; 
	return max ;
}

int numElementos(TValor * valores){
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
MatrizDispersa::MatrizDispersa(int* filas, int* columnas, double* numeros){
	numeroValores = numElementos(numeros);
	nfilas = buscaMax(filas);
	ncolumnas = buscaMax(columnas);
}
	
 
