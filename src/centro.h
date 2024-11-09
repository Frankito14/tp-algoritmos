#ifndef CENTRO_H
#define CENTRO_H
using namespace std;
#include <string>

typedef struct
    {
        string codigo;
        string nombre;
        string pais;
        float superficie;
        int cant_laboratorios;
        int cant_p_nacionales;
        int cant_p_internacionales;
    } Centro;

#endif //CENTRO_H