#include <iostream>
//#include "./estructuras/lista.cpp"
//#include "./estructuras/archivo.cpp"
#include "menu.cpp"
#include "centro.h"
#include "../src/estructuras/tabla-hash.h"
//#include "../src/estructuras/tabla-hash.cpp" //Si no funciona, descomentar esto
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

CentroEliminado* CentroEliminado::instance = nullptr;

struct Proyecto
    {
        string cod_origen;
        string cod_destino;
        int costo;
        float duracion;
    };

void cargarCentros(TablaHash* tabla){
    string centroTexto;
    ifstream archivo("centros.txt");
    while (getline (archivo, centroTexto)){
        string datosCentro [10];
        stringstream ssCentro(centroTexto);
        string temp;
        int i = 0;
        while(getline(ssCentro, temp, ' '))
        {
            datosCentro[i] = temp;
            i++;
        }
        Centro* c = new Centro();
        c->codigo = datosCentro[0];
        if(c->codigo != "") {
            c->nombre = datosCentro[1] + " " + datosCentro[2] + " " + datosCentro[3] + " " + datosCentro[4];
            c->pais = datosCentro[5];
            c->superficie = stof(datosCentro[6]);
            c->cant_laboratorios = stoi(datosCentro[7]);
            c->cant_p_nacionales = stoi(datosCentro[8]);
            c->cant_p_internacionales = stoi(datosCentro[9]);
            tabla->agregar(c);
        }
    }
    archivo.close();
    //inicio guardarCentros()
    tabla->mostrar_todos();
}


int main() {
    
    TablaHash* tabla = new TablaHash();
    cargarCentros(tabla);
    
    Menu* menu = new Menu(tabla);
    
    
    while(true)
        menu->mostrarMenuPrincipal();

    delete[] menu;
    delete[] tabla;

    return 0;
}