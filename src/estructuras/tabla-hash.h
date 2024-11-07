#ifndef TABLA_H_INCLUDED
#define TABLA_H_INCLUDED
#include <iostream>
#include <String>
#include "lista.h"
#include "../centro.h"
using namespace std;

class TablaHash 
{
    private:
        Centro* tabla[10];
        //int hash(string c);

    public:
        TablaHash();
        void agregar(Centro* c);
        void eliminar(Centro* c);
        Centro* elem(int i);
        Centro* buscar(string codigo);
        int hash(string c);
        string mostrar(int i);
        Lista listaElementos();
};

#endif