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
public:
	string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789 ";
	Usuario();
	Usuario(string key1);
	string keyGen();
	string encrypt(string message1);
	string decrypt(string encryptedMessage);
	string getMessage();
};
