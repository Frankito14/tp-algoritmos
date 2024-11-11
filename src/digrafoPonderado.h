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
    int destino; 
    Peso peso; 
    Arista* siguiente;
};

class DigrafoPonderado
{
private:
    int cantidadVertices;      
    string* codigosVertices;    // codigos de los centros
    Arista** listaAdyacencia;
public:
    DigrafoPonderado(int cantidadVertices);

    //Manejo de codigos
    void asignarCodigoAVertice(int indexVertice, string codigo);
    bool sePuedeAgregarElCodigo(string codigoAAgregar);
    string obtenerCodigoPorIndex(int indexVertice);
    int obtenerIndexPorCodigo(string codigoBuscado);
    void agregarArista(string codigoOrigen, string codigoDestino, int costo, float tiempo);

    //Interfaces
    void caminoMasCorto(string codigoOrigen, string codigoDestino, string atributo);
    void mostrarListaAdyacencia();
    virtual ~DigrafoPonderado();
};

#endif //DIGRAFO_H_INCLUDED
