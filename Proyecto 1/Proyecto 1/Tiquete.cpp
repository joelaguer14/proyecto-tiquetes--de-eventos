/*Tiquete.cpp
Creado por:
Manfred Joel Agüero Campos
Terminado el dia:
19 de diciembre del 2018
Proyecto 1*/
#include "Tiquete.h"

Tiquete::Tiquete()
{
	fecha=" ";
	hora=" ";
	lugar=" ";
	fechaSistema=" ";
	precio = 10500;
	impr = 1255;

}

void Tiquete::setFecha(string f)
{
	fecha = f;
}

void Tiquete::setHora(string h)
{
	hora = h;
}

void Tiquete::setLugar(string l)
{
	lugar = l;
}

void Tiquete::setFechaSistema(string fS)
{
	fechaSistema = fS;
}

int Tiquete::totalAPagar(int f) //Este metodo calcula el total a pagar por tiquete para escribirlo en el tiquete
{
	int total = 0;
	total = precio + impr;
	if (f <= 20) {
		total = total + total * 0.50;
	}
	total = total + total * 0.13;
	return total;
}

string Tiquete::getFecha()
{
	return fecha;
}

string Tiquete::getHora()
{
	return hora;
}

string Tiquete::getLugar()
{
	return lugar;
}

string Tiquete::getFechaSistema()
{
	return fechaSistema;
}

void Tiquete::generaTicket(int k, int i, int j)//Este metodo genera un archivo donde guarda los tiquetes de cada compra
{
	ofstream outFile;						   // creando flujo tipo objeto.
											  //Abriendo archivo de salida.....
	outFile.open("tiquetes.txt", ios::app);  //dando nombre externo.
											//se coloca el apuntador al final del archivo
	outFile << "-----------Tiquete numero: " << k+1 << "  ----------" << endl << endl;
	outFile << "Fecha del sistema: " << getFechaSistema() << endl;
	outFile << "Fecha del evento: " << getFecha() << endl;
	outFile << "Lugar del evento: " << getLugar() << endl;
	outFile << "Hora del evento: " << getHora() << endl;
	outFile << "Localidad del asiento: " << numeroAsiento(i,j) << endl<<endl;
	outFile << "Total a pagar: " << totalAPagar(i) << "  I.V.I." << endl;
	outFile.close();
}

string Tiquete::numeroAsiento(int i, int j)//este metodo convierte los dos parametros de la posicion del asiento en un string para asignarselo
										   // a asiento y poder asi, generar el tiquete
{
	asiento = " ";
	stringstream s;
	s << i << "," << j;
	asiento = s.str();
	return asiento;
}


Tiquete::~Tiquete()
{
	//destructor de tiquete
}
