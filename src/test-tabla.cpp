// #include "estructuras/tabla-hash.h"
// #include "estructuras/tabla-hash.cpp"
// #include <iostream>
// using namespace std;


// CentroEliminado* CentroEliminado::instance = nullptr;

// int main() {
//     CentroEliminado* centro1 = CentroEliminado::getInstance();
    
//     TablaHash* tabla = new TablaHash();

//     Centro* cent = new Centro();
//     Centro* cent2 = new Centro();
//     Centro* cent3 = new Centro();
//     Centro* cent4 = new Centro();
//     Centro* cent5 = new Centro();
//     Centro* cent6 = new Centro();

//     cent->codigo = "ABC";
//     cent->nombre = "Centro ABC";
//     cent->pais = "Argentina";
//     cent->superficie = 3000;
//     cent->cant_laboratorios = 3;
//     cent->cant_p_nacionales = 7;
//     cent->cant_p_internacionales = 2;
//     cent2->codigo = "ZYD";
//     cent2->nombre = "Centro ZYD";
//     cent2->pais = "Brasil";
//     cent2->superficie = 5000;
//     cent2->cant_laboratorios = 8;
//     cent2->cant_p_nacionales = 9;
//     cent2->cant_p_internacionales = 2;
//     cent3->codigo = "XDR";
//     cent3->nombre = "Centro XDR";
//     cent3->pais = "EEUU";
//     cent3->superficie = 2500;
//     cent3->cant_laboratorios = 4;
//     cent3->cant_p_nacionales = 5;
//     cent3->cant_p_internacionales = 12;
//     cent4->codigo = "DJS";
//     cent4->nombre = "Centro DJS";
//     cent4->pais = "Argentina";
//     cent4->superficie = 2500;
//     cent4->cant_laboratorios = 12;
//     cent4->cant_p_nacionales = 12;
//     cent4->cant_p_internacionales = 3;
//     cent5->codigo = "EPS";
//     cent5->nombre = "Centro EPS";
//     cent5->pais = "Brasil";
//     cent5->superficie = 1500;
//     cent5->cant_laboratorios = 1;
//     cent5->cant_p_nacionales = 7;
//     cent5->cant_p_internacionales = 7;
//     cent6->codigo = "MCK";
//     cent6->nombre = "Centro MCK";
//     cent6->pais = "Argentina";
//     cent6->superficie = 2900;
//     cent6->cant_laboratorios = 4;
//     cent6->cant_p_nacionales = 4;
//     cent6->cant_p_internacionales = 10;
    
//     tabla->agregar(cent);
//     tabla->agregar(cent2);
//     tabla->agregar(cent3);
//     tabla->agregar(cent4);
//     tabla->agregar(cent5);
//     tabla->agregar(cent6);
// // /* 
// //     for (size_t i = 0; i < 1; i++)
// //     {
        
// //         // if(tabla->mostrar(i) == "") {
// //         //     cout << "Null" << endl;
// //         // } else {
// //         //     tabla->mostrar(i);
// //         // }
// //     } */
    
// //     tabla->mostrar_todos();
// //     cout << "---------" << endl;

// //     // cout << tabla->buscar_por<int>([](Centro* c) -> int {
// //     //     return c->cant_laboratorios;
// //     // }, 3)->codigo;
    
//     // int* nuevos_centros = tabla->ordenar_por<int>([](Centro* c) -> int {
//     //     return c->cant_laboratorios;
//     // });



//     // for (size_t i = 0; i < 6; i++)
//     // {
//     //     cout << tabla->buscar_por<int>([](Centro* c) -> int {
//     //         return c->cant_laboratorios;
//     //     }, nuevos_centros[i], 0)->codigo
//     //     << ": " << nuevos_centros[i] << endl;
//     // }

// //     // return 0;

    // tabla->mostrar_lista_ordenada<string>([](Centro* c) -> string {
    //     return c->codigo;
    // });
//     cout << "-----------------" << endl;
//     tabla->mostrar_lista_ordenada<string>([](Centro* c) -> string {
//         return c->nombre;
//     });
//     cout << "-----------------" << endl;
//     tabla->mostrar_lista_ordenada<string>([](Centro* c) -> string {
//         return c->pais;
//     });
//     cout << "-----------------" << endl;
//     tabla->mostrar_lista_ordenada<float>([](Centro* c) -> float {
//         return c->superficie;
//     });
//     cout << "-----------------" << endl;
//     tabla->mostrar_lista_ordenada<int>([](Centro* c) -> int {
//         return c->cant_laboratorios;
//     });
//     cout << "-----------------" << endl;
//     tabla->mostrar_lista_ordenada<int>([](Centro* c) -> int {
//         return c->cant_p_nacionales;
//     });
//     cout << "-----------------" << endl;
//     tabla->mostrar_lista_ordenada<int>([](Centro* c) -> int {
//         return c->cant_p_internacionales;
//     });
//     cout << "-----------------" << endl;
// }