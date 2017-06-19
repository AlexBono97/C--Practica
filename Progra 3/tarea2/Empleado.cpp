#include "Empleado.h"

Empleado::Empleado()
{
    //ctor
}
void Empleado::setNombre(const char* nombre)
{
    strcpy(nombre_empleado,nombre);
}

void Empleado::setDireccion(const char* direccion)
{
    strcpy(this->direccion,direccion);
}

void Empleado::setCiudad(const char* ciudad)
{
    strcpy(this->ciudad,ciudad);

}

void Empleado::setProvincia(const char* provincia)
{
    strcpy(this->provincia,provincia);
}

void Empleado::setCodigoPostal(const long int codigo)
{
    this->codigo_postal=codigo;
}

void Empleado::setSalario(const double salario)
{
    this->salario=salario;
}

char* Empleado::getNombre()
{
    return nombre_empleado;
}

char* Empleado::getDirecion()
{
    return direccion;
}

char* Empleado::getCiudad()
{
    return ciudad;
}

char* Empleado::getProvincia()
{
    return provincia;
}

long int Empleado::getCodigoPostal()
{
    return codigo_postal;
}

double Empleado::getSalario()
{
    return salario;
}

Empleado::~Empleado()
{
    //dtor
}
