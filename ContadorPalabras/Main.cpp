// ContadorPalabras.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Archivo.h"
#include "ContadorDePalabras.h"
using namespace std;


int main()
{
	Archivo* archivo = new Archivo("Prueba.txt");
	char* texto = archivo->charArchivo();
	int length = archivo->getLength();
	cout << length << endl;

	ContadorDePalabras* contador = new ContadorDePalabras(texto, length);
	contador->sanitize();
	char** textoLimpio = contador->getTextoLimpio();
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < 300; j++) {
			cout << textoLimpio[i][j];
		}
		cout << endl;
	}

	system("pause");
    return 0;
}

