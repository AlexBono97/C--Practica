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
    cout << "empiezo" << endl;
    Pino *b=new Pino(2,3);
    Pino *c=new Pino(4,5);
    cout << "un pino" << endl;
    Cedro *d=new Cedro(6,5);
    cout << "un cedro" << endl;
    a->addArbol(b);
    cout << "agrego pino, arbol 1 valor 6" << endl;
    a->addArbol(c);
    cout << "agrego pino, arbol 2 valor 20" << endl;
    a->addArbol(d);
    cout << "agrego cedro, arbol 2 valor 30" << endl;
    Aguacate * e = new Aguacate(10);
    a->addArbol(e);
    cout << "agrego aguacate arbol tail valor 10" << endl;

    cout<< "Valor del pino 1: "<< b->getValor()<<endl;
    cout << "Valor del pino 2: "<<c->getValor()<<endl;
    cout << "Valor del cedro 1: "<<d->getValor()<<endl;
    cout << "Valor del aguacate: "<<e->getValor()<<endl;



    cout<< "Valor Arboleda: "<<a->getValorArboleda()<<endl;
    cout << "borrare algo" << endl;
    cout << "Cantidad: "<< a->getCantidad()<<endl;
    a->deleteArbol(4);
    cout << "Tail: " << a->getTail()->getValor()<<endl;
    cout<<"Nuevo valor: " << a->getValorArboleda()<<endl;
    cout << "Nueva Cantidad: " << a->getCantidad() << endl;

    return 0;
}
