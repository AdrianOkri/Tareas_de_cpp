// *******************  Incluir librer�as  *******************
#include "iostream"
#include "string"
#include <stdlib.h>
#include <time.h>

using namespace std;

// *******************  Variables  *******************
int calficaiones[50], concurencia[11];
int mayor = 0, frecuencia = 0, index, num;
int i, j, lim = 50;

// Nos devuelve 50 n�meros al azar, que ser�n las calificaciones de los alumnos
void NumeroAzar() {
  srand(time(NULL)); // Generar la "semilla" de n�meros aleatorios
  for(i = 0; i < lim; i++) {
      num =  rand() % (11); // N�meros aleatorios de 0 a 10
      calficaiones[i] = num;
  }
}
// Ver que calificaci�n se repite m�s que otras
void CalcularOcurrencia() {
  for(i = 0; i <= 10; i++) {
    for (j = 0; j < 50; j++) {
      if (i == calficaiones[j]) {
        frecuencia ++;
      }
    }
    concurencia[i] = frecuencia;
    cout << "Los alumnos que tuvieron la calificaci�n " << i << " son de: " << frecuencia << endl;
    frecuencia = 0;
  }
}
// Obtener la calificaci�n con mayor frecuencia
void ObtenerCaliMayor() {
  for (i = 0; i <= 10; i++) {
		if (concurencia[i] > mayor) {
			mayor = concurencia[i];
      		index = i;
		}
	}
	cout << "\nLa calificaci�n con la mayor concurrencia es: " << index << " pues se repite " << mayor << " veces " << endl;
}
// ******************* Inicio *******************
int main(int argc, char** argv) {
	NumeroAzar();
  	CalcularOcurrencia();
  	ObtenerCaliMayor();
	return 0;
}
