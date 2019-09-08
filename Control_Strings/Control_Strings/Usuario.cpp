#include "Usuario.h"

Usuario::Usuario() {
	message = "";
}
Usuario::Usuario(string text) {
	message = text;
}
string Usuario::keyGen() {
	vector <string> clave;
	string key = "";
	srand(time(NULL));
	for (int i = 0;i < message.length();i++) {
		int randomValue = modulo(rand(), message.length());
		string temp;
		temp = to_string(randomValue);
		clave.push_back(temp);
	}
	for (int i = 0;i < message.length();i++) {
		stringstream temp(clave[i]);
		int temp2;
		temp >> temp2;
		key = key + alphabet[temp2];
	}
	return key;
}
string Usuario::encrypt(string key) {
	int* arrow = new int[message.length()]; //creamos un arreglo de enteros para almacenar
	for (int i = 0;i < message.length();i++) {
		int n1;
		int n2;
		for (int k = 0; k < alphabet.size();k++) {
			if (alphabet[k] == message[i]) {       // recorremos el abecedario y recorremos los valores hasta que este sea igual a mensaje sub i
				n1 = k;								 // si la anterior condicion es verdadera igualamos n1 a esa parte de la cadena
			}
		}
		for (int t = 0; t < alphabet.size();t++) {
			if (alphabet[t] == key[i]) {		// usamos la misma iteracion anterior, pero en vez de mensaje sub i, lo comparamos con clave sub i
				n2 = t;								// esta vez si la condicion se cumple igualamos n2 a esa parte de la cadena
			}
		}
		if (n1 + n2 < 37) {
			arrow[i] = (n1 + n2);// almacenamos la suma de n1 y n2 en arrow 
		}
		else {
			arrow[i] = (n1 + n2) - 36;
		}
	}

	string mensajeCifrado = ""; // creamos un string para almacenar el mensaje cifrado

	for (int i = 0;i < message.length();i++) {
		int l = arrow[i]; // igualamos una variable l a arrow sub i 
		mensajeCifrado = mensajeCifrado + alphabet[l]; // almacenamos en mensajeCifrado el caracter abecedario sub l
	}
	return mensajeCifrado;
}
string Usuario::decrypt(string mensajeCifrado, string key) {
	string mensajeNuevo = "";
	for (int i = 0; i < mensajeCifrado.length();i++) {
		int pos1;
		pos1 = alphabet.find(mensajeCifrado[i]) - alphabet.find(key[i]);
		if (pos1 <= 0) {
			mensajeNuevo = mensajeNuevo + alphabet[pos1 + 36];
		}
		else {
			mensajeNuevo = mensajeNuevo + alphabet[pos1];
		}
	}
	return mensajeNuevo;
}
string Usuario::getMessage() {
	return message;
}