/*Coleccion.h
Creado por:
Manfred Joel Agüero Campos
Terminado el dia:
19 de diciembre del 2018
Proyecto 1
*/

#pragma once
#include"Asiento.h"
class Coleccion
{
	Asiento ***matriz;
	int fil;
	int col;
	string dia;
	string hora;
	string lugar;
public:
	Coleccion(int,int);
	void SetEstadoAsi(int, int, char);
	void SetHora(string);
	void SetDia(string);
	void SetLugar(string);
	char getEstadoAsi(int, int);
	string getHora();
	string getDia();
	string getLugar();
	string toStringMatriz();
	~Coleccion();
};

