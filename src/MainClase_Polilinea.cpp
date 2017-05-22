#include <iostream>
using namespace std;

int main (){

// Constructor por defecto

	Polilinea linea_1;

// Introducimos los puntos de la línea
// Nuevo está en la llamada de cin

	cin >> linea_1;

// Constructor de copia

	Polilinea linea_2 (linea_1);

	cout << linea_2;

// Sobrecarga del operador de asignación

	Polilinea linea_3;

	linea_3 = linea_2;

	cout << linea_3;
}
