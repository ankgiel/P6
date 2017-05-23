#ifndef _PRECUENCIAS_H
#define _PRECUENCIAS_H

#include <iostream>
using namespace std;

class Pareja{
	int nveces;
	int dato;

public:

// Constructor por defecto

	Pareja (): nveces (0), dato (0) {}

// Constructor explícito que inserta un nuevo dato

	explicit Pareja (int n): nveces (1), dato (n) {}

// Constructor de copia

	Pareja (const Pareja& aux): nveces (aux.getNVeces ()), dato (aux.getDato ()) {}

	const int& getDato () const { return dato; }
	int& getDato () { return dato; }
	const int& getNVeces () const { return nveces; }
	int& getNVeces () { return nveces; }
};

ostream& operator<< (ostream&, const Pareja);

class Precuencias{
	Pareja *parejas;
	int npares;

	inline void CopiarParejas (Precuencias&);

// Intercambia el valor de 2 precuencias

	void Swap (Precuencias &);

/*
	Comprueba si n está ya insertado en alguna pareja
	Devuelve un entero indicando la pareja en la que está
	Si no existe devuelve -1
*/

	int ExisteValor (int);

// Redimensiona Precuencias

	void ReSize (int = 1);

public:

// Constructor por defecto

	Precuencias (): parejas (0), npares (0) {}

// Constructor de copia

	Precuencias (const Precuencias&);

// Destructor

	~Precuencias (){ delete [] parejas; }

// Operador de asignación

	Precuencias& operator= (const Precuencias&);

// Agrega un nuevo valor a la precuencia exista o no

	Precuencias& agregarValor (int);

	int getnPares () const
	{
		return npares;
	}

	inline Pareja& operator[] (int);
	inline Pareja& operator[] (int) const;
	friend istream& operator>> (istream&, Precuencias&);
};

istream& operator>> (istream&, Precuencias&);
ostream& operator<< (ostream&, const Precuencias&);

#endif
