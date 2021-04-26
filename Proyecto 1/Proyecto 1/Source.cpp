/*Source.cpp
Creado por:
Manfred Joel Agüero Campos
Terminado el dia:
19 de diciembre del 2018
Proyecto 1*/
#include<iostream>
#include<string>
#include <sstream>// libreria necesaria
#include <ctime>
using namespace std;
#include <ctime>
#include"Vector.h"
#include"Coleccion.h"
#include"Tiquete.h"


int main() {
	int opc = 0;
	int opcAdmin = 0;
	int opcAd = 0;
	string contr;
	Tiquete tiquete;
	string horS = " ";
	int f=0;
	int c = 0;
	Vector *dia=new Vector();
	string fecha = " ";
	string hora = " ";
	string lugar = " ";
	int cont = 0;
	do {//menú principal
		cout << "1) Administrador" << endl;
		cout << "2) compra de tiquetes" << endl;
		cout << "3) Salir" << endl;
		cin >> opc;
		switch (opc) {
		case 1:
			system("cls");
			cout << "Digite la contrasena: "; cin >> contr;
			if (contr == "ADMIN" || contr == "Admin" || contr == "admin") {
				do {//menú administrador
					system("cls");
					cout << "1) Fecha 1" << endl;
					cout << "2) Fecha 2" << endl;
					cout << "3) Fecha 3" << endl;
					cout << "4) Salir" << endl;
					cin >> opcAdmin;
					do {//menú opciones por fecha
						system("cls");
						cout << "1) Agregar fecha." << endl;
						cout << "2) Agregar hora." << endl;
						cout << "3) Agregar lugar." << endl;
						cout << "4) Eliminar." << endl;
						cout << "5) Salir." << endl;
						cin >> opcAd;
						switch (opcAd) {
						case 1:
							system("cls");
							fecha = " ";
							cout << "Digite la fecha del evento: "; cin >> fecha;
							dia->setDia(opcAdmin-1, fecha);
							break;
						case 2:
							system("cls");
							hora = " ";
							cout << "Digite la hora del evento: "; cin >> hora;
							dia->setHora(opcAdmin-1, hora);
							
							break;
						case 3:
							system("cls");
							lugar = " ";
							cout << "Digite el lugar del evento: "; cin >> lugar;
							dia->setLugar(opcAdmin-1, lugar);
							
							break;
						case 4:
							system("cls");
							dia->elimina(opcAdmin-1);
							
							cout << "-----eliminando----" << endl;
							break;
						case 5:
							system("cls");
							break;
						default:
							system("cls");
							cout << "Digite un valor valido" << endl;
							break;
						}

					} while (opcAd != 5);

				} while (opcAdmin != 4);


				break;
			}
			else {
				system("cls");
				cout << "Contraseña incorrecta." << endl;
					break;
			}
		case 2://sistema de compra de tiquetes
			system("cls");
			f = 0;
			c = 0;
			opcAdmin = 0;
			horS = " ";
			if (cont < 5) {
				cout << "--------Compra de tiquetes----------" << endl;
				cout << "Digite la opcion de la fecha para la que desea su entrada: " << endl;
				cout << "1)" << dia->getDia(0) << endl;
				cout << "2)" << dia->getDia(1) << endl;
				cout << "3)" << dia->getDia(2) << endl;
				cin >> opcAdmin;
				system("pause");
				if (opcAdmin == 1 || opcAdmin == 2 || opcAdmin == 3) {
					system("cls");
					cout << dia->toString(opcAdmin - 1) << endl;
					cout << "Digite la fila del asiento deseado: "; cin >> f;
					cout << "Digite la columna del asiento deseado: "; cin >> c;
					f = f - 1;
					c = c - 1;
					dia->setEstadoAsi(opcAdmin - 1, f, c, 'O');
					cout << dia->toString(opcAdmin - 1) << endl;
					tiquete.setFecha(dia->getDia(opcAdmin - 1));
					tiquete.setHora(dia->getHora(opcAdmin - 1));
					tiquete.setLugar(dia->getLugar(opcAdmin - 1));
					std::stringstream b;		//Este método permite utilizar la fecha del sistema para generar
					time_t tSac = time(NULL);	//el tiquete, esto lo hace pasando los datos a una variable tipo string
#pragma warning(disable : 4996)
					struct tm* tmP = localtime(&tSac);
					b << tmP->tm_mday << "-" << tmP->tm_mon + 1 << "-" << tmP->tm_year + 1900;
					horS = b.str();
					tiquete.setFechaSistema(horS);
					tiquete.generaTicket(cont, f+1, c+1);
					cout << "Tiquete generado. Gracias por su compra." << endl;
					cont = cont + 1;
					system("pause");
					break;
				}

				else {
					cout << "Digite una opcion valida" << endl;
					break;
				}
			}
			else if (cont >= 5) {
				cout << "No se permite realizar mas de 5 compras" << endl;
				system("pause");
			}



			
		case 3:
			system("cls");
			break;
		default:
			system("cls");
			cout << "Digite un valor valido" << endl;
			break;
		}

	} while (opc!=3);
	
	system("pause");
	tiquete.~Tiquete();
	dia->~Vector();
	return 0;
}