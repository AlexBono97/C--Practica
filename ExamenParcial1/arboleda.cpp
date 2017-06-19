#include "arboleda.h"

arboleda::arboleda()
{
    //ctor
}

void arboleda::addArbol(Arbol * a)
{
    if(cant==0)
    {
        head=a;
        tail=a;
        cant=1;


    }else if(cant==1)
    {
        head->setSiguiente(a);
        tail=a;
        cant++;
    }else
    {
        tail->setSiguiente(a);
        temp1=tail;
        tail=a;
        cant++;
    }
}

int arboleda::getCantidad()
{
    return cant;
}

void arboleda::deleteArbol(int pos)
{
    int w=pos;
    Arbol * anterior;
    Arbol * siguiente;
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
    }else if(pos==1)
    {
        head=head->getSiguiente();
        siguiente=head->getSiguiente();
        cant--;

    }else if(pos>1 && pos<cant)
    {//temp3=temp2;
        //anterior=temp2->getAnt();
        //siguiente=temp2->getSig();
       temp2=head->getSiguiente();
        temp1=head;
            while(deletos==0)
            {cont++;
                temp3=temp2;
                siguiente=temp3->getSiguiente();

                if(cont==pos && cont<cant){
                    temp1->setSiguiente(siguiente);
                    temp2=0;
                    temp3=0;
                    cant--;
                    deletos++;
            }
            temp2=temp3->getSiguiente();
            temp1=temp1->getSiguiente();

        }
    }
    else if(pos==cant)
    {
        temp1=tail;

    }
}

arboleda::~arboleda()
{
    //dtor
}
