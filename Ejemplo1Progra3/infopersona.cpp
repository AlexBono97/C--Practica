#include "infopersona.h"
#include <string.h>

Infopersona::Infopersona()
{
    strcpy(direccion, "");
    strcpy(ciudad, "");
    strcpy(provincia, "");

}
//Funciones Set
void Infopersona::setDireccion(const char * c)
{
    strcpy(direccion, c);
}

void Infopersona::setCiudad(const char * c)
{
    strcpy(ciudad, c);
}

void Infopersona::setProvincia(const char * c)
{
    strcpy(provincia, c);
}

void Infopersona::setCdPostal(long int c)
{
    codigo_postal = c;
}

//Funciones SET

char * Infopersona::getDireccion()
{
    return direccion;
}

char * Infopersona::getCiudad()
{
    return ciudad;
}

char * Infopersona::getProvincia()
{
    return provincia;
}

long int Infopersona::getCdPostal()
{
    return codigo_postal;
}

Infopersona::~Infopersona()
{
    //dtor
}
