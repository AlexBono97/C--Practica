#include "nodo.h"

nodo::nodo()//Constructor Default
{
    setValor(0);
    setSig(0);
}



nodo::nodo(int v)//constructor 2
{
    setValor(v);
    setSig(0);

}

nodo::nodo(int v, nodo * s)//constructor 3
{
    setValor(v);
    setSig(s);

}
nodo::~nodo()
{
    //dtor
}

void nodo::setValor(int v)
{
    valor=v;
}

int nodo::getValor()
{
    return valor;
}

void nodo::setSig(nodo * s)
{
    sig = s;
}

nodo * nodo::getSig()
{
    return sig;
}

void nodo::setAnt(nodo * s)
{
    ant =s;
}

nodo * nodo::getAnt()
{
    return ant;
}

//probando




