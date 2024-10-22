#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

typedef int Dato;

class NodoLista
{
private:
    Dato dato;
    NodoLista* siguiente;

public:

    NodoLista(Dato d);

    void cambiar_dato(Dato d);

    void cambiar_siguiente(NodoLista* s);

    Dato obtener_dato();

    NodoLista* obtener_siguiente();

    
};

#endif // NODO_H_INCLUDED
