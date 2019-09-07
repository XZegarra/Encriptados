#include "Usuario.h"

Usuario::Usuario() {
	message = "";
}
Usuario::Usuario(string text) {
	message = text;
}
int Usuario::keyGen() {
	int keyFilas;
	int tam = message.length();
	for (int i = 3;i < message.length();i++) {
		keyFilas = i;
		if (modulo(tam, keyFilas)) {
			continue;
		}
		else {
			break;
		}
	}
	return keyFilas;
}
string Usuario::encrypt(int key) {
	int filas = key;
	int columnas;
	string encrypted = "";
	for (int i = 1;i < message.length();i++) {
		if (i * filas >= message.length()) {
			columnas = i;
			break;
		}
	}
	for (int j = 0;j < columnas;j++) {
		string str = "";
		for (int i = j;i < message.length();i+=columnas) {
			str = str + message[i];
		}
		encrypted = encrypted + str;
	}
	return encrypted;
}
string Usuario::decrypt() {
	return "Hola";
}
string Usuario::getMessage() {
	return message;
}
