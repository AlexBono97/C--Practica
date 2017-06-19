#include "pino.h"

Pino::Pino()
{
    edad=0;
    //ctor
}

Pino::~Pino()
{
    //dtor
}

Pino::Pino(int al, int ed):Arbol()
{
    setAltura(al);
    setEdad(ed);
}

void Pino::setAltura(int a)
{
    Arbol::setAltura(a);
}

int Pino::getAltura()
{
    return Arbol::getAltura();
}

void Pino::setEdad(int e)
{
    edad=e;
}

int Pino::getEdad()
{
    return edad;
}

int Pino::getValor()
{
    int valor= Pino::getAltura()*Pino::getEdad();
    return valor;
}
