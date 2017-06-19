#include "Pino.h"

Pino::Pino() : Arbol(0)
{
    edad=0;
}
Pino::Pino(int h, int e) : Arbol(h)
{
    edad=e;
}

int Pino::getEdad()
{
    return edad;
}
int Pino::getValor()
{
    return getAltura()*edad;
}

void Pino::setEdad(int e)
{
    edad=e;
}


