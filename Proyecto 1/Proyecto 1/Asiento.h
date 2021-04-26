/*Asiento.h
Creado por:
Manfred Joel Agüero Campos
Terminado el dia:
19 de diciembre del 2018
Proyecto 1
*/

#pragma once
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
class Asiento
{
private:
	int numeracionF;
	int numeracionC;
	char estado;
public:
	Asiento();
	void setNumeraciones(int, int);
	void setEstado(char);
	int getNumF();
	int getNumC();
	char getEstado();
	string toStringAsiento();
	~Asiento();
};

