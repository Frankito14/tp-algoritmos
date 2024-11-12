#ifndef TABLA_H_INCLUDED
#define TABLA_H_INCLUDED
#include <iostream>
#include <string>
#include <functional>
#include "lista.h"
#include "../centro.h"
using namespace std;

class TablaHash 
{
    private:
        Centro** tabla;
        int cant_elem;
        int size;

    public:
        TablaHash();
        void agregar(Centro* c);
        void eliminar(Centro* c);
        Centro* buscar(string codigo);
        void mostrar(Centro* c);
        void mostrar_todos();
        int hash(string c, int cant_espacios);
        void resize_tabla();
        void array_null(Centro** &tab, int size);
        void agregar_todos(Centro** &new_tab, int nuevo_size);
        
        // Busca de a un elemento de la lista, ignorando x cantidad de entradas
        template <typename T>
        Centro* buscar_por(function<T(Centro*)> funcion, T atributo, int ignorar) {
            int i = 0;
            int cant_ignorar = 0;
            Centro* elemento = nullptr;
            while(elemento == nullptr && i < size) {
                if(tabla[i] != nullptr && atributo == funcion(tabla[i])) {
                    if(cant_ignorar < ignorar) {
                        cant_ignorar++;
                    } else {
                        elemento = tabla[i];
                    }
                    
                }
                i++;
            }

            return elemento;
        };

        // Imprime por pantalla la lista ordenada por un atributo pasado por parámetro.
        template <typename T>
        void mostrar_lista_ordenada(function<T(Centro*)> funcion) {
            T elem_anterior;
            int ignorar = 0;
            T* nueva_tabla = this->convertir_tabla<T>([&funcion](Centro* c)-> T {
                return funcion(c);
            });
            mergesort(nueva_tabla, cant_elem);

            for (size_t i = 0; i < cant_elem; i++)
            {
                if(elem_anterior == nueva_tabla[i]) {
                    ignorar++;
                } else {
                    ignorar = 0;
                };
                this->mostrar(
                    this->buscar_por<T>(funcion, nueva_tabla[i], ignorar)
                );
                cout << endl;
                elem_anterior = nueva_tabla[i];
            };
        };

        // Similar a función map, convierte la tabla a una lista con una transformación aplicada.
        template <typename T>
        T* convertir_tabla(function<T(Centro*)> funcion) {
            T* tabla_nueva = new T[cant_elem];
            int index_nuevo = 0;
            for (size_t i = 0; i < size; i++)
            {
                if(tabla[i] != nullptr && tabla[i] != CentroEliminado::getInstance()) {
                    tabla_nueva[index_nuevo] = funcion(tabla[i]);
                    index_nuevo++;
                }
            }
            return tabla_nueva;
        };

        // Mergesort, ordena el array transformado
        template <typename T>
        void mergesort(T* &arr, int a_size) {
            if(a_size > 1) {
                int medio = a_size/2;
                T* izq = subarreglo(arr, 0, medio-1);
                T* der = subarreglo(arr, medio, a_size-1);
                mergesort(izq, medio);
                mergesort(der, a_size-medio);
                mezclar(arr, a_size, izq, medio, der, a_size-medio);
                delete[] izq;
                delete[] der;
            }
        };

        // Mezcla los arrays ordenándolos
        template <typename T>
        void mezclar(T* &arr, int a_size, T* &izq, int i_size, T* &der, int d_size){
            int i=0, j=0;
            for (size_t k = 0; k < a_size; k++)
            {
                if(i == i_size) { 
                    arr[k] = der[j++];
                } else if(j == d_size) {
                    arr[k] = izq[i++];
                } else if(izq[i] < der[j]) { 
                    arr[k] = izq[i++];
                } else {
                    arr[k] = der[j++];
                }
            } 
            
        };
        
        // Crea los subarreglos para el mergesort
        template <typename T>
        T* subarreglo(T* &arr, int inicio, int final) {
            T* subarreglo = new T[final-inicio+1];
            int nuevo_index = 0;
            for (size_t i = inicio; i <= final; i++)
            {
                subarreglo[nuevo_index] = arr[i];
                nuevo_index++;
            };    

            return subarreglo;
        };
};

#endif