#include <iostream>
#include "Skyline.h"
using namespace std;

/*
	Intercambia el valor de 2 objetos Skyline

	Intercambian las direcciones de memoria de los punteros abscisas y alturas
	Intercambia el número de elementos que contiene
*/

void Skyline::Swap (Skyline &aux){

	double *abscisas = this -> abscisas;
	double *alturas = this -> alturas;
	int num_elem = this -> n;

	this -> abscisas = aux.getAbscisas ();
	this -> alturas = aux.getAlturas ();
	this -> n = aux.getElementos ();

	aux.abscisas = abscisas;
	aux.alturas = alturas;
	aux.n = num_elem;
}

/*
	Copia el vector abscisas

	PRE: TAM_AUX >= this -> N
*/

void Skyline::CopiaAbscisas (const double *aux){
	for (int i = 0; i < this -> n; i++)
		this -> abscisas [i] = aux [i];
}

/*
	Copia el vector alturas

	PRE: TAM_AUX >= this -> N
*/

void Skyline::CopiaAlturas (const double *aux{
	for (int i = 0; i < this -> n; i++)
		this -> alturas [i] = aux [i];
}

//	Constructor que permite reservar i elementos de abscisas y alturas

Skyline::Skyline (int i): n (i) {
	abscisas = new double [i];
	alturas = new double [i];
}

/*
	Constructor de copia

	Asigna el número de elementos del otro vector
	CopiaAbscisas, CopiaAlturas
*/

Skyline::Skyline (const Skyline &aux){
	this -> n = aux.n;

	abscisas = new double [i];
	alturas = new double [i];

	CopiaAbscisas (aux.abscisas);
	CopiaAlturas (aux.alturas);
}

/*
	Equivalente al constructor de copia
*/

Skyline::Skyline (double *abscisas, double *alturas, int n){
	this -> n = n;
	this -> abscisas = new double [n];
	this -> alturas = new double [n];

	CopiaAbscisas (abscisas);
	CopiaAlturas (alturas);
}

/*
	Constructor específico para crear un primer edificio
	1 parámetro: Comienzo (abscisas) del edificio
	2 parámetro: Comienzo (alturas) del edificio
	3 parámetro: Altura del edificio
*/

Skyline::Skyline (double valor_1, double valor_2, double valor_3){
	this -> n = 2;
	this -> abscisas = new double [n];
	this -> alturas = new double [n];

	this -> abscisas [0] = valor_1, this -> abscisas [1] = valor_2, this -> alturas [0] = valor_3, this -> alturas [1] = 0;
}

/*
	Sobrecarga del operador de asignación

	Si no el mismo objeto
		Crea un Skyline auxiliar como copia del objeto enviado
		Intercambia valores con this

	El destructor se encarga de destruir el objeto local
	Devuelve *this
*/

Skyline& Skyline::operator= (const Skyline &aux){
	if (&aux != this){
		Skyline reaux (aux);

		Swap (reaux);
	}

	return *this;
}

/*
	Sobrecarga del operador de inserción de flujo

	Formato:
		Número de elementos: x
		Abscisas:
			x1	x2	x3	...	xn
		Alturas:
			x1	x2	x3	...	xn
*/

ostream& (ostream &out, const Skyline &aux){
	out << "Número de elementos: " << aux.getElementos () << endl;
	out << "Abscisas: " << endl;

	for (int i = 0; i < aux.getElementos (); i++)
		out << '\t' << aux.getAbscisas (i);
	
	out << endl << "Alturas: " << endl;

	for (int i = 0; i < aux.getElementos (); i++)
		out << '\t' << aux.getAlturas (i);

	out << endl;
}

/*
	Sobrecarga del operador de extracción de flujo

	Pide primero los elementos del Skyline
	CreaObjeto
	Completa vector abscisas
	Completa vector alturas
*/

istream& (istream &in, Skyline &aux){
	int n;
	double valor;

	cout << "Introduzca el número de elementos: ";
	cin >> n;

	Skyline reaux (n);

	cout << "Introduzca el valor de las abscisas: ";

	for (int i = 0; i < n; i++){
		cin >> valor;

		reaux.setAbscisas (valor, i);
	}

	cout << "Introduzca el valor de las alturas: ";

	for (int i = 0; i < n; i++){
		cin >> valor;

		reaux.setAbscisas (valor, i);
	}

	reaux.Swap (aux);
}

/*
	Destructor

	Elimina punteros abscisas y alturas
*/

Skyline::~Skyline (){
	delete [] abscisas;
	delete [] alturas;
}
