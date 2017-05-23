Definir la estructura de la clase barquitos:

  class Barquitos{
    int **v;
    int filas;
    int columnas;
    ...
   }
  
Constructor con filas y columnas:
  Asigna filas y columnas
  CreaMatriz
  
CreaMatriz:
  Crea un vector de punteros (tantos como filas)
  Crea en v[0], filas x columnas elementos
  Asigna punteros a cada fila de la matriz
  
Constructor de copia:
  Asigna filas y columnas
  CreaMatriz
  CopiaValores
  
CopiaValores:
  Desde i = 0 hasta filas
    Desde j = 0 hasta columnas
      v [i][j] = aux.v [i][j]
   
Destructor:
  Elimina v[0]
  Elimina v
  
Sobrecarga del operador de asignación:
  Si no es el mismo
    Crea auxiliar con el constructor de copia
    Swap
  Devuelve *this
  
Swap:
  Intercambia filas y columnas
  Intercambia **v
  
InsertaBarquito (recibe fila, columna, tamaño del barquito, carácter):
  Comprueba si no existe en las posiciones que se desea ningún barquito y tamaño válido (método auxiliar)
    Si se puede
      Introducir valor entero i = 0 desde (fila, columna)
        Si carácter == 'V' (significa que se quiere poner en vertical)
          hasta (fila + tam, columna)
            Se introduce valor de que existe un barco
        Sino
          Si carácter == 'H' (significa que se quiere poner en horizontal)
            hasta (fila, columna + tam)
             Se introduce valor de que existe un barco en esa posición
    Sino
      Lanza excepción indicando de que no se puede utilizar en dicha posición Ó devuelve un bool indicando si la operación
      ha tenido éxito o no
      
CompruebaValido (comprueba si se puede introducir un barco en una posición deseada, recibe filas, columnas, tamaño y carácter):
  Si  carácter == 'V'
    Desde i = 0; i < tam && correcto; i++
      Si (*(filas + i, columnas) < 0)
        correcto = false;
  Sino
    Desde j = 0; j < tam && correcto; j++
      Si (*(filas, columnas + j) < 0)
        correcto = false;                         // Se supone que el hecho de que haya un barquito es menor que 0, aux asi
                                                  // la condición se produce con el valor que tenga el puto barco
  Devuelve correcto;
