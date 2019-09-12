#include <iostream>
#include "Funciones.h"
#include "Usuario.h"

using namespace std;

string removeLetter(string str, int pos) {
	string str1;

	for (int i = 0;i < pos;i++) {
		str1 = str1 + str[i];
	}
	if (pos == str.length() - 1) {
		for (int i = pos + 1; i < str.length();i++) {
			str1 = str[i];
		}
	}
	return str1;
}
int main() {
	/*
	Usuario Emisor("gyd");
	cout << Emisor.getRandomAlphabet() << endl;
	*/
	string alphabet  = "abcdefghijklmnopqrstuvwxyz0123456789 ";
	srand(time(NULL));
	string duplicateAlphabet = alphabet;
	string randomAlphabet1;
	//Generating the random alphabets
	for (int i = 0;i < alphabet.length();i++) {
		int v1 = modulo(rand(), duplicateAlphabet.length());
		while (duplicateAlphabet[v1] == 'T') {
			v1 = modulo(rand(), duplicateAlphabet.length());
		}
		randomAlphabet1 = randomAlphabet1 + duplicateAlphabet[v1];

		cout << randomAlphabet1 << endl;
		duplicateAlphabet[v1] = 'T';

	}
}