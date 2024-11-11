#include <iostream>
#include <string>

using namespace std;


struct Peso {
    int costo;
    float tiempo;
};

struct Arista {
    int destino; //Index del destino
    Peso peso;
    Arista* siguiente;  // Siguiente arista en la lista
};


class Grafo {
private:
    int cantidadVertices;  
    string* codigosVertices;  // Guarda los codigos de los centros
    Arista** listaAdyacencia;  // arreglo de punteros a listas de aristas

public:
    // Constructor
    Grafo(int cantidadNodos) {
        cantidadVertices = cantidadNodos;
        codigosVertices = new string[cantidadVertices];  
        listaAdyacencia = new Arista*[cantidadVertices]; 

        // Setear a null pointer
        for (int i = 0; i < cantidadVertices; ++i) {
            listaAdyacencia[i] = nullptr;
        }
    }

    // Destructor
    ~Grafo() {
        for (int i = 0; i < cantidadVertices; ++i) {
            Arista* arista = listaAdyacencia[i];
            while (arista != nullptr) {
                Arista* siguiente = arista->siguiente;
                delete arista; 
                arista = siguiente;
            }
        }
        delete[] listaAdyacencia;
        delete[] codigosVertices;
    }

    // Asignar codigo a un vertice
    void asignarCodigoAVertice(int indexVertice, string codigo) {
        codigosVertices[indexVertice] = codigo;  
    }

    // Obtener un codigo de la lista segun su index
    string obtenerCodigoPorIndex(int indexVertice) {
        return codigosVertices[indexVertice];
    }

    // Obtener el index de un codigo
    int obtenerIndexPorCodigo(string codigo) {
        int index = -1; //Si el codigo no esta cargado, retorna -1
        for(int i = 0; i < cantidadVertices; i++){
            if( codigosVertices[i] == codigo)
                index = i;
        }
        return index;
    }

    // Retorna si el codigo esta cargado (>= 0) o no (-1)
    bool sePuedeCargarElCodigo(string codigo) {
        return obtenerIndexPorCodigo(codigo) == -1;
    }

    void agregarArista(string origen, string destino, int costo, float tiempo) {
        // Crear una nueva arista
        int indexOrigen = obtenerIndexPorCodigo(origen);
        int indexDestino = obtenerIndexPorCodigo(destino);
        Arista* nuevaArista = new Arista;
        nuevaArista->destino = indexDestino;
        nuevaArista->peso.costo = costo;
        nuevaArista->peso.tiempo = tiempo;
        nuevaArista->siguiente = listaAdyacencia[indexOrigen];  // Apuntamos a la arista anterior
        listaAdyacencia[indexOrigen] = nuevaArista;  // Ahora la nueva arista es la primera en la lista
    }


    void mostrarGrafo() {
        for (int i = 0; i < cantidadVertices; ++i) {
            cout << "Centro " << codigosVertices[i] << " ("<< i <<"): ";
            Arista* arista = listaAdyacencia[i];
            while (arista != nullptr) {
                cout << codigosVertices[arista->destino] << " (Costo: " << arista->peso.costo << ", Tiempo: " << arista->peso.tiempo << ") ";
                arista = arista->siguiente;
            }
            cout << endl;
        }
    }
    /*
    // Obtener las aristas adyacentes de un vértice
    void obtenerAristasAdyacentes(int u) {
        cout << "Aristas adyacentes al vértice " << codigosVertices[u] << ": ";
        Arista* arista = listaAdyacencia[u];
        if (arista == nullptr) {
            cout << "No tiene aristas adyacentes." << endl;
            return;
        }
        while (arista != nullptr) {
            cout << "(Destino: " << codigosVertices[arista->destino] << ", Costo: " << arista->peso. << ") ";
            arista = arista->siguiente;
        }
        cout << endl;
    }
    */

    // Método para encontrar el recorrido mínimo entre dos vértices usando Dijkstra
    void encontrarRecorridoMinimo(string origen, string destino) {
        int indexOrigen = obtenerIndexPorCodigo(origen);
        int indexDestino = obtenerIndexPorCodigo(destino);

        // Inicializamos las distancias y el arreglo de predecesores
        int* distancia = new int[cantidadVertices];
        int* predecesor = new int[cantidadVertices];
        bool* visitado = new bool[cantidadVertices];

        for (int i = 0; i < cantidadVertices; ++i) {
            distancia[i] = 1000000;  // Usamos un valor alto como "infinito"
            predecesor[i] = -1;
            visitado[i] = false;
        }
        distancia[indexOrigen] = 0;

        // Algoritmo de Dijkstra sin usar colas de prioridad
        for (int i = 0; i < cantidadVertices - 1; ++i) {
            // Buscar el vértice con la distancia más pequeña
            int u = -1;
            for (int j = 0; j < cantidadVertices; ++j) {
                if (!visitado[j] && (u == -1 || distancia[j] < distancia[u])) {
                    u = j;
                }
            }

            visitado[u] = true;

            // Relajamos las aristas
            Arista* arista = listaAdyacencia[u];
            while (arista != nullptr) {
                int v = arista->destino;
                int peso = arista->peso.costo;

                if (distancia[u] + peso < distancia[v]) {
                    distancia[v] = distancia[u] + peso;
                    predecesor[v] = u;
                }
                arista = arista->siguiente;
            }
        }

        // Si la distancia al vértice destino sigue siendo infinita, no hay camino
        if (distancia[indexDestino] == 1000000) {
            cout << "No hay camino desde " << codigosVertices[indexOrigen] << " hasta " << codigosVertices[indexDestino] << "." << endl;
        } else {
            // Imprimimos el costo del camino más corto
            cout << "El costo del camino mas corto desde " << codigosVertices[indexOrigen] << " hasta " << codigosVertices[indexDestino] << " es: " << distancia[indexDestino] << endl;

            // Reconstruimos el camino
            cout << "El camino es: ";
            int v = indexDestino;
            while (v != -1) {
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
};

int main() {

    Grafo g(5);

    g.asignarCodigoAVertice(0, "AAA");
    g.asignarCodigoAVertice(1, "BBB");
    g.asignarCodigoAVertice(2, "CCC");
    g.asignarCodigoAVertice(3, "DDD");
    g.asignarCodigoAVertice(4, "EEE");

    g.agregarArista("AAA", "BBB", 10, 5.0);
    g.agregarArista("AAA", "CCC", 40, 15.0);
    g.agregarArista("BBB", "CCC", 20, 10.0);
    g.agregarArista("DDD", "EEE", 30, 2.0);



    g.mostrarGrafo();

    //g.obtenerAristasAdyacentes(1);
    g.encontrarRecorridoMinimo("AAA", "CCC");

    return 0;
}