#ifndef EJ_5
#define EJ_5

#include <iostream>
#include "Matriz2D-2.h"
using namespace std;

typedef double TipoValor ; 

int BuscaMax(int * vec, int num);
int numElementos(TipoValor * valores); 


class Valor{
private:
    int fila;
    int columna;
    TipoValor valor;

public:
    Valor(){}

    Valor(int fil, int col, TipoValor val){
    	if (fil>=0 && col>=0){
    		fila=fil;
    		columna=col;
    		valor=val;
    	}
    }

    int getfila() const {
		return fila ; 
	}

	int getcolumna() const {
		return columna ; 
	}

	TipoValor getvalor() const {
		return valor ; 
	}

    void mostrar() const {
        cout << "{" << fila << ", " << columna << ", " << valor << "} ";
    }
};

class MatrizDispersa{
private:
	int nfilas;
	int ncolumnas; 
	Valor * valores;
	int numeroValores;

public: 
	MatrizDispersa() ; 
	MatrizDispersa(int* filas, int* columnas, TipoValor* numeros) ; 
	~MatrizDispersa(){
		delete[] valores;
	} 

	int getnumeroValores() const {
		return numeroValores ; 
	}

	int getnfilas() const {
		return nfilas ; 
	}

	int getncolumnas() const {
		return ncolumnas ; 
	}

	Valor * getvalores() const {
		return valores ;
	}

	void MuestraValores();

	Matriz2D_2 CreaMatrizDispersa ();
};

#endif 