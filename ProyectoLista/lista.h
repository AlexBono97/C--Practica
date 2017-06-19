#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"

class Lista
{
public:
    Lista();
    void agregarNodo(Nodo* n);
    void removerNodo();
    Nodo* buscarNodo();
    Nodo* nodoMayor();
    Nodo* nodoMenor();
    Nodo* ultimoNodo();
    int cantNodos();
    int sumaNodos();
    double promedioNodos();
    Nodo* inicial;
private:


};

#endif // LISTA_H
