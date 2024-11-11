#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "centro.h"
#include "digrafoPonderado.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Menu
{
private:
    //Centro* centros = new Centro[0];
    DigrafoPonderado* proyectos;
    
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
    //Funciones de proyectos
    void cargarProyectos();
    void verColaboraciones();
    void buscarMasEconomico();
    void buscarMasRapido();


};

#endif 
