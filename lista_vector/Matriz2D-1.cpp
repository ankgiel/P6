

#include "Matriz2D-1.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;


/*********************************************************************/
// FUNCIONES AUXILIARES
/*********************************************************************/

int  CalculaColumnas (const char *nombre);
void Limpia (char *cad);
bool LeeDatosDeUnaFila (TipoBase * datos, int num_datos, ifstream & fi);


/*********************************************************************/
// Constructor (1) sin argumentos (matriz vacia)
Matriz2D_1 :: Matriz2D_1(void)
	: filas(0), columnas(0), datos(0) 
{
}

/*********************************************************************/
// Constructor (2) de matrices cuadradas
Matriz2D_1 :: Matriz2D_1(int orden)	
	: filas(orden), columnas(orden) 
{
	ReservarMemoria (filas, columnas);
}

/*********************************************************************/
// Constructor (3) de matrices rectangulares, 
// con iniciacion a un valor dado (opcional)
Matriz2D_1 :: Matriz2D_1(int fils, int cols, TipoBase valor) 
	: filas(fils),columnas(cols) 
{
	ReservarMemoria (filas, columnas);
	Inicializar(valor);
}

/*********************************************************************/
// Constructor (4) de copia
Matriz2D_1 :: Matriz2D_1 (const Matriz2D_1 & otro)
{
    // Reserva de memoria para los valores de la matriz
    ReservarMemoria (otro.filas, otro.columnas);
    // Copia el contenido de la matriz y los campos privados
    CopiarDatos(otro);
}

/
}

/*********************************************************************/
// Destructor
Matriz2D_1 :: ~Matriz2D_1(void) 
{
	LiberarMemoria();
}

/*********************************************************************/
// Consulta si la matriz esta vacia
bool Matriz2D_1 :: EstaVacia(void) 
{
	return (datos == 0);
}

/*********************************************************************/
// Método de lectura de las filas 
int Matriz2D_1 :: NumFilas (void) const
{
	return (filas);
}

/*********************************************************************/
// Método de lectura de las columnas
int Matriz2D_1 :: NumColumnas (void) const
{
	return (columnas);
}

/*********************************************************************/
// Fijar todas las casillas a un valor dado  
void Matriz2D_1 :: Inicializar(TipoBase valor) 
{
	for(int i = 0; i < filas; i++)
		for(int j = 0; j < columnas; j++)
			datos[i][j] = valor;	
}	

/*********************************************************************/
// Operador de asignación (1)
Matriz2D_1 & Matriz2D_1 :: operator = (const Matriz2D_1 & otro)
{
    if (this != &otro) { // Evitar autoasignación

        // Libera la memoria ocupada
        LiberarMemoria();

        // Reserva de memoria para los valores de la matriz
        ReservarMemoria (otro.filas, otro.columnas);

        // Copia el contenido de la matriz y los campos privados
        CopiarDatos(otro);
    }
    return (*this);  // Objeto implicito: parte
                     // izquierda de la asignación
}

/*********************************************************************/
// Operador de asignación (2)
Matriz2D_1 & Matriz2D_1 :: operator = (const TipoBase & valor)
{
	// Escribir "valor" en todas las casillas 
    Inicializar(valor);
 
    return (*this);  // Objeto implicito: parte
                     // izquierda de la asignación
}

/*********************************************************************/
// Operator ()
// PRE: 0 <= fila < NumFilas()
// PRE: 0 <= columna < NumColumnas()
TipoBase & Matriz2D_1 :: operator () (const int fila, const int columna)
{
	return (datos[fila][columna]);
}
TipoBase & Matriz2D_1 :: operator () (const int fila, const int columna) const
{
	return (datos[fila][columna]);
}
/*********************************************************************/
// Operador unario +
Matriz2D_1 Matriz2D_1 :: operator + (void) 
{
	return (*this); // Copia de *this
}

/*********************************************************************/
// Operador unario -
Matriz2D_1 Matriz2D_1 :: operator - (void) 
{
	Matriz2D_1 tmp = (*this); // Copia de *this

	// Cambia el signo de todas las casillas
	for(int i = 0; i < filas; i++) {
		for(int j = 0; j < columnas; j++)
			tmp.datos[i][j] = -(tmp.datos[i][j]);
	}
	return (tmp);
}

