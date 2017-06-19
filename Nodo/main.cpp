#include <iostream>
#include "nodo.h"
#include "col.h"

using namespace std;

int main()
{

    col * cabeza = new col();
    nodo * temp();

    nodo * miNodo1 = new nodo(10);
    cabeza->addNod(miNodo1);
    nodo * miNodo2 = new nodo(5);
    cabeza->addNod(miNodo2);
    nodo * miNodo3 = new nodo(3);
    cabeza->addNod(miNodo3);
    nodo * miNodo4 = new nodo(1);
    cabeza->addNod(miNodo4);

    cout << "Nodo 1: " << miNodo1->getValor() <<endl;//1
    cout << "Nodo 2: " << miNodo1->getSig()->getValor()<<endl;//2
    cout << "Nodo 3: " << miNodo2->getSig()->getValor()<<endl;//3
    cout << "Nodo 4: " << miNodo3->getSig()->getValor()<<endl;//4
    cout << "Cantidad: "<< cabeza->getCant() << endl;
    cout << "Suma de Nodos: " << cabeza->getSumNods()<<endl;

    nodo * miNodo5=new nodo(10);
    cabeza->deleteNodoWith(1);
    cout << "head: "<< cabeza->getHead()->getValor()<<endl;

    cout << "Nodo 1: " << miNodo1->getValor() <<endl;
  //  cout << "Nodo 2: " << miNodo1->getSig()->getValor()<<endl;
    cout << "Nodo 3: " << miNodo2->getSig()->getValor()<<endl;
   // cout << "Nodo 4: " << miNodo3->getSig()->getValor()<<endl;
    cout << "Cantidad: "<< cabeza->getCant() << endl;
    cout << "Suma de Nodos: " << cabeza->getSumNods()<<endl;
   // cout << "get ant: " << miNodo4->getAnt()->getValor()<<endl;
/*
    cabeza->setHead(miNodo1);
    cabeza->addCant(1);
    nodo * miNodo2 = new nodo(6);
    cabeza->addCant(1);
    nodo * miNodo3 = new nodo(9);
    cabeza->setTail(miNodo3);
    cabeza->addCant(1);
    */
    return 0;
}
