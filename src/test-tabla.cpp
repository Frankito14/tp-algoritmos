#include "estructuras/tabla-hash.h"
#include "estructuras/tabla-hash.cpp"
#include <iostream>
using namespace std;

int main() {
    TablaHash* tabla = new TablaHash();

    Centro* cent = new Centro();
    // Centro* cent2 = new Centro();

    cent->codigo = "ABC";
    cent->nombre = "Centro ABC";
    // cent2->codigo = "ZYD";
    // cent2->nombre = "Centro ZYB";

    cout << cent->codigo << endl;
    cout << cent->nombre << endl;

    

    cout << tabla->hash(cent->codigo) << endl;
    tabla->agregar(cent);
    cout << tabla->elem(9)->codigo << endl;
    tabla->eliminar(cent);
    cout << tabla->elem(9)->codigo << endl;
    

    return 0;
}