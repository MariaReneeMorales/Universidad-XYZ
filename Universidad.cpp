#include <stdio.h> 
#include <iostream> 
#include <math.h> 
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

using namespace std;

//Definición de variables globales.
string gaTickets[10][6];

//Función de número y letras.
string random(char lcTipo, int lnMax){
	//Definición de variables. 
	string lcRand;
	int lnCount;
	
	for(lnCount = 1; lnCount <= 6; lnCount++){
		lcRand += lcTipo + rand() % (lnMax - 1);
    }
	
	return lcRand;
}

//Función abrir ticket.
int AbrirTicket(int lnNumTicket){
	//Permite imprimir tildes, ñ o caracteres especiales. 
	setlocale(LC_ALL, "");
	system("cls");
	
	//Captura y lectura de datos.
	cout << endl << endl;
	cout << " Bienvenido al sistema de tickets, por favor, ingrese los datos solicitados " << endl << endl;
	cout << " Su número de ticket es: " << lnNumTicket + 1 << endl;
	
	cout << " Nombre:  ";
	cin.ignore();
	cin.clear();
	getline(cin, gaTickets[lnNumTicket][0]);
	
	cout << " Apellido:  ";
	getline(cin, gaTickets[lnNumTicket][1]);
	
	cout << " ID:  ";
	getline(cin, gaTickets[lnNumTicket][2]);
	
	cout << " Email:  ";
	getline(cin, gaTickets[lnNumTicket][3]);
	
	cout << " Carrera:  ";
	getline(cin, gaTickets[lnNumTicket][4]);

	cout << " Ingrese su ticket:  ";
	getline(cin, gaTickets[lnNumTicket][5]);

	cout << endl << endl << endl;
	cout << " ¡Ticket ingresado correctamente! " << endl;
	
	//Pausa.
	Sleep(1000); 
	
	return 0;
}

//Función ver tickets.
int VerTickets(int lnNumTicket){
	//Permite imprimir tildes, ñ o caracteres especiales. 
	setlocale(LC_ALL, "");
	system("cls");
	
	//Definición de variables.
	int lnCount; 
	
	//Impresión de datos.
	cout << endl << endl;
	cout << " ¡Bienvenido al reporte de tickets! " << endl << endl;
	cout << " Tickets creados: " << lnNumTicket << endl << endl;
	cout << " No.| Nombre             | Apellido           | ID                 | Email                        | Carrera                      | Ticket                                                          |" << endl;
	cout << " ___________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << endl;
	for (lnCount = 0; lnCount < lnNumTicket; lnCount++){
		cout << " " << lnCount + 1 << "  |";
		printf("%-20s|", gaTickets[lnCount][0].c_str());
		printf("%-20s|", gaTickets[lnCount][1].c_str());
		printf("%-20s|", gaTickets[lnCount][2].c_str());
		printf("%-30s|", gaTickets[lnCount][3].c_str());
		printf("%-30s|", gaTickets[lnCount][4].c_str());
		printf("%-65s|", gaTickets[lnCount][5].c_str());
		cout << endl;
	}
	cout << " ___________________________________________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << endl << endl;
	cout << "          Presione cualquier tecla para continuar...";
	_getch();
	
	return 0;
}

//Función normal.
int main(){
	//Permite imprimir tildes, ñ o caracteres especiales. 
	setlocale(LC_ALL, "");
	
	//Definición de variables.
	string lcOpcion, lcUser, lcPass, lcClave;
	int lnCount, lnOpcion, lnTickets;
	time_t ldFecha = time(NULL);
	
	//Ciclo.	
	do{
		//Título.
		cout << endl << endl;
		cout << "          U N I V E R S I D A D  X Y Z";
		cout << endl << endl << endl << endl;
		
		//Captura y lectura de datos.
		cout << "— Instrucciones: marqué 1 = si y 0 = no " << endl << endl; 
		cout << " ¿Mantiene una matrícula activa? ";
		cin >> lcOpcion;
		cout << endl << endl;
		
		//Condición. 
		if (lcOpcion == "1"  || lcOpcion == "si" || lcOpcion == "Si"){
			lcUser = random('A', 26);
			lcPass = random('1', 9);
			
			//Mostrando datos del usuario.
			cout << " Sus credenciales son: " << endl << endl;
			cout << "      Usuario: " << lcUser << endl;
			cout << "      Clave: " << lcPass << endl << endl;
			
			//Capturando clave otorgada.
			cout << " Ingrese su clave:  ";
			cin >> lcClave; 
			
			//Ingreso al sistema de tickets.
			if (lcClave == lcPass){
				//Limpiando pantalla + Título + DateTime.
				system("cls");
				cout << endl;
				cout << "          ¡B I E N V E N I D O " << lcUser << "!" << endl << endl << endl;
			    	printf(" Fecha y hora de ingreso: %s", ctime(&ldFecha)); 
				cout << endl << endl;
				
				//Solicitando cambio de contraseña + Opciones.
				cout << " Por seguridad, cambie su clave: "; 
				cin >> lcPass;
				cout << endl << endl;
				cout << "          ¡Su clave fue cambiada éxitosamente! " << endl << endl << endl;
				cout << " ¿Qué desea hacer?" << endl << endl;
				
				//Inicializando variable.
				lnTickets = 0;
	 		
				//Ciclo
				do{
					//Menú de opciones.
					cout << endl;
					cout << "     1. Subir un ticket" << endl;
					cout << "     2. Ver tickets" << endl;
					cout << "     3. Salir" << endl << endl;
					
					//Captura y lectura de datos.
					cout << " Ingrese una opción: ";
					cin >> lnOpcion;
					
					//Menú desplegable según condición.
					switch (lnOpcion){
						case 1: 
							AbrirTicket(lnTickets);
							lnTickets = lnTickets + 1;
						break;
						case 2: 
							VerTickets(lnTickets);
						break;
						case 3: 
							//Saliendo del ciclo.
						break; 
						default: 
							cout << " La opción ingresada no es válida... Por favor, intente de nuevo.";
							Sleep(1000); 
						break;
					}
					//Limpiando pantalla.
					system("cls");
					
				} while (lnOpcion != 3);
				
				//Fecha de salida.
				cout << endl << endl;
				printf("— Fecha y hora de salida: %s", ctime(&ldFecha)); 
				cout << endl << endl;
			}
		}	
		else {
			cout << " ¡Advertencia! Usted no mantiene una matrícula activa." << endl << endl;
		}
		//Pausa + Limpiando pantalla + enter para continuar. 
		cout << endl;
		cout << "          Presione cualquier tecla para continuar...";
		_getch();
		system("cls");
	} while (lcOpcion == "1" || lcOpcion == "si" || lcOpcion == "Si");
	
	return 0;
}
