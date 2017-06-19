#include "ultimallamada.h"
#include "contacto.h"
#include "agenda.h"
ultimallamada::ultimallamada()
{
    contactollamado=0;
    siguienteUltimaLlamada=0;
    //ctor
}

ultimallamada::ultimallamada(contacto * c, ultimallamada * sig)
{
    contactollamado=c;
    siguienteUltimaLlamada = 0;

}

void ultimallamada::add(ultimallamada * n)
{
    agenda * g;

    if(cantLlamadas==0)
    {
        head=n;
        cantLlamadas=1;
    }
    else if(cantLlamadas==1)
    {
        head->setSig(n);
        cantLlamadas++;
    }else
    {
        ultimallamada * temp1=head;
        ultimallamada * temp2=temp1->getSig();
        while(temp1!=0)
        {
            if(temp2==0)
            {
                cantLlamadas++;
                temp1->setSig(n);
                break;
            }
            temp1=temp2;
            temp2=temp1->getSig();
        }


    }
}

void ultimallamada::setSig(ultimallamada * s)
{
    sig=s;
}

ultimallamada * ultimallamada::getSig()
{
    return sig;
}

ultimallamada * ultimallamada::gethead()
{
    return head;
}

ultimallamada::~ultimallamada()
{
    //dtor
}
