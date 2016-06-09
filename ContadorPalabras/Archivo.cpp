#include "stdafx.h"
#include "Archivo.h"
using namespace std;


Archivo::Archivo(char* nombreArchivo)
{
	this->nombreArchivo = nombreArchivo;
}


Archivo::~Archivo()
{
}

char* Archivo::charArchivo()
{
	//Se abre el archivo y busca su largo.
	ifstream lectura(this->nombreArchivo);
	lectura.seekg(0, lectura.end);
	int largo = lectura.tellg();
	this->length = largo;
	lectura.seekg(0, lectura.beg);

	//Se almacena el archivo como char*.
	char * texto = new char[this->length];
	lectura.read(texto, this->length);
	
	//Se cierra el archivo y se devuelve el char*.
	lectura.close();
	return texto;
}

int Archivo::getLength()
{
	return this->length;
}
