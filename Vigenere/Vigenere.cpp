#include <iostream>
#include "Funciones.h"
#include "Usuario.h"

using namespace std;

int main() {

	Usuario persona("hola");
	string mensajeEncriptado = persona.encrypt("hola como estas amigo mio");
	cout << mensajeEncriptado << endl;
	string mensajeDesincriptado = persona.decrypt(mensajeEncriptado);
	cout << mensajeDesincriptado;
}