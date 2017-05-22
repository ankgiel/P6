

#ifndef VECTOR_DINAMICO
#define VECTOR_DINAMICO

// Definici�n del tipo enumerado TipoRedimension
enum TipoRedimension {DeUnoEnUno, EnBloques, Duplicando};

// Definici�n del tipo TipoBase y el valor NULO asociado
typedef int TipoBase;
#define NULO 0

///////////////////////////////////////////////////////////////

class VectorDinamico 
{
private: 
	TipoBase * datos;	// Direcci�n de memoria donde se 
						// almacenan los datos.
	int   tam;			// N�mero de casillas reservadas.
	int   usados;		// N�mero de casillas usadas.

	// Capacidad inicial, por defecto 
	static const int TAM_DEF = 10; 

	// Tipo de redimensionamiento activo
	TipoRedimension tipo_redimension;

	// Tamanio del bloque para redimensionar
	static const int TAM_BLOQUE = 5;

public: 
	
	// Constructor sin argumentos
	VectorDinamico (void);

	// Constructor con uno/dos argumentos
	VectorDinamico (int tam_inicial, TipoBase valor_inicial=NULO); 

	// Destructor 
	~VectorDinamico(void);

	// Devuelve el estado (vacio/ocupado) del vector 
	bool Vacio (void);

	// Devuelve el numero maximo de casillas disponibles
	int Capacidad (void);

	// Devuelve el numero de casillas ocupadas
	int NumDatosGuardados(void);

	// Aniade un elemento al vector dinamico (al final)
	void Aniade (TipoBase valor);

	// Devuelve el contenido de la casilla "posicion"
	// PRE: 0 <= posicion < NumDatosGuardados() 
	TipoBase Elemento (int posicion);

	// Establece el tipo de redimensionamiento
	void FijaRedimensionamiento (TipoRedimension tipo);

	// Consulta el tipo de redimensionamiento
	TipoRedimension ConsultaRedimensionamiento (void);


private:

	// Pedir memoria para alojar "casillas" datos
	void PedirMemoria (int num_casillas);

	// Liberar la memoria ocupada
	void LiberarMemoria (void);

	// Inicializar el vector a un valor com�n
	void Inicializar (TipoBase valor_inicial=NULO);

	// Redimensiona el vector din�mico de acuerdo al 
	// tipo de redimensi�n establecido.
	// Copia todos los datos en el nuevo almac�n.  
	void RedimensionaAlmacen (void);

};

///////////////////////////////////////////////////////////////

#endif
