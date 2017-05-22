#include "BigInt.h"
#include <iostream>
#include <stdlib.h>
using namespace std;



/*
	Crea un vector auxiliar
	Copia Vector
	Cambia el valor del tamaño
	Libera auxiliar
*/

template <typename T>
void Redimensiona (T*& p, long long int& cap, long long int tam){
		if (cap + tam > 0){
			T* aux = new T [cap + tam];

			CopiaVector (aux, p, cap + tam);
			Swap (p, aux);
			cap += tam;

			delete [] aux;
		}
		else
			throw length_error ("Error al introducir los datos en Redimensiona.");
}

BigInt::BigInt (): util (1), capacidad (1){
	v = new short [1];
}

BigInt::BigInt (const BigInt &numero) : util (getUtil ()), capacidad (getCapacidad ()){
	v = new short [capacidad];

	for (int i = 0; i < util; i++)
		v [i] = numero.v [i];
}

BigInt& BigInt::operator= (const BigInt& numero){
	if (this != &numero){
		BigInt *aux  = new BigInt (numero);
		BigInt *aux_2;

		aux_2 = this;
		this = aux;
		aux = aux_2;
		
		delete aux;
	}

	return *this;
}

BigInt::~BigInt (){
	delete v;
}

BigInt& BigInt::operator+ (const BigInt& numero) const
{
	
	long long int cap = (capacidad >= numero.capacidad) ? capacidad : numero.capacidad;
	long long int usados = (util >= numero.util) ? util : numero.util;
	BigInt aux;
	short acarreo (0);

	aux.v = new short [cap + 1];

	for (int i = 0; i < util; i++){
		aux.v [i] = numero.v [i] + v [i] + acarreo;

		if (aux.v [i] >= 10){
			aux.v [i] -= 10;
			acarreo = 1;
		}
	}

	return aux;
}

istream& operator>> (istream& in, BigInt& numero){
	char aux;
	int i = 0;

	in.get (aux);

	while (aux != '\n'){
		numero.v [i] = atoi (aux);
		++i;

		if (i >= numero.util)
			++numero.util;
		if (i >= numero.capacidad)
			Redimensiona (numero.v, numero.capacidad, numero.capacidad);
		
		in.get (aux);
	}

	return in;
}

ostream& operator<< (ostream& out, const BigInt& numero){
	for (int i = 0; i < numero.getUtil (); i++)
		out << numero.v [i] << endl;

	return out;
}
