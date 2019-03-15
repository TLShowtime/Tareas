#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
template <class T>
class List {
private:
	struct Nodo {
		T elemento;
		struct Nodo * siguiente;
		Nodo(T x) :elemento{ x }, siguiente{ 0 } {}
		Nodo(T x, struct Nodo* sig) :elemento{ x }, siguiente{ sig } {}
	};

	typedef struct Nodo * link;

	link primero;        // Puntero al primer elemento de la lista
	int tam;            // Cantidad de elementos de la lista
	string nombreLista;    // Nombre de la lista

	// Metodo de clase
	static void insertR(link &p, T x, int pos);

public:

	List(string nombre);
	int len();
	void push_front(T x);
	void push_back(T x);
	void insertar(T x, int pos);
	void insertarR(T x, int pos);
	bool remove(int pos, T& x);
	bool pop(T& x);
	bool pop_back(T& x);
	bool get(int pos, T& element);
	bool get_front(T& element);
	bool get_back(T& element);
	void print();
	string to_String();
	~List();

};

template<class T>
void List<T>::insertR(link & p, T x, int pos) {
	if (p == NULL)
		p = new Nodo(x);
	else {
		if (pos == 0)
			p = new Nodo(x, p);
		else
			insertR(p->siguiente, x, pos - 1);
	}
}

template<class T>
List<T>::List(string nombre) {
	nombreLista = nombre;
	primero = NULL;
	tam = 0;
}

template <class T>
void List<T>::push_front(T x) {
	primero = new Nodo(x, primero);
	tam++;
}

template<class T>
void List<T>::push_back(T x) {
	if (!primero)
		primero = new Nodo(x, primero);
	else {
		link p;
		for (p = primero; p->siguiente; p = p->siguiente) {}
		p->siguiente = new Nodo(x);
	}
	tam++;
}

template<class T>
void List<T>::insertar(T x, int pos) {
	if (!primero) {
		primero = new Nodo(x);
	}
	else {
		if (pos == 0)
			primero = new Nodo(x, primero);
		else {
			link p = primero;
			while (p->siguiente && pos > 1) {
				p = p->siguiente;
				pos--;
			}
			p->siguiente = new Nodo(x, p->siguiente);
		}
	}
	tam++;
}

template<class T>
void List<T>::insertarR(T x, int pos) {
	insertR(primero, x, pos);
	tam++;
}

template<class T>
bool List<T>::remove(int pos, T & x)
{
	if (primero) {
		if (pos < 0) {
			cout << "La posicion " << pos << " no esta en el rango. \n";
			return false;
		}
		else {
			link p = primero;
			if (pos == 0) {
				p = p->siguiente;
				x = primero->elemento;
				primero->siguiente == nullptr;
				delete primero;        //libera del heap
				primero = p;
			}
			else {
				if (pos >= tam) {
					pos = tam - 1;
				}
				int cont = pos;
				while (cont > 1) {
					p = p->siguiente;
					cont--;
				}
				x = p->siguiente->elemento;

				if (pos == tam - 1) { // si el elemento a eliminar es el ultimo
					link q = p->siguiente;
					p->siguiente = nullptr;
					delete q;    //libera del heap

				}
				else {
					link q = p->siguiente->siguiente; //el elemento despues de la posicion a eliminar
					p->siguiente->siguiente = nullptr;
					delete p->siguiente; //libera del heap 
					p->siguiente = q;
				}
			}
			tam--;
			return true;

		}
	}
	else {
		return false;
	}

}

template<class T>
bool List<T>::pop(T & x) // elimina el elemento al inicio de la lista
{
	if (tam == 0) { //si no tiene elementos
		return false;
	}
	else {
		link p = primero;
		p = p->siguiente;
		x = primero->elemento;
		primero->siguiente == nullptr;
		delete primero; //libera del heap lo que apunta primero
		primero = p;
		tam--;
		return true;
	}
}

template<class T>
bool List<T>::pop_back(T & x) //remover el ultimo elemento de la lista
{
	if (len() == 0) {
		return false;
	}
	else {
		link p = primero;
		while (p->siguiente->siguiente!=nullptr) {
			p = p->siguiente;
		}
		x = p->siguiente->elemento;
		link q = p->siguiente;
		p->siguiente = nullptr;
		delete q;    //libera del heap
		tam--;
		return true;
	}
}

template<class T>
bool List<T>::get(int pos, T & element) //obtener valor del nodo en una posicion
{
	if (pos >= tam || pos < 0) {
		cout << "La posicion " << pos << " no esta en el rango. \n";
		return false;
	}
	else {
		link p = primero;
		if (pos == 0) {			//pos 0
			element = primero->elemento;
		}
		else {
			while (pos > 0) {
				p = p->siguiente;
				pos--;
			}
			element = p->elemento;
		}
		return true;
	}

}

template<class T>
bool List<T>::get_front(T & element)    //obtener valor del nodo inicial
{
	if (tam == 0) {
		return false;
	}
	else {
		element = primero->elemento;
	}
}

template<class T>
bool List<T>::get_back(T & element)		//obtener valor del nodo final
{
	if (len() == 0) {
		return false;
	}
	else {
		link p = primero;
		while (p->siguiente != nullptr) {
			p = p->siguiente;
		}
		element = p->elemento;
		return true;
	}
}

template<class T>
void List<T>::print() {
	cout << nombreLista << " = [";
	if (primero) {
		link p = primero;
		cout << p->elemento;
		p = p->siguiente;
		while (p) {
			cout << ", " << p->elemento;
			p = p->siguiente;
		}
	}
	cout << "]" << "\n";
}

template<class T>
string List<T>::to_String()
{
	link p = primero;
	string s = nombreLista + " = [";
	if (p) {
		s += std::to_string(p->elemento);
		p = p->siguiente;
	}
	while (p) {
		s += ", " + std::to_string(p->elemento);
		p = p->siguiente;
	}
	s += "]";
	return s;
}

template<class T>
int List<T>::len() {
	return tam;
}

template<class T>
List<T>::~List() {
	link p;
	while (primero) {
		// Borrra todos los elementos en la
		// lista.
		p = primero->siguiente;
		delete primero;
		primero = p;
	}
}
