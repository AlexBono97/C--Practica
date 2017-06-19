#ifndef ARBOLEDA_H
#define ARBOLEDA_H
#include "arbol.h"

class arboleda
{
    public:
        arboleda();
        virtual ~arboleda();
        void addArbol(Arbol * a);
        int getCantidad();
        void deleteArbol(int pos);
        Arbol * getultimoArbol();
        Arbol * getprimerArbol();
        int getvalorArboleda();
        Arbol * setSig();

    protected:

    private:
        int cant;
        Arbol * head;
        Arbol * tail;
        Arbol * temp1;
        Arbol * temp2;
        Arbol * temp3;
        Arbol * temp4;
};

#endif // ARBOLEDA_H
