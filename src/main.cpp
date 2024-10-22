// Your First C++ Program
#include <iostream>
#include "lista.cpp"
using namespace std;

int main() {
    Lista* numeros = new Lista();
    Lista* impares = new Lista();
    numeros->agregar(20, 1);
    numeros->agregar(10, 2);
    numeros->agregar(2, 3);
    numeros->agregar(3, 4);
    numeros->mostrar();

    numeros->mostrar();

    return 0;
}