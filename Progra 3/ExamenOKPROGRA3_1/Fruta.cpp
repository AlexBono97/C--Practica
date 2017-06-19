#include "Fruta.h"

Fruta::Fruta()
{
    //ctor
}
Fruta::Fruta(int w, int m)
{
    peso=w;
    tamano=w;
    siguiente=0; //ESTO ME FALTABA :/
}
void Fruta::setPeso(int w)
{
    peso=w;
}
void Fruta::setTamano(int t)
{
    tamano=t;
}
void Fruta::setSig(Fruta*sg)
{
    siguiente=sg;
}
int Fruta::getPeso()
{
    return peso;
}
int Fruta::getTamano()
{
    return tamano;
}
Fruta* Fruta::getSig()
{
    return siguiente;
}

