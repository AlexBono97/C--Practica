#include "aplicacion.h"


using namespace std;
Aplicacion::Aplicacion(QString n, long int i)
{
    next=0;
    ant=0;
    head=0;
    tail=0;
    int x= n.length();
    n.resize(x-4);
    name=n;
    id=i;
    //ctor
}

Aplicacion::~Aplicacion()
{
    //dtor
}

void Aplicacion::setNext(Aplicacion* n)
        {
          next=n;
        }

        Aplicacion* Aplicacion::getNext()
        {
            return next;
        }
void Aplicacion::setAnt(Aplicacion* n)
        {
          ant=n;
        }

        Aplicacion* Aplicacion::getAnt()
        {
            return ant;
        }
