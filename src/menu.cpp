#include "menu.h"

Menu::Menu() {}

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
        cout << "consultarCentro()"<< endl;
        break;
    case 2:
        cout << "agregarCentro() "<< endl;
        break;
    case 3:
        cout << "eliminarCentro() "<< endl;
        break;
    case 4:
        cout << "verTodosCentros() "<< endl;
        break;
    default:
        cout << "Opción incorrecta ";
        break;
    }
}

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
        cout << "buscarMasEconomico()"<< endl;
        break;
    case 2:
        cout << "buscarMasRapido() "<< endl;
        break;
    default:
        cout << "Opción incorrecta " << endl;
        break;
    }
}
