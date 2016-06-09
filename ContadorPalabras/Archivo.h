#pragma once
class Archivo
{
public:
	Archivo(char * nombreArchivo);
	~Archivo();
	char* charArchivo();
	int getLength();
	char* nombreArchivo;
	int length;
};

