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
	void insertarR(T x, int pos);
	bool remove(int pos, T& x);
	bool pop(T& x);
	bool pop_back(T& x);
	bool get(int pos, T& element);
	bool get_front(T& element);
	bool get_back(T& element);
	void print();
	~ListaSimpleB();
};
