#include "paquetedosdias.h"
#include "paquete.h"

paquetedosdias::paquetedosdias()
{
    //ctor
}

paquetedosdias::~paquetedosdias()
{
    //dtor
}

paquetedosdias::paquetedosdias(int c, string nom, string dir, string ciu, string esta, long cd, int pe, int costo) : paquete()
{
    cobrodosdias=c;
    nombre=nom;
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

}

double paquetedosdias::calcularCostodosdias()
{
    return cobrodosdias+paquete::calcularCosto();
}

