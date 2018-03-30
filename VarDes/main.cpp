// *******************  Incluir librer�as  *******************
#include "iostream"
#include "string"
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;
// *******************  Variables  *******************
const int lim = 5, rango = 5; // Definir� el tama�o del arreglo, y de los ciclos
int valores[lim], valoresCuadrado[lim], valorAux[lim]; // Arreglos
int num, i, j;
float media = 0;
// *******************  Funciones  *******************

// Nos devuelve 50 n�meros al azar, que ser�n los valores para la Varianza y Desviaci�n Est�ndar
void NumeroAzar() {
  srand(time(NULL)); // Generar la "semilla" de n�meros aleatorios
  for(i = 0; i < lim; i++) {
      num =  rand() % ((rango - 1) + 1); // N�meros aleatorios de 0 a 10
      valores[i] = num; // Guardar el n�mero aleatorio en el arreglo
      cout << "[ " << num << " ] ";
  }
}

// Calcular media
void CalcularMedia() {
	for (i = 0; i < lim; i++) {
		media += valores[i];
	}
	media /= lim;
}
void RestarMediaElevar() {
	int a;
	for (i = 0; i < lim; i++) {
		a = valores[i] - media;
		valorAux[i] = pow(a , 2);
	}
}


// ******************* Varianza y Desviaci�n Est�ndar *******************

void ObtenerV_D() {
	double varianza = 0, desviacionEstandar = 0;
	
	CalcularMedia();
	RestarMediaElevar();
	
	for (i = 0; i < lim; i++) {
		varianza += valorAux[i];
	}
	varianza /= lim;
	desviacionEstandar = pow(varianza, 0.5);
	
	cout << "\n\n\n La varianza es de: " << varianza << endl;
	cout << "\n La Desviaci�n Est�ndar es de: " << desviacionEstandar << endl;
	
}

// Restar media a cada dato
int main(int argc, char** argv) {
	NumeroAzar();
	ObtenerV_D();
	return 0;
}
