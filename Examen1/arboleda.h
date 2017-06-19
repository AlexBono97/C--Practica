#ifndef ARBOLEDA_H
#define ARBOLEDA_H
#include "arbol.h"


class Arboleda
{
    public:
        Arboleda();
        virtual ~Arboleda();
        Arboleda(Arbol * s);

        void setHead(Arbol * s);
        Arbol * getHead();//
        void setTail(Arbol * s);
        Arbol * getTail();


      //  void setValorArboleda(int v);
        int getValorArboleda();
        int getCantidad();

        void addArbol(Arbol * a);
        void deleteArbol(int pos);
        Arbol * getUltimoArbol();
        Arbol * getPrimerArbol();



    protected:

    private:
        int cant=0;
        Arbol * head;
        Arbol * tail;
        Arbol * temp1;
        Arbol * temp2;
        Arbol * temp3;
        Arbol * temp4;
        Arbol * temp5;
};

#endif // ARBOLEDA_H
