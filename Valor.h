#ifndef VALOR_H
#define VALOR_H

#include <iostream>
using namespace std;

class Valor{
private:
    int fila;
    int columna;
    double valor;

	 bool CompruebaCorrecto (int i, int j = 0){
			return (i >= 0 && j >= 0) ? true : false;
	 }

public:

    /**
     * Constructor por defecto
     */
    Valor(){
    }

    /**
     * Constructor de la clase
     * @param fila
     * @param columna
     * @param valor
     */
    Valor(int fila, int columna, double valor){
      setValor (fila, columna, valor);
    }

	// Toma los valores del objeto

	int getFila () const {	return fila;	}
	int getColumna () const {	return columna;	}
	double getValor () const {	return valor;	}

	// Modifica los valores del objeto

	void setValor (int i, int j, double valor) {
		if (CompruebaCorrecto (i, j)){
			fila = i;
			columna = j;
			this -> valor = valor;
		}
	}
};

ostream& operator<< (ostream& out, const Valor& valor){
	out << "{" << valor.getFila () << ", " << valor.getColumna () << ", " << valor << "} ";
}

#endif //VALOR_H

 
