#include "contacto.h"

contacto::contacto()
{
    //ctor
}

contacto::contacto(string nombre, int num, int opera)
{
    this->nombre=nombre;
    this->numContacto=num;
    this->operadorCel=opera;
}

void contacto::setSig(contacto *c)
{
    sig = c;
}

contacto * contacto::getSig()
{
    return sig;
}

int contacto::getnumero()
{
    return numContacto;
}

contacto::~contacto()
{
    //dtor
}
