#include "agenda.h"
#include "ultimallamada.h"
#include <iostream>

agenda::agenda()
{
    contactoHead=0;
    ultimallamadaHead=0;
    CantContactos=0;
    //ctor
}

bool agenda::seRepite(int n)//hacer arreglos del final
{
    /*contacto *temp=contactoHead;
    while(temp!=0){
        if(temp->getnumero==n){
            return true;
        }
        temp=temp->getSig();
    }*/
    return false;
}

void agenda::add(contacto * c)
{
    if(CantContactos==0)
    {
        contactoHead=c;
        CantContactos=1;

    }else if(CantContactos==1)
    {
        contactoHead->setSig(c);
        CantContactos++;
    }else
    {
        int deletos=0;
        contacto * temp1=contactoHead;
        contacto * temp2=contactoHead->getSig();
        while(temp1!=0)
        {
            if(temp2==0)
            {
                temp1->setSig(c);
                CantContactos++;
                break;
            }
            temp1=temp2;
            temp2=temp1->getSig();
        }
    }
}


std::pair<bool,int> agenda::buscar(int numContacto)
{
    int posicion=0;
    bool existe=false;
    pair<bool, int> p= make_pair(false,-1);
    contacto *temp=contactoHead;
    while(temp!=0){
        if(temp->getnumero()==numContacto){
            p= make_pair(true,posicion);
            return p;
            break;
        }
        posicion++;
        temp=temp->getSig();
    }
    return p;

}

contacto * agenda::getContacto(int pos)
{
    int deletos=0;
    int posicion=0;
    contacto *temp=contactoHead;
    while(temp!=0)
        {
            if(posicion==pos)
            {
                return temp;
                break;
            }
        posicion++;
        temp=temp->getSig();
        }

}



void agenda::llamar(int pos)
{
    ultimallamada * m;
    int deletos=0;
    int posicion=1;
    contacto *temp=contactoHead;
    while(temp!=0)
        {
            if(posicion==pos)
            {
               ultimallamada * registro = new ultimallamada(temp,0);
               m->add(registro);
               break;
            }
        posicion++;
        temp=temp->getSig();
        }
}

void agenda::imprimirAgenda()
{
    int impresos=0;
    int deletos=0;
    int posicion=0;
    contacto *temp=contactoHead;
    if(posicion!=CantContactos-1)
    {
      while(posicion!=CantContactos)
        {
            cout << temp->nombre << " " << temp->numContacto << " " << temp->operadorCel <<endl;
            posicion++;
            temp=temp->getSig();
        }

    }

}

void agenda::imprimirUltimasLlamadas()
{
    agenda * g;
    ultimallamada * n;
    int deletos=0;
    int posicion=0;
    ultimallamada *temp=g->getUltimaHead();
    if(temp!=0)
    {
      while(posicion!=n->cantLlamadas)
        {
                cout << temp->contactollamado->nombre<<endl;
                posicion++;
                temp=temp->getSig();
        }

    }
}



ultimallamada * agenda::getUltimaHead()
{
    ultimallamada * n;
    return n->gethead();
}

agenda::~agenda()
{
    //dtor
}
