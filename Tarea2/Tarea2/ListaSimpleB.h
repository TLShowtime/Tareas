#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;

template <class T,int N=10>
class ListaSimpleB
{
	struct Node {
		bool lleno;
		T elemento[N];
		struct Node* siguiente;

		Node() :lleno{ false }, siguiente{ 0 }{}
		Node(struct Node* sig) :lleno{ false }, siguiente{ sig }{}
	};

	typedef struct Node* link;

	link primero;
	int tam;
	string nombreLista;

public:
	ListaSimpleB(string nombre);
	int len();
	void push_front(T x);
	void push_back(T x);
	void insertar(T x, int pos);
	bool remove(int pos, T& x);
	bool pop(T& x);
	bool pop_back(T& x);
	bool get(int pos, T& element);
	bool get_front(T& element);
	bool get_back(T& element);
	void print();
	~ListaSimpleB();
};



template<class T, int N>
ListaSimpleB<T, N>::ListaSimpleB(string nombre)
{
	primero = nullptr;
	tam = 0;
	nombreLista = nombre;
}

template<class T, int N>
int ListaSimpleB<T, N>::len()
{
	return tam;
}

template<class T, int N>
void ListaSimpleB<T, N>::push_front(T x) {
	if (primero == nullptr) {
		primero = new Node();
		primero->elemento[0] = x;
		tam++;
	}
	else {
		link p = primero;
		int i = N - 1;
		T elementoBrinco = p->elemento[i];
		T elementoPrimer = x;
		while (p->siguiente && p->lleno) {
			p->elemento[i] = p->elemento[i - 1];
			i--;
			if (i == 0) {
				p->elemento[i] = elementoPrimer;
				p = p->siguiente;
				elementoPrimer = elementoBrinco;
				i = N - 1;
				elementoBrinco = p->elemento[i];
			}
		}
		if (p->lleno) {
			i = N - 1;
			T elementoBrinco = p->elemento[i];
			while (i > 0) {
				p->elemento[i] = p->elemento[i - 1];
				i--;
				if (i == 0) {
					p->elemento[i] = elementoPrimer;
					p->siguiente = new Node();
					p = p->siguiente;
					p->elemento[i] = elementoBrinco;
					tam++;
				}
			}
		}
		else {
			i = tam % N;
			while (i > 0) {
				p->elemento[i] = p->elemento[i - 1];
				i--;
				if (i == 0) {
					p->elemento[i] = elementoPrimer;
				}
			}
			tam++;
			p->lleno = tam % N == 0;
		}
	}
}

template<class T, int N>
void ListaSimpleB<T, N>::push_back(T x)
{
	if (primero == 0) {
		primero = new Node();
		primero->elemento[0]=x;
		tam++;
	}
	else {
		link p=primero;
		while (p->siguiente) {
			p = p->siguiente;
		}
		if (p->lleno) {
			p->siguiente = new Node();
			p->siguiente->elemento[0]=x;
			tam++;
		}
		else {
			p->elemento[tam++ % N] = x;
			p->lleno = (tam%N == 0);
		}
	}
}

template<class T, int N>
void ListaSimpleB<T, N>::insertar(T x, int pos){
	if (primero==nullptr) {
		push_back(x);
	}
	else {
		if (pos >= tam) {
			push_back(x);
		}
		else {
			link p = primero;
			int i = 0;
			while (i < pos / N) {
				p = p->siguiente;
				i++;
			}
			T elementoSustituto = x;
			if (!p->lleno) {
				T elementoBrinco = p->elemento[tam%N - 1];
				i = tam % N - pos % N;
				int largo = tam % N;
				while (i > 0) {
					p->elemento[largo] = p->elemento[largo - 1];
					i--;
					largo--;
					if (i == 0) {
						p->elemento[largo] = elementoSustituto;
					}
				}
				tam++;
				p->lleno = tam % N == 0;

			}
			else {
				int largo = N - 1;
				T elementoBrinco = p->elemento[largo];
				i = N - pos % N - 1;
				while (i > 0) {
					p->elemento[largo] = p->elemento[largo - 1];
					largo--;
					i--;
					if (i == 0) {
						p->elemento[largo] = elementoSustituto;
						p = p->siguiente;
						elementoSustituto = elementoBrinco;
						elementoBrinco = p->elemento[N - 1];
					}
				}
				if (p->lleno) {
					i = N - 1;
					T elementoBrinco = p->elemento[i];
					while (i > 0) {
						p->elemento[i] = p->elemento[i - 1];
						i--;
						if (i == 0) {
							p->elemento[i] = elementoSustituto;
							p->siguiente = new Node();
							p = p->siguiente;
							p->elemento[i] = elementoBrinco;
							tam++;
						}
					}
				}
				else {
					i = tam % N;
					while (i > 0) {
						p->elemento[i] = p->elemento[i - 1];
						i--;
						if (i == 0) {
							p->elemento[i] = elementoSustituto;
						}
					}
					tam++;
					p->lleno = tam % N == 0;
				}

			}
		}
	}

}

template<class T, int N>
bool ListaSimpleB<T, N>::remove(int pos, T & x){
	if (!primero) {
		return false;
	}
	else {
		link p = primero;
		int i = 0;
		while (i < pos / N) {
			p = p->siguiente;
			i++;
		}
		i = pos%N;
		x = p->elemento[i];
		int veces = pos;
		while (veces < tam) {
			p -> elemento[i] = p->elemento[i + 1];
			i++;
			veces++;
			if (i%N == 0) {
				p->elemento[i - 1] = p->siguiente->elemento[0];
				p = p->siguiente;
				i = i % N;
			}
		}
		tam--;
		return false;
	}
}

template<class T, int N>
bool ListaSimpleB<T, N>::pop(T & x){
	if (!primero) {
		return false;
	}
	else {
		remove(0, x);
		return true;
	}
}

template<class T, int N>
bool ListaSimpleB<T, N>::pop_back(T & x){
	if (!primero) {
		return false;
	}
	else {
		remove(tam - 1, x);
		return true;
	}
}


template<class T, int N>
void ListaSimpleB<T, N>::print()
{
	cout << nombreLista << " = [";
	if (primero) {
		link p = primero;
		cout << p->elemento[0];
		int i = 1;
		while (p && i<tam) {
			if (i%N == 0) {
				p = p->siguiente;
				cout << " || ";
			}
			cout << ", " << p->elemento[i%N];
			i++;
		}
	}
	cout << "]" << "\n";
}

template<class T, int N>
ListaSimpleB<T, N>::~ListaSimpleB() {
	link p;
	while (primero) {
		// Borrra todos los elementos en la
		// lista.
		p = primero->siguiente;
		delete primero;
		primero = p;
	}
}
