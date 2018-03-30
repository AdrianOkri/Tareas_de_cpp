// *******************  Incluir librerías  *******************
#include "iostream"
#include "string"
#include <stdlib.h>
#include <time.h>

using namespace std;
// ******************* Variables *******************
int datosClima[24];
int mayor = 0, menor = 24, promedio = 0;;
int i, hrs = 24, num;
// ******************* Funciones *******************

// Nos dará los 24 números que representarán el clima a lo largo del día
void NumerosAzar() {
    srand(time(NULL)); // Generar la "semilla" de números aleatorios
    
    for(i = 0; i < hrs; i++){
        num = 1 + rand() % ((hrs + 1) - 1);
        datosClima[i] = num;
	}
}
// Mostrar el clima que hay a lo largo del día
void HoraClima() {
	for (i = 0; i < hrs; i++) {
		cout << i + 1 << " hrs: " << datosClima[i] << " c" << endl;
	}
}
// Calcular el promedio
void CalcularPromedio() {
	for (i = 0; i < hrs; i++) {
		promedio += datosClima[i]; // Sumar todos los valores
	}
	promedio /= hrs; // Dividir entre las horas totales
	cout << "El promedio es de: " << promedio << endl;
}
// Calcular el número Mayor y Menor de todos los valores
void MostrarMayorMenor() {
	for (i = 0; i < hrs; i++) {
		if (datosClima[i] > mayor) {
			mayor = datosClima[i];
		}
		if (datosClima[i] < menor) {
			menor = datosClima[i];
		}
	}
	cout << "El número mayor es: " << mayor << endl;
	cout << "El número menor es: " << menor << endl;
}
// *******************  Inicio  *******************
int main()
{
   NumerosAzar();
   HoraClima();
   CalcularPromedio();
   MostrarMayorMenor();
   return 0;
}
