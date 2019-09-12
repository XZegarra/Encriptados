#include "Usuario.h"

Usuario::Usuario() {
	key = 0;
}
Usuario::Usuario(int key1) {
	key = key1;
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
string Usuario::encrypt(string message1) {
	message = message1;
	int filas = key;
	int columnas;
	string encrypted;
	for (int i = 1;i < message.length();i++) {
		if (i * filas >= message.length()) {
			columnas = i;
			break;
		}
	}
	for (int j = 0;j < columnas;j++) {
		string str = "";
		for (int i = j;i < filas*columnas;i+=columnas) {
			if (i < message.length()) {
				str = str + message[i];
			}
			else {
				str = str + "w";
			}
		}
		encrypted = encrypted + str;
	}
	return encrypted;
}
string Usuario::decrypt(string encryptedMessage) {
	int columnas = key;
	int filas;
	string decrypted = "";
	for (int i = 1;i < encryptedMessage.length();i++) {
		if (i * columnas >= encryptedMessage.length()) {
			filas = i;
			break;
		}
	}

	for (int j = 0;j < columnas;j++) {
		string str = "";
		for (int i = j;i < encryptedMessage.length();i += columnas) {
			str = str + encryptedMessage[i];
		}
		decrypted = decrypted + str;
	}
	return decrypted;
}
string Usuario::getMessage() {
	return message;
}
