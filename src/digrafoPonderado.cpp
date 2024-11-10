#include "digrafoPonderado.h"

DigrafoPonderado::DigrafoPonderado(int cantidadVertices)
{
    this->cantidadVertices = cantidadVertices;

    // Inicializamos el arreglo de claves de los vértices
    codigosVertices = new string[cantidadVertices];
    // Crear un arreglo de listas de adyacencia, inicialmente vacío
    listaAdyacencia = new Arista **[cantidadVertices]; // Crear un arreglo de punteros a listas de adyacencia
    for (int i = 0; i < cantidadVertices; i++)
    {
        listaAdyacencia[i] = nullptr; // Inicializamos cada lista de adyacencia como nullptr
    }
}

// Método para asignar la clave a un vértice
void DigrafoPonderado::asignarCodigoAVertice(int indexVertice, const string &codigo)
{
    codigosVertices[indexVertice] = codigo;
}

bool DigrafoPonderado::sePuedeAgregarElCodigoVertice(const string &codigoAAgregar)
{
    return (obtenerIndexDeCodigoVertice(codigoAAgregar) == -1);
}

// Método para obtener la clave de un vértice
string DigrafoPonderado::obtenerCodigoVertice(int indexVertice)
{
    return codigosVertices[indexVertice];
}

// Método para obtener la clave de un vértice
int DigrafoPonderado::obtenerIndexDeCodigoVertice(const string &codigoBuscado)
{
    int index = -1;
    for (int i = 0; i < cantidadVertices; i++)
    {
        if (codigosVertices[i] == codigoBuscado)
        {
            index = i;
        }
    }
    return index;
}

// Método para agregar una arista (u, v) con peso (costo, tiempo)
void DigrafoPonderado::agregarArista(const string &codigoOrigen, const string &codigoDestino, int costo, float tiempo)
{
    // Crear una nueva arista
    int vOrigen = obtenerIndexDeCodigoVertice(codigoOrigen);
    int vDestino = obtenerIndexDeCodigoVertice(codigoDestino);
    Arista *nuevaArista = new Arista;
    nuevaArista->destino = vDestino;
    nuevaArista->peso.costo = costo;
    nuevaArista->peso.tiempo = tiempo;

    // Si no hay ninguna lista de adyacencia en el vértice origen, la creamos
    if (listaAdyacencia[vOrigen] == nullptr)
    {
        listaAdyacencia[vOrigen] = new Arista* [1];
        listaAdyacencia[vOrigen][0] = nuevaArista;
    }
    else
    {
        //redimensionamos el arreglo
        int tamanioActual = 0;
        while (listaAdyacencia[vOrigen][tamanioActual] != nullptr)
            tamanioActual+=1;
        // Crear un nuevo arreglo con una posición extra
        Arista **nuevaLista = new Arista *[tamanioActual + 1];

        // Copiar las aristas existentes
        for (int i = 0; i < tamanioActual; ++i)
        {
            nuevaLista[i] = listaAdyacencia[vOrigen][i];
        }

        // Agregar la nueva arista
        nuevaLista[tamanioActual] = nuevaArista;

        // Eliminar la lista vieja y actualizar la lista de adyacencia
        delete[] listaAdyacencia[vOrigen];
        listaAdyacencia[vOrigen] = nuevaLista;

    }
}

// Método para encontrar el camino más corto usando Dijkstra
void DigrafoPonderado::caminoMasCorto(string codigoOrigen, string codigoDestino, string atributo)
{

    int start = obtenerIndexDeCodigoVertice(codigoOrigen);
    int end = obtenerIndexDeCodigoVertice(codigoDestino);

    if (start == -1 || end == -1)
    {
        cout << "Los codigos de los centros no son validos" << endl;
        return;
    }

    // Inicializar arreglos auxiliares
    int infinito = 100000; // Maximo valor de un Int
    int *distancias = new int[cantidadVertices];
    int *predecesores = new int[cantidadVertices];
    bool *visitados = new bool[cantidadVertices];
    for (int i = 0; i < cantidadVertices; i++)
    {
        distancias[i] = infinito;
        predecesores[i] = -1;
        visitados[i] = false;
    }
    // La distanicia de un vertice consigo mismo siempre es 0
    distancias[start] = 0;

    // Cola de prioridades (implementada manualmente como el índice de vértice y su distancia)
    for (int i = 0; i < cantidadVertices; ++i)
    {
        int u = -1;
        // Encontrar el vértice con la distancia más pequeña que aún no haya sido visitado
        for (int j = 0; j < cantidadVertices; ++j)
        {
            if (!visitados[j] && (u == -1 || distancias[j] < distancias[u]))
            {
                u = j;
            }
        }

        // marcar el vértice como visitado
        visitados[u] = true;

        // actualizar las distancias de los vecinos
        if (listaAdyacencia[u] != nullptr)
        {
            for (int j = 0; listaAdyacencia[u][j] != nullptr; ++j)
            {
                int vDestino = listaAdyacencia[u][j]->destino;
                int peso;
                if(atributo == "costo")
                    peso = listaAdyacencia[u][j]->peso.costo;
                else if (atributo == "tiempo")
                    peso = listaAdyacencia[u][j]->peso.tiempo;
                // si encontramos una distancia más corta, la actualizamos
                if (distancias[u] + peso < distancias[vDestino])
                {
                    distancias[vDestino] = distancias[u] + peso;
                    predecesores[vDestino] = u;
                }
            }
        }
    }

    if (distancias[end] == infinito)
    {
        cout << "No hay camino desde " << codigoOrigen << " hasta " << codigoDestino << endl;
    }
    else
    {
        cout << "La colaboración basada en " << atributo << " mas rapida es de " << codigoOrigen << " a " << codigoDestino << " es: " << distancias[end] << endl;

        cout << "El camino mas corto es: ";
        int temp = end;
        string path = codigoDestino;
        while (predecesores[temp] != -1)
        {
            path = codigosVertices[predecesores[temp]] + " -> " + path;
            temp = predecesores[temp];
        }
        cout << path << endl;
    }

    delete[] distancias;
    delete[] predecesores;
    delete[] visitados;
}


void DigrafoPonderado::mostrarListaAdyacencia()
{
    cout << "Lista de adyacencia del grafo:" << endl;
    for (int i = 0; i < cantidadVertices; i++)
    {
        cout << codigosVertices[i] << " (" << i << "): "; // codigo (0)
        if (listaAdyacencia[i] != nullptr)
        {
            for (int j = 0; listaAdyacencia[i][j]!= nullptr; j++)
            {   /*
                cout << codigosVertices[listaAdyacencia[i][j]->destino] << " (costo: " << listaAdyacencia[i][j]->peso.costo
                     << ", tiempo: " << listaAdyacencia[i][j]->peso.tiempo << ") ";*/ cout <<listaAdyacencia[i][j]->peso.costo<< endl;
            }
            
        }
        cout << endl;
    }
}


DigrafoPonderado::~DigrafoPonderado()
{
    for (int i = 0; i < cantidadVertices; ++i)
    {
        if (listaAdyacencia[i] != nullptr)
        {
            delete[] listaAdyacencia[i]; // lista de adyacencia de cada vértice
        }
    }
    delete[] listaAdyacencia; 
    delete[] codigosVertices; 
}
