#ifndef _CLASE_POLILINEA_H_
#define _CLASE_POLILINEA_H_

#include <iostream>
using namespace std;

class Punto{
private:
	int x;
	int y;
public:
	Punto (): x (0), y (0) {}
	Punto (int i, int j) : x (i), y (j) {}

	friend ostream& operator<< (ostream&, const Punto&);
};

ostream& operator<< (ostream& out, const Punto&);

class Polilinea{
	Punto *v;
	int num;

	inline void Swap (Polilinea&);
	inline void CopiaPuntos (const Polilinea&);

public:
	Polilinea (): v (0), num (0) {}
	Polilinea (const Polilinea&);
	~Polilinea ();

	inline Punto& operator[] (int);
	inline Punto& operator[] (int) const;
	Polilinea& operator= (const Polilinea&);

	void Nuevo (int, int);
	void Nuevo (const Punto);

	int getElementos () const {
		return num;
	}

	friend istream& operator>> (istream&, Polilinea&);
};

istream& operator>> (istream&, Polilinea&);
ostream& operator<< (ostream&, const Polilinea&);

#endif
