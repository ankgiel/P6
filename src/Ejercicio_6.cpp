Comienzo:

class Skyline {
 private:
  double *abscisas;   // array de abscisas
  double *alturas;    // array de alturas (> 0, la ultima sera 0)
  int n;              // tam de los arrays anteriores
public:
  ...
};

Constructor por defecto:
  Todo a 0

Destructor:
  Elimina punteros abscisas y alturas
  
Constructor de copia:
  Asigna n del objeto pasado como parámetro al implícito
  Crea abscisas con n elementos
  Crea alturas con n elementos
  Copia abscisas
  Copia alturas
  
Sobrecarga del operador de asignación:
  Si no son el mismo
    CreaAuxiliar con el constructor de copia
    Intercambia valores
  Devuelve *this
  
Intercambia valores:
  Intercambia n
  Intercambia punteros
  
/////////////////////////////////// No entiendo el otro constructor ////////////////////////////////////////

getElementos:
  Devuelve n
  
Sobrecarga del operador () (int, int):
  Si está dentro del rango se devuelve abscisas [i], alturas [j]
  Sino
    Se lanza excepción tipo length_error (throw length_error ("Te me has venido arriba primo.")) [así sería]
    
