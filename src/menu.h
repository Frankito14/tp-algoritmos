#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "centro.h"
#include "digrafoPonderado.cpp"
#include "./estructuras/tabla-hash.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Menu
{
private:
    DigrafoPonderado* proyectos;
    TablaHash* centros;   
public:
    Menu();
    void mostrarMenuPrincipal();
    void mostrarMenuCentros();
    void mostrarMenuProyectos();
    void cerrarMenu();

private:
    //Funciones de centros
    void cargarCentros();
    void consultarCentro();
    void agregarCentro();
    void eliminarCentro();
    void verTodosLosCentros();
    void mostrarCentro(Centro c);
    template <typename T>
    void imprimirOrdenados(function<T(Centro*)> funcion);
    //Funciones de proyectos
    void cargarProyectos();
    void verColaboraciones();
    void buscarMasEconomico();
    void buscarMasRapido();
};

#endif 
