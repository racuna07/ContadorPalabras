// ContadorPalabras.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Archivo.h"
#include "ContadorDePalabras.h"
#include "Palabra.h"
using namespace std;


int main()
{
	//Se abre y se lee el archivo, luego se almacena en un char* y se obtiene su largo.
	Archivo* archivo = new Archivo("Prueba2.txt");
	char* texto = archivo->charArchivo();
	int length = archivo->getLength();

	//Se inicializa el contador que analiza el texto cuando se llama a su constructor.
	ContadorDePalabras* contador = new ContadorDePalabras(texto, length);
	
	char** textoLimpio = contador->getTextoLimpio();
	for (int i = 0; i < contador->getNumeroLineas(); i++) {
		for (int j = 0; textoLimpio[i][j-1] != '\n'; j++) {
		
			cout << textoLimpio[i][j];
		}
	}
	cout << "Numero de palabras: " << contador->numeroPalabras << endl;

	char** palabras = contador->getPalabras();
	for (int i = 0; i < contador->iPalabra; i++) {
		for (int j = 0; palabras[i][j]!=' ' ;j++){
			cout << palabras[i][j];
		}
		cout << endl;
	}

	Palabra** vectorPalabras = contador->getVectorPalabras();
	int** vectorIndices = contador->getVectorIndices();
	cout << "Palabra                     Repeticiones       Indices" << endl;
	for (int i = 0; i < contador->iPalabra; i++) {
		Palabra* palabra = vectorPalabras[i];
		char* charPalabra = palabra->getPalabra();
		int* indices = vectorIndices[i];
		int repeticiones = contador->getRepeticionesPalabra(charPalabra);
		cout << charPalabra<< " " << repeticiones<<"  ";
		for (int j = 0; j < repeticiones; j++) {
			cout << '[' << indices[j*2] <<','<< indices[(j*2) + 1] << ']';
		}
		cout<<endl;
	}
	system("pause");
    return 0;
}

