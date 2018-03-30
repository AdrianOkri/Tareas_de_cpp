// *******************  Incluir librerías  *******************
#include "iostream"
#include "string"
#include <stdlib.h>
#include <time.h>

using namespace std;

// *******************  Variables  *******************
const int lim = 50, rango = 50; // Definirá el tamaño del arreglo, y de los ciclos
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
// Nos devuelve 50 números al azar, que serán los valores para la Moda, Media y Mediana
void NumeroAzar() {
  srand(time(NULL)); // Generar la "semilla" de números aleatorios
  for(i = 0; i < lim; i++) {
      num =  rand() % ((rango - 1) + 1); // Números aleatorios de 0 a 10
      valores[i] = num; // Guardar el número aleatorio en el arreglo
  }
  Imprimir("Lista de números aleatorios");
}
// Ordenar números de mayor a menor
void OrdenarNumeros() {
	int aux;
	
	for (i = 0; i < lim; i++) {
		for (j = i+1; j < lim; j++) {
			if(valores[i] > valores[j]){
				aux = valores[i];
				valores[i] = valores[j];
				valores[j] = aux;
			}
		}
	}
	Imprimir("Lista de números ordenados");
}
// *******************  Moda  *******************
int Repetir(int n) {
	int x = 0;
	for (j = 0; j < lim; j++) {
		if(n == valores[j]) { // Cada que un valor se repita, la variable x incrementará en 1
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
		
		if (rep < Repetir(n)) { // La condición manda un valor a la función, si está tiene un número mayor de repeticiones
			rep = Repetir(n); // se guarda en la variable rep y a su vez
			valor = valores[i]; // guardamos el valor que se repite más
		}
	}
	
	if (rep != 1) { // Imprimir los resultados de la Moda
		cout << "\n\nLa moda en el areglo es " << valor << ", se repite: " << rep << " veces" << endl;	
	} else { // Si ningún dato se repite más de una vez, no hay moda
		cout << "\n\nNo hay Moda" << endl;
	}
	
}
// *******************  Media  *******************
void CalcularMedia() {
	float media = 0;
	for (i = 0; i < lim; i++) {
		media += valores[i];
	}
	media /= lim;
	
	cout << "La media del arreglo es: " << media << endl;
}
// *******************  Mediana  *******************
void CalcularMediana() {
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
