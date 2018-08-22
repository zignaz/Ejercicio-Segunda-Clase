// ConsoleApplication2.cpp : main project file.

#include "stdafx.h"


#include <iostream>
#include "conio.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"



using namespace std;
using namespace System;

int MENU()
{
	int opcion;
	do
	{
		system("cls");
		cout << "[1]Generar los datos del arreglo en forma aleatoria" << endl;
		cout << "[2]Listar en pantalla los elementos del arreglo" << endl;
		cout << "[3]Buscar el mayor y mostrar su ubicacion" << endl;
		cout << "[4]Buscar el menos y mostrar su ubicacion" << endl;
		cout << "[5]Ordenar el arreglo en forma descendente y mostrarlo en pantalla" << endl;
		cout << "INGRESE UNA OPCION:" << endl;
		cin >> opcion;
	} while (opcion<1 || opcion>5);
	return opcion;
}


int *generar_datos(int *N) {




	int *arr = new int[*N];

	for (int i = 0; i < *N; i++)
	{
		arr[i] = rand() % 100;
	}

	return arr;
}

void imprimir_datos(int *N, int *arr) {

	if (*N != 0)
	{
		for (int i = 0; i < *N; i++)
		{
			cout << " " << i + 1 << " es : " << arr[i] << endl;
		}
	}

	_getch();
}

int Mayor(int *N, int *arr) {

	int aux = arr[0];
	int mayor;
	for (int i = 1; i < *N; i++)
	{
		if (aux < arr[i])
		{
			aux = arr[i];
		}
	}

	mayor = aux;
	return mayor;
}

int Menor(int *N, int *arr) {

	int aux = arr[0];
	int menor;
	for (int i = 1; i < *N; i++)
	{
		if (aux > arr[i])
		{
			aux = arr[i];
		}
	}

	menor = aux;
	return menor;


}




void Ordenar(int *N, int *arr) {

	int *arr2 = new int[*N];

	for (int i = 0; i < *N; i++)
	{
		arr2[i] = arr[i];
	}


	int aux;
	for (int k = 0; k < *N; k++)
	{


		for (int j = 0; j < *N; j++)
		{

			if (arr[j] < arr[k])
			{
				aux = arr[j];
				arr[j] = arr[k];
				arr[k] = aux;
			}

		}

	}



}

void Eliminar_Ultimo(int *N, int *arr) {
	
	int* aux= new int[*N-1];

	for (int i = 0; i < *N-1; i++)
	{
		aux[i] = arr[i];
		
	}

	*arr = NULL;
	for (int j = 0; j < *N-1; j++)
	{
		arr[j] = aux[j];
		
	}
	*N = *N - 1;

}



int main() {

	int *arr = NULL;

	int *N = new int;
	*N = 0;



	int menu;

	while (1) {

		menu = MENU();
		if (menu == 1)
		{
			*N = rand() % 50;
			arr = generar_datos(N);
		}
		if (menu == 2)
		{
			imprimir_datos(N, arr);
		}
		if (menu == 3)
		{

			int M = Mayor(N, arr);
			cout << "El numero mayor es: " << M << endl;


			_getch();
		}
		if (menu == 4)
		{
			int Men = Menor(N, arr);
			cout << "El numero menor es: " << Men << endl;
			_getch();
		}
		if (menu == 5)
		{
			Ordenar(N, arr);
			imprimir_datos(N, arr);

		}
		if (menu == 6)
		{
			Eliminar_Ultimo(N, arr);
			imprimir_datos(N, arr);

		
		}
	}
	_getch();
	_getch();
	_getch();
	_getch();


	return 0;
}