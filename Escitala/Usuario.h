#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/Funciones.h"
#include <vector>
#include <sstream>
#include <bitset> 

using namespace std;

class Usuario
{
	string message;
	int key;
public:
	string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789 ";
	Usuario();
	Usuario(int key1);
	int keyGen();
	string encrypt(string menssage);
	string decrypt(string encryptedMessage);
	string getMessage();
};
