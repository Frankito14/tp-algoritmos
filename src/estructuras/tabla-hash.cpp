#include "tabla-hash.h"


TablaHash::TablaHash()
{
    Centro** tabla = new Centro*[1];
    int cant_elem = 0;
}

void TablaHash::agregar(Centro* c) {
    int size = int(cant_elem / 0.8);
    Centro** nueva_tabla = new Centro*[size];
    this->copy_in(tabla, nueva_tabla);
    delete[] tabla;
    tabla = nueva_tabla;
    int posicion = hash(c->codigo);
    tabla[posicion] = c;
};

void TablaHash::eliminar(Centro* c) {
    int posicion = hash(c->codigo);
    delete tabla[posicion];
    tabla[posicion] = CentroEliminado::instance;
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
        posicion += int(codigo[i]) * 128 * (i+1);
    };
    return posicion % 10;
};

string TablaHash::mostrar(int i) {
    return tabla[i]->codigo;
};

Lista<string>* TablaHash::mostrar_todos() {
    Lista<string>* lista = new Lista<string>();
    int size = sizeof(tabla) / sizeof(tabla[0]);
    for (size_t i = 0; i < size; i++)
    {
        if(tabla[i] != nullptr) {
            lista->agregar_al_final(tabla[i]->codigo + ": " + tabla[i]->nombre);
        };
    };
    return lista;
};

void TablaHash::copy_in(Centro* tab[], Centro* new_tab[]) {
    int size = sizeof(tab) / sizeof(tab[0]);
    for (size_t i = 0; i < size; i++)
    {
        if(tab[i] != nullptr) {
            new_tab[i] = tab[i];
        }
    }
};

Lista<Centro*>* TablaHash::listaElementos() {
    Lista<Centro*>* listaElementos = new Lista<Centro*>();
    for (size_t i = 0; i < 10; i++)
    {
        if(tabla[i] != nullptr && tabla[i] != CentroEliminado::instance) {
            listaElementos->agregar_al_final(tabla[i]);
        }
    }
    return listaElementos;
}