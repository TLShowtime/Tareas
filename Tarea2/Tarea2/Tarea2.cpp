// Tarea2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "ListaSimple.h"
#include "ListaSimpleB.h"

int main() {

	ListaSimpleB<int> lm("Lista2");

	lm.push_back(1);
	lm.push_back(2);
	lm.push_back(3);
	lm.push_back(4);
	lm.push_back(5);
	lm.push_back(6);
	lm.push_back(7);
	lm.push_back(8);
	lm.push_back(9);
	lm.push_back(10);
	//lm.push_front(30);
	//lm.push_front(20);
	//lm.push_front(10);
	lm.push_back(11);
	lm.push_back(12);
//	lm.insertarR(5, 0);
//	lm.insertarR(8, 1);
	//lm.insertarR(15, 5);
//	lm.insertarR(50, 99);
	//lm.insertarR(999, 1);
	lm.print();
	//int x = 0;
	//lm.remove(10, x);
	//lm.print();
	//std::cout << "Elemento guardado: " << x << ".\n";
	
	//lm.pop(x);
	//lm.print();
	//std::cout << "Elemento guardado: " << x << ".\n";

	//std::cout << "Tamano: " << lm.len() << "\n";
	//List<string> la("Personas");
	//la.push_back("ana");
	//la.push_back("juan");
	//la.print();
//	std::cout << "\n";


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
