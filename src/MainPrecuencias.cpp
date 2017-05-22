#include <iostream>
#include "Precuencias.h"
using namespace std;

int main(void){
	Precuencias precuencia_1;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Introducción de la precuencia

	cout << "Introduzca la Precuencia, para terminar introduzca un número fuera del rango [0,9]." << endl;

	try{
		cin >> precuencia_1;
	}
	catch (const exception& e){
		cout << e.what () << endl;
	}

	try{
		while (true)
			cin >> precuencia_1;
	}
	catch (const exception& e){
		cout << e.what () << endl;
	}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Constructor de copia

	Precuencias precuencia_2 (precuencia_1);

	cout << "Precuencia copiada." << endl << precuencia_2;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Asignación

	Precuencias precuencia_3;

	precuencia_3 = precuencia_2;

	cout << "Precuencia asignada." << endl << precuencia_3;
}
