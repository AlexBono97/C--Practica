#include "nodo.h"

Nodo::Nodo(int val)
{
    this->valor=val;
    this->agregarAnt(0);
    this->agregarSig(0);
}

int Nodo::getVal()
{
    return valor;
}

void Nodo::agregarSig(Nodo *n)
{
    sig=n;
}

void Nodo::agregarAnt(Nodo *n)
{
    ant=n;
}

Nodo* Nodo::getSig()
{
    return sig;
}

Nodo* Nodo::getAnt()
{
    return ant;
}
