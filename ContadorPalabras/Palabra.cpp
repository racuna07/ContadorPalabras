#include "stdafx.h"
#include "Palabra.h"

Palabra::Palabra()
{
	this->palabra = NULL;
	this->indice = NULL;
}

Palabra::Palabra(char * palabra, int indice)
{
	
	this->palabra = palabra;
	this->indice = indice;
}

Palabra::~Palabra()
{
}

char * Palabra::getPalabra()
{

	return this->palabra;
}

int Palabra::getIndice()
{
	return this->indice;
}
