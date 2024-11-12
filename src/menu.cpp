#include "menu.h"
#include "centro.h"
#include "../src/estructuras/tabla-hash.h"
#include <string>

Menu::Menu()
{
    cargarCentros();
    cargarProyectos();
}

void Menu::mostrarMenuPrincipal()
{
    int opcion;
    cout << "Gestion de centros de investigacion" << endl;
    cout << "1 - Ver Centros" << "\n"
         << "2 - Ver Proyectos" << "\n"
         << "3 - Cerrar aplicacion" << endl;
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
    case 3:
        cerrarMenu();
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
         << "4 - Ver todos los centros " << "\n"
         << "5- Volver al menu anterior " << endl;

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
        cout << "verTodosLosCentros()" << endl;
        break;
    case 5:
        cout << "Volviendo al menu anterior" << endl;
        break;
    default:
        break;
    }
}

void Menu::cerrarMenu()
{
    delete proyectos;
    delete[] centros;
    exit(0);
}

void Menu::cargarCentros()
{
    TablaHash *centros = new TablaHash();
    string centroTexto;
    ifstream archivo("centros.txt");
    while (getline(archivo, centroTexto))
    {
        string datosCentro[10];
        stringstream ssCentro(centroTexto);
        string temp;
        int i = 0;
        while (getline(ssCentro, temp, ' '))
        {
            datosCentro[i] = temp;
            i++;
        }
        Centro *c = new Centro();
        c->codigo = datosCentro[0];
        if (c->codigo != "")
        {
            c->nombre = datosCentro[1] + " " + datosCentro[2] + " " + datosCentro[3] + " " + datosCentro[4];
            c->pais = datosCentro[5];
            c->superficie = stof(datosCentro[6]);
            c->cant_laboratorios = stoi(datosCentro[7]);
            c->cant_p_nacionales = stoi(datosCentro[8]);
            c->cant_p_internacionales = stoi(datosCentro[9]);
            centros->agregar(c);
        }
    }
    archivo.close();
    centros->mostrar_todos();
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
    string opcion;
    cout << "Consultar centro" << endl;
    cout << "Ingrese el codigo del centro a buscar: ";
    cin >> opcion;
    Centro* centro_buscado = centros->buscar(opcion);
    if(centro_buscado == nullptr) {
        cout << "El centro no esta guardado.";
    } else {
        centros->mostrar(centro_buscado);
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
    Centro* centro_a_eliminar = centros->buscar(opcion);
    centros->eliminar(centro_a_eliminar);
    cout << "Centro eliminado correctamente" << endl;;
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

    centros->agregar(nuevoCentro);
    centros->mostrar(centros->buscar(nuevoCentro->codigo));

    cout << "\n" << "Centro agregado correctamente" << endl;
}

void Menu::verTodosLosCentros(){
    centros->mostrar_todos();
    int opcion;
    cout << "Ordenar por: " << endl;
    cout << "1 - Codigo" << "\n"
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
        centros->mostrar_lista_ordenada<string>([](Centro* c) {
            return c->codigo;
        });
        break;
    case 2:
        centros->mostrar_lista_ordenada<string>([](Centro* c) -> string {
            return c->nombre;
        });
        break;
    case 3:
        centros->mostrar_lista_ordenada<string>([](Centro* c) -> string {
            return c->pais;
        });
        break;
    case 4:
        centros->mostrar_lista_ordenada<float>([](Centro* c) -> float {
            return c->superficie;
        });
        break;
    case 5:
        centros->mostrar_lista_ordenada<int>([](Centro* c) -> int {
            return c->cant_laboratorios;
        });
        break;
    case 6:
        centros->mostrar_lista_ordenada<int>([](Centro* c) -> int {
            return c->cant_p_nacionales;
        });
        break;
    case 7:
        centros->mostrar_lista_ordenada<int>([](Centro* c) -> int {
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
    cout << "1 - Ver todas las colaboraciones" << "\n"
         << "2 - Buscar colaboracion mas economica" << "\n"
         << "3 - Buscar colaboracion mas rapida" << "\n"
         << "4 - Volver al menu anterior" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        verColaboraciones();
        break;
    case 2:
        buscarMasEconomico();
        break;
    case 3:
        buscarMasRapido();
        break;
    case 4:
        cout << "Volviendo al menu anterior" << endl;
        break;
    default:
        cout << "Opcion incorrecta " << endl;
        break;
    }
}

void Menu::verColaboraciones()
{
    proyectos->mostrarListaAdyacencia();
}

void Menu::buscarMasEconomico()
{
    string codigoOrigen, codigoDestino;
    cout << "Ingrese el codigo de origen del centro: " << endl;
    cin >> codigoOrigen;
    cout << "Ingrese el codigo de destino del centro: " << endl;
    cin >> codigoDestino;
    proyectos->caminoMasCorto(codigoOrigen, codigoDestino, "costo");
}

void Menu::buscarMasRapido()
{
    string codigoOrigen, codigoDestino;
    cout << "Ingrese el codigo de origen del centro: " << endl;
    cin >> codigoOrigen;
    cout << "Ingrese el codigo de destino del centro: " << endl;
    cin >> codigoDestino;
    proyectos->caminoMasCorto(codigoOrigen, codigoDestino, "tiempo");
}

void Menu::cargarProyectos()
{
    string *codigos = new string[1];
    int cantidadVertices = 0;
    string proyectoTexto;
    ifstream archivo("proyectos.txt");
    int vuelta = 1;
    // Obtenemos la cantidad de vertices que tendra el grafo. Tenemos que contar los codigos (Sin contar los repetidos)
    while (getline(archivo, proyectoTexto))
    {
        stringstream codigo;
        codigo << proyectoTexto[0] << proyectoTexto[1] << proyectoTexto[2];
        string codigoOrigen = codigo.str();
        codigo.str("");
        codigo << proyectoTexto[4] << proyectoTexto[5] << proyectoTexto[6];
        string codigoDestino = codigo.str();
        // Crea un nuevo arreglo que tendra el tamaño necesario para guardar los nuevos codigos encontrados
        if (cantidadVertices == 0)
        {
            codigos[0] = codigoOrigen;
            cantidadVertices++;
        };
        bool origenCargado = false;
        bool destinoCargado = false;
        // Busca si los codigos ya estan cargados
        for (int i = 0; i < cantidadVertices; i++)
        {
            if (codigos[i] == codigoOrigen)
                origenCargado = true;
            if (codigos[i] == codigoDestino)
                destinoCargado = true;
        }

        // Si algun codigo no esta cargado, redimension el arreglo y los carga
        if (!origenCargado || !destinoCargado)
        {
            // Crea un nuevo arreglo agregando los codigos que se usaran como vertices del grafo
            string *nuevosCodigos = new string[cantidadVertices + !origenCargado + !destinoCargado];
            // Copia el arreglo actual al nuevo
            for (int i = 0; i < cantidadVertices; i++)
            {
                nuevosCodigos[i] = codigos[i];
            }
            if (!origenCargado && !destinoCargado)
            {
                nuevosCodigos[cantidadVertices] = codigoOrigen;
                nuevosCodigos[cantidadVertices + 1] = codigoDestino;
                cantidadVertices += 2;
            }
            else
            {
                if (!origenCargado)
                {
                    nuevosCodigos[cantidadVertices] = codigoOrigen;
                    cantidadVertices++;
                }
                if (!destinoCargado)
                {
                    nuevosCodigos[cantidadVertices + !origenCargado] = codigoDestino;
                    cantidadVertices++;
                }
            }
            vuelta++;

            delete[] codigos;
            codigos = nuevosCodigos;
        }
    }
    archivo.close();
    // Creamos el grafo con la cantidad de nodos y cargamos las aristas
    proyectos = new DigrafoPonderado(cantidadVertices);
    string proyectoTexto2;
    ifstream archivo2("proyectos.txt");
    int verticesAgregados = 0;
    while (getline(archivo2, proyectoTexto2))
    {
        string datos[4];
        stringstream ss(proyectoTexto2);
        string temp;
        int i = 0;
        while (getline(ss, temp, ' '))
        {
            datos[i] = temp;
            i++;
        }

        if (proyectos->sePuedeAgregarElCodigo(datos[0]))
        {
            proyectos->asignarCodigoAVertice(verticesAgregados, datos[0]);
            verticesAgregados++;
        }

        if (proyectos->sePuedeAgregarElCodigo(datos[1]))
        {
            proyectos->asignarCodigoAVertice(verticesAgregados, datos[1]);
            verticesAgregados++;
        }

        proyectos->agregarArista(datos[0], datos[1], stoi(datos[2]), stof(datos[3])); // (origen, destino, costo, tiempo)
    }
}
