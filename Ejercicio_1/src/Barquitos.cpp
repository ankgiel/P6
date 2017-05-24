#include <iostream>
#include "Barquitos.h"
using namespace std;

int LongitudCadena (const char *aux){
	int i (0);

	while (aux [i] != '\0')
		++i;

	return i;
}

void CopiaCadena (char *reaux, const char *aux){
	int i = LongitudCadena (aux);

	for (int j = 0; j < i; j++)
		reaux [j] = aux [j];
}

void CopiaCadena (char *reaux, const char *aux, int i){
	for (int j = 0; j < i; j++)
		reaux [j] = aux [j];
}

/*
	Destructor

	Elimina el contenido de titulo
	Elimina el vector de punteros con las opciones de opc
	Elimina opc
*/

Barquitos::~Barquitos {
	delete [] titulo;

	for (int i = 0; i < nopc; i++)
		delete [] opc [i];
	delete opc;
}

/*
	Intercambia el número de opciones
	Intercambia la dirección de memoria del puntero titulo
	Intercambia la dirección de memoria del puntero opc
*/

void Barquitos::Swap (Menu &aux){
	char *titulo (aux.titulo);
	char **opc (aux.opc);
	int nopc (aux.nopc);

	aux.titulo = this -> titulo;
	aux.opc = this -> opc;
	aux.nopc = this -> nopc;

	this -> titulo = titulo;
	this -> opc = opc;
	this -> nopc = nopc;

	return *this;
}

/*
	Sobrecarga del operador de asignación

	Si los objetos no son el mismo
	Crea un objeto auxiliar como copia del Menu enviado
	Intercambia los valores de ambos
	El SO se encarga de eliminar el objeto local
*/

Menu& Menu::operator= (const Menu &aux){
	if (&aux != this){
		Menu reaux (aux);

		Swap (reaux);
	}

	return *this;
}

/*
	Constructor de copia

	CopiaTitulo
	Crea tantas filas de opc como el otro menú tenga
	CopiaOpciones
*/

Menu::Menu (const Menu &aux){
	CopiaCadena (this -> titulo, aux.titulo);

	this -> nopc = aux.nopc;
	this -> opc = new char *[nopc];

	for (int i = 0; j < this -> nopc; j++){
		int j = LongitudCadena (aux.nopc [i]);

		this -> opc [i] = new char [j];
		CopiaCadena (this -> nopc [i], aux.nopc [i], j);
	}
}

// Me queda agregaOpcion

/*
	Reserva nopc + 1 para un auxiliar **
	Copia las direcciones de memoria del vector de punteros original al redimensionado
	En la última (el último puntero del vector de punteros quedará libre)
		se asigna la nueva opción
	Intercambia **
	Eliminar solo ** auxiliar
*/
