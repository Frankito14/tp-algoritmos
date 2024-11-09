#ifndef DIGRAFO_H_INCLUDED
#define DIGRAFO_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Peso {
    int costo;  
    float tiempo;
};

struct Arista {
    int destino; //A donde apunta la arista
    Peso peso; 
};

class DigrafoPonderado
{
private:
    int cantidadVertices;      
    string* codigosVertices;    // codigos de los centros
    Arista*** listaAdyacencia;
public:
    DigrafoPonderado(int cantidadVertices);
    void mostrarListaAdyacencia();
    void asignarCodigoAVertice(int indexVertice, const string& codigo);
    bool sePuedeAgregarElCodigoVertice(const string& codigoAAgregar);
    string obtenerCodigoVertice(int indexVertice);
    int obtenerIndexDeCodigoVertice(const string& codigoBuscado);
    void agregarArista(const string& codigoOrigen, const string& codigoDestino, int costo, float tiempo);
    void caminoMasCorto(string codigoOrigen, string codigoDestino);
    virtual ~DigrafoPonderado();
};

#endif //DIGRAFO_H_INCLUDED
