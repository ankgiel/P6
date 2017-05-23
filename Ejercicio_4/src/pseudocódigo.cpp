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
       Quedarse con dicha dirección de memoria en un puntero
  Recorre celdas hasta la primera celda de la otra
       Igual pero en otro puntero
  Recorrer ambas celdas desde sus respectivos punteros hasta (ultima celda lista 1 - primera ultima celda lista 2)
      asignar valores de celdas siguientes
  
ConcatenaListas:
  Asigna num_elem como la suma de las 2 listas
  CreaLista
  Copia valores pasando primera lista desde 0 hasta num_elem primera lista
  Copia valores pasando la segunda lista desde num_elem primera lista hasta num_elem del objeto implícito

CreaLista:
  Crea tantas celdas como sea el valor de num_elem
 
 Sobrecarga del operador de asignacion:
      Igual que siempre (constructor de copia + swap)
              
 Swap:
      Intercambia el puntero de inicio de las listas
      
 Sobrecarga del operador [] (borra una celda de la lista):
               Igual que la segunda alternativa
               
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
  
TERCERA ALTERNATIVA (la más rara pero la considero la mejor de todas por ser eficiente y modularizable):
    Invariante de la representación (algo que siempre va a pasar):
       Va a tener una celda de cabecera (una que no tenga valores ni se borre ni nada, la de inicio)
              
    Constructor por defecto:
        Asigna num_elem a 1
        Crea la celda de cabecera
    
    Constructor de copia:
        Asigna num_elem
        Crea la celda de cabecera
        CopiaValores
        
    PRE: el primer puntero tiene que ser uno implícito del objeto
    
    CopiaValores (pasa como argumento 2 puntero a celda, se copiara el contenido del 2 al primero):
         // Nos olvidamos de que tenemos que controlar que haya al menos una celda
         Desde el puntero 1 del objeto implícito hasta que el puntero pasado sea 0
              Si i == a num_elem
                aux = CreaNueva (puntero a celda)
                incrementa num_elem
              Sino
                asignar valores
              
              asignar puntero aux (el que recorre la lista) a sig
              
    Sobrecarga del operador de asignación:
          Como siempre
          
    Sobrecarga del operador + (concatena 2 listas):
          Asigna num_elem como suma de las 2 listas
          Recorre hasta el último elemento
            Guarda el último puntero en uno auxiliar
          CopiaValores (último puntero, puntero inicial de la 2 celda)
    
    Sobrecarga del operador []:
              Igual que los anteriores
         

