#include "InfoPersona.h"

InfoPersona::InfoPersona()
{
    //ctor
}

void InfoPersona::setDireccion(const char* direccion)
{
    strcpy(this->direccion,direccion);
}

void InfoPersona::setCiudad(const char* ciudad)
{
    strcpy(this->ciudad,ciudad);
}

void InfoPersona::setProvincia(const char* provincia)
{
    strcpy(this->provincia,provincia);
}

void InfoPersona::setCodigoPostal(const long int codigo)
{
    this->codigo_postal=codigo;
}

char* InfoPersona::getDirecion()
{
    return direccion;
}

char* InfoPersona::getCiudad()
{
    return ciudad;
}

char* InfoPersona::getProvincia()
{
    return provincia;
}

long int InfoPersona::getCodigoPostal()
{
    return codigo_postal;
}


InfoPersona::~InfoPersona()
{
    //dtor
}
