#include "paquete.h"

paquete::paquete()
{

    //ctor
}

paquete::paquete(string nom, string  dir, string ciu, string esta, long cd, int pes, int costo)
{
    nombre=nom;
    direccion=dir;
    ciudad=ciu;
    estado=esta;
    codigopostal=cd;
    if(pes>0)
    {
        peso=pes;
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
}

paquete::~paquete()
{
    //dtor
}

double paquete::calcularCosto()
{
    return costoporonza*peso;
}
