#ifndef _BIG_INT_H_
#define _BIG_INT_H_
#include <iostream>
using namespace std;

// Copia un vector en otro

template <class T>
inline void CopiaVector (T* p, T* v, int fin, int ini = 0){
	for (ini; ini < fin; ini++)
		p[ini] = v[ini];
}

/*
	Intercambia el valor de 2 punteros
*/

template <typename T>
inline void Swap (T*& p, T*& v){
	T* aux = p;
	p = v;
	v = aux;
}

/*
	Crea un vector auxiliar
	Copia Vector
	Cambia el valor del tamaño
	Libera auxiliar
*/

template <typename T>
void Redimensiona (T*&, long long int&, long long int);

/*
	Utilizo dos datos miembros:
		Capacidad: Contiene el número de enteros reservados
		Util: Contiene el número de enteros que están utilizados

	Objetivo:
		Reducir a O (1) la redimensión del objeto
*/

class BigInt{
	short *v;
	long long int util;
	long long int capacidad;
public:

// Constructor por defecto

	BigInt ();

// Constructor de copia

	BigInt (const BigInt&);

// Destructor

	~BigInt ();

// Operador de asignación

	BigInt &operator= (const BigInt&);

// Operador de suma

	BigInt& operator+ (const BigInt&) const;

	long long int getCapacidad () const
	{
		return capacidad;
	}
	long long int getUtil () const
	{
		return util;
	}

	friend istream &operator>> (istream&, BigInt&);
	friend ostream &operator<< (ostream&, const BigInt&);
};

istream& operator>> (istream&, BigInt&);
ostream& operator<< (ostream&, const BigInt&);
	
#endif
