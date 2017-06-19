#include "lista.h"

Lista::Lista()
{
    inicial=0;
}

Nodo* Lista::ultimoNodo()
{
    Nodo* ultimo=0;
    Nodo* temp=inicial;
    while(temp!=0)
    {
        ultimo=temp;
        temp=temp->getSig();
    }
    return ultimo;
}

void Lista::agregarNodo(Nodo* n)
{
    if(inicial==0){
        inicial=n;
        inicial->agregarAnt(0);
        inicial->agregarSig(0);
    }
    else{
      Nodo* ultimo=ultimoNodo();
      ultimo->agregarSig(n);
      n->agregarAnt(ultimo);
    }
}

void Lista::removerNodo()
{

}

Nodo* Lista::nodoMayor()
{
    Nodo* temp= inicial->getSig();
    Nodo* mayor=inicial;
    while(temp!=0){
        if(temp->getVal()<mayor->getVal()){

            mayor=temp;
        }
        temp=temp->getSig();
    }
    return mayor;
}

Nodo* Lista::nodoMenor()
{
    Nodo* temp= inicial->getSig();
    Nodo* menor=inicial;
    while(temp!=0){
        if(temp->getVal()>menor->getVal()){

            menor=temp;
        }
        temp=temp->getSig();
    }
    return menor;
}
int Lista::cantNodos()
{
    Nodo* temp= inicial;
    int cant = 0;
    while(temp!=0){
        cant++;
        temp=temp->getSig();
    }
    return cant;
}

int Lista::sumaNodos()
{
    Nodo* temp= inicial;
    int suma = 0;
    while(temp!=0){
        suma+=temp->getVal();
        temp=temp->getSig();
    }
    return suma;
}

double Lista::promedioNodos()
{
    return sumaNodos()/cantNodos();
}
