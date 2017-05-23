#include <iostream>
#include "Precuencias.h"
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Precuencias::CopiarParejas (const Precuencias& aux){
	for (int i = 0; i < getnPares (); i++)
		this -> operator [] (i) = aux [i];
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Precuencias::Swap (Precuencias &aux){
	Pareja *par = aux.parejas;
	int n_par = aux.getnPares ();

// Intercambia el puntero de las parejas

	aux.parejas = this -> parejas;
	aux.npares = this -> npares;

// Intercambia el número de parejas del vector

	this -> parejas = par;
	this -> npares = n_par;
}

// Si existe devuelve la posición de la pareja
// Sino devuelve -1 (valor no permitido en el rango)

int Precuencias::ExisteValor (int i){
	bool existe = false;
	int j = 0;

	while (j < getnPares () && !existe){
		++j;

		if (i == (parejas + j) -> getDato ())
			existe = true;
	}

	return (existe) ? j : -1;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

Pareja& Precuencias::operator[] (int i){
	if (i > 0 && i < npares)
		return parejas [i];
}

Pareja& Precuencias::operator[] (int i) const{
	if (i > 0 && i < npares)
		return parejas [i];
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

Precuencias::Precuencias (const Precuencias &aux){
	npares = aux.npares;
	parejas = new Pareja [npares];

	CopiarParejas (aux);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Precuencias::ReSize (int i){
	Precuencias reaux;

	reaux.parejas = new Pareja [getnPares () + i];
	reaux.npares += getnPares () + i;

	CopiarParejas (reaux);
	Swap (reaux);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

Precuencias& Precuencias::operator= (const Precuencias& aux){
	if (&aux != this){
		Precuencias reaux (aux);

		Swap (reaux);
	}

	return *this;
}

ostream& operator<< (ostream& out, const Precuencias& aux){
	for (int i = 0; i < aux.getnPares (); i++)
		out << "Pareja " << i << ": " << aux [i];
}

ostream& operator<< (ostream& out, const Pareja aux){
	out << "Número " << aux.getDato () << ", " << aux.getNVeces () << " veces." << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
	Si existe suma nveces en pareja
	Sino inserta nueva pareja
	Incrementa el número de npares
	Introduce el valor en la pareja nueva
*/

Precuencias& Precuencias::agregarValor (int i){
	if (ExisteValor (i) != -1)
		++(parejas + i) -> getNVeces ();
	else{
		ReSize ();
		(parejas + getnPares () - 1) -> getDato () = i;
		(parejas + getnPares () - 1) -> getNVeces () = 1;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

istream& operator>> (istream& in, Precuencias& aux){
	int num;

	cout << "Introduzca número: ";
	in >> num;

	if (num >= 0 && num < 10)
		aux.agregarValor (num);
	else
		throw length_error ("Gracias por participar.");
}
