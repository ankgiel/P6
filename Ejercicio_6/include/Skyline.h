#ifndef _SKYLINE_H_
#define _SKYLINE_H_

#include <iostream>
using namespace std;

/*
	Invariante de la representación:
		n siempre contiene un valor válido
*/

// SE ME HA OLVIDADO PONER A 0 LA ÚLTIMA ALTURA AL CREAR EL OBJETO O.o

class Skyline{
private:
	double *abscisas;
	double *alturas;
	int n;

	inline void CopiaAbscisas (const double *);
	inline void CopiaAlturas (const double *);

public:
	Skyline (): abscisas (0), alturas (0), n (0) {}
	Skyline (int);
	Skyline (double*, double*, int);
	Skyline (const Skyline &);
	Skyline (double, double, double);
	~Skyline ();

	Skyline& operator= (const Skyline&);

	double getAbscisa (const int i) const{
		if (i >= 0 && i < n)
			return abscisas [i];
	}

	double getAltura (const int i) const{
		if (i >= 0 && i < n)
			return alturas [i];
	}

	double setAbscisa (const double aux, int i){
		if (i >= 0 && i < n)
			this -> abscisas [i] = aux;
	}

	double setAltura (const double aux, int i){
		if (i >= 0 && i < n)
			this -> alturas [i] = aux;
	}

	int getElementos () const{
		return n;
	}

	void Swap (Skyline&);
};

ostream& operator<< (ostream&, const Skyline&);
istream& operator>> (istream&, Skyline&);

#endif
