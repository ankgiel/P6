

#include <iostream>
#include <iomanip>

#include "VectorDinamico.h"

using namespace std; 


// Constructor sin argumentos
VectorDinamico :: VectorDinamico (void) : 
	tam (TAM_DEF), usados (0), 
	tipo_redimension (EnBloques) 
{
	// La memoria la pide el constructor 
	PedirMemoria (tam);
}

// Constructor con uno/dos argumentos
VectorDinamico :: VectorDinamico (int tam_inicial, 
								 TipoBase valor_inicial) :  
	tam (tam_inicial), usados (0), 
	tipo_redimension (EnBloques) 
{
	// La memoria la pide el constructor
	PedirMemoria (tam);
	// Inicializar el vector din�mico
	Inicializar (valor_inicial);
}

// Destructor 
VectorDinamico :: ~VectorDinamico(void)
{
	LiberarMemoria ();
}

// Devuelve el estado (vacio/ocupado) del vector 
bool VectorDinamico :: Vacio (void)
{
	return ((usados==0) ? true : false);
}

// Devuelve el numero maximo de casillas disponibles
int VectorDinamico :: Capacidad (void)
{
	return (tam);
}

// Devuelve el numero de casillas ocupadas
int VectorDinamico :: NumDatosGuardados(void)
{
	return (usados);
}

// Aniade un elemento al vector dinamico (al final)
// PRE: usados < tam
void VectorDinamico :: Aniade (TipoBase valor)
{
	// Comprobar si es necesario redimensionar el almac�n
		
	if (NumDatosGuardados() == Capacidad()) { 
			
		// Redimensionar 
		RedimensionaAlmacen ();
	}

	datos [usados] = valor;
	usados++;
}

// Devuelve el contenido de la casilla "posicion"
// PRE: 0 <= posicion < NumDatosGuardados() 
TipoBase VectorDinamico :: Elemento (int posicion)
{
	return (datos [posicion]);
}

// Establece el tipo de redimensionamiento
void VectorDinamico :: FijaRedimensionamiento (TipoRedimension tipo)
{
	tipo_redimension = tipo;
}

// Consulta el tipo de redimensionamiento
TipoRedimension VectorDinamico :: ConsultaRedimensionamiento (void)
{
	return (tipo_redimension);
}


//**********************************************
// METODOS PRIVADOS
//**********************************************

// Pedir memoria para alojar "casillas" datos
void VectorDinamico :: PedirMemoria (int num_casillas)
{
	datos = new TipoBase[num_casillas];
}

// Liberar la memoria ocupada
void VectorDinamico :: LiberarMemoria (void)
{
	delete [] datos;
}

// Inicializar el vector a un valor com�n
void VectorDinamico :: Inicializar (TipoBase valor_inicial)
{
	for (int i=0; i<tam; i++) 
		datos[i] = valor_inicial;
}

// Redimensiona el vector din�mico de acuerdo al 
// tipo de redimensi�n establecido.
// Copia todos los datos en el nuevo almac�n.  
void VectorDinamico :: RedimensionaAlmacen (void)
{
	switch (tipo_redimension) {

		case (DeUnoEnUno): // 1 casilla m�s
            tam++;
            break;

        case (EnBloques): // TAM_BLOQUE casillas m�s
            tam+=TAM_BLOQUE;
            break;

        case (Duplicando): // Duplicar tama�o
            tam*=2;
            break;
    }


	// SOLAMENTE PARA DEPURACI�N O EJEMPLO
	cout << endl;
	cout << "ALMACEN REDIMENSIONADO HASTA --> " 
		 << tam << " CASILLAS" << endl;
	cout << endl;
	// FIN DE DEPURACI�N O EJEMPLO


	// Pedir memoria para el nuevo almacen 
	TipoBase * tmp = new TipoBase[tam]; 
		
	// Copiar los datos de manera eficiente:
	memcpy (tmp, datos, usados*sizeof(TipoBase)); 

	// Copiar los datos (cl�sica)
	//for (int i=0; i<usados; i++) 
	//	tmp[i]=datos [i]; 

	// Liberar la memoria del antiguo almac�n
	delete [] datos; 

	datos = tmp; // Reasignacion
}

