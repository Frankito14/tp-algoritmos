#include "digrafoPonderado.h"

DigrafoPonderado::DigrafoPonderado(int cantidadNodos)
{
    cantidadVertices = cantidadNodos;
    codigosVertices = new string[cantidadVertices];
    listaAdyacencia = new Arista *[cantidadVertices];

    // Setear a null pointer
    for (int i = 0; i < cantidadVertices; ++i)
    {
        listaAdyacencia[i] = nullptr;
    }
}

// Método para asignar la clave a un vértice
void DigrafoPonderado::asignarCodigoAVertice(int indexVertice, string codigo)
{
    codigosVertices[indexVertice] = codigo;
}

bool DigrafoPonderado::sePuedeAgregarElCodigo(string codigo)
{
    return (obtenerIndexPorCodigo(codigo) == -1);
}

// Método para obtener la clave de un vértice
string DigrafoPonderado::obtenerCodigoPorIndex(int indexVertice)
{
    return codigosVertices[indexVertice];
}

// Método para obtener la clave de un vértice
int DigrafoPonderado::obtenerIndexPorCodigo(string codigoBuscado)
{
    int index = -1;
    for (int i = 0; i < cantidadVertices; i++)
    {
        if (codigosVertices[i] == codigoBuscado)
            index = i;
    }
    return index;
}

// Método para agregar una arista (u, v) con peso (costo, tiempo)
void DigrafoPonderado::agregarArista(string codigoOrigen, string codigoDestino, int costo, float tiempo)
{
    // Crear una nueva arista
    int indexOrigen = obtenerIndexPorCodigo(codigoOrigen);
    int indexDestino = obtenerIndexPorCodigo(codigoDestino);
    Arista *nuevaArista = new Arista;
    nuevaArista->destino = indexDestino;
    nuevaArista->peso.costo = costo;
    nuevaArista->peso.tiempo = tiempo;
    nuevaArista->siguiente = listaAdyacencia[indexOrigen]; // Apuntamos a la arista anterior
    listaAdyacencia[indexOrigen] = nuevaArista;            // Ahora la nueva arista es la primera en la lista
}

// Método para encontrar el camino más corto usando Dijkstra
void DigrafoPonderado::caminoMasCorto(string codigoOrigen, string codigoDestino, string atributo)
{
    int indexOrigen = obtenerIndexPorCodigo(codigoOrigen);
    int indexDestino = obtenerIndexPorCodigo(codigoDestino);

    // Inicializamos las distancias y el arreglo de predecesores
    int *distancia = new int[cantidadVertices];
    int *predecesor = new int[cantidadVertices];
    bool *visitado = new bool[cantidadVertices];

    for (int i = 0; i < cantidadVertices; ++i)
    {
        distancia[i] = 1000000; // Usamos un valor alto como "infinito"
        predecesor[i] = -1;
        visitado[i] = false;
    }
    distancia[indexOrigen] = 0;

    // Algoritmo de Dijkstra sin usar colas de prioridad
    for (int i = 0; i < cantidadVertices - 1; ++i)
    {
        // Buscar el vértice con la distancia más pequeña
        int u = -1;
        for (int j = 0; j < cantidadVertices; ++j)
        {
            if (!visitado[j] && (u == -1 || distancia[j] < distancia[u]))
            {
                u = j;
            }
        }

        visitado[u] = true;

        // Relajamos las aristas
        Arista *arista = listaAdyacencia[u];
        while (arista != nullptr)
        {
            int v = arista->destino;
            int peso;
            if(atributo == "costo")
                peso = arista->peso.costo;
            else if(atributo == "tiempo")
                peso = arista->peso.tiempo;
            else
                return;

            if (distancia[u] + peso < distancia[v])
            {
                distancia[v] = distancia[u] + peso;
                predecesor[v] = u;
            }
            arista = arista->siguiente;
        }
    }

    // Si la distancia al vértice destino sigue siendo infinita, no hay camino
    if (distancia[indexDestino] == 1000000)
    {
        cout << "No hay camino desde " << codigosVertices[indexOrigen] << " hasta " << codigosVertices[indexDestino] << "." << endl;
    }
    else
    {
        // Imprimimos el costo del camino más corto
        cout << "La colaboracion mas rapida basada en " << atributo << " es: "<< codigosVertices[indexOrigen] << " hasta " << codigosVertices[indexDestino] << " es: " << distancia[indexDestino] << endl;

        // Reconstruimos el camino
        cout << "El camino es: ";
        int v = indexDestino;
        while (v != -1)
        {
            cout << codigosVertices[v] << " <- ";
            v = predecesor[v];
        }
        cout << endl;
    }

    // Limpiamos la memoria
    delete[] distancia;
    delete[] predecesor;
    delete[] visitado;
}

void DigrafoPonderado::mostrarListaAdyacencia()
{
    cout << "Colaboraciones entre centros:" <<endl;
    for (int i = 0; i < cantidadVertices; ++i)
    {
        cout << "Centro " << codigosVertices[i] << " (" << i << "): ";
        Arista *arista = listaAdyacencia[i];
        while (arista != nullptr)
        {
            cout << codigosVertices[arista->destino] << " (Costo: " << arista->peso.costo << ", Tiempo: " << arista->peso.tiempo << ") ";
            arista = arista->siguiente;
        }
        cout << endl;
    }
}

DigrafoPonderado::~DigrafoPonderado()
{
    for (int i = 0; i < cantidadVertices; ++i)
    {
        Arista *arista = listaAdyacencia[i];
        while (arista != nullptr)
        {
            Arista *siguiente = arista->siguiente;
            delete arista;
            arista = siguiente;
        }
    }
    delete[] listaAdyacencia;
    delete[] codigosVertices;
}
