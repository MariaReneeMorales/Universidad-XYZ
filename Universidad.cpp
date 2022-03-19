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
char gaTickets[10][6][50];

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
	cin.getline(gaTickets[lnNumTicket][0],50);
	
	cout << " Apellido:  ";
	cin.ignore();
	cin.getline(gaTickets[lnNumTicket][1],50);
	
	cout << " ID:  ";
	cin.ignore();
	cin.getline(gaTickets[lnNumTicket][2],50);
	
	cout << " Email:  ";
	cin.ignore();
	cin.getline(gaTickets[lnNumTicket][3],50);
	
	cout << " Carrera:  ";
	cin.ignore();
	cin.getline(gaTickets[lnNumTicket][4],50);

	cout << " Ingrese su ticket:  ";
	cin.ignore();
	cin.getline(gaTickets[lnNumTicket][5],50);

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
	cout << " _______________________________________________________" << endl;
	
	for (lnCount = 0; lnCount < lnNumTicket; lnCount++){
		cout << " No. Ticket: " << lnCount + 1 << endl;
		cout << " Nombre:     " << gaTickets[lnCount][0] << endl;
		cout << " Apellido:   " << gaTickets[lnCount][1] << endl;
		cout << " ID:         " << gaTickets[lnCount][2] << endl;
		cout << " Email:      " << gaTickets[lnCount][3] << endl;
		cout << " Carrera:    " << gaTickets[lnCount][4] << endl;
		cout << " Ticket:     " << gaTickets[lnCount][5] << endl;
		cout << " _______________________________________________________" << endl;
	}
	cout << endl << endl;
	cout << "          Presione cualquier tecla para continuar...";
	_getch();
	
	return 0;
}

int main(){
	//Permite imprimir tildes, ñ o caracteres especiales. 
	setlocale(LC_ALL, "");
	
	//Título.
	cout << endl << endl;
	cout << "          U N I V E R S I D A D  X Y Z";
	cout << endl << endl;
	
	return 0;
}
