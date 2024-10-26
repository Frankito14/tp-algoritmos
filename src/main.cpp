#include <iostream>
//#include "./estructuras/lista.cpp"
//#include "./estructuras/archivo.cpp"
#include "menu.cpp"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

struct Centro
    {
        string codigo;
        string nombre;
        string pais;
        float superficie;
        int cant_laboratorios;
        int cant_p_nacionales;
        int cant_p_internacionales;
    };

struct Proyecto
    {
        string cod_origen;
        string cod_destino;
        int costo;
        float duracion;
    };

void mostrarCentros(vector<Centro> centros){
    for (auto& c : centros) {
        cout << c.codigo << " - "
             << c.nombre << " - "
             << c.pais << " - " 
             << c.superficie << " - " 
             << c.cant_laboratorios << " - " 
             << c.cant_p_nacionales << " - " 
             << c.cant_p_internacionales << endl;
    }
}

void cargarCentros(){
    string centroTexto;
    ifstream archivo("centros.txt");
    vector <Centro> centros;
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
        Centro c;
        c.codigo = datosCentro[0];
        c.nombre = datosCentro[1] + " " + datosCentro[2] + " " + datosCentro[3] + " " + datosCentro[4];
        c.pais = datosCentro[5];
        c.superficie = stof(datosCentro[6]);
        c.cant_laboratorios = stoi(datosCentro[7]);
        c.cant_p_nacionales = stoi(datosCentro[8]);
        c.cant_p_internacionales = stoi(datosCentro[9]);
        centros.push_back(c);

    }
    mostrarCentros(centros);
    archivo.close();
    //inicio guardarCentros()
    ofstream archivoSalida;
    archivoSalida.open("centros.txt");
    for (auto& c : centros) {
        stringstream superficieRedondeada;
        superficieRedondeada<<(c.superficie);
        archivoSalida << (c.codigo + " " + c.nombre + " " + c.pais + " " + (superficieRedondeada.str()) + " " +  to_string(c.cant_laboratorios) + " " +  to_string(c.cant_p_nacionales) + " "  +  to_string(c.cant_p_internacionales)) << endl;
      
    }
    archivoSalida << ("ABB Centro Institucional Fransico Alvarez Chile 10.5 10 2 3") << endl;
    //fin guardarCentros
    archivo.close();
}

void guardarCentros(){
    
    
}


int main() {
    
    cargarCentros();
    Menu* menu = new Menu();
    while(true)
        menu->mostrarMenuPrincipal();
    /*
    Lista* numeros = new Lista();
    Lista* impares = new Lista();
    numeros->agregar(20, 1);
    numeros->agregar(10, 2);
    numeros->agregar(2, 3);
    numeros->agregar(3, 4);
    numeros->mostrar();

    numeros->mostrar();
    */



    return 0;
}