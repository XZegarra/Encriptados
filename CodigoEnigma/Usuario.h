#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Funciones.h"
#include <vector>
#include <sstream>
#include <bitset> 

using namespace std;

class Usuario
{
	string message;
	string key;
	string randomAlphabet1;
	string randomAlphabet2;
	string randomAlphabet3;
	string removeLetter(string str, int pos);

public:
	string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789 ";
	Usuario();
	Usuario(string key1);
	string keyGen();
	string encrypt(string menssage);
	string decrypt(string encryptedMessage);
	string getMessage();
	string getRandomAlphabet();
};
