#ifndef EJ_5
#define EJ_5

typedef double TValor

int BuscaMax(int * vec, int );
int numElementos(TValor * valores); 

class MatrizDispersa{
private:
	int nfilas;
	int ncolumnas; 
	Valor * valores;
	int numeroValores;

public: 
	MatrizDispersa() ; 
	MatrizDispersa(int* filas, int* columnas, double* numeros) ; 
	~MatrizDispersa(){
		delete[] valores;
	}

	int getnumeroValores() const {
		return numeroValores ; 
	}



}

#endif 