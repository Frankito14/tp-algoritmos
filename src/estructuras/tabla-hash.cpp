#include "tabla-hash.h"

TablaHash::TablaHash() : cant_elem(0), size(1)
{
    this->tabla = new Centro*[1];
    this->array_null(tabla, 1);
}

// Agrega un elemento a la tabla.
void TablaHash::agregar(Centro* c) {
    this->cant_elem += 1;
    this->resize_tabla();
    int posicion = hash(c->codigo, size);
    bool guardado = false;
    while(!guardado){
        if(tabla[posicion] == nullptr) {
            tabla[posicion] = c;
            guardado = true;
        } else {
            posicion += 1;
            if(posicion > size) {
                posicion = 0;
            }
        }
    }    
};

// Cambia el tamaño de la tabla agregando todos los elementos que ya estaban guardados
void TablaHash::resize_tabla() {
    int nuevo_size = int(cant_elem / 0.8);
    Centro** nueva_tabla = new Centro*[nuevo_size];
    this->array_null(nueva_tabla, nuevo_size);
    this->agregar_todos(nueva_tabla, nuevo_size);

    delete[] tabla;
    this->tabla = nueva_tabla;
    this->size = nuevo_size;
}

// Carga a todos los valores de la tabla que se pasa por parámetro el valor nullptr
void TablaHash::array_null(Centro** &tab, int size) {
    for (size_t i = 0; i < size; i++)
    {
        tab[i] = nullptr;
    }
}

// Agrega todos los elementos ya existentes a la nueva_tab
void TablaHash::agregar_todos(Centro**& nueva_tab, int nuevo_size) {
    for (size_t i = 0; i < size; i++)
    {
        if(tabla[i] != nullptr) {
            int hash = this->hash(tabla[i]->codigo, nuevo_size);
            bool guardado = false;
            while(!guardado){
                if(nueva_tab[hash] == nullptr) {
                    nueva_tab[hash] = tabla[i];
                    guardado = true;
                } else {
                    hash += 1;
                    if(hash > size) {
                        hash = 0;
                    }
                }
            }
        }
    }
};

// Muestra todos los elementos de la tabla.
void TablaHash::mostrar_todos() {
    for (size_t i = 0; i < size; i++)
    {
        if(tabla[i] != nullptr && tabla[i] != CentroEliminado::getInstance()) {
            cout << tabla[i]->codigo << ": " << tabla[i]->cant_laboratorios;
            cout << endl;
        }
    }
}

// Elimina un elemento de la tabla
void TablaHash::eliminar(Centro* c) {
    int posicion = hash(c->codigo, size);
    bool sigue_buscando = true;
    int intentos = 0;

    while(sigue_buscando && intentos < size) {
        if(tabla[posicion] == c) {
            delete tabla[posicion];
            tabla[posicion] = CentroEliminado::getInstance();
            sigue_buscando = false;
            cant_elem -= 1;
        } else if(tabla[posicion] == nullptr) {
            sigue_buscando = false;
        } else {
            posicion = (posicion + 1) % size;
            intentos++;
        }
    }   
}

// Busca un elemento por su posición por el hash.
Centro* TablaHash::buscar(string c) {
    int posicion = hash(c, size);
    bool sigue_buscando = true;
    int intentos = 0;
    Centro* elemento = nullptr;
    while(sigue_buscando && intentos < size){
        if(tabla[posicion] == nullptr) {
            sigue_buscando = false;
            elemento = nullptr;
        } else if(tabla[posicion]->codigo == c) {
            elemento = tabla[posicion];
            sigue_buscando = false;
        } else {
            posicion = (posicion + 1) % size;
            intentos++;
        }
    }

    return elemento;
};

// Devuelve el hash de un código para una cantidad de espacios de una tabla.
int TablaHash::hash(string codigo, int cant_espacios) {
    int posicion = 1;
    for (size_t i = 0; i < codigo.length(); i++)
    {
        posicion += int(codigo[i]) * 128 * (i+1);
    };
    return posicion % cant_espacios;
};

// Imprime por pantalla un centro
void TablaHash::mostrar(Centro* c) {
    cout << 
        "[" + 
            c->codigo + ": " <<
            c->nombre + " (" <<
            c->pais + ") " <<
            "Sup: " << c->superficie << " - " <<
            "Lab: " << c->cant_laboratorios << " - " <<
            "Proy. Nac.: " << c->cant_p_nacionales << " - " <<
            "Proy. internac.: " << c->cant_p_internacionales <<
        "]";
};