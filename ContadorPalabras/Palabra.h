#pragma once
class Palabra
{
public:
	Palabra();
	Palabra(char*,int);
	~Palabra();
	char* getPalabra();
	int getIndice();
private:
	char* palabra;
	int indice;
};

