/*Coleccion.cpp
Creado por:
Manfred Joel Agüero Campos
Terminado el dia:
19 de diciembre del 2018
Proyecto 1
*/

#include "Coleccion.h"

Coleccion::Coleccion(int F, int C)
{
	fil = F;
	col = C;
	matriz = new Asiento**[fil]; //Se crea el primer vector dinámico 

	for (int i = 0; i<fil; i++)
	{
		matriz[i] = new Asiento*[col];//Se crean los otros vectores dinámicos
	}  //Al salir del ciclo anterior, la matriz ya está construida



	for (int i = 0; i<fil; i++)
	{
		for (int j = 0; j<col; j++)
		{
			matriz[i][j] = new Asiento();//se crea cada asiento y se le asigna su respectiva numeracion y estado
			matriz[i][j]->setNumeraciones(i, j);
			matriz[i][j]->setEstado('d');
		}
	}
	dia = " ";
	hora=" ";
	lugar=" ";
}

void Coleccion::SetEstadoAsi(int i, int j, char e)
{
	matriz[i][j]->setEstado(e);
}

void Coleccion::SetHora(string hor)
{
	hora = hor;
}

void Coleccion::SetDia(string d)
{
	dia = d;
}

void Coleccion::SetLugar(string l)
{
	lugar = l;
}

char Coleccion::getEstadoAsi(int i, int j)
{
	return matriz[i][j]->getEstado();
}

string Coleccion::getHora()
{
	return hora;
}

string Coleccion::getDia()
{
	return dia;
}

string Coleccion::getLugar()
{
	return lugar;
}

string Coleccion::toStringMatriz()//metodo toString que permite visualizar los 
{								  //asientos en su respectiva posicion y con su debido estado
	stringstream s;
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			s << matriz[i][j]->toStringAsiento() << " ";
		}
		s << endl;
	}
	return s.str();
}

Coleccion::~Coleccion()
{
	for (int i = 0; i<fil; i++)
	{
		for (int j = 0; j<col; j++)
		{
			delete matriz[i][j];//libera la memoria de cada asiento
		}
	}
	//liberar memoria
	for (int i = 0; i<fil; i++)
	{
		delete[] matriz[i]; //libera la memoria de cada fila, cada fila es un vector
	}

	delete[] matriz; //libera la memoria del primer vector
}
