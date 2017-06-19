#include <iostream>
#include "Arboleda.h"
#include "Arbol.h"
#include "Pino.h"
#include "Cedro.h"
#include "Aguacate.h"
#include "Fruta.h"

using namespace std;

int main()
{
    Arboleda *a=new Arboleda();
    Pino *a=new Pino(3,2);
    Cedro *b=new Cedro(4,10);
    Pino * c new Pino (4,5)
    Aguacate *w=new Aguacate(7,2);
    w->setFruta(4,4);
    a->addArbol(a);
    a->addArbol(b);
    a->addArbol(c);
    a->addArbol(w);

   //Si sumo estas dos deberia dar el valorarboleada
    cout<<"Valor del Pino 1: "<<a->getValor()<<endl;
    cout<< "Valor del Cedro 1: "<<b->getValor()<<endl;
    cout<< "Valor del Pino 2: "<<c->getValor()<<endl;
    cout<< "Valor del Aguacate: "<<d->getValor()<<endl;
    cout<<"VALOR ARBOLEADA"<<endl;
    cout<<a->getValorArboleda()<<endl;

    a->deleteArbol(3);
    cout<<a->getValorArboleda()<<endl;

    return 0;

}
