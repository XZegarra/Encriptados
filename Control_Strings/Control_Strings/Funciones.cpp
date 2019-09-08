#include "Funciones.h"

using namespace std;

void prueba() {
	cout << "Lo logre";
}
int modulo(int dividendo,int divisor) {
	int cociente = dividendo / divisor;
	int residuo;
	if (divisor>0) {
		residuo = dividendo - (cociente * divisor);
	}
	else {
		int temp = cociente * divisor;
		temp -= divisor;
		residuo = (temp) - dividendo;
	}

	return residuo;
}