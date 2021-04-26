/*Asiento.cpp
Creado por:
Manfred Joel Agüero Campos
Terminado el dia:
19 de diciembre del 2018
Proyecto 1
*/

#include "Asiento.h"

Asiento::Asiento()
{
	numeracionF = 0;
	numeracionC = 0;
	estado = 'd';
}

void Asiento::setNumeraciones(int iF, int jC)
{
	numeracionF = iF;
	numeracionC = jC;
}

void Asiento::setEstado(char e)
{
	
	if(e=='d'||e=='O'){//hace la validación de que el estado sea correcto
		estado = e;
	}
	else {
		cout << "Digite un valor valido" << endl;
	}

}

int Asiento::getNumF()
{
	return numeracionF;
}

int Asiento::getNumC()
{
	return numeracionC;
}

char Asiento::getEstado()
{
	return estado;
}

string Asiento::toStringAsiento()//toString que permite visualizar el estado de los asientos
{
	stringstream s;
	s << estado;
	return s.str();
}


Asiento::~Asiento()
{
}
