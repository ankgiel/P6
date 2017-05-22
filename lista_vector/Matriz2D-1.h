/*********************************************************************/
// METODOLOGIA DE LA PROGRAMACION
// GRADO EN INGENIERIA INFORMATICA
//
// CURSO 2013-2014
// (C) FRANCISCO JOSE CORTIJO BON
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
//
// Fichero de cabecera asociado a la clase Matriz2D-1
//
// Implementacion del tipo Matriz2D_1
//
// Matriz 2D dinamica de datos "TipoBase" en la que cada fila es un 
// vector dinamico independiente. 
//
/*********************************************************************/

#ifndef MATRIZ2D1
#define MATRIZ2D1

// Definición del tipo TipoBase y el valor NULO asociado
typedef int TipoBase;
#define NULO 0

///////////////////////////////////////////////////////////////

class Matriz2D_1 {

	private:
		TipoBase ** datos;	// Los valores de la matriz
		int filas;			// Núm. de filas
		int columnas;		// Núm. de columnas

	public:
		// Constructor sin argumentos (matriz vacia)
		Matriz2D_1(void);       

		// Constructor de matrices cuadradas
		Matriz2D_1(int orden);  
		
		// Constructor de matrices rectangulares, 
		// con iniciacion a un valor dado (opcional)
		Matriz2D_1(int fils, int cols, TipoBase valor=NULO);

		// Constructor de copia 
		Matriz2D_1 (const Matriz2D_1 & otro);

				// Destructor
		~Matriz2D_1(void); 
		
		// Consulta si la matriz esta vacia
		bool EstaVacia(void); 
 
		// Métodos de lectura de las filas y columnas
		int NumFilas (void) const;
		int NumColumnas (void) const;

		// Fijar todas las casillas a un valor dado  
		void Inicializar (TipoBase valor=NULO);

		// Operador de asignación 
		Matriz2D_1 & operator = (const Matriz2D_1 & otro);
		Matriz2D_1 & operator = (const TipoBase & valor);

		// Operator ()
		// PRE: 0 <= fila < NumFilas()
		// PRE: 0 <= columna < NumColumnas()
		TipoBase & operator () (const int fila, const int columna);
		TipoBase & operator () (const int fila, const int columna) const;


		// Operadores unarios + y -
		Matriz2D_1 operator + (void);
		Matriz2D_1 operator - (void);


		
		// Operadores combinados
		Matriz2D_1 & operator += (TipoBase valor);
		Matriz2D_1 & operator -= (TipoBase valor);
		Matriz2D_1 & operator *= (TipoBase valor);
		Matriz2D_1 & operator /= (TipoBase valor);

		Matriz2D_1 & operator += (Matriz2D_1 & otro);
		Matriz2D_1 & operator -= (Matriz2D_1 & otro);


		// Operadores == y != 
		bool operator == (const Matriz2D_1 & otro); 
		bool operator != (const Matriz2D_1 & otro); 


		// NUEVOS métodos: Guardan/recuperan una matriz en/de un fichero 
		// de texto. El nombre del fichero se pasa como argumento
		void GuardaEnFichero   (const char *nombre); 
		void RecuperaDeFichero (const char *nombre); 


	private:
	
		// Pedir memoria para alojar "fils"x"cols" datos
		void ReservarMemoria (int fils, int cols);

		// Liberar la memoria ocupada
		void LiberarMemoria (void);

		// Copiar datos
		void CopiarDatos (const Matriz2D_1 & otro);


		// NUEVOS métodos privados de la clase.
		void RecuperaDatosDeFichero (const char * nombre);
		void AniadeFila (TipoBase * datos_de_una_fila);

};

///////////////////////////////////////////////////////////////

void PintaMatriz (const Matriz2D_1 & m);

///////////////////////////////////////////////////////////////

#endif