/*********************************************************************/
// Operador binario + (1) 
// PRE:   (m1.NumFilas() == m2.NumFilas()) 
//	    Y (m1.NumColumnas() == m2.NumColumnas()) 
Matriz2D_1 operator + (Matriz2D_1 & m1, Matriz2D_1 & m2)
{
	Matriz2D_1 resultado;	// Matriz vacía

	if ((m1.filas == m2.filas) && (m1.columnas == m2.columnas)) {
		
		int fils = m1.filas;
		int cols = m1.columnas;

		Matriz2D_1 matriz_suma (fils, cols); // Por defecto se inicia a NULO

		// Sumar casilla a casilla

		for (int f=0; f<fils; f++) 
			for (int c=0; c<cols; c++) 
				matriz_suma.datos[f][c]= m1.datos[f][c]+ m2.datos[f][c];

		resultado = matriz_suma;

	}

	return (resultado);
}

/*********************************************************************/
// Operador binario + (2) 
Matriz2D_1 operator + (Matriz2D_1 & m, TipoBase valor)
{
	// Crear matriz con valor constante con las dimensiones de "m"
	Matriz2D_1 matriz_constante (m.filas, m.columnas, valor);

	return (m + matriz_constante); // Operador binario + (1)
}

/*********************************************************************/
// Operador binario + (3) 
Matriz2D_1 operator + (TipoBase valor, Matriz2D_1 & m)
{
	return (m + valor );	// Operador binario + (2)
}

/*********************************************************************/
// Operador binario - (1) 
// PRE:   (m1.NumFilas() == m2.NumFilas()) 
//	    Y (m1.NumColumnas() == m2.NumColumnas()) 
Matriz2D_1 operator - (Matriz2D_1 & m1, Matriz2D_1 & m2)
{
	return (m1 + (-m2));
}

/*********************************************************************/
// Operador binario - (2) 
Matriz2D_1 operator - (Matriz2D_1 & m, TipoBase valor)
{
	// Crear matriz con valor constante con las dimensiones de "m"
	Matriz2D_1 matriz_constante (m.filas, m.columnas, valor);

	return (m - matriz_constante);	// Operador binario - (1)
}

/*********************************************************************/
// Operador binario - (3) 
Matriz2D_1 operator - (TipoBase valor, Matriz2D_1 & m)
{
	// Crear matriz con valor constante con las dimensiones de "m"
	Matriz2D_1 matriz_constante (m.filas, m.columnas, valor);

	return (matriz_constante - m);	// Operador binario - (1)
}

/*********************************************************************/
// Operador == 
bool Matriz2D_1 :: operator == (const Matriz2D_1 & otro) 
{
	// Si las dimensiones son diferentes, las matrices son distintas
	bool iguales = ((filas == otro.filas) && (columnas == otro.columnas));
	
	if (iguales) { // Comparar casilla a casilla

		for (int i = 0; (i<filas) && iguales; i++) {
			
			for (int j= 0; (j<columnas) && iguales; j++)
				
				if (datos[i][j] != otro.datos[i][j])
					iguales = false;
		}
	}
	return (iguales);
}

/*********************************************************************/
// Operador != 
bool Matriz2D_1::operator != (const Matriz2D_1 & otro) 
{
	return !((*this) == otro);
}

/*********************************************************************/
// Operador combinado += (1)
Matriz2D_1 & Matriz2D_1:: operator += (Matriz2D_1 & otro)
{
	(*this) = (*this) + otro; // Operador binario + (1)
	return (*this);
}

/*********************************************************************/
// Operador combinado += (2)
Matriz2D_1 & Matriz2D_1:: operator += (TipoBase valor)
{
	(*this) = (*this) + valor; // Operador binario + (2)
	return (*this);
}

/*********************************************************************/
// Operador combinado -= (1)
Matriz2D_1 & Matriz2D_1:: operator -= (Matriz2D_1 & otro)
{
	(*this) = (*this) - otro; // Operador binario - (1)
	return (*this);
}

/*********************************************************************/
// Operador combinado -= (2)
Matriz2D_1 & Matriz2D_1:: operator -= (TipoBase valor)
{
	(*this) = (*this) - valor; // Operador binario - (2)
	return (*this);
}

/*********************************************************************/
// Operador combinado *=
Matriz2D_1 & Matriz2D_1:: operator *= (TipoBase valor)
{
	for (int f=0; f<filas; f++) 
		for (int c=0; c<columnas; c++) 
			datos[f][c]= datos[f][c]*valor;
	return (*this);
}

