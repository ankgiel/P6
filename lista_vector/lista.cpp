
#include <iostream>
#include "lista.h"
using namespace std; 

Lista LeeLista (void) 
{
	PNodo inic=0;
	PNodo fin, nuevo; 
	TipoBase valor; 

	cout << "Introducir un valor (para finalizar, introducir un negativo): "; 
	cin >> valor;

	if (valor >= 0)	{

		// crear e inicar el primer nodo 
		inic = new Nodo;
		inic->valor = valor; 
		inic->sig = 0; 

		fin = inic; // marcamos el ultimo nodo

		cout << "Introducir un valor (para finalizar, introducir un negativo): "; 
		cin >> valor;

		while (valor >= 0) {

			// crear e iniciar un nuevo nodo
			nuevo = new Nodo;
			nuevo->valor = valor; 

			fin->sig = nuevo; // enlazar (al final)
			fin = nuevo;      // actualizar el ultimo

			cout << "Introducir un valor (para finalizar, introducir un negativo): "; 
			cin >> valor;
		}

		fin->sig = 0; // marcar el final
	}

	return (inic); 
}

void PintaLista (const Lista l)
{
	PNodo p; 

	for (p=l; p!=0; p=p->sig)
		cout << "Valor =  " << p->valor << endl;
	cout << endl;

}


void LiberaLista (Lista l)
{
	PNodo p, ant; 

	if (l!=0) {

   		ant = l; 
		p = l->sig; 

		while (p!=0) {
			delete ant;
			ant = p;
			p = p->sig;
		}

		delete ant;
	}
}


int CuentaElementos (const Lista l)
{
	PNodo p = l; 
	int contador = 0; 

	for (PNodo p=l; p!=0; contador++, p=p->sig);

	return (contador);
}



bool   EstaOrdenada (const Lista l)
{
	PNodo p = l; 
	TipoBase anterior; 

	bool ordenada = true; // por defecto, una lista vacia esta ordenada

	if (p) { // si hay al menos un nodo
		anterior = p->valor; //  valor del primer nodo
		p = p->sig;			 //  apuntar al segundo
	}
	while (p && ordenada) {
		if (p->valor >= anterior) {
			anterior = p->valor;
			p = p->sig;			 //  apuntar al segundo
		}
		else ordenada = false; 
	}
	
	return (ordenada);
}

void OrdenaSeleccionLista (Lista &l)
{
	if (l!=0) { // si la lista esta vacia, no se hace nada

		PNodo primero = l; // marca el inicio de la parte NO ordenada
		
		while (primero->sig != 0) {

			TipoBase val_min = primero->valor; // el primer elemento es el primer 
			PNodo pos_min = primero;           // menor de la parte no ordenada

			PNodo p = primero->sig;            // exploramos la parte no ordenada

			while (p!=0) {

				if (p->valor < val_min) {   // se encuentra un nuevo menor
					val_min = p->valor;
					pos_min = p;
				}
				p = p->sig;  // se sigue avanzando
			}

			// Intercambio: el menor pasa a ocupar la posicion marcada por primero  
			TipoBase tmp = primero->valor; 
			primero->valor = pos_min->valor;
			pos_min->valor = tmp; 

			primero = primero->sig; // avanza la parte no ordenada
		
		}// while (primero->sig != 0)
	} // if (l!=0)
}

void InsertaOrdenadamente (Lista &l, TipoBase v)
{
	if (l!=0) { 

		PNodo p = l; 
		PNodo ant = l; 

		while ((p->valor < v) && (p->sig!=0)) {
			ant = p;
			p = p->sig;
		}

		PNodo nuevo = new Nodo;
		nuevo->valor = v; 

		if (ant==l) { // insertar el primero
			nuevo->sig = l; 
			l = nuevo; 
		} 
		else 
			if (p->sig==0){ // insertar el ultimo
				p->sig = nuevo;
				nuevo->sig = 0;
			}
			else { // insertar en medio
				ant->sig = nuevo;
				nuevo->sig = p;
			}
	} 
	else { // el nodo nuevo es el primero y unico
		l = new Nodo;
		l->valor = v; 
		l->sig = 0;
	}

}

void EliminaValor (Lista &l, TipoBase v)
{
	if (l!=0) { 

		PNodo p = l; 
		PNodo ant = p; 

		while ((p->valor != v) && (p->sig!=0)) {
			ant = p;
			p = p->sig;
		}

		if (p->valor == v) {
			
			if (p==l) // borrar el primero
				l = l->sig; 
			else // borra un nodo intermedio
				ant->sig = p->sig; 
			delete p;

		} // if (p->valor == v)
	}

}


/**********************************************/
/**********************************************/

Lista MezclaListas (Lista &l1, Lista &l2)
{

	Lista l3=0; // Iniciar la lista resultante a 0 
	PNodo p3;

	if ((l1!=0) && (l2!=0)) { 
		// Si las dos estuvieran vacias, como hemos iniciado l3 a 0 
		// se devolveria el valor 0 (lista vacia) 
 
		// El primer nodo se procesa de manera diferente al resto: 
		// se trata de seleccionar el primer nodo de la lista l3, que será el 
		// primero de l1 o el primero de l2 (el menor de ambos)

		if (l1->valor < l2->valor) {
			l3 = l1;
			l1 = l1->sig; 
		}
		else {
			l3 = l2;
			l2 = l2->sig; 
		}

		p3 = l3; // l3 ya no se mueve 

		// Mientras queden en las dos listas...

		while ((l1!=0) && (l2!=0)) {

 			if (l1->valor < l2->valor) {
				p3->sig = l1;
				l1 = l1->sig; 
			}
			else {
				p3->sig = l2;
				l2 = l2->sig; 
			}

			p3 = p3->sig;

		} // while ((l1!=0) && (l2!=0)) 

		if (l1==0) { // enlazar con lo que queda de l2
			p3->sig = l2;
			l2 = 0; 			
		} else {     // enlazar con lo que queda de l1
			p3->sig = l1;
			l1 = 0; 			
		}

	} // if ((l1!=0) && (l2!=0))

	return (l3); 
}
