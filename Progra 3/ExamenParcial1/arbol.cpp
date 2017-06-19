#include "arbol.h"

Arbol::Arbol()
{
    //ctor
}

void Arbol::setSiguiente(Arbol * s)
{
    sig=s;
}

Arbol * Arbol::getSiguiente()
{
    return sig;
}

Arbol::~Arbol()
{
    //dtor
}
