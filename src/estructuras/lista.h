#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>
#include <string>
#include "nodoLista.h"
using namespace std;

template<typename T>
class Lista
{
private:
    NodoLista* primero;
    int largo;

public:
    Lista();
    void agregar(int d, int pos);
    void agregar_al_final(T d);
    void eliminar(int pos);
    int consultar(int pos);
    bool estaVacia();
    virtual ~Lista();
    int obtener_largo();
    void mostrar();


private:
    NodoLista* obtener_nodo(int pos);
};

#endif // LISTA_H_INCLUDED
