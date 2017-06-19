#include "paquetenocturno.h"
#include "paquete.h"
#include <string>

paquetenocturno::paquetenocturno()
{
    //ctor
}

paquetenocturno::~paquetenocturno()
{

}

paquetenocturno::paquetenocturno(int cobron,string n, string dir, string ciu, string esta, long cd, int pe, int costo):paquete()
{
    cobronocturno=cobron;
    nombre=n;
    direccion=dir;
    ciudad=ciu;
    estado=esta;
    codigopostal=cd;
    if(pe>0)
    {
        peso=pe;
    }
    else
    {
        peso=0;
    }
    if(costo>0)
    {
        costoporonza=costo;
    }
    else
    {
        costoporonza=0;
    }

    //ctor
}

double paquetenocturno::calcularcostonocturno()
{
    return cobronocturno+paquete::calcularCosto();
}
