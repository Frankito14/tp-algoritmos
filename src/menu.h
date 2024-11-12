#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "centro.h"
#include "../src/estructuras/tabla-hash.h"
#include <iostream>
#include <fstream>
#include <functional>
using namespace std;

class Menu 
{
private:
    TablaHash* _tabla;

public:
    Menu(TablaHash* tabla);
    void mostrarMenuPrincipal();
    void mostrarMenuCentros();
    void mostrarMenuProyectos();

private:
    //Funciones de centros
    void consultarCentro();
    void agregarCentro();
    void eliminarCentro();
    void verTodosLosCentros();
    void mostrarCentro(Centro c);
    template <typename T>
    void imprimirOrdenados(function<T(Centro*)> funcion);
    //Funciones de proyectos
    void buscarMasEconomico();
    void buscarMasRapido();


};

#endif 
