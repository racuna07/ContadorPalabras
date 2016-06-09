#include "stdafx.h"
#include "ContadorDePalabras.h"


ContadorDePalabras::ContadorDePalabras(char * texto,int length)
{
	this->texto = texto;
	this->length = length;
	this->textoLimpio = new char*[length];
}

void ContadorDePalabras::sanitize()
{
	int numeroLinea = 0;
	int indice = 0;
	char* linea = new char[300];

	for (int i = 0; i < this->length; i++) {
		char caracter = this->texto[i];
		if (caracter == '\n') {
			if (indice > 1) {
				this->textoLimpio[numeroLinea] = linea;
				numeroLinea += 1;
				indice = 0;
				linea = new char[300];
			}
			indice = 0;
			linea = new char[300];
		}

		else if ((caracter == ' ')&& i!=0) {
			if (texto[i - 1] == ' ' ) { continue; }
			linea[indice] = caracter;
			indice += 1;
		}

		else{
			linea[indice] = caracter;
			indice += 1;
		}
	}
	
}

char ** ContadorDePalabras::getTextoLimpio()
{
	return this->textoLimpio;
}

char** ContadorDePalabras::getPalabras()
{
	return 0;
}

int ContadorDePalabras::getRepeticionesPalabra(char *palabra)
{
	return 0;
}

int* ContadorDePalabras::getPosicionPalabra(char *palabra,int numeroAparicion)
{
	return 0;
}

