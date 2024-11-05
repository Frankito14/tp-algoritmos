#include "estructuras/tabla-hash.h"
#include "estructuras/tabla-hash.cpp"
#include <iostream>
using namespace std;

int main() {
    TablaHash* tabla = new TablaHash();

    Centro cent, cent2;

    cent.codigo = "ABC";
    cent.nombre = "Centro ABC";
    cent2.codigo = "ZYD";
    cent2.nombre = "Centro ZYB";

    cout << tabla->hash(cent.codigo);
    cout << tabla->hash(cent2.codigo) << endl;
    tabla->agregar(cent);
    tabla->agregar(cent2);

    // cout << "Busqueda: " << tabla->buscar(cent.codigo).nombre << endl;
/* 
    cout << "Hash: " << tabla->hash("CBA") << endl;
    cout << "Hash: " << tabla->hash("CBB") << endl;
    cout << "Hash: " << tabla->hash("ABC") << endl;
    cout << "Hash: " << tabla->hash("BCC") << endl; 
*/
    for (size_t i = 0; i < 10; i++)
    {
        string mostrar = tabla->mostrar(i);
        if(mostrar != "") {
            cout << i << ": " << mostrar << endl;
        }
        /* if(tablaP[i] != nullptr) {
            cout << i << ": " << 0 << endl;
        } else {
            cout << i << ": " << tablaP[i] << endl;
        } */
        
    }



    return 0;
}