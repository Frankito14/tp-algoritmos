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

void DigrafoPonderado::agregarArista(string codigoOrigen, string codigoDestino, int costo, float tiempo)
{

    int indexOrigen = obtenerIndexPorCodigo(codigoOrigen);
    int indexDestino = obtenerIndexPorCodigo(codigoDestino);
    Arista *nuevaArista = new Arista;
    nuevaArista->destino = indexDestino;
    nuevaArista->peso.costo = costo;
    nuevaArista->peso.tiempo = tiempo;
    nuevaArista->siguiente = listaAdyacencia[indexOrigen]; // Apuntamos a la arista anterior
    listaAdyacencia[indexOrigen] = nuevaArista;            // Pasa a ser la primera en la lista, pero el orden no es relevante
}

// Método para encontrar el camino más corto usando Dijkstra
void DigrafoPonderado::caminoMasCorto(string codigoOrigen, string codigoDestino, string atributo)
{
    // Indices de los codigos
    int indexOrigen = obtenerIndexPorCodigo(codigoOrigen);
    int indexDestino = obtenerIndexPorCodigo(codigoDestino);

    const int INFINITO = 1000000;

    int *distancia = new int[cantidadVertices];
    int *predecesor = new int[cantidadVertices];
    bool *visitado = new bool[cantidadVertices];

    for (int i = 0; i < cantidadVertices; ++i)
    {
        distancia[i] = INFINITO; // Distancias entre los nodos
        predecesor[i] = -1;      // Index de los predecesores
        visitado[i] = false;     // Si el nodo ya se proceso
    }
    distancia[indexOrigen] = 0;

    // Dijkstra
    // Procesa cada vertice
    for (int i = 0; i < (cantidadVertices - 1); i++)
    {
        // Buscar el vértice con la menor distancia
        int indexVertice = -1; // No hay nodo seleccionado
        for (int j = 0; j < cantidadVertices; j++)
        {
            if (!visitado[j] && (indexVertice == -1 || distancia[j] < distancia[indexVertice]))
            {
                indexVertice = j; // Selecciona el nodo con la distancia mas corta o setea el primero
            }
        }

        visitado[indexVertice] = true;

        // "Relajar" (Encontrar la distancia de los adyacentes del nodo actual)
        Arista *arista = listaAdyacencia[indexVertice];
        while (arista != nullptr)
        {
            int v = arista->destino;
            int peso;
            if (atributo == "costo")
                peso = arista->peso.costo;
            else if (atributo == "tiempo")
                peso = arista->peso.tiempo;
            else
                return;

            if (distancia[indexVertice] + peso < distancia[v])
            {
                distancia[v] = distancia[indexVertice] + peso;
                predecesor[v] = indexVertice;
            }
            arista = arista->siguiente;
        }
    }

    // Si la distancia al vértice destino sigue siendo infinita, no hay camino
    if (distancia[indexDestino] == INFINITO)
    {
        cout << "No hay camino desde " << codigosVertices[indexOrigen] << " hasta " << codigosVertices[indexDestino] << "." << endl;
    }
    else
    {
        // Imprimimos el costo del camino más corto
        cout << "La colaboracion mas rapida basada en " << atributo << " de " << codigosVertices[indexOrigen] << " a " << codigosVertices[indexDestino] << " es: " << distancia[indexDestino] << endl;

        // Reconstruimos el camino
        cout << "El camino es: ";
        int v = indexDestino;
        while (v != indexOrigen)
        {
            cout << codigosVertices[v] << " <- ";
            int pred = predecesor[v];
            // Buscar la arista entre v y pred para mostrar su costo y tiempo
            Arista *arista = listaAdyacencia[pred];
            while (arista != nullptr)
            {
                if (arista->destino == v)
                {
                    if(atributo == "costo")
                        cout << "(Costo: " << arista->peso.costo << ") <- ";
                    else if (atributo == "tiempo")
                        cout << "(Tiempo: " << arista->peso.tiempo << ") <- ";
                    break;
                }
                arista = arista->siguiente;
            }
            v = pred;
        }
        cout << codigosVertices[v] << endl;
    }

    // Limpiamos la memoria
    delete[] distancia;
    delete[] predecesor;
    delete[] visitado;
}

void DigrafoPonderado::mostrarListaAdyacencia()
{
    cout << "Colaboraciones entre centros:" << endl;
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
    for (int i = 0; i < cantidadVertices; i++)
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
