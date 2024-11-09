#include <iostream>
#include "menu.cpp"
#include "centro.h"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;


void mostrarCentros(vector<Centro> centros)
{
    for (auto &c : centros)
    {
        cout << c.codigo << " - "
             << c.nombre << " - "
             << c.pais << " - "
             << c.superficie << " - "
             << c.cant_laboratorios << " - "
             << c.cant_p_nacionales << " - "
             << c.cant_p_internacionales << endl;
    }
}

void cargarCentros()
{
    string centroTexto;
    ifstream archivo("centros.txt");
    vector<Centro> centros;
    while (getline(archivo, centroTexto))
    {
        string datosCentro[10];
        stringstream ssCentro(centroTexto);
        string temp;
        int i = 0;
        while (getline(ssCentro, temp, ' '))
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
    /*
    // inicio guardarCentros()
    ofstream archivoSalida;
    archivoSalida.open("centros.txt");
    for (auto &c : centros)
    {
        stringstream superficieRedondeada;
        superficieRedondeada << (c.superficie);
        archivoSalida << (c.codigo + " " + c.nombre + " " + c.pais + " " + (superficieRedondeada.str()) + " " + to_string(c.cant_laboratorios) + " " + to_string(c.cant_p_nacionales) + " " + to_string(c.cant_p_internacionales)) << endl;
    }
    // fin guardarCentros
    archivo.close();
    */
}

void guardarCentros()
{
}

/*
int cantidadDeVerticesEnArchivo(){
    string *codigos = new string[1];
    int cantidadVertices = 0;
    string proyectoTexto;
    ifstream archivo("proyectos.txt");
    // Obtenemos la cantidad de vertices que tendra el grafo. Tenemos que contar los codigos (Sin contar los repetidos)
    while (getline(archivo, proyectoTexto))
    {
        stringstream codigo;
        codigo << proyectoTexto[0] << proyectoTexto[1] << proyectoTexto[2];
        string codigoOrigen = codigo.str();
        codigo.str("");
        codigo << proyectoTexto[4] << proyectoTexto[5] << proyectoTexto[6];
        string codigoDestino = codigo.str();
        // Crea un nuevo arreglo que tendra el tamaño necesario para guardar los nuevos codigos encontrados
        if (cantidadVertices == 0)
        {
            codigos[0] = codigoOrigen;
            cantidadVertices++;
        }
        bool destinoCargado = false;
        bool origenCargado = false;
        // Busca si los codigos ya estan cargados
        for (int i = 0; i < cantidadVertices; i++)
        {
            if (codigos[i] == codigoOrigen)
                origenCargado = true;
            if (codigos[i] == codigoDestino)
                destinoCargado = true;
        }
        // Crea un nuevo arreglo agregando los codigos que se usaran como vertices del grafo
        string *nuevosCodigos = new string[cantidadVertices + !origenCargado + !destinoCargado];
        // Copia el arreglo actual al nuevo
        for (int i = 0; i < cantidadVertices; i++)
        {
            nuevosCodigos[i] = codigos[i];
        }
        if (!origenCargado)
        {
            nuevosCodigos[cantidadVertices] = codigoOrigen;
            cantidadVertices++;
        }
        if (!destinoCargado)
        {
            nuevosCodigos[cantidadVertices + !origenCargado] = codigoDestino;
            cantidadVertices++;
        }
        delete[] codigos;
        codigos = nuevosCodigos;
    }
    archivo.close();
    return cantidadVertices;
}

void cargarProyectos()
{
    //Creamos el grafo con la cantidad de nodos y cargamos las aristas
    int cantidadVertices = 4;
    DigrafoPonderado grafo(cantidadVertices);
    string proyectoTexto;
    ifstream archivo("proyectos.txt");
    int verticesAgregados = 0;
    while (getline(archivo, proyectoTexto))
    {

        string datos[4];
        stringstream ss(proyectoTexto);
        string temp;
        int i = 0;
        while (getline(ss, temp, ' '))
        {
            datos[i] = temp;
            i++;
        }
        
        if(grafo.sePuedeAgregarElCodigoVertice(datos[0])){
            grafo.asignarCodigoAVertice(verticesAgregados, datos[0]);
            verticesAgregados++;
        }

        if(grafo.sePuedeAgregarElCodigoVertice(datos[1])){
            grafo.asignarCodigoAVertice(verticesAgregados, datos[1]);
            verticesAgregados++;
        }
        
        //grafo.agregarArista(datos[0], datos[1], datos[2], datos[]); // (origen, destino, costo, tiempo)
    }
    grafo.mostrarListaAdyacencia();

}
*/


int main()
{
    //cargarProyectos();
    
    DigrafoPonderado* grafo = new DigrafoPonderado(3);
    grafo->asignarCodigoAVertice(0, "AAA");
    grafo->asignarCodigoAVertice(1, "BBB");
    grafo->asignarCodigoAVertice(2, "CCC");
    grafo->mostrarListaAdyacencia();

    
    //cargarCentros();
    Menu *menu = new Menu();
    while (true)
        menu->mostrarMenuPrincipal();


    return 0;
}
