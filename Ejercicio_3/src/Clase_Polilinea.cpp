#include <iostream>
#include "Clase_Polilinea.h"
using namespace std;

// Intercambia el valor de 2 polilíneas

void Polilinea::Swap (Polilinea& aux){
	Punto *reaux = aux.v;
	int elementos (aux.getElementos ());

// Intercambia el número de elementos

	aux.num = this -> getElementos ();
	aux.v = this -> v;

// Intercambia el puntero

	this -> v = reaux;
	this -> num = elementos;
}

///////////////////////////////////////////////////// Constructor de copia ////////////////////////////////////////////////////////////////

/*
	El error se produce aquí, concretamente por el hecho de que en la primera iteración, en la creación
	intenta copiar un puntero nulo en un puntero que está asignado y provoca que éste pierda su dirección de memoria
	por el hecho de que es una operación no válida
	
	Para comprobarlo compilalo con g++ -g -o bin/prueba -Iinclude src/Clase_Polilinea.cpp src/MainClase_Polilinea.cpp
	O como se llamen
	Luego gdb prueba
	Y dentro break Polilinea::CopiaPuntos
	Se ve fácil así
*/

void Polilinea::CopiaPuntos (const Polilinea& aux){
	for (int i = 0; i < getElementos (); i++)
		this -> operator[] (i) = aux [i];
}

///////////////////////////////////////////////////// Constructor de copia ///////////////////////////////////////////////

Polilinea::Polilinea (const Polilinea& aux){
	num = aux.getElementos ();
	v = new Punto [num];

	CopiaPuntos (aux);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Punto& Polilinea::operator[] (int i){
	return v [i];
}

Punto& Polilinea::operator[] (int i) const{
	return v [i];
}

//////////////////////////////////////////////////////////// Sobrecarga del operador de asignación //////////////////////////////////////////////////

Polilinea& Polilinea::operator= (const Polilinea& aux){
	if (&aux != this){

// Copia objeto

		Polilinea reaux (aux);

// Intercambia el contenido de los objetos
	
		Swap (reaux);
	}
}

///////////////////////////////////////////////////////////////// Introduce un nuevo valor el la polilínea ///////////////////////////////////////

void Polilinea::Nuevo (int i, int j){
	Polilinea aux;
	Punto p (i, j);

	aux.v = new Punto [num + 1];
	CopiaPuntos (aux);
	aux [num] = p;
	Swap (aux);
}

void Polilinea::Nuevo (const Punto p){
	Polilinea aux;

	aux.v = new Punto [num + 1];
	CopiaPuntos (aux);
	aux [num] = p;
	Swap (aux);
}

/////////////////////////////////////////////////////////////////// Destructor ///////////////////////////////////////////////////

Polilinea::~Polilinea (){
	delete [] v;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

istream& operator>> (istream& in, Polilinea& aux){
	cout << "Introduzca número de elementos: ";
	in >> aux.num;

	for (int i = 0; i < aux.num; i++){
		int k, j;

		cout << "Punto " << i << endl;
		cout << "\tIntroduzca la coordenada x: " << endl;
		in >> k;
		cout << "\tIntroduzca la coordenada y: " << endl;
		in >> j;

		aux.Nuevo (k,j);
	}
}

ostream& operator>> (ostream& out, const Polilinea& aux){
	out << "Número de puntos: " << aux.getElementos () << endl;

	for (int i = 0; i < aux.getElementos (); i++)
		out << "\tPunto " << i << ": " << aux [i] << endl;
}

ostream& operator>> (ostream& out, const Punto& aux){
	out << "Coordenada x: " << aux.x << endl;
	out << "Coordenada y: " << aux.y << endl;
}
