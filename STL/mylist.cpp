#include "mylist.h"

mylist::mylist()
{
    head=0;
    tail=0;
    cant=0;
    //ctor
}

mylist::mylist(int v)
{
    setValor(v);
    setSig(0);
}

mylist::mylist(mylist * d)
{
    addList(d);
}

mylist::~mylist()
{
    //dtor
}

void mylist::setValor(int v)
{
    valor=v;
}

int mylist::getValor()
{
    return valor;
}

void mylist::setSig(mylist * s)
{
    sig = s;
}

mylist * mylist::getSig()
{
    return sig;
}

void mylist::setAnt(mylist * s)
{
    ant =s;
}

mylist * mylist::getAnt()
{
    return ant;
}

int mylist::getSize()
{
    cant = 0;
    mylist * temp=head;
    while(temp!=0)
    {
        cant++;
        temp=temp->getSig();

    }
    return cant;

  // solo retorna
  //return cant;
}

mylist * mylist::getFront()
{
    return head;
}

mylist * mylist::getBack()
{
    return tail;
}

void mylist::addList(mylist * d)//agrega nodos singulares
{
    if(cant==0)
    {
        head=d;
        tail=d;
        cant=1;


    }else if(cant==1)
    {
        head->setSig(d);
        tail=d;
        tail->setAnt(head);
        cant++;
    }else
    {
        tail->setSig(d);
        temp1=tail;
        tail=d;
        tail->setAnt(temp1);
        cant++;
    }
}

void mylist::insertList(mylist * n, int posicion) //funciona
{
    int w=posicion;
    mylist * anterior;
    mylist * siguiente;
    int cont=1;
    int deletos=0;
    temp1=n;

     if(posicion==1)
    {
        temp2=head;
        head->setAnt(temp1);
        temp1->setSig(head);
        head=temp1;
        cant++;
    }else if(posicion==cant)
    {
        anterior=tail->getAnt();
        siguiente=0;
        anterior->setSig(temp1);
        temp1->setAnt(anterior);
        temp1->setSig(tail);
        tail->setAnt(temp1);
        cant++;
    }else if(posicion==cant+1)
    {
        tail->setSig(temp1);
        temp1->setAnt(tail);
        temp1->setSig(0);
        tail=temp1;
        cant++;
    }

    else if(posicion>1 && posicion<cant)
    {
        temp2=head->getSig();
        //temp3=temp2;
        //anterior=temp2->getAnt();
        //siguiente=temp2->getSig();
            while(deletos==0)
            {
                anterior=temp2->getAnt();
                siguiente=temp2->getSig();
                temp3=temp2;
                if(cont==posicion && cont < cant){
                    anterior->setSig(temp1);
                    temp1->setAnt(anterior);
                    temp1->setSig(temp2);
                    temp2->setAnt(temp1);
                    cant++;
                    deletos++;
            }
            temp2=temp3->getSig();
            cont++;
        }
    }

    }

void mylist::deleteList(int posicion) //funciona
{
    int w=posicion;
    mylist * anterior;
    mylist * siguiente;
    int cont=1;
    int deletos=0;

    if(cant==0)
    {

    }else if(cant==1)
    {
        if(cont==w)
        {
            head=0;
            tail=0;
            cant=0;
        }
    }else if(posicion==1)
    {
        head=head->getSig();
        siguiente=head->getSig();
        anterior=0;
        cant--;

    }else if(posicion>1 && posicion<cant)
    {//temp3=temp2;
        //anterior=temp2->getAnt();
        //siguiente=temp2->getSig();
       temp2=head->getSig();

            while(deletos==0)
            {cont++;
                temp3=temp2;
                anterior=temp2->getAnt();
                siguiente=temp3->getSig();

                if(cont==posicion && cont<cant){
                    anterior->setSig(siguiente);
                    siguiente->setAnt(anterior);
                    temp2=0;
                    cant--;
                    deletos++;
            }
            temp2=temp3->getSig();

        }
    }
    else if(posicion==cant)
    {
        anterior=tail->getAnt();
        siguiente=0;
        tail->setAnt(0);
        anterior->setSig(0);
        tail=anterior;
        cant--;
    }
}

