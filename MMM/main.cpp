// *******************  Incluir librer�as  *******************
#include "iostream"
#include "string"
#include <stdlib.h>
#include <time.h>

using namespace std;

// *******************  Variables  *******************
const int lim = 50, rango = 50; // Definir� el tama�o del arreglo, y de los ciclos
int valores[lim]; // Arreglos
int num, i, j;

// *******************  Funciones  *******************
// Imprimir valores del Arreglo
void Imprimir(string mensaje) {
	cout << "\n\n ******************* " << mensaje << " ******************* \n" << endl;
	for (i = 0; i < lim; i++) {
		cout << "[ " << valores[i] << " ] ";
	}
}
// Nos devuelve n�meros al azar determinado por el lim, que ser�n los valores para la Moda, Media y Mediana
void NumeroAzar() {
  srand(time(NULL)); // Generar la "semilla" de n�meros aleatorios
  for(i = 0; i < lim; i++) {
      num =  rand() % ((rango - 1) + 1); // N�meros aleatorios de 0 a 10
      valores[i] = num; // Guardar el n�mero aleatorio en el arreglo
  }
  Imprimir("Lista de n�meros aleatorios");
}
// Ordenar n�meros de mayor a menor
void OrdenarNumeros() {
	int aux;
	// Ordenaci�n de burbuja
	for (i = 0; i < lim; i++) { // Funciona revisando cada elemento de la lista que va a ser ordenada con el siguiente:
		for (j = i+1; j < lim; j++) { // intercambi�ndolos de posici�n si est�n en el orden equivocado
			if(valores[i] > valores[j]){ // Es necesario revisar varias veces toda la lista hasta que no se necesiten m�s intercambios
				aux = valores[i]; //  lo cual significa que la lista est� ordenada
				valores[i] = valores[j];
				valores[j] = aux;
			}
		}
	}
	Imprimir("Lista de n�meros ordenados");
}
// *******************  Moda  *******************
int Repetir(int n) { // La moda es el valor con mayor frecuencia en una distribuci�n de datos
	int x = 0;
	for (j = 0; j < lim; j++) {
		if(n == valores[j]) { // Cada que un valor se repita, la variable x incrementar� en 1
			x++;
		}
	}
	return x; // Retornar el valor total de x
}
// Calcular Moda
void CalcularModa() {
	int n = 0, valor = 0, rep = 0;
	
	for (i = 0; i < lim; i++) {
		n = valores[i];
		
		if (rep < Repetir(n)) { // La condici�n manda un valor a la funci�n, si est� tiene un n�mero mayor de repeticiones
			rep = Repetir(n); // se guarda en la variable rep y a su vez
			valor = valores[i]; // guardamos el valor que se repite m�s
		}
	}
	
	if (rep != 1) { // Imprimir los resultados de la Moda
		cout << "\n\nLa moda en el areglo es " << valor << ", se repite: " << rep << " veces" << endl;	
	} else { // Si ning�n dato se repite m�s de una vez, no hay moda
		cout << "\n\nNo hay Moda" << endl;
	}
	
}
// *******************  Media  *******************
void CalcularMedia() { //La media aritm�tica es el valor promedio de las muestras
	float media = 0; //  y es independiente de las amplitudes de los intervalos.
	for (i = 0; i < lim; i++) { // Se simboliza como y se encuentra s�lo para variables cuantitativas
		media += valores[i];
	}
	media /= lim;
	
	cout << "La media del arreglo es: " << media << endl;
}
// *******************  Mediana  *******************
void CalcularMediana() { // La media es el valor de la variable que deja el mismo n�mero de datos antes y despu�s que �l
	if (lim % 2 == 0) { // Para un arreglo par
		float n1 = valores[(lim / 2) - 1], n2 = valores [lim / 2];
		float promedio = (n1 + n2) / 2;
		cout << "La mediana del arreglo es: " << promedio << endl;
	}else { // Para un arreglo impar
		cout << "Mediana del arreglo es: " << valores[lim / 2] << endl;
	}
}
// *******************  Inicio  *******************
int main(int argc, char** argv) {
	NumeroAzar();
	OrdenarNumeros();
	CalcularModa();
	CalcularMedia();
	CalcularMediana();
	return 0;
}
