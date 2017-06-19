#include "cliente.h"
#include <string.h>

cliente::cliente()
{
    strcpy(nombre_cliente, "");

}
//Funciones SET
void cliente::setNombre_cliente(const char * c)
{
    strcpy(nombre_cliente, c);
}

void cliente::setSaldo(double c)
{
    saldo=c;
}

void cliente::setDireccion_cliente(const char * c)
{
    cliente1.setDireccion(c);
}

void cliente::setCiudad_cliente(const char * c)
{
    cliente1.setCiudad(c);
}

void cliente::setProvincia_cliente(const char * c)
{
    cliente1.setProvincia(c);
}

void cliente::setCdPostal_cliente(long int c)
{
    cliente1.setCdPostal(c);
}
//Funciones GET
char * cliente::getNombre_cliente()
{
    return nombre_cliente;
}

char * cliente::getDireccion_cliente()
{
    return cliente1.getDireccion();
}

char * cliente::getCiudad_cliente()
{
    return cliente1.getCiudad();
}

char * cliente::getProvincia_cliente()
{
    return cliente1.getProvincia();
}

long int cliente::getCdPostal_cliente()
{
    return cliente1.getCdPostal();
}

double cliente::getSaldo()
{
    return saldo;
}


