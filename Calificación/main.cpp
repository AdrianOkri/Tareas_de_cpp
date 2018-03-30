// *******************  Incluir librerías  *******************
#include "iostream"
#include "string"
#include <stdlib.h>
#include <time.h>

using namespace std;

// *******************  Variables  *******************
int calficaiones[50], concurencia[11];
int mayor = 0, frecuencia = 0, index, num;
int i, j, lim = 50;

// Nos devuelve 50 números al azar, que serán las calificaciones de los alumnos
void NumeroAzar() {
  srand(time(NULL)); // Generar la "semilla" de números aleatorios
  for(i = 0; i < lim; i++) {
      num =  rand() % (11); // Números aleatorios de 0 a 10
      calficaiones[i] = num;
  }
}
// Ver que calificación se repite más que otras
void CalcularOcurrencia() {
  for(i = 0; i <= 10; i++) {
    for (j = 0; j < 50; j++) {
      if (i == calficaiones[j]) {
        frecuencia ++;
      }
    }
    concurencia[i] = frecuencia;
    cout << "Los alumnos que tuvieron la calificación " << i << " son de: " << frecuencia << endl;
    frecuencia = 0;
  }
}
// Obtener la calificación con mayor frecuencia
void ObtenerCaliMayor() {
  for (i = 0; i <= 10; i++) {
		if (concurencia[i] > mayor) {
			mayor = concurencia[i];
      		index = i;
		}
	}
	cout << "\nLa calificación con la mayor concurrencia es: " << index << " pues se repite " << mayor << " veces " << endl;
}
// ******************* Inicio *******************
int main(int argc, char** argv) {
	NumeroAzar();
  	CalcularOcurrencia();
  	ObtenerCaliMayor();
	return 0;
}
