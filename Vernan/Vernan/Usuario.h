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
	string alphabet = "abcdefghijklmnopqrstuvwxyz0123456789 ";
	public:
		Usuario();
		Usuario(string text);
		string keyGen();
		string encrypt(string key);
		string decrypt();
		string getMessage();
};

