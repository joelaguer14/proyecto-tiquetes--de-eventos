/*Vector.h
Creado por:
Manfred Joel Agüero Campos
Terminado el dia:
19 de diciembre del 2018
Proyecto 1
*/

#pragma once
#include<string>
#include<iostream>
using namespace std;
#include"Coleccion.h"
class Vector
{
	Coleccion **vector;

public:
	Vector();
	void setDia(int, string);
	void setHora(int, string);
	void setLugar(int, string);
	void elimina(int);
	string getDia(int);
	string getHora(int);
	string getLugar(int);
	string toString(int);
	void setEstadoAsi(int, int, int, char);

	~Vector();
};

