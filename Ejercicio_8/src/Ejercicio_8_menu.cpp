// La clase empieza así

class Menu {
  char *titulo; // Título general del Menú
  char **opc; // Cadenas de longitud variable que describen cada una de las opciones
  int nopc; // Número de opciones en el menú
  
  ...
};

Constructor de copia
  Pone todo a 0

Destructor
  Elimina título
  Desde i = 0 hasta nopc
    Elimina opc [i]
  Elimina opc
  
Constructor de copia
  Reconoce el tamaño del título
  Desde 0 hasta tamaño del título
    Copiar caracter a caracter
  Crear tantas filas de opc como sea el valor de nopc del objeto pasado a la función
  Desde 0 hasta nopc
    Copia Caracter a caracter cada opción del título
 
Sobrecarga del operador de asignación (=)
  Si no son iguales
    Llama al constructor de copia creando un auxiliar
    Intercambia valores del auxiliar y this
 
Intercambiar valores
  Intercambia nopc
  Intercambia la dirección de memoria de titulo
  Intercambia la dirección de memoria de opc
  
setTitulo (recibe una cadena char)
  Reconoce longitud de la cadena
  Elimina un título actual
  Crea un vector con la longitud de la cadena
  Copia caracter a caracter

getNumeroOpciones
  Devuelve el número de opciones del menú
 
agregarOpcion (recibe una cadena)
  Reserva nopc + 1 para un auxiliar **
  Apunta al mismo sitio que **opc
  En la última (el último puntero del vector de punteros quedará libre) se asigna la nueva opción
  Intercambia **
  Eliminar solo **

Sobrecarga del operador<< y operador>> y poco más
Voto por una representación interca como un puntero a puntero que maneje un vector de punteros y estos tenga vectores de cadenas
Equivale a una de las representaciones de la práctica 5
