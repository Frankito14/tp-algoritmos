#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <iostream>
#include "nodoLista.h"
using namespace std;

class Lista
{
private:
    NodoLista* primero;
    int largo;

public:
    Lista();
    void agregar(int d, int pos);
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
