#include "fruta.h"

fruta::fruta()
{
    //ctor
}

void fruta::addFruta(fruta * g)
{
    if(cant==0)
    {
        head=g;
        tail=g;
        cant=1;


    }else if(cant==1)
    {
        head->setSig(g);
        tail=g;
        cant++;
    }else
    {
        tail->setSig(g);
        temp1=tail;
        tail=g;
        temp1->setSig(tail);
        cant++;
    }
}

void fruta::setSig(fruta * f)
{
    sigui=f;
}

fruta * fruta::getSig()
{
    return sigui;
}

int fruta::getValorfrutas()//recorre y suma el total almacenanado
{
    return 0;
}

void fruta::setValorfrutas()//agrega un valor a cada fruta nueva

{

}

fruta::~fruta()
{
    //dtor
}
