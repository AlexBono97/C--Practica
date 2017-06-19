#include "Cedro.h"

Cedro::Cedro() : Arbol(0) //Tomo la altura que me manda mi papá
{
    grosor=0;
}
Cedro::Cedro(int h, int g) : Arbol(h)
{
    grosor=g;
}
int Cedro::getGrosor()
{
    return grosor;
}
int Cedro::getValor()
{
    return getAltura()*grosor;
}
void Cedro::setGrosor(int g)
{
    grosor=g;
}
