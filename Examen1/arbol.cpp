#include "arbol.h"

Arbol::Arbol()
{
    //ctor
}

Arbol::Arbol(int a)
{
    altura =a;
}

void Arbol::setSiguiente(Arbol * s)
{
    sig=s;
}

Arbol * Arbol::getSiguiente()
{
    return sig;
}

void Arbol::setAltura(int a)
{
    altura=a;
}

int Arbol::getAltura()
{
    return altura;
}

Arbol::~Arbol()
{
    //dtor
}