/*********************************************************************/
// Operador combinado /=
Matriz2D_1 & Matriz2D_1:: operator /= (TipoBase valor)
{
	for (int f=0; f<filas; f++) 
		for (int c=0; c<columnas; c++) 
			datos[f][c]= datos[f][c]/valor;
	return (*this);
}



/*********************************************************************/
// NUEVO: Método que rellena una matriz (que ya existe) a partir de 
// los datos presentes en el fichero de texto llamado "nombre". 
//
// Este método NO es un constructor: el objeto sobre el que se aplica 
// ya existe, por lo tanto, lo primero que debe hacerse es "limpiarlo" 
// y después, leer los valores y calcular filas y columnas a partir de 
// los datos almacenados en el fichero llamado "nombre"

void Matriz2D_1 :: RecuperaDeFichero (const char * nombre)
{
	// Limpiar el objeto: Liberar memoria reservada previamente
	LiberarMemoria (); 

	// Leer los datos del fichero
	RecuperaDatosDeFichero (nombre);
}


//**********************************************
// METODOS PRIVADOS
//**********************************************
		
// Pedir memoria para alojar "fils"x"cols" datos
void Matriz2D_1 :: ReservarMemoria (int fils, int cols)
{
	datos = 0;

	if ((fils > 0) && (cols > 0)) {

		// Reservar vector de punteros
		datos = new TipoBase * [fils];

		// Reservar para cada una de las filas
		for(int i = 0; i < fils; i++)
			datos[i] = new TipoBase[cols];
	}
}

// Liberar la memoria ocupada
void Matriz2D_1 :: LiberarMemoria (void)
{
	if (datos) {
		
		for(int i = 0; i < filas; i++)
			delete [] datos[i];

		delete [] datos;
	}
}

// Copiar campos privados y datos de la matriz
void Matriz2D_1 :: CopiarDatos (const Matriz2D_1 & otro)
{
    // Copiar campos privados
    filas = otro.filas;
    columnas = otro.columnas;

	/*
    // Copiar cada una de las casillas 
	for (int f=0; f<filas; f++)
		for (int c=0; c<columnas; c++)
			datos[f][c] = otro.datos[f][c];
	*/

    // Copiar cada una de las filas
	for (int f=0; f<filas; f++)
		memcpy (datos[f], otro.datos[f], columnas*sizeof(TipoBase));
}


/*********************************************************************/
// NUEVO: Amplia la matriz. Añade una fila, con los datos que están 
// almacenados en el vector "datos_de_una_fila"
//
// PRE: El vector "datos_de_una_fila" tiene tantas casillas como 
//		columnas tiene la matriz. 

void Matriz2D_1 :: AniadeFila (TipoBase * datos_de_una_fila)
{
	// Reservar una estructura auxiliar, con una casilla más que la que 
	// tiene "datos" y copiar en ella los valores guardados en la matriz. 
	// La nueva casilla (la última) apuntará a la nueva fila.

	TipoBase ** tmp = new TipoBase * [filas+1]; // "tmp" tiene una fila más

	if (datos) { // Importante: solo si la matriz NO ESTA VACÍA
		for(int i = 0; i < filas; i++) 
			tmp[i] = datos[i];
		delete [] datos;
	}

	datos = tmp; // Actualizar "datos"--> ya apunta a un vector ampliado
	
	datos[filas] =  new TipoBase[columnas]; // Enlazar la nueva fila al final 
											// de "datos" (en datos[filas])

	// Copiar el vector "datos_de_una_fila" en la nueva fila
	for(int c = 0; c < columnas; c++) 
		datos[filas][c] = datos_de_una_fila[c];

	filas++; // Actualizar el numero de filas
} 

/*********************************************************************/
// NUEVO: Método PRIVADO que rellena un dato "Matriz2D_1" con los  
// datos guardados en el fichero de texto llamado "nombre".
// Este método calcula los valores de los campos "filas" y "columnas".
//
// Este método es usado por:
// 1) Constructor 
//       Matriz2D_1 :: Matriz2D_1 (const char * nombre); 
// 2) Método
//	void Matriz2D_1 :: RecuperaDeFichero (const char * nombre);

