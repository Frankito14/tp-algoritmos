#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "centro.h"
#include <iostream>
#include <fstream>
using namespace std;

class Menu
{
private:
    //Lista* centros;
    //Lista* proyectos;
public:
    Menu();
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
    //Funciones de proyectos
    void buscarMasEconomico();
    void buscarMasRapido();


};

#endif 
