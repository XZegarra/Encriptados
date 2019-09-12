#include "Usuario.h"

Usuario::Usuario() {

}
Usuario::Usuario(string key1) {
	key = key1;
	srand(time(NULL));
	string duplicateAlphabet = alphabet;

	//Generating the random alphabets
	for (int i = 0;i < alphabet.length();i++) {
		int v1 = modulo(rand(),duplicateAlphabet.length());
		randomAlphabet1 = randomAlphabet1 + duplicateAlphabet[v1];
		duplicateAlphabet = removeLetter(duplicateAlphabet, v1);
	}
}
string Usuario::removeLetter(string str, int pos) {
	string str1;

	for (int i = 0;i < pos;i++) {
		str1 = str1 + str[i];
	}
	if (pos != str.length() - 1) {
		for (int i = pos + 1; i < str.length();i++) {
			str1 = str[i];
		}
	}
	return str1;
}
string Usuario::getRandomAlphabet() {
	return randomAlphabet1;
}
string Usuario::keyGen() {
	
	return "Hola";
}
string Usuario::encrypt(string message1) {
	message = message1;
	return message;
	
	
}
string Usuario::decrypt(string encryptedMessage) {
	string decrypted;

	return decrypted;
}
string Usuario::getMessage() {
	return message;
}
