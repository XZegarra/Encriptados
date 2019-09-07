
#include <string>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <vector>
using namespace std;


int main()
{
	string abecedario = "abcdefghijklmnopqrstuvwxyz0123456789 "; //la cadena que almacena el abecedario predeterminado
	cout << abecedario.length();
	string mensaje; //la cadena que almacenara el mensaje
	
	cout << "Ingrese el mensaje: " << endl;
	getline(cin, mensaje); //usamos el comando getline para ingresar el mensaje para tener el espacio tambien

	int tam = mensaje.length();
	srand(time(NULL));			
	int aleatorio;

	vector <string> posiciones;		//Esta cadena son las posiciones de las letras para tener, despues, el mensaje cifrado

	for (int i = 0;i < tam;i++) {
		aleatorio = (rand()+rand()+rand())%37; //generamos un numero aleatorio para posiciones sub i, dividido entre el tamaño del string para no exceder el limite
		string alt = to_string(aleatorio); //transformamos el numero a un char
		posiciones.push_back(alt); //insertamos el char en la cadena
	}
	cout << "Estas son las posiciones: " << endl;
	for (int i = 0; i < tam; i++) {
		cout  << posiciones[i] << " " ;
	}
	cout << endl;
	string clave = ""; //la clave del string la iniciamos en una cadena vacia
	 
	for (int i = 0;i < tam;i++) {
		int temp;
		stringstream pos(posiciones[i]);
		pos >> temp;
		clave = clave + abecedario[temp];
	}
	cout << "La clave es: " << endl << clave << endl;
	
	int* arrow = new int[tam]; //creamos un arreglo de enteros para almacenar
	for (int i = 0;i < tam;i++) {
		int n1;
		int n2;
		for (int k = 0; k < abecedario.size();k++) {
			if (abecedario[k] == mensaje[i]) {       // recorremos el abecedario y recorremos los valores hasta que este sea igual a mensaje sub i
				n1 = k;								 // si la anterior condicion es verdadera igualamos n1 a esa parte de la cadena
			}
		}
		for (int t = 0; t < abecedario.size();t++) {
			if (abecedario[t] == clave[i]) {		// usamos la misma iteracion anterior, pero en vez de mensaje sub i, lo comparamos con clave sub i
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

	for (int i = 0;i < tam;i++) {
		int l = arrow[i]; // igualamos una variable l a arrow sub i 
		mensajeCifrado = mensajeCifrado + abecedario[l]; // almacenamos en mensajeCifrado el caracter abecedario sub l
	}
	cout << "El mensaje cifrado es: " << endl;
	cout << mensajeCifrado;
	string mensajeNuevo = "";
	for (int i = 0; i < mensajeCifrado.length();i++) {
		int pos1;
		pos1 = abecedario.find(mensajeCifrado[i]) - abecedario.find(clave[i]);
		if (pos1 < 0) {
			mensajeNuevo = mensajeNuevo + abecedario[pos1+36];
		}
		else{
			mensajeNuevo = mensajeNuevo + abecedario[pos1];
		}
	}
	cout << endl << "Este es el mensaje: " << endl;
	cout << mensajeNuevo;
	
	
	
	
}

