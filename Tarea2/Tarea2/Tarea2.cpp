// Tarea2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include "ListaSimple.h"
#include "ListaSimpleB.h"
#include <string>

string enunciado[]{ "Lista Simple \nDemostraciones:\n","Lista Simple B \nDemostraciones:\n"};

string metodos[]{"int len()","void push_front(T x)","void push_back(T x)","void insertar(T x, int pos)",
	"void insertarR(T x, int pos)" , "bool remove(int pos, T& x)", "bool pop(T& x)","bool pop_back(T& x)",
	"bool get(int pos, T& element)", "bool get_front(T& element)", "bool get_back(T& element)"
};

string casos[]{
	"Caso General\n","Caso 1. Lista Vacia\n"
};

void printEnunciado(int num) {
	cout << enunciado[num];
}

void print(int metodo,int caso) {
	cout << "-------------------------------Metodo--------------------------\n " << metodos[metodo] << "\n";
	cout << casos[caso];
};

void imprimirExito(bool exito,string pMetodo) {
	if (exito) {
		cout << "Metodo " << pMetodo <<" exitoso. \n\n";
	}
	else {
		cout << "No se pudo hacer "<<  pMetodo <<" a la lista. \n\n";
	}

}
void printPrueba(string ejemplo, string result) {
	cout << "Lo que se espera: " << ejemplo << "\n" << "Respuesta: ";
	cout << result << "\n";
	cout << "\n----------------------------------------------\n";
}
void printElemento(int elemento, int pos) {
	cout << "El elemento en la posicion " << pos << " es: " << elemento << "\n\n";
}

void printElemento(int elemento) {
	cout << "El elemento es: " << elemento << "\n\n";
}

