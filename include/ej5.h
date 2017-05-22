#ifndef EJ_5
#define EJ_5
#include <iostream>
using namespace std;

typedef double TValor

int BuscaMax(int * vec, int );

class MatrizDispersa{
private:
	int nfilas;
	int ncolumnas; 
	Valor * valores;
	int numeroValores;

	int numElementos(TValor * valores); 
	void CopiaValores (const MatrizDispersa &);
public: 
	MatrizDispersa() ; 
	MatrizDispersa(int* filas, int* columnas, double* numeros) ; 
	MatrizDispersa (const MatrizDispersa&);
	~MatrizDispersa(){
		delete[] valores;
	}

	int getnumeroValores() const {
		return numeroValores ; 
	}
	int getFilas () const {
		return nfilas;
	}
	int getColumnas () const {
		return ncolumnas;
	}

// Faltaría un método para asignar valores
	
	MatrizDispersa &operator= (const MatrizDispersa&);
	
	friend ostream& operator<< (ostream&, const MatrizDispersa&);
	friend istream& operator>> (istream&, MatrizDispersa&);
}

ostream& operator<< (ostream&, const MatrizDispersa&);
istream& operator>> (istream&, MatrizDispersa&);

#endif 
