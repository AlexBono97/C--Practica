#include "Arbol.h"

Arbol::Arbol()
{
}
Arbol::Arbol(int a)
{
    Altura=a;
}
void Arbol::setAltura(int n)
{
    Altura=n;
}
int Arbol::getAltura()
{
    return Altura;
}
void Arbol::setSig(Arbol*n)
{
    siguiente=n;
}
Arbol* Arbol::getSig()
{
    return siguiente;
}

