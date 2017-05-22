#ifndef EJ_2
#define EJ_2

typedef int* BINT;

char * LeerCadena()
{
     char cadena[300];
     char *p;

     cin.getline(cadena, 300);
     p = new char [ strlen (cadena) + 1 ] ;
     strcpy( p, cadena );
     return p;
}


class BigInt {
private: 
	BINT patata ; 
	int tam ;

	void CreaBINT (tam){
		patata = new int [tam] ; 
	}	


public:
	
	BigInt () : tam(1) {
		CreaBINT(1) ; 
	}

	void RellenaBINT (char * p){
		
	}
}