#include <iostream>
#include "myvector.h"
#include "mylist.h"

using namespace std;

int main()
{

    myvector * mivector = new myvector();

    myvector * vect1 = new myvector(9);
    myvector * vect2 = new myvector(8);
    myvector * vect3 = new myvector(7);
    myvector * vect4 = new myvector(7);
    myvector * vect5 = new myvector(7);

    mivector->addVector(vect1);
    mivector->addVector(vect2);
    mivector->addVector(vect3);

    //Probando mivector
    cout << "Tamano de Vector: " <<mivector->getSize() <<endl;
    cout << "Borrando un elemento....." <<endl;
    mivector->deleteVector(1);
    cout << "Nuevo tamano de vector: " << mivector->getSize() << endl;
    cout << "Agregando dos nuevos elementos...." << endl;
    mivector->addVector(vect4);
    mivector->addVector(vect5);
    cout << "Nuevo tamano de vector: " << mivector->getSize() << endl;

    //probando milista
    mylist * milista = new mylist();

    mylist * list1= new mylist(1);
    mylist * list2= new mylist(2);
    mylist * list3= new mylist(3);
    mylist * list4= new mylist(4);
    mylist * list5= new mylist(5);
    mylist * list6= new mylist(6);

    milista ->addList(list1);
    milista ->addList(list2);
    milista ->addList(list3);
    milista ->addList(list4);

    cout<< "Tamano de lista: " << milista->getSize() << endl;
    cout<< "Borrando un elemento..."<<endl;
    milista->deleteList(2);
    cout << "Nuevo tamano lista: "<< milista->getSize()<<endl;
    cout << "agregaremos 2 elementos nuevos..." << endl;
    milista->addList(list5);
    milista->addList(list6);
    cout << "Tamano final: "<<milista->getSize()<<endl;
    cout << "Getting Value of Front: " << milista->getFront()->getValor()<<endl;
    cout << "Getting Value of Back: " << milista->getBack()->getValor()<<endl;





    return 0;
}
