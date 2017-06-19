#include "Cliente.h"

Cliente::Cliente()
{
    //ctor
}
void Cliente::setNombre(const char* nombre)
{
    strcpy(nombre_cliente,nombre);
}

void Cliente::setDireccion(const char* dir)
{
    strcpy(direccion,dir);
}

void Cliente::setCiudad(const char* ciu)
{
    strcpy(ciudad,ciu);
}

void Cliente::setProvincia(const char* prov)
{
    strcpy(provincia,prov);
}

void Cliente::setCodigoPostal(const long int codigo)
{
    codigo_postal=codigo;
}

void Cliente::setSaldo(const double sal)
{
    saldo=sal;
}

char* Cliente::getNombre()
{
    return nombre_cliente;
}

char* Cliente::getDirecion()
{
    return direccion;
}

char* Cliente::getCiudad()
{
    return ciudad;
}

char* Cliente::getProvincia()
{
    return provincia;
}

long int Cliente::getCodigoPostal()
{
    return codigo_postal;
}

double Cliente::getSaldo()
{
    return saldo;
}

Cliente::~Cliente()
{
    //dtor
}
