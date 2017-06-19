#include "cedro.h"

Cedro::Cedro()
{
    //ctor
}

Cedro::Cedro(int altura, int grosor): Arbol()
{
    setAltura(altura);
    setGrosor(grosor);
}

void Cedro::setAltura(int a)
{
    Arbol::setAltura(a);
}

int Cedro::getAltura()
{
     return Arbol::getAltura();
}

void Cedro::setGrosor(int g)
{
    grosor=g;
}

int Cedro::getGrosor()
{
    return grosor;
}

int Cedro::getValor()
{
   int valor= Cedro::getGrosor() * Cedro::getAltura();
   return valor;
}
Cedro::~Cedro()
{
    //dtor
}
