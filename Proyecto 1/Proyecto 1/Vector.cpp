/*Vector.cpp
Creado por:
Manfred Joel Agüero Campos
Terminado el dia:
19 de diciembre del 2018
Proyecto 1
*/

#include "Vector.h"

Vector::Vector()
{//constructor de la clase vector, pide los datos del tamaño de cada matriz para crearla
	vector = new Coleccion*[3];
	for (int i = 0; i < 3; i++) {
		int fila = 0;
		int colum = 0;
		cout << "Digite la cantidad de filas deseadas para el gimnasio " << i+1 << " : "; cin >> fila;
		cout << "Digite la cantidad de columnas deseadas para el gimnasio " << i+1 << " : "; cin >> colum;
		cout << endl;
		vector[i] = new Coleccion(fila, colum);
	}
}

void Vector::setDia(int i, string n)
{
	vector[i]->SetDia(n);
}

void Vector::setHora(int i, string h)
{
	vector[i]->SetHora(h);
}

void Vector::setLugar(int i, string l)
{
	vector[i]->SetLugar(l);
}

void Vector::elimina(int i)
{
	delete vector[i];
}

string Vector::getDia(int i)
{
	return vector[i]->getDia();
}

string Vector::getHora(int i)
{
	return vector[i]->getHora();
}

string Vector::getLugar(int i)
{
	return vector[i]->getLugar();
}

string Vector::toString(int i) {//permite realizar el toString de la matriz, que se encuentra dentro de una posicion en específico del vector
	stringstream s;				//mediante la clase vector
	s<<vector[i]->toStringMatriz()<<endl;
	return s.str();
}

void Vector::setEstadoAsi(int i, int f, int c, char e)
{
	vector[i]->SetEstadoAsi(f, c, e);
}

Vector::~Vector()
{
	for (int i = 0; i < 3; i++) {//destructor del vector y los objetos dentro de él
		delete vector[i];
	}
	delete[] vector;
}
