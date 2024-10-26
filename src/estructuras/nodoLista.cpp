#include "nodoLista.h"

NodoLista::NodoLista(Dato d)
{
    dato = d;
    siguiente = 0;
}

void NodoLista::cambiar_dato(Dato d)
{
    dato = d;
}

void NodoLista::cambiar_siguiente(NodoLista* s)
{
    siguiente = s;
}

Dato NodoLista::obtener_dato()
{
    return dato;
}

NodoLista* NodoLista::obtener_siguiente()
{
    return siguiente;
}
