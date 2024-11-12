#include "menu.h"
#include "centro.h"
#include "../src/estructuras/tabla-hash.h"
#include <string>

Menu::Menu(TablaHash* tabla) : _tabla(tabla){}

void Menu::mostrarMenuPrincipal()
{
    int opcion;
    cout << "Gestion de centros de investigacion" << endl;
    cout << "1 - Ver Centros" << "\n"
         << "2 - Ver Proyectos" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        mostrarMenuCentros();
        break;
    case 2:
        mostrarMenuProyectos();
        break;
    default:
        cout << "Opción incorrecta " << endl;
        break;
    }
}

void Menu::mostrarMenuCentros()
{
    int opcion;
    cout << "Centros de investigacion" << endl;
    cout << "1 - Consultar centro" << "\n"
         << "2 - Agregar centro" << "\n"
         << "3 - Eliminar centro " << "\n"
         << "4 - Ver todos los centros " << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        consultarCentro();
        break;
    case 2:
        agregarCentro();
        break;
    case 3:
        eliminarCentro();
        break;
    case 4:
        verTodosLosCentros();
        break;
    default:
        break;
    }
}

void Menu::consultarCentro()
{
    string opcion;
    cout << "Consultar centro" << endl;
    cout << "Ingrese el codigo del centro a buscar: ";
    cin >> opcion;
    Centro* centro_buscado = _tabla->buscar(opcion);
    if(centro_buscado == nullptr) {
        cout << "El centro no esta guardado.";
    } else {
        _tabla->mostrar(centro_buscado);
    }
    delete centro_buscado;
    cout << endl;
}

void Menu::eliminarCentro()
{
    string opcion;
    cout << "Eliminar centro" << endl;
    cout << "Ingrese el codigo del centro a eliminar: ";
    cin >> opcion;
    Centro* centro_a_eliminar = _tabla->buscar(opcion);
    _tabla->eliminar(centro_a_eliminar);
    cout << "Centro eliminado correctamente" << endl;
}

void Menu::agregarCentro()
{
    Centro* nuevoCentro = new Centro();
    string opcionCodigo, opcionNombre, opcionPais;
    float opcionFloat;
    int opcionInt;
    cout << "Agregar centro" << endl;
    cout << "Ingrese el codigo del nuevo centro: " << endl;
    cin >> opcionCodigo;
    cin.ignore();
    nuevoCentro->codigo = opcionCodigo;
    cout << "Ingrese el nombre del nuevo centro (4 palabras): " << endl;
    getline(cin, opcionNombre);
    nuevoCentro->nombre = opcionNombre;
    cout << "Ingrese el país del nuevo centro: " << endl;
    cin >> opcionPais;
    nuevoCentro->pais = opcionPais;
    cout << "Ingrese la superficie del nuevo centro: " << endl;
    cin >> opcionFloat;
    nuevoCentro->superficie = opcionFloat;
    cout << "Ingrese la cantidad de laboratorios del nuevo centro: " << endl;
    cin >> opcionInt;
    nuevoCentro->cant_laboratorios = opcionInt;
    cout << "Ingrese la cantidad de proyectos nacionales del nuevo centro: " << endl;
    cin >> opcionInt;
    nuevoCentro->cant_p_nacionales = opcionInt;
    cout << "Ingrese la cantidad de proyectos internacionales del nuevo centro: " << endl;
    cin >> opcionInt;
    nuevoCentro->cant_p_internacionales = opcionInt;

    _tabla->agregar(nuevoCentro);
    _tabla->mostrar(_tabla->buscar(nuevoCentro->codigo));

    cout << "\n" << "Centro agregado correctamente" << endl;
}

void Menu::verTodosLosCentros()
{
    _tabla->mostrar_todos();

    int opcion;
    cout << "Ordenar por: " << endl;
    cout << "1 - Código" << "\n"
         << "2 - Nombre" << "\n"
         << "3 - Pais" << "\n"
         << "4 - Superficie" << "\n"
         << "5 - Cantidad de laboratorios" << "\n"
         << "6 - Cantidad de proyectos nacionales" << "\n"
         << "7 - Cantidad de proyectos internacionales" << "\n"
         << "Otro: salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        _tabla->mostrar_lista_ordenada<string>([](Centro* c) {
            return c->codigo;
        });
        break;
    case 2:
        _tabla->mostrar_lista_ordenada<string>([](Centro* c) -> string {
            return c->nombre;
        });
        break;
    case 3:
        _tabla->mostrar_lista_ordenada<string>([](Centro* c) -> string {
            return c->pais;
        });
        break;
    case 4:
        _tabla->mostrar_lista_ordenada<float>([](Centro* c) -> float {
            return c->superficie;
        });
        break;
    case 5:
        _tabla->mostrar_lista_ordenada<int>([](Centro* c) -> int {
            return c->cant_laboratorios;
        });
        break;
    case 6:
        _tabla->mostrar_lista_ordenada<int>([](Centro* c) -> int {
            return c->cant_p_nacionales;
        });
        break;
    case 7:
        _tabla->mostrar_lista_ordenada<int>([](Centro* c) -> int {
            return c->cant_p_internacionales;
        });
        break;
    default:
        break;
    }
}

// Proyecto
void Menu::mostrarMenuProyectos()
{
    int opcion;
    cout << "Proyectos entre centros" << endl;
    cout << "1 - Buscar colaboración mas económica" << "\n"
         << "2 - Buscar colaboración mas rápida" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        cout << "buscarMasEconomico()" << endl;
        break;
    case 2:
        cout << "buscarMasRapido() " << endl;
        break;
    default:
        cout << "Opción incorrecta " << endl;
        break;
    }
}
