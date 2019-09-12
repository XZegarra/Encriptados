#include <iostream>
#include "Funciones.h"
#include "../Usuario.h"

using namespace std;

int main() {

	Usuario Emisor(11);
	cout << "El mensaje es: " << endl << Emisor.getMessage() << endl;
	cout << "El mensaje incriptado es: " << endl << Emisor.encrypt("Hola como estas") << endl;
	cout << "El mensaje desinptado es: " << endl << Emisor.decrypt("trus5wwwwwweeat wwwwwwn nabwwwwwwgyt ywwwwwwo al wwwwww nraewwwwwwhoeslwwwwwwa   iwwwwwwmah3awwwwwwbga1swwwwww") << endl;
}