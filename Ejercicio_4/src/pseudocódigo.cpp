Constructor por defecto
Constructor de copia
Destructor
Sobrecarga del operador de asignación
Sobrecarga del operador + (concatena una lista con la otra)
Sobrecarga del operador [] (recibe un int y borra el elemento de i de la lista)

class Celda {
  double info;
  Celda *sig;
  
public:
  Celda (): info (0), sig (0) {}
  
  double getValor (){
    return info;
  }
  Celda *getSiguiente () {
    return sig;
  }
};

class Lista {
private:
  Celda *inic;
  int num_elem;
  
  ...
};

PRIMERA ALTERNATIVA (mayor modularización, preferible para futuras mejoras, menor eficiencia):

Constructor por defecto:
  Asigna todo a 0
  
Constructor de copia:
  Asigna número de elementos
  CreaLista
  CopiaValores
  
CopiaValores (lista, int (ultima celda lista 1), int (ultima celda lista 2), int (primero celda lista 1), int (primera celda lista 2)
  PRE: ULTIMA CELDA LISTA 1 - PRIMERA CELDA LISTA 1 == ULTIMA CELDA LISTA 2 - PRIMERA CELDA LISTA 2 Y TIENEN QUE SER VALORES
      >= 0 Y MENORES QUE NUMERO DE ELEMENTO DE AMBAS CELDAS
  Recorre celdas hasta primera celda de algunas de las 2
  Recorre celdas hasta la primera celda de la otra
  Copiar valor de celdas hasta (ultima celda lista 1 - primera ultima celda lista 2)
  
SEGUNDA ALTERNATIVA (menor modularización, menor eficiencia):
  
  Constructor por defecto:
    Todo a 0
   
  Constructor de copia:
    Asigna num_elem
    Creo la primera celda
    Se tiene 2 punteros auxiliares
      Uno para mantener el anterior y otro para ir avanzando
    Bucle for para ir recorriendo la lista hasta num_elem
      Va creando celdas y asignando los valores de la otra celda a la anterior
  
  Sobrecarga del operador de asignación:
    Si no son el mismo puntero inicial
      Crea una lista auxiliar con el constructor de copia
      Intercambia valores
      
    Devuelve this
     
  Destructor:
    Puntero auxiliar que contiene el valor de inic
    Bucle for i = 0, hasta num_elem
      Asigna el valor de inic a el auxiliar
      Elimina inic
      Asigna el siguiente del auxiliar a inic
   
  Sobrecarga del operador + (concatena 2 listas)
    Asigna num_elem como la suma de ambas listas
    Creo la primera celda
    Se tiene 2 punteros auxiliares
      Uno para mantener el anterior y otro para ir avanzando
    Bucle for para ir recorriendo la primera lista hasta num_elem (de la primera lista)
      Va creando celdas y asignando los valores de la otra celda a la anterior
    Bucle for para ir recorriendo la segunda lista desde num_elem (de la primera lista) hasta num_elem (lista actual)
      Va creando celdas y asignando los valores de la otra celda a la anterior
    
    Devuelve *this; // Devuelve lista por referencia
  
  Sobrecarga del operador [] (borra 1 elemento de la lista)
    Si elemento enviado es menor que num_elem
      Recorre hasta elemento - 1
      
      (No hace falta comprobar si el siguiente es 0 ni nada, en caso de serlo lo contendrá la celda anterior a borrar)
      Puntero auxiliar para recibir la dirección de memoria de la siguiente celda a la que apunta la que se borra
      Borra con la celda anterior a borrar la celda a borrar (siguiente)
      Asigna ese siguiente la dirección de memoria del puntero auxiliar que creamos
  
