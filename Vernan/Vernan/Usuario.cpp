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
	vector <string> trueValue;
	vector <string> keyValue;
	vector <string> binaryR;
	string result = "";
	for (int i = 0;i < message.length(); i++) {
		int temp1 = alphabet.find(message[i]);
		int temp2 = alphabet.find(key[i]);
		trueValue.push_back(to_string(temp1));
		keyValue.push_back(to_string(temp2));
	}
	for (int i = 0;i < message.length();i++) {
		string newS = "";
		int toConvert1;
		int toConvert2;
		string temp1 = trueValue[i];
		string temp2 = keyValue[i];
		stringstream temporary1(temp1);
		stringstream temporary2(temp2);
		temporary1 >> toConvert1;
		temporary2 >> toConvert2;
		bitset <6> set1(toConvert1);
		bitset <6> set2(toConvert2);
		string firstValue = set1.to_string();
		string secondValue = set2.to_string();
		for (int k = 0;k < firstValue.length();k++) {
			if (firstValue[k] == secondValue[k]) {
				newS = newS + '0';
			}
			else {
				newS = newS + '1';
			}
			if (newS.length() == firstValue.length()) {
				binaryR.push_back(newS);
			}
		}
	}
	for (int i = 0;i < binaryR.size();i++) {
		string temp = binaryR[i];
		int number =  stoi(temp,0,2);
		if (number >= alphabet.length()) {
			int newNumber = modulo(number,alphabet.length());
			result = result + alphabet[newNumber];
		}
		else {
			result = result + alphabet[number];
		}
	}
	return result;
}
string Usuario::decrypt() {
	return "Hola";
}
string Usuario::getMessage() {
	return message;
}