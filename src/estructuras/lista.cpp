#include "lista.h"
#include "nodoLista.cpp"

Lista::Lista()
{
    primero = 0;
    largo = 0;
}

bool Lista::estaVacia()
{
    return (largo == 0);
}

void Lista::agregar(Dato d, int pos)
{
    NodoLista* nuevo = new NodoLista(d);
    if (pos == 1)
    {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    }
    else
    {
        NodoLista* anterior = obtener_nodo(pos - 1);
        NodoLista* siguiente = anterior->obtener_siguiente();
        nuevo->cambiar_siguiente(siguiente);
        anterior->cambiar_siguiente(nuevo);
    }
    largo++;
}

void Lista::agregar_al_final(Dato d)
{
    NodoLista* nuevo = new NodoLista(d);
    if (primero == 0)
    {
        nuevo->cambiar_siguiente(primero);
        primero = nuevo;
    }
    else
    {
        NodoLista* anterior = obtener_nodo(largo - 1);
        anterior->cambiar_siguiente(nuevo);
    }
    largo++;
}

NodoLista* Lista::obtener_nodo(int pos)
{
    NodoLista* aux = primero;
    for(int i = 1; i < pos; i++)
        aux = aux->obtener_siguiente();
    return aux;
}

Dato Lista::consultar(int pos)
{
    NodoLista* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

void Lista::eliminar(int pos)
{
    NodoLista* borrar;
    if (pos == 1)
    {
        borrar = primero;
        primero = borrar->obtener_siguiente();
    }
    else
    {
        NodoLista* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        NodoLista* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);
    }
    delete borrar;
    largo--;
}


Lista::~Lista()
{
    while (! estaVacia())
        eliminar(1);
}

int Lista::obtener_largo()
{
    return largo;
}

void Lista::mostrar()
{
      cout<<"[";

      if(!estaVacia())
      {
          for (int i = 1; i < largo; i++)
            cout<<this->consultar(i)<<",";
        cout<<this->consultar(largo);
      }

      cout<<"]"<<endl;
}



