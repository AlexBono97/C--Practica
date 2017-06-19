#include "col.h"
//#include "nodo.h"

col::col()
{
   head=0;
   tail=0;
   cant=0;

}

col::col(nodo * f)
{
   addNod(f);
}

col::~col()
{
    //dtor
}

int col::getSumNods()
{
    int suma = 0;
    nodo * temp=head;
    while(temp!=0)
    {
        suma+=temp->getValor();
        temp= temp->getSig();
    }
    return suma;

}

int col::getCant()
{
    cant = 0;
    nodo * temp=head;
    while(temp!=0)
    {
        cant++;
        temp=temp->getSig();

    }
    return cant;

  // solo retorna
    //return cant;

}

void col::addNod(nodo * d)//agrega nodos singulares
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

//Nuevas funciones para la lista doblemente enlazada

void col::insertNodos(nodo * n, int posicion) //funciona
{
    int w=posicion;
    nodo * anterior;
    nodo * siguiente;
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

void col::deleteNodos(int posicion) //funciona
{
    int w=posicion;
    nodo * anterior;
    nodo * siguiente;
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
//}

void col::deleteNodosinSig(nodo * n) //funciona
{
    nodo * anterior;
    nodo * siguiente;
    temp1=head;
    temp3=tail;
    int deletos=0;
    temp2=temp1;
    int control=cant;

    if(n==head)
        {
            head=temp1->getSig();
            cant--;
        }
    if(n==tail)//problema
    {
        anterior=tail->getAnt();
        anterior->setSig(0);
        tail->setAnt(0);
        tail=anterior;
        cant--;
    }
    while(deletos==0 && cant==control)
    {
        temp2=temp1;
        temp3=temp1;
        anterior=temp1->getAnt();
        siguiente=temp1->getSig();

        if(n==temp1)
        {
            temp1=temp1->getSig();
            anterior->setSig(siguiente);
            siguiente->setAnt(anterior);
            cant--;
            deletos--;
        }
        temp1=temp3->getSig();



    }


}

void col::deleteNodoWith(int v)
{
    nodo * anterior;
    nodo * siguiente;
    int cont=1;
    int deletos=0;
    int w=head->getValor();
    if(cant==0)
    {

    }else if(w==v)
    {
        siguiente=head->getSig();
        siguiente->setAnt(0);
        head->setSig(0);
        head->setAnt(0);
        head=siguiente;
        cant--;
    }
    else if(v!=tail->getValor())
    {
       temp2=head->getSig();
            while(cont<cant)
            {
                cont++;
                temp3=temp2;
                anterior=temp2->getAnt();
                siguiente=temp2->getSig();
                int h=temp2->getValor();

                if(v==h && cont<cant)
                    {
                    anterior->setSig(siguiente);
                    siguiente->setAnt(anterior);
                    temp2=0;
                    cant--;
                    deletos++;
                    }
            temp2=temp3->getSig();
            }
}
else
{
                anterior=tail->getAnt();
                siguiente=0;
                tail->setAnt(0);
                anterior->setSig(0);
                tail=anterior;
                cant--;
                    }
            }



//probando
void col::setHead(nodo * d) //funciona
{
    head = d;
}

nodo * col::getHead() //funciona
{
    return head;
}

void col::setTail(nodo * d) //funciona
{
    tail = d;
}

nodo * col::getTail() //funciona
{
    return tail;
}

void col::addCant(int c) //funciona
{
    cant+=c;
}


