#ifndef MATRIZ2D2
#define MATRIZ2D2

typedef double TipoBase ; 

typedef TipoBase ** Matriz2D_2 ; 

Matriz2D_2 CreaMatriz2D_2 (int fils, int cols ) ;

void liberaMatriz2D_2 (Matriz2D_2 matriz, int fils , int cols) ;

Matriz2D_2 LeeMatriz2D_2 (int fils , int cols) ;

Matriz2D_2 AleatoriaMatriz2D_2 (int fils , int cols, int max) ;

void MuestraMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols) ;

Matriz2D_2 CopiaMatriz2D_2 (Matriz2D_2 matriz , int fils , int cols ) ;

Matriz2D_2 SubMatriz2D_2 (Matriz2D_2 matriz , int fil_ini , int col_ini, int fil_end , int col_end) ;

Matriz2D_2 EliminaFilaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int fila_borrar) ;

Matriz2D_2 EliminaColumnaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols, int columna_borrar) ;

Matriz2D_2 TraspuestaMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols) ;

Matriz2D_2 InvierteMatriz2D_2 (Matriz2D_2 matriz, int fils, int cols) ;

#endif 