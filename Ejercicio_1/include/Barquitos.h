#ifndef _BARQUITOS_H_
#define _BARQUITOS_H_

#include <iostream>
using namespace std;

/*
	Calcula la longitud dada una CADENA CLÁSICA
*/

int LongitudCadena (const char *);
void CopiaCadena (char *, const char *);

/*
	Invariante de la representación:
		nopc siempre tendrá un valor válido aún siendo 0
		Tanto título como todas y cada una de las opciones de opc tendrán
		al final '\0'
*/

// Me queda añadirles a las cadena de título y opciones '\0'

class Menu {
	char *titulo;
	char **opc;
	int nopc;

public:
	Menu (): nopc (0), opc (0), titulo (0) {}
	Menu (const Menu &);
	~Menu ();

	Menu& Swap (Menu &);
	Menu& agregarOpcion (const char*);
	Menu& setTitulo (const char *aux){
		delete [] this -> titulo;
		CopiaCadena (this -> titulo, aux);
	}

	Menu& operator= (const Menu &);

	int getNumeroOpciones () const {
		return nopc;
	}

// Permitimos acceder al menú y a las opciones
//	Pero no se permite modificar su contenido

	const char *getTitulo () const {
		return titulo;
	}
	const char *getOpcion (int i) const {
		if (i >= 0 && i < nopc)
			return opc [i];
	}
};

ostream& operator<< (ostream&, const Menu &);
istream& operator>> (istream&, Menu &);

#endif
