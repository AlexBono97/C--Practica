#include "aguacate.h"
#include "fruta.h"

Aguacate::Aguacate()
{
    //ctor
}

Aguacate::Aguacate(int altura) : Arbol()
{
    setAltura(altura);
}

void Aguacate::setAltura(int a)
{
    Arbol::setAltura(a);
}

int Aguacate::getAltura()
{
    return Arbol::getAltura();
}

int Aguacate::getValor()//aun no terminada
{
    return Aguacate::getAltura();
}

Aguacate::~Aguacate()
{
    //dtor
}
