#include "Aguacate.h"

Aguacate::Aguacate()
{

}
Aguacate::Aguacate(int n,int m) : Arbol(n)
{
    cant=0;
}
int Aguacate::getCant()
{
    return cant;
}
int Aguacate::getValor()
{
    int val=0;
    Fruta*temp=frct;
    while(temp->getSig()!=0)
    {
        val=val+(temp->getPeso()*temp->getTamano());
        temp=temp->getSig();
    }
    return val;
}
void Aguacate::setFruta(int pe, int pa)
{
    if(frct==0)
    {
        Fruta *newe= new Fruta(pe,pa);
        frct=newe;
    }
    else{
        Fruta*temp=frct;
    while(temp->getSig()!=0)
    {
        temp=temp->getSig();
    }
    temp->setPeso(pe);
    temp->setTamano(pa);
    }
}
Aguacate::~Aguacate()
{
    //dtor
}
