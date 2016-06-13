#include "stdafx.h"
#include "ContadorDePalabras.h"
#include "Palabra.h"


using namespace std;

ContadorDePalabras::ContadorDePalabras(char * texto, int length)
{
	this->texto = texto;
	this->length = length;
	this->textoLimpio = new char*[length];
	this->sanitize();
	this->palabras = new Palabra*[numeroPalabras];
	for (int i = 0; i < numeroPalabras; ++i) {
		palabras[i] = new Palabra();
	}
	this->numeroApariciones = new int[numeroPalabras];
	for (int i = 0; i < numeroPalabras; ++i) {
		numeroApariciones[i] = 0;
	}
	this->indicesDeApariciones = new int*[numeroPalabras];
	for (int i = 0; i < numeroPalabras; ++i) {
	indicesDeApariciones[i] = new int[20];
}
	this->analizarTexto();
}

char ContadorDePalabras::caracterValido(char caracter)
{
	char* caracteresValidos = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz¡…Õ”⁄·ÈÌÛ˙aeiou";
	for (int i = 0; i <= 62; i++) {
		if (caracter == caracteresValidos[i]) {
			if (i < 26) { return caracteresValidos[i + 26];}
			if (i >= 26 && i <= 52) { return caracter; }
			if (i > 52 && i <= 57) { return caracteresValidos[i + 10];}
			if (i > 58) { return caracteresValidos[i + 5]; }
			}
		}
		return '0';
}

void ContadorDePalabras::analizarTexto()
{
	char* palabra = new char[30];
	for (int i = 0; i < this->numeroLineas; i++) {
		int letrasPalabra = 0;
		for (int j = 0; textoLimpio[i][j] != '\n'; j++) {
			char c = textoLimpio[i][j];
			if (c != ' ') {
				palabra[letrasPalabra] = c;
				letrasPalabra += 1;
			}
			else {
				palabra[letrasPalabra] = c;
				int* ubicacion = new int[2];
				ubicacion[0] = i;
				ubicacion[1] = j - letrasPalabra;
				this->agregarPalabra(palabra, ubicacion);
				letrasPalabra = 0;
				palabra = new char[30];
			}
		}

	}
	sort(palabras, palabras + this->iPalabra, ordenar);

}

void ContadorDePalabras::agregarPalabra(char * palabra, int* lugar)
{
	bool encontrada = false;
	for (int i = 0; i < this->iPalabra; i++) {
		char* palabraActual = palabras[i]->getPalabra();
		if (palabraActual == NULL) { break; }
		if (strcmp(palabra, palabraActual)==0) {
			encontrada = true;
			int indice = palabras[i]->getIndice();
			numeroApariciones[indice] += 1;
			this->agregarIndice(indice,numeroApariciones[indice],lugar);
		}
	}
	if (!encontrada) {
		palabras[this->iPalabra] = new Palabra(palabra, this->iPalabra);
		numeroApariciones[this->iPalabra] += 1;
		this->agregarIndice(this->iPalabra, numeroApariciones[this->iPalabra],lugar);
		this->iPalabra += 1;
		
	}
}

void ContadorDePalabras::agregarIndice(int indice, int apariciones, int* lugar)
{
	indicesDeApariciones[indice][apariciones * 2] = lugar[0];
	indicesDeApariciones[indice][(apariciones * 2)+1] = lugar[1];
}

void ContadorDePalabras::sanitize()
{
	int lineaActual = 0;
	int indice = 0;
	int numeroPalabras = 1;
	char* linea = new char[100];

	for (int i = 0; i < this->length; i++) {
		char caracter = this->texto[i];
		if (caracter == '\n') {
			if (indice > 1) {
				linea[indice] = caracter;
				this->textoLimpio[lineaActual] = linea;
				lineaActual += 1;
				indice = 0;
				linea = new char[100];
				numeroPalabras += 1;
			}
			indice = 0;
			linea = new char[100];
		}

		else if ((caracter == ' ')&& i!=0) {
			if (texto[i - 1] == ' ' ) { continue; }
			linea[indice] = caracter;
			indice += 1;
			numeroPalabras += 1;
		}

		else{
			if (caracterValido(caracter)!='0') {
				linea[indice] = caracterValido(caracter);
				indice += 1;
			}
		}
		this->numeroLineas = lineaActual;
		this->numeroPalabras = numeroPalabras;
	}
	
}

int ContadorDePalabras::getNumeroLineas()
{
	return this->numeroLineas;
}

char ** ContadorDePalabras::getTextoLimpio()
{
	return this->textoLimpio;
}

Palabra ** ContadorDePalabras::getVectorPalabras()
{
	return this->palabras;
}

int ** ContadorDePalabras::getVectorIndices()
{
	return this->indicesDeApariciones;
}

char** ContadorDePalabras::getPalabras()
{
	char** resultado = new char*[this->numeroPalabras];
	char* palabra = this->palabras[0]->getPalabra();
	for (int i = 0;i<this->numeroPalabras; i++) {
		if (palabra == NULL) { break; }
		resultado[i] = palabra;
		palabra = this->palabras[i+1]->getPalabra();
	}
	return resultado;
}

int ContadorDePalabras::getRepeticionesPalabra(char *palabra)
{
	for (int i = 0; i < iPalabra; i++) {
		Palabra* palabraActual = palabras[i];
		if (strcmp(palabra, palabraActual->getPalabra()) == 0) {
			return numeroApariciones[palabraActual->getIndice()];
		}
		
	}
}

int* ContadorDePalabras::getPosicionPalabra(char *palabra,int numeroAparicion)
{
	for (int i = 0; i < iPalabra; i++) {
		Palabra* palabraActual = palabras[i];
		if (strcmp(palabra, palabraActual->getPalabra()) == 0) {
			int* posicion = new int[2];
			posicion[0] = indicesDeApariciones[palabraActual->getIndice()][numeroAparicion * 2];
			posicion[1] = indicesDeApariciones[palabraActual->getIndice()][(numeroAparicion * 2) + 1];
			return posicion ;
		}

	}
}

bool ContadorDePalabras::ordenar(Palabra* a, Palabra* b)
{
 return strcmp(a->getPalabra(), b->getPalabra())<0;
}

