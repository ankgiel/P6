

#include <iostream>
#include "lista.h"
using namespace std; 


int main (void)
{
	Lista l1=0, l2=0; // iniciar los punteros a 0

	// Leer y ordenar la lista 1
	l1 = LeeLista (); 
	PintaLista (l1); 
	cout << "La secuencia 1 tiene " << CuentaElementos(l1) << " elementos\n";
	OrdenaSeleccionLista (l1);
	PintaLista (l1); 

	// Leer y ordenar la lista 2
	l2 = LeeLista (); 
	PintaLista (l2); 
	cout << "La secuencia 2 tiene " << CuentaElementos(l2) << " elementos\n";
	OrdenaSeleccionLista (l2);
	PintaLista (l2); 

	// Mezclar las dos listas
	Lista l3 = MezclaListas (l1, l2); 
	cout << "La mezcla tiene " << CuentaElementos(l3) << " elementos\n";
	PintaLista (l3); 

	cout << "La secuencia original 1 tiene " << CuentaElementos(l1) << " elementos\n";
	cout << "La secuencia original 2 tiene " << CuentaElementos(l2) << " elementos\n";

	LiberaLista (l1);
	LiberaLista (l2);
	LiberaLista (l3);

	char c;
	cin >> c; 
	return 0;
}
