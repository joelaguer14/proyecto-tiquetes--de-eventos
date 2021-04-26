/*Tiquete.h
Creado por:
Manfred Joel Agüero Campos
Terminado el dia:
19 de diciembre del 2018
Proyecto 1*/

#pragma once
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
class Tiquete
{
private:
	string fecha;
	string hora;
	string lugar;
	string fechaSistema;
	string asiento;
	int precio;
	int impr;

	
public:
	Tiquete();
	void setFecha(string);
	void setHora(string);
	void setLugar(string);
	void setFechaSistema(string);
	int totalAPagar(int);
	string getFecha();
	string getHora();
	string getLugar();
	string getFechaSistema();
	void generaTicket(int, int, int);
	string numeroAsiento(int, int);
	~Tiquete();
};

