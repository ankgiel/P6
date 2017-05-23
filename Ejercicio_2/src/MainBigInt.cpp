#include <iostream>
#include "BigInt.h"
using namespace std;

int main (){
	BigInt numero_1;

	cout << "Introduzca el BigInt: " << endl;
	cin >> numero_1;

	BigInt numero_2 (numero_1), numero_3;

	numero_3 = numero_1 + numero_2;

	cout << "BigInt sumado consigo mismo: " << endl;
}
