#include "arboleda.h"
#include "iostream"
using namespace std;

Arboleda::Arboleda()
{

    //ctor
}

Arboleda::~Arboleda()
{
    //dtor
}


Arboleda::Arboleda(Arbol * s)
{
    addArbol(s);
    cant=1;
    head=s;
    tail=s;

}

void Arboleda::addArbol(Arbol*a)
{
    if(cant==0)
    {
        head=a;
        tail=a;
        cant=1;
    }
    else if(cant==1)
    {
        head->setSiguiente(a);
        tail=a;
        cant++;
    }
    else
    {
        temp1=tail;
        tail=a;
        temp1->setSiguiente(tail);
        cant++;

      /*  Arbol*temp=head;
        while(temp->getSiguiente()!=0)
        {
            temp=temp->getSiguiente();
        }
        temp->setSiguiente(a);
        tail=a;
        cant++;*/

    }
}

int Arboleda::getCantidad()
{
    return cant;
}

void Arboleda::deleteArbol(int posicion)
{
/*
    int w=posicion;
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
    }else if(posicion==1)
    {
        head=head->getSiguiente();
        siguiente=head->getSiguiente();
        anterior=0;
        cant--;

    }else if(posicion>1 && posicion<cant)
    {
        int cont=1;
        temp4=head;
        temp1=head->getSiguiente();
        temp2=temp1->getSiguiente();
    while (deletos!=1)
        {

            temp3=temp1;
            if(posicion==cont)
            {
                temp4->setSiguiente(temp2);
                temp1=0;
                temp3=0;
                cant--;
                deletos++;
            }
            temp4=temp1;
            temp1=temp2;
            temp2=temp2->getSiguiente();

            cont++;

        }


    }



    else if(posicion==cant)
    {

        anterior->setSiguiente(tail);
        tail=0;
        tail=anterior;
        cant--;
    }*/
    int w=posicion;
    Arbol * anterior;
    Arbol * siguiente;
    int cont=0;
    int deletos=0;

    if(cant==0)
    {
        cout<<"No ha agregado ningun arbol aun" <<endl;
    }
    else if(cant==1)
    {
        if(cont==w)
        {
            head=0;
            tail=0;
            cant=0;
        }
    }
    else if(posicion==1)
    {
        head=head->getSiguiente();
        siguiente=head->getSiguiente();
        anterior=0;
        cant--;

    }
    else if(posicion>1 && posicion<cant)
    {
        //seteo de los punteros
        temp1=head;
        temp2=head->getSiguiente();
        temp3=temp2->getSiguiente();
        while(deletos==0)
            {
                cout << "Contador al inicio: " << cont << endl;
                cont++;
                cout << "Contador luego del ++: " << cont << endl;
                temp4=temp2;

                if(cont==posicion-1 && cont<cant)
                    {
                    cout << "entro al primer if: "<<cont << endl;
                    temp1->setSiguiente(temp3);
                    temp2=0;
                    cant--;
                    deletos++;
                    }
                temp1=temp1->getSiguiente();
                temp2=temp4->getSiguiente();
                temp3=temp3->getSiguiente();

                }
    }
    else if(posicion == cant)
    {
        //Arboleda * f;
        int cont=0;
        temp1=head;
        temp2=temp1->getSiguiente();
        while(deletos==0)
            {
                cout << "Contador luego del ++: " << cont << endl;
                if(temp2==tail)
                    {
                    cout << "entro al primer if del ultimo evento: "<<cont << endl;
                    temp1->setSiguiente(0);
                    tail=temp1;
                    temp2=0;
                    cant--;
                    break;
                    }
                temp1=temp1->getSiguiente();
                temp2=temp2->getSiguiente();
                cont++;

            }
}
}

Arbol * Arboleda::getUltimoArbol()
{
    return tail;
}

Arbol * Arboleda::getPrimerArbol()
{
    return head;
}

int Arboleda::getValorArboleda()// Aun no lista

{
    int suma = 0;
    Arbol * temp=head;
    while(temp!=0)
    {
        suma+=temp->getValor();
        temp= temp->getSiguiente();
    }
    return suma;
}

Arbol * Arboleda::getTail()
{
    return tail;
}

Arbol * Arboleda::getHead()
{
    return head;
}

void Arboleda::setTail(Arbol * s)
{
    tail=s;
}






