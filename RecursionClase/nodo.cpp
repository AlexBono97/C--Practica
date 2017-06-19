#include "nodo.h"

nodo::nodo()
{
    //ctor
}

nodo::~nodo()
{
    //dtor
}

void nodo::setValor(int v)
{
    valor=v;
}

int nodo::getValor()
{
    return valor;
}

void nodo::ordenar(nodo * n1)
{
    if(cant==0)
    {
    }
    else{
        nodo* temp=n1;
        nodo* menor=n1;
        nodo* ultimo=0;
        while(temp!=0){

            if(temp->getValor() < menor->getValor())
            {
                menor=temp;
            }
            if(temp->sig==0)
            {
                ultimo=temp;
            }
            temp=temp->sig;
        }
        ultimo->sig=n1;
    }



}

void nodo::addNodo(nodo *s)
{
        if(cant==0)
    {
        head=s;
        tail=s;
        cant=1;


    }else if(cant==1)
    {
        head->setSiguiente(s);
        tail=s;
        cant++;
    }else
    {
        tail->setSiguiente(s);
        temp1=tail;
        tail=s;
        cant++;
    }
}

nodo * nodo::getSiguiente()
{
    return sig;
}

void nodo::setSiguiente(nodo * s)
{
    sig=s;
}
