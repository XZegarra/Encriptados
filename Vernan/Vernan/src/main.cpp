#include <iostream>
#include "Funciones.h"
#include "../Usuario.h"

using namespace std;

int main() {

	Usuario Emisor("hola como estas amigo mio");
	cout <<"El mensaje es: " << endl << Emisor.getMessage() << endl;
	string clave = Emisor.keyGen();
	cout << "La clave es: " << endl << clave << endl;
	cout <<"El mensaje incriptado es: "<< endl << Emisor.encrypt(clave);
}