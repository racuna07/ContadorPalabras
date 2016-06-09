#pragma once
class ContadorDePalabras
{
public:
	char* texto;
	char** textoLimpio;
	int length;
	ContadorDePalabras(char* texto, int length);
	~ContadorDePalabras();
	void sanitize();
	char** getTextoLimpio();
	char** getPalabras();
	int getRepeticionesPalabra(char*palabra);
	int* getPosicionPalabra(char*palabra,int numeroAparicion);
};

