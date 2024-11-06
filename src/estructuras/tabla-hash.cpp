#include "tabla-hash.h"

TablaHash::TablaHash()
{
    Centro* tabla[10] = {nullptr};
}

void TablaHash::agregar(Centro* c) {
    int posicion = hash(c->codigo);
    tabla[posicion] = c;
};

void TablaHash::eliminar(Centro* c) {
    int posicion = hash(c->codigo);
    delete tabla[posicion];
    tabla[posicion] = nullptr;
}

Centro* TablaHash::elem(int i) {
    return tabla[i];
}

Centro* TablaHash::buscar(string c) {
    int posicion = hash(c);
    return tabla[posicion];
};

int TablaHash::hash(string codigo) {
    int posicion = 1;
    for (size_t i = 0; i < codigo.length(); i++)
    {
        posicion += int(codigo[i]) * (i+1);
    };
    return posicion % 10;
};

string TablaHash::mostrar(int i) {
    return tabla[i]->codigo;
}

