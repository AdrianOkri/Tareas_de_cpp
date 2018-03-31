// *******************  Incluir librerías  *******************
#include "iostream"
#include "string"
#include <stdlib.h>
#include <time.h>

using namespace std;
// *******************  Variables  *******************
int candidato1 = 0,candidato2 = 0,candidato3 = 0,candidato4 = 0,candidato5 = 0;
int voto, total, usuario = 1;
float procentaje;
// *******************  Funciones  *******************
void Menu() {
	char f = 'f'; bool a = true;
	do {
		cout << "\n P R O G R A M A		D E		V O T O S " << endl;
		cout << "\n						 		Usario " << usuario << endl;
		cout << "\n candidato1 = 1\n candidato2 = 2\n candidato3 = 3\n candidato4 = 4\n candidato5 = 5\n :";
		cin >> voto;
		system("cls");
		cout << " H A S		V O T A D O 	P O R 	E L 	C A N D I D A T O   " << voto << endl;
		cout << "\n Anular voto = n		Finalizar = f		Continuar = c" << endl;
		cin >> f;
		if (f == 'f') {
			a = false;
		}
		if (voto > 0 && voto < 6 && f != 'n') {
			switch(voto) {
				case 1: candidato1++; break;
				case 2: candidato2++; break;
				case 3: candidato3++; break;
				case 4: candidato4++; break;
				case 5: candidato5++; break;
			}
			system("cls");
			usuario++;
		} else if (f == 'n') {
			cout << "Voto anulado" << endl;
		} else {
			cout << "Voto no valido" << endl;
		}
	}while(a);
}

void MostrarProcentaje(int n, int candidato) {
	procentaje = (candidato * 100) / total;
	cout << "El porcentaje de candidato " << n << " es de: " << procentaje << "%" << endl;
}

void ContarVotos() {
	total = candidato1 + candidato2 + candidato3 + candidato4 + candidato5;
	cout << " El total de votos es de: " << total << endl;
	MostrarProcentaje(1, candidato1); MostrarProcentaje(2, candidato2);
	MostrarProcentaje(3, candidato3); MostrarProcentaje(4, candidato4);
	MostrarProcentaje(5, candidato5);
}

int main(int argc, char** argv) {
	Menu();
	ContarVotos();
	return 0;
}
