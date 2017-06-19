#include "Arboleda.h"

Arboleda::Arboleda()
{
    cantidad=0;
    head=0;
    tail=0;
}
void Arboleda::addArbol(Arbol*ar)
{
    if(head==0)
    {
        head=ar;
        tail=ar;
        cantidad++;
    }
    else
    {
        Arbol*temp=head;
        while(temp->getSig()!=0)
        {
            temp=temp->getSig();
        }
        temp->setSig(ar);
        tail=ar;
        cantidad++;

    }
}
int Arboleda::getCantidad()
{
    return cantidad;
}
void Arboleda::deleteArbol(int po)
{
    Arbol*temp=head;
    int contador=0;
    while (contador<po){
       temp=temp->getSig();
    }

    temp->setSig(temp->getSig()->getSig()); //El siguiente de mi siguiente
    temp=temp->getSig();
    temp=0;
    cantidad=cantidad-1;

}
Arbol* Arboleda::getPrimerArbol()
{
    return head; //Retorno la cabeza
}
Arbol* Arboleda::getUltimoArbol()
{
    return tail; //Retorno la cola
}
int Arboleda::getValorArboleda()
{
    int val=0;
    Arbol* temp=head;
    while(temp->getSig()!=0)
    {
        val+=temp->getValor();
        temp=temp->getSig();
    }
    return val;
}

