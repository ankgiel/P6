
/*********************************************************************/

#ifndef LISTA
#define LISTA

typedef double TipoBase;

struct Nodo {
   TipoBase valor; 
   Nodo *sig; 
};
typedef Nodo * PNodo;
typedef Nodo * Lista;

Lista LeeLista (void); 
void  PintaLista (const Lista l); 
int   CuentaElementos (const Lista l);
void  LiberaLista (Lista l);

bool  EstaOrdenada (const Lista l);
void  OrdenaSeleccionLista (Lista &l);
void  InsertaOrdenadamente (Lista &l, TipoBase v);
void  EliminaValor (Lista &l, TipoBase v);

Lista MezclaListas (Lista &l1, Lista &l2);

#endif