int main() {
	typedef struct Nodo* link;
	int elemento_removido;
	//ListaSimple
	printEnunciado(0);
	List<int> lm("Lista1");


	print(5, 1);
	lm.print();
	imprimirExito(lm.remove(3, elemento_removido), metodos[5]);


	print(6, 1);
	lm.print();
	imprimirExito(lm.pop(elemento_removido), metodos[6]);

	print(7, 1);
	lm.print();
	imprimirExito(lm.pop_back(elemento_removido), metodos[7]);

	print(8, 1);
	lm.print();
	imprimirExito(lm.get(0, elemento_removido), metodos[8]);

	print(9, 1);
	lm.print();
	imprimirExito(lm.get_front(elemento_removido), metodos[9]);

	print(10, 1);
	lm.print();
	imprimirExito(lm.get_back(elemento_removido), metodos[10]);

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
	cout << "Original: ";
	lm.print();
	cout << "----------------------------------------------\n";

	//Remove 
	print(5, 0);
	imprimirExito(lm.remove(3, elemento_removido), metodos[5]); //remover en medio de la lista
	imprimirExito(lm.remove(12, elemento_removido), metodos[5]);//remover al final de la lista
	imprimirExito(lm.remove(0, elemento_removido), metodos[5]);//remover al inicio de la lista

	printPrueba("[2, 3, 5, 6, 7, 8, 9]", lm.to_String());

	//bool pop(T& x)
	print(6, 0);
	imprimirExito(lm.pop(elemento_removido), metodos[6]);
	imprimirExito(lm.pop(elemento_removido), metodos[6]);
	imprimirExito(lm.pop(elemento_removido), metodos[6]);

	printPrueba("[6, 7, 8, 9]", lm.to_String());

	//-------------------------------------------

	lm.push_front(30);
	lm.push_front(20);
	lm.push_front(10);
	lm.push_back(11);
	lm.push_back(12);

	lm.insertarR(5, 0);
	lm.insertarR(8, 1);
	lm.insertarR(15, 5);
	lm.insertarR(50, 99);
	lm.insertarR(999, 1);

	cout << "Lista Prueba \n";
	lm.print();
	cout << "\n---------------------------------------\n";

	//bool pop_back(T& x)
	print(7, 0);
	imprimirExito(lm.pop_back(elemento_removido), metodos[7]);
	imprimirExito(lm.pop_back(elemento_removido), metodos[7]);
	imprimirExito(lm.pop_back(elemento_removido), metodos[7]);

	printPrueba("[5, 999, 8, 10, 20, 30, 15, 6, 7, 8, 9]", lm.to_String());

	//bool get(int pos, T& element)"
	print(8, 0);
	lm.print();
	imprimirExito(lm.get(7, elemento_removido), metodos[8]);
	printElemento(elemento_removido, 7);
	imprimirExito(lm.get(5, elemento_removido), metodos[8]);
	printElemento(elemento_removido, 5);
	imprimirExito(lm.get(0, elemento_removido), metodos[8]);
	printElemento(elemento_removido, 0);

	//"bool get_front(T& element)"
	print(9, 0);
	lm.print();
	imprimirExito(lm.get_front(elemento_removido), metodos[9]);
	printElemento(elemento_removido);

	lm.pop(elemento_removido);
	lm.pop(elemento_removido);
	lm.pop(elemento_removido);

	cout << "Nueva Lista: ";
	lm.print();
	imprimirExito(lm.get_front(elemento_removido), metodos[9]);
	printElemento(elemento_removido);

	lm.pop(elemento_removido);

	cout << "Nueva Lista: ";
	lm.print();
	imprimirExito(lm.get_front(elemento_removido), metodos[9]);
	printElemento(elemento_removido);

	//"bool get_back(T& element)"
	print(10, 0);
	lm.print();
	imprimirExito(lm.get_back(elemento_removido), metodos[10]);
	printElemento(elemento_removido);

	lm.pop_back(elemento_removido);
	lm.pop_back(elemento_removido);
	lm.pop_back(elemento_removido);

	cout << "Nueva Lista: ";
	lm.print();
	imprimirExito(lm.get_back(elemento_removido), metodos[10]);
	printElemento(elemento_removido);

	lm.pop_back(elemento_removido);

	cout << "Nueva Lista: ";
	lm.print();
	imprimirExito(lm.get_back(elemento_removido), metodos[10]);
	printElemento(elemento_removido);

	//----------------------------ListaSimpleB-----------------------------------------------
	cout << "----------------------------ListaSimpleB-----------------------------------\n";
	ListaSimpleB<int> ld("Lista Doble 1");
	int tamano;
	/**ld.push_back(12);
	ld.push_back(11);
	ld.push_back(12);
	ld.push_back(11);
	ld.push_back(12);
	ld.push_back(11);
	*/ld.push_back(12);
	ld.push_back(11);
	ld.push_back(12);
	ld.push_back(11);

	ld.push_back(12);
	ld.push_back(12);

	tamano = ld.len();

	
	tamano=ld.len();

	ld.print();
	cout << "\nEl tamano es: " << tamano;

	ld.push_front(55);
	ld.push_front(56);
	ld.push_front(55);
	ld.push_front(56);
	ld.push_front(55);
	ld.push_front(56);
	ld.push_front(55);
	
	tamano = ld.len();

	cout << "\nEl tamano es: " << tamano << "\n";
	ld.print();

	ld.insertar(12, 2);
	ld.print();
	ld.insertar(123124, 6);
	ld.print();
	ld.insertar(123124, 12);
	ld.print();
	ld.insertar(23, 5);
	ld.print();
	ld.insertar(10000, 31);
	ld.print();
	ld.insertar(101331, 31);
	ld.insertar(1001, 31);
	ld.insertar(1004, 31);
	ld.insertar(1004213, 31);
	ld.insertar(1, 31);
	ld.insertar(10000, 31);
	ld.insertar(101331, 31);
	ld.insertar(1001, 31);
	ld.insertar(1004, 31);
	ld.print();

	int x;
	ld.remove(21, x);
	ld.print();
	ld.remove(12, x);
	ld.print();
	ld.remove(ld.len()-1, x);
	ld.print();
	ld.pop(x);
	ld.print();
	ld.pop_back(x);
	ld.print();


	cout << "\nEl tamano es: " << tamano << "  ";
	
	ld.print();

	//------------get--------
	elemento_removido = 0;
	ld.get(9, elemento_removido);
	cout <<"\nEn la posicion: "<< 9 <<"se tomo el elemento: "<<elemento_removido;
	ld.get_front(elemento_removido);
	cout << "\nSe tomo al inicio un : "<< elemento_removido;
	ld.get_back(elemento_removido);
	cout << "\nSe tomo al final un : " << elemento_removido;

	ld.print();
	

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
