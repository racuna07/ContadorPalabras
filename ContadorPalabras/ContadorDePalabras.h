#pragma once
using namespace std;
class ContadorDePalabras
{
	friend class Palabra;
public:
	char* texto;
	char** textoLimpio;
	int length;
	int numeroLineas;
	int numeroPalabras;
	Palabra** palabras;
	int iPalabra = 0;
	int* numeroApariciones;
	int** indicesDeApariciones;
	

	ContadorDePalabras(char* texto, int length);
	~ContadorDePalabras();
	char caracterValido(char caracter);
	void analizarTexto();
	void agregarPalabra(char*palabra,int* ubicacion);
	void agregarIndice(int indice,int apariciones,int* lugar);
	int getNumeroLineas();
	void sanitize();
	char** getTextoLimpio();
	Palabra** getVectorPalabras();
	int** getVectorIndices();
	char** getPalabras();
	int getRepeticionesPalabra(char*palabra);
	int* getPosicionPalabra(char*palabra,int numeroAparicion);
	static bool ordenar(Palabra*, Palabra*);
};

