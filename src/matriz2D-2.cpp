#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <iostream>
#include "Matriz2D-2.h"

using namespace std; 
/*MATRIZ CONTINUA EN MEMORIA DE TAMAÑO FILAxCOLUMNAS.
PRIMERO ENLAZA UN PUNTERO AL ELEMENTO INICIAL
PARA EL RESTO DE PUNTEROS, ENLAZA EL INICIO DE CADA FILA
SUMANDOLE EL ANCHO DE FILAS(COLUMNAS)*/

Matriz2D_2 CreaMatriz2D_2 (int fils, int cols) 
{
	Matriz2D_2 matriz ; 

	matriz = new TipoBase * [fils] ; 

	matriz[0] = new TipoBase [fils*cols] ; 

	for(int f=1 ; f<fils ; f++)
		matriz[f] = matriz[f-1] + cols ; 

	return matriz ; 	
}


void liberaMatriz2D_2 (Matriz2D_2 matriz, int fils , int cols)
{
	delete [] matriz[0] ; 
	delete [] matriz ; 
}


Matriz2D_2 LeeMatriz2D_2 (int fils , int cols) 
{
	Matriz2D_2 matriz = CreaMatriz2D_2 (fils,cols) ; 

	for( int f=0 ; f<fils ; f++ ) 
		for (int c=0 ; c<cols ; c++ ) 
		{
			cout << "Elemento " << setw(3) << f << " ," << setw(3) << c << " - " ;
			cin >> matriz[f][c] ;
		}
	return matriz ; 
}

Matriz2D_2 AleatoriaMatriz2D_2 (int fils , int cols, int max) 
{
	Matriz2D_2 matriz = CreaMatriz2D_2 (fils,cols) ; 

	for( int f=0 ; f<fils ; f++ ) 
		for (int c=0 ; c<cols ; c++ ) 
			matriz[f][c] = rand()%max ;	
	return matriz ; 
}


void MuestraMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols)
{
	for (int f=0 ; f<fils ; f++){
		cout << "Fila " << f << " - " ;
		for (int c=0 ; c<cols ; c++)
			cout << setw(3) << matriz[f][c] ;
		cout << endl ; 
	}
}


Matriz2D_2 CopiaMatriz2D_2 (Matriz2D_2 matriz , int fils , int cols ) 
{
	Matriz2D_2 copia = CreaMatriz2D_2 (fils,cols) ; 

	memcpy (copia[0] , matriz[0] , fils*cols*sizeof(TipoBase)) ; 

	return copia ; 
}


Matriz2D_2 SubMatriz2D_2 (Matriz2D_2 matriz , int fil_ini , int col_ini, int fil_end , int col_end)
{
	int num_fils = fil_end - fil_ini +1 ; 
	int num_cols = col_end - col_ini +1 ; 

	Matriz2D_2 submatriz = CreaMatriz2D_2 (num_fils, num_cols) ;

	for(int f_sub=0 , f_mat=fil_ini ; f_sub<num_fils ; f_mat++ , f_sub++)
		memcpy (submatriz[f_sub], &(matriz[f_mat][col_ini]), num_cols*sizeof(TipoBase));

	return submatriz ; 
}


Matriz2D_2 EliminaFilaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int fila_borrar) 
{
	Matriz2D_2 reducida = CreaMatriz2D_2 (fils -1 , cols) ; 

	memcpy ( reducida[0] , &(matriz[0][0]) , fila_borrar*cols*sizeof(TipoBase) ) ;

	memcpy ( reducida[fila_borrar] , &(matriz[fila_borrar+1][0]) , (fils - fila_borrar-1)*cols*sizeof(TipoBase)) ; 

	return reducida ; 
}

Matriz2D_2 EliminaColumnaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int columna_borrar) 
{
	Matriz2D_2 reducida = CreaMatriz2D_2 (fils , cols -1) ; 

	for(int f=0 ; f<fils ; f++)
	{
		memcpy ( reducida[f] , &(matriz[f][0]) , columna_borrar*sizeof(TipoBase) ) ;
		memcpy ( reducida[f]+columna_borrar , &(matriz[f][columna_borrar+1]) , (cols - columna_borrar)*sizeof(TipoBase) ) ;
	}

	return reducida ; 
}


Matriz2D_2 TraspuestaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols) 
{
	int fils_t = cols ; 
	int cols_t = fils ; 

	Matriz2D_2 traspuesta = CreaMatriz2D_2 (fils_t , cols_t);

		for(int f_t=0 ; f_t<fils_t ; f_t++)
		for (int c_t=0 ; c_t<cols_t ; c_t++)
			traspuesta[f_t][c_t] = matriz[c_t][f_t] ;

	return traspuesta ;
}

Matriz2D_2 InvierteMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols)
{
	Matriz2D_2 invertida = CreaMatriz2D_2 (fils,cols) ; 

	for(int f=0 , j=fils-1 ; f<=j ; f++ , j--)
	{
		memcpy (invertida[f] , &(matriz[j][0]) , cols*sizeof(TipoBase));
		memcpy (invertida[j] , &(matriz[f][0]) , cols*sizeof(TipoBase));
	}

	return invertida ; 
}