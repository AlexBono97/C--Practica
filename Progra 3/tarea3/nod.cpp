#include "nod.h"

nod::nod(int v)
{
    this->valor=v;
    this->sig=0;
}

int nod::getVal()
{
    return valor;
}

void nod::add(nod* n)
{
  this->sig=n;
}

int nod::getValSigs()
{
    int vals=valor;
    nod* temp=this->sig;
    while(temp!=0){
        vals+=temp->valor;
        temp=temp->sig;
    }
    return vals;
}
nod::~nod()
{
    //dtor
}
