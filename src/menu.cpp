#include "menu.h"
#include "centro.h"
#include <string>

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
        consultarCentro();
        break;
    case 2:
        agregarCentro();
        break;
    case 3:
        eliminarCentro();
        break;
    case 4:
        cout << "verTodosLosCentros()" <<endl;
        break;
    default:
        break;
    }
}

void Menu::mostrarCentro(Centro c)
{
    cout << c.codigo << " - "
         << c.nombre << " - "
         << c.pais << " - "
         << c.superficie << " - "
         << c.cant_laboratorios << " - "
         << c.cant_p_nacionales << " - "
         << c.cant_p_internacionales << endl;
}

void Menu::consultarCentro()
{
    int opcion;
    cout << "Consultar centro" << endl;
    cout << "Ingrese el codigo del centro a buscar: ";
    cin >> opcion;
    // Buscar centro
    cout << "<Datos del centro>" << endl;
}

void Menu::eliminarCentro()
{
    int opcion;
    cout << "Eliminar centro" << endl;
    cout << "Ingrese el codigo del centro a eliminar: ";
    cin >> opcion;
    // Buscar centro
    // Borrar centro
    cout << "Centro eliminado correctamente" << endl;
}

void Menu::agregarCentro()
{
    Centro nuevoCentro;
    string opcionString;
    float opcionFloat;
    int opcionInt;
    cout << "Agregar centro" << endl;
    cout << "Ingrese el codigo del nuevo centro: " << endl;
    cin >> opcionString;
    nuevoCentro.codigo = opcionString;
    cout << "Ingrese el nombre del nuevo centro (4 palabras): " << endl;
    cin >> opcionString;
    nuevoCentro.nombre = opcionString;
    cout << "Ingrese el país del nuevo centro: " << endl;
    cin >> opcionString;
    nuevoCentro.pais = opcionString;
    cout << "Ingrese la superficie del nuevo centro: " << endl;
    cin >> opcionFloat;
    nuevoCentro.superficie = opcionFloat;
    cout << "Ingrese la cantidad de laboratorios del nuevo centro: " << endl;
    cin >> opcionInt;
    nuevoCentro.cant_laboratorios = opcionInt;
    cout << "Ingrese la cantidad de proyectos nacionales del nuevo centro: " << endl;
    cin >> opcionInt;
    nuevoCentro.cant_p_nacionales = opcionInt;
    cout << "Ingrese la cantidad de proyectos internacionales del nuevo centro: " << endl;
    cin >> opcionInt;
    nuevoCentro.cant_p_internacionales = opcionInt;
    // Guardar centro
    mostrarCentro(nuevoCentro);
    cout << "Centro agregado correctamente" << endl;
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
