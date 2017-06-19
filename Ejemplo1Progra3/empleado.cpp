#include "empleado.h"
#include <string.h>

Empleado::Empleado()
{
    strcpy(nombre_empleado, "");

}

//Funciones SET
void Empleado::setNombre_empleado(const char * c)
{
    strcpy(nombre_empleado, c);
}

void Empleado::setSalario(double c)
{
    salario=c;
}

void Empleado::setDireccion_empleado(const char * c)
{
    empleado1.setDireccion(c);
}

void Empleado::setCiudad_empleado(const char * c)
{
    empleado1.setCiudad(c);
}

void Empleado::setProvincia_empleado(const char * c)
{
    empleado1.setProvincia(c);
}

void Empleado::setCdPostal_empleado(long int c)
{
    empleado1.setCdPostal(c);
}
//Funciones GET
char * Empleado::getNombre_empleado()
{
    return nombre_empleado;
}

char * Empleado::getDireccion_empleado()
{
    return empleado1.getDireccion();
}

char * Empleado::getCiudad_empleado()
{
    return empleado1.getCiudad();
}

char * Empleado::getProvincia_empleado()
{
    return empleado1.getProvincia();
}

long int Empleado::getCdPostal_empleado()
{
    return empleado1.getCdPostal();
}

double Empleado::getSalario()
{
    return salario;
}

Empleado::~Empleado()
{
    //dtor
}