void Matriz2D_1 :: RecuperaDatosDeFichero (const char * nombre)
{
	// Calcular num. de columnas
	columnas = CalculaColumnas (nombre);

	ifstream fi (nombre);
	if (!fi) {
		cerr << "Error: no puede abrirse " << nombre << endl;
		exit (1);
	}

	// Reservar memoria para los datos que formarán cada fila
	TipoBase * datos_de_una_fila = new TipoBase[columnas]; 

	// Leer una fila de datos del fichero y añadir los datos a la matriz 

	while (LeeDatosDeUnaFila (datos_de_una_fila, columnas, fi)) 
		AniadeFila (datos_de_una_fila);	

	fi.close();
}

/*********************************************************************/
/*********************************************************************/
// FUNCIONES AUXILIARES
/*********************************************************************/
/*********************************************************************/


/*********************************************************************/
/*********************************************************************/
// Elimina todos los separadores iniciales y finales

void Limpia (char *cad)
{
	// Buscar primer caracter no separador

	int orig=0;
	while ( (cad[orig]) && (isspace(cad[orig])) ) 
		orig++;

	// Comprobar si hemos recorrido toda la cadena (toda ella tenia 
	// separadores) o se ha parado antes (hay algun caracter no-separador)

	if (orig == strlen(cad)) // Toda la cadena tenia separadores
		cad[0]='\0';

	else {

		// Cadena no vacia con separadores iniciales
		// y con un caracter no-separador al menos 

		// "Desplazar" la cadena hacia el principio, de manera que 
		// la casilla 0 contendrá el primer caracter no-separador.

		int dest = 0; 

		do {
			cad[dest]=cad[orig];
			dest++;
			orig++;
		} while (cad[orig]); 

		cad[dest]='\0';

	} 

	// Limpiar el final

	if (strlen(cad)>0) {

		int fin = strlen(cad)-1;

		while (isspace(cad[fin])) // Buscar el ultimo no-separador
			fin--;

		cad[fin+1]='\0';
	}

}

/*********************************************************************/
// Calcula y devuelve el número de columnas de datos en las líneas 
// no vacías del fichero cuyo nombre es "nombre"

int CalculaColumnas (const char *nombre)
{
	ifstream fi (nombre);
	if (!fi) {
		cerr << "Error: no puede abrirse " << nombre << endl;
		exit (1);
	}

	// Leer la primera cadena, limpiarla de separadores al principio 
	// y al final, y calcular el numero de columnas (elementos por fila)

	const int MAX = 500;
	char cad[MAX];

	// Saltar lineas vacias

	fi.getline (cad, MAX);
	Limpia (cad);

	while ((strlen(cad)==0) && (!fi.eof())) {
		fi.getline (cad, MAX);
		Limpia (cad);
	}

	bool en_palabra = true; // IMPORTANTE: Previamente se han eliminado 
							// los separadores iniciales de la cadena.

	int cont_palabras = 0;

	for (int i=0; (cad[i]) ; i++) {

		if (isspace(cad[i])) {

			if (en_palabra) {
				cont_palabras++;
				en_palabra = false;
			}

		}
		else // no es separador

			if (!en_palabra) en_palabra=true;

	} // for


	cont_palabras++;  

	fi.close();

	return (cont_palabras);
}

/*********************************************************************/
// Devuelve TRUE si ha podido leer una serie de "num_datos" datos 
// desde el fichero  asociado al flujo "fi". 
// Si puede leerlos, copia los datos en el vector "datos".
// Si no puede (encuentra el fin de fichero) devuelve FALSE.
//
// PRE: TODAS las líneas tienen exactamente "columnas" datos. 

bool LeeDatosDeUnaFila (TipoBase * datos, int num_datos, ifstream & fi)
{
	bool exito = true; 

	fi >> datos[0];

	if (!fi.eof()) 
		for (int i=1; i < num_datos; i++) 	
			fi >> datos[i];
	else 
		exito = false;

	return (exito);
}

/*********************************************************************/
/*********************************************************************/


//**********************************************
// OTRAS FUNCIONES
//**********************************************

#include <iostream>
using namespace std;

void PintaMatriz (const Matriz2D_1 & m)
{
	int fils = m.NumFilas();
	int cols = m.NumColumnas();

	for (int f=0; f<fils; f++) {
		for (int c=0; c<cols; c++)
			cout << m(f,c) << " "; 
		cout << endl;
	}
	cout << endl; 
}
